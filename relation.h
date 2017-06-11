#ifndef RELATION_H
#define RELATION_H

#include "note.h"
#include "iterator.h"
#include <QString>

class exception {
public:
    exception(const QString& message=" "): info(message){}
    QString getInfo() const {return info;}
private:
    QString info;
};

class Couple {
    Note* note1;
    Note* note2;
    QString label;
public:
    Couple(Note* n1, Note* n2, QString& lb): note1(n1), note2(n2), label(lb) {}
    const Note& getNote1() const { return *note1; }
    const Note& getNote2() const { return *note2; }
    const QString& getLabel() const {return label;}
    void setLabel(QString& newLb) {label = newLb;}
    ~Couple(){}
};

class Relation {
    Couple** couples;
    unsigned int nbCouples;
    unsigned int maxCouples;

protected:
    QString titre;
    QString description;
    bool orientee;
public:
    Relation(const QString& titr, const QString& desc="", bool orie=true):
        titre(titr), description(desc), nbCouples(0), maxCouples(10), orientee(orie){}

    virtual void setTitre(const QString& newTitre) = 0;                     //pure
    virtual void setDescription(const QString& newDescription) = 0;         //pure
    virtual void setOrientee(bool boolVal) = 0;                             //pure

    const QString& getTitre() const {return titre;}
    const QString& getDescription() const {return description;}
    bool getOrientee() const {return orientee;}

    void ajouterCouple(Couple* newCouple);
    void supprimerCouple(Couple* supCouple);

    virtual ~Relation(){
        for (unsigned int i=0; i < nbCouples; i++) delete couples[i];
        delete[] couples;
    }

    //implement iterator
    class iterator: public Iterator<Couple>{
     friend class Relation;
     iterator(Couple** c): Iterator(c){}
    };
    iterator begin() {return iterator(couples);}
    iterator end() {return iterator(couples+nbCouples);}
};

class RelationNormale: public Relation{
public:
    RelationNormale(const QString& titr, const QString& desc, bool orie=true): Relation(titr, desc, orie){}

    void setTitre(const QString& newTitre) {titre = newTitre;}
    void setDescription(const QString& newDescription){description = newDescription;}
    void setOrientee(bool boolVal){orientee = boolVal;}
};

class RelationPreexistente: public Relation{
    void setTitre(const QString&){}
    void setDescription(const QString&){}
    void setOrientee(bool){}

    static RelationPreexistente* instance_RelationPreexistente;
    RelationPreexistente(const RelationPreexistente&);
    ~RelationPreexistente(){}
    RelationPreexistente& operator=(const RelationPreexistente&);
    RelationPreexistente(): Relation("ref", "preexistente"){}

public:
    static RelationPreexistente& getRelationPreexistente(){
        if (!instance_RelationPreexistente) instance_RelationPreexistente = new RelationPreexistente;
            return *instance_RelationPreexistente;
    }
    static void libererRelationPreexistente(){
        if (instance_RelationPreexistente){
            delete instance_RelationPreexistente;
            instance_RelationPreexistente = 0;
        }
    }
};

class RelationManager{
    Relation** relations;
    unsigned int nbRelations;
    unsigned int maxRelations;

    static RelationManager* instance_RelationManager;
    RelationManager(const RelationManager&){}
    RelationManager(){
        relations = new Relation*[maxRelations+10];
        maxRelations += 10;
        RelationPreexistente& RP = RelationPreexistente::getRelationPreexistente();
        relations[0] = &RP;
        nbRelations++;
    }
    RelationManager& operator=(const RelationManager&);
public:
    static RelationManager& getRelationManager(){
        if (!instance_RelationManager){
            instance_RelationManager = new RelationManager;
            return *instance_RelationManager;
        }
    }
    static void libererRelationManager(){
        if (instance_RelationManager){
            delete instance_RelationManager;
        }
    }

    void ajouterRelation(Relation* newRelation);
    void supprimerRelation(Relation* supprimerRelation);

    //implement iterator
    class iterator: public Iterator<Relation>{
     friend class RelationManager;
     iterator(Relation** c): Iterator(c){}
    };
    iterator begin() {return iterator(relations);}
    iterator end() {return iterator(relations+nbRelations);}

    ////////////////////////////
    //Method load, save to XML//
    ////////////////////////////
    void loadRelationManager(const QString & filename);
    void saveRelationManager(const QString & filename);
};

#endif // RELATION_H
