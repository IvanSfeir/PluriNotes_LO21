/*!
 *@file     relation.h
 *@author   Ngo Sy Toan
 * @date    June 2017
 * @brief   The relation file: contain all the description of a relation, couple and Relation Manager
 */
#ifndef RELATION_H
#define RELATION_H

#include "note.h"
#include "iterator.h"
#include <QString>
#include "exception.h"
/*!
 * \brief The Couple class: contain 2 note linked together by a relation, with label
 */
class Couple {
    /*!
     * \brief note1: note from
     */
    Note* note1;
    /*!
     * \brief note2: note to
     */
    Note* note2;
    /*!
     * \brief label: label of the couple
     */
    QString label;
public:
    /*!
     * \brief Couple: constructor of couple
     * \param n1: note from
     * \param n2: note to
     * \param lb: label of the couple
     * \details This couple indicates the relation from note 1 to note 2 if it is oriented otherwise the relation between note 1 and note 2
     */
    Couple(Note* n1, Note* n2, QString& lb): note1(n1), note2(n2), label(lb) {}
    /*!
     * \brief getNote1: get the note 1 in the couple
     * \return const Note&
     */
    const Note& getNote1() const { return *note1; }
    /*!
     * \brief getNote2: get the note 1 in the couple
     * \return const Note&
     */
    const Note& getNote2() const { return *note2; }
    /*!
     * \brief getLabel: get the label of the couple
     * \return const QString&
     */
    const QString& getLabel() const {return label;}
    /*!
     * \brief setLabel: set the new label
     * \param newLb: new label
     */
    void setLabel(QString& newLb) {label = newLb;}

    /*!
     * \brief destructor of couple
     */
    ~Couple(){}
};

/*!
 * \brief The Relation class is abstract, it contains couples and the orientation of the couples inside.
 * \details There are RelationNormale and RelationPreexistence are inherit relation
 */
class Relation {
    /*!
     * \brief couples: table of couples
     */
    Couple** couples;
    /*!
     * \brief nbCouples: number of couples in the table
     */
    unsigned int nbCouples;
    /*!
     * \brief maxCouples: maximum couples can be contained in the table
     */
    unsigned int maxCouples;

protected:
    /*!
     * \brief titre: titre of the relation
     */
    QString titre;
    /*!
     * \brief description: description of the relation
     */
    QString description;
    /*!
     * \brief orientee: true if orientee
     */
    bool orientee;
public:
    /*!
     * \brief Relation: constructor of relation
     * \param titr: titre of the relation
     * \param desc: description of the relation
     * \param orie: orientation of the relation
     */
    Relation(const QString& titr, const QString& desc="", bool orie=true):
        titre(titr), description(desc), nbCouples(0), maxCouples(0), orientee(orie){}

    /*!
     * \brief setTitre: set new titre
     * \param newTitre: new titre of the relation
     * \details class pure virtual
     */
    virtual void setTitre(const QString& newTitre) = 0;                     //pure
    /*!
     * \brief setDescription: set new description
     * \param newDescription: new description of the relation
     * \details class pure virtual
     */
    virtual void setDescription(const QString& newDescription) = 0;         //pure
    /*!
     * \brief setOrientee: set new orientee
     * \param boolVal: true if the relation is oriented
     * \details class pure virtual
     */
    virtual void setOrientee(bool boolVal) = 0;                             //pure
    /*!
     * \brief getTitre: get titre of relation
     * \return const QString&
     */
    const QString& getTitre() const {return titre;}
    /*!
     * \brief getDescription: get description of relation
     * \return const QString&
     */
    const QString& getDescription() const {return description;}
    /*!
     * \brief getOrientee: get orientee of relation
     * \return bool
     */
    bool getOrientee() const {return orientee;}
    /*!
     * \brief ajouterCouple: add new couple into relation
     * \param newCouple: pointer to the new couple
     */
    void ajouterCouple(Couple* newCouple);
    /*!
     * \brief supprimerCouple: delete the couple
     * \param supCouple: pointer to the couple need to delete
     */
    void supprimerCouple(Couple* supCouple);
    /*!
     * \brief ~Relation: destructor of relation
     * \details Free the table couple, virtual function
     */
    virtual ~Relation(){
        for (unsigned int i=0; i < nbCouples; i++) delete couples[i];
        delete[] couples;
    }

    //implement iterator
    /*!
     * \brief The iterator class: iterator of relation, iterate throught the table of couple
     */
    class iterator: public Iterator<Couple>{
    friend class Relation;
    iterator(Couple** c): Iterator(c){}
    };
    /*!
     * \brief begin: get the pointer to the beginning of the table of couple
     * \return iterator
     */
    iterator begin() {return iterator(couples);}
    /*!
     * \brief end: get the pointer to the end of the table of couple
     * \return iterator
     */
    iterator end() {return iterator(couples+nbCouples);}
};

/*!
 * \brief The RelationNormale class: heritate of Relation class
 * \details Normal relation which can be deleted and change titre, description and orientation
 */
class RelationNormale: public Relation{
public:
    /*!
     * \brief RelationNormale: constructor of RelationNormale
     * \param titr: titre of RelationNormale
     * \param desc: description of RelationNormale
     * \param orie: orientation of RelationNormale, true if orientee
     */
    RelationNormale(const QString& titr, const QString& desc, bool orie=true): Relation(titr, desc, orie){}
    /*!
     * \brief setTitre: set new titre to RelationNormale
     * \param newTitre: new titre of RelationNormale
     */
    void setTitre(const QString& newTitre) {titre = newTitre;}
    /*!
     * \brief setDescription: set new description to RelationNormale
     * \param newDescription: new description of RelationNormale
     */
    void setDescription(const QString& newDescription){description = newDescription;}
    /*!
     * \brief setOrientee: set new orientee to RelationNormale
     * \param boolVal: true of orientee
     */
    void setOrientee(bool boolVal){orientee = boolVal;}
};

/*!
 * \brief The RelationPreexistente class: the Preexistence class, Reference
 * \details Cannot delete this class, this class hold the first place in table of Relation in RelationManager, singleton
 */
class RelationPreexistente: public Relation{
    /*!
     * \brief setTitre: define the virtual function herited from Relation class
     * \details it is in the private to prevent changing titre
     */
    void setTitre(const QString&){}
    /*!
     * \brief setDescription: define the virtual function herited from Relation class
     * \details it is in the private to prevent changing description
     */
    void setDescription(const QString&){}
    /*!
     * \brief setOrientee: define the virtual function herited from Relation class
     * \details it is in the private to prevent changing orientation
     */
    void setOrientee(bool){}

    /*!
     * \brief instance_RelationPreexistente: instance of Singleton of RelationPreexistente
     */
    static RelationPreexistente* instance_RelationPreexistente;
    /*!
     * \brief RelationPreexistente: constructor by recopy
     * \param r: RelationPreexistence
     * \details hide this function in private to prevent constructor by recopy
     */
    RelationPreexistente(const RelationPreexistente& r);
    /*!
     * \brief ~RelationPreexistence: destructor, hide it because of Singleton
     */
    ~RelationPreexistente(){}
    /*!
     * \brief operator =: constructor by affectation
     * \return RelationPreexistence&
     * \details Private because Singleton
     */
    RelationPreexistente& operator=(const RelationPreexistente&);
    /*!
     * \brief RelationPreexistente: constructor
     */
    RelationPreexistente();

public:
    /*!
     * \brief getRelationPreexistente: get the RelationPreexistence
     * \return the instance of RelationPreexistence
     * \details contruct new instance if there is no instance, otherwise get the instance pointer
     */
    static RelationPreexistente* getRelationPreexistente(){
        if (!instance_RelationPreexistente) instance_RelationPreexistente = new RelationPreexistente;
            return instance_RelationPreexistente;
    }
    static void libererRelationPreexistente(){
        if (instance_RelationPreexistente){
            delete instance_RelationPreexistente;
            instance_RelationPreexistente = 0;
        }
    }
};

/*!
 * \brief The RelationManager class: Relation Manager to manage Relation, Singleton
 */
class RelationManager{
    /*!
     * \brief relations: table of relations
     * \details first relation in table is RelationPreexistence
     */
    Relation** relations;
    /*!
     * \brief nbRelations: number of relations in the table
     */
    unsigned int nbRelations;
    /*!
     * \brief maxRelations: maximum number of relations in the table
     */
    unsigned int maxRelations;

    /*!
     * \brief instance_RelationManager: instance of RelationManager
     * \details Private because Singleton
     */
    static RelationManager* instance_RelationManager;
    /*!
     * \brief RelationManager: constructor by recopy of RelationManager
     * \details Private because Singleton
     */
    RelationManager(const RelationManager&){}
    /*!
     * \brief RelationManager: constructor of RelationManager
     * \details Private because Singleton
     */
    RelationManager();
    /*!
     * \brief operator =: constructor by affectation
     * \return RelationManager&
     * \details Private because of Singleton
     */
    RelationManager& operator=(const RelationManager&);
public:
    /*!
     * \brief getRelationManager: get instance of RelationManager, contruct if there is no instance of RelationManager
     * \return pointer to instance of RelationManager
     */
    static RelationManager* getRelationManager(){
        if (RelationManager::instance_RelationManager==nullptr){
            RelationManager::instance_RelationManager = new RelationManager;
            RelationPreexistente* RP = RelationPreexistente::getRelationPreexistente();
            instance_RelationManager->ajouterRelation(RP);
        }
        return instance_RelationManager;
    }
    /*!
     * \brief libererRelationManager: Free the instance of RelationManager
     */
    static void libererRelationManager(){
        if (RelationManager::instance_RelationManager!=nullptr){
            delete RelationManager::instance_RelationManager;
        }
    RelationManager::instance_RelationManager=nullptr;  
    }
    /*!
     * \brief getRelationFromTitle: return pointer to relation from a titre
     * \param titre: titre of the relation
     * \return Relation*
     */
    Relation* getRelationFromTitle(QString& title);
    /*!
     * \brief getNbRelations: get number of relations in RelationManager
     * \return unsigned int
     */
    unsigned int getNbRelations() {return nbRelations;}
    /*!
     * \brief ajouterRelation: add Relation to table of Relation in RelationManager
     * \param newRelation: pointer to the newRelation
     */
    void ajouterRelation(Relation* newRelation);
    /*!
     * \brief supprimerRelation: detete a Relation in RelationManager
     * \param supprimerRelation: pointer to the Relation needed to delete
     */
    void supprimerRelation(Relation* supprimerRelation);

    //implement iterator
    /*!
     * \brief The iterator class: iterator through table of relations
     */
    class iterator: public Iterator<Relation>{
     friend class RelationManager;
     iterator(Relation** c): Iterator(c){}
    };
    /*!
     * \brief begin: return the pointer to the first position in the table
     * \return iterator
     */
    iterator begin() {return iterator(relations);}
    /*!
     * \brief end: return the pointer to the end position in the table
     * \return iterator
     */
    iterator end() {return iterator(relations+nbRelations);}

    /*!
     * \brief loadRelationManager: load .xml to RelationManager
     * \param filename: file .xml to load
     */
    void loadRelationManager(const QString & filename);
    /*!
     * \brief saveRelationManager: save RelationManager to .xml
     * \param filename: save to file .xml
     */
    void saveRelationManager(const QString & filename);
};

#endif // RELATION_H
