#ifndef RELATION_H
#define RELATION_H

//#include "Note.h"
#include "iterator.h"
#include <QString>

class RelationException {
public:
    RelationException(const QString& message=" "): info(message){}
    QString getInfo() const {return info;}
private:
    QString info;
};

class Couple {
    Note note1;
    Note note2;
public:
    Couple(Note& n1, Note& n2): note1(n1), note2(n2){}
    const Note& getNote1() const { return note1; }
    const Note& getNote2() const { return note2; }
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
    Relation(const QString& titr, const QString& desc, int max=10, bool orie=true):
        titre(titr), description(desc), nbCouples(0), maxCouples(max), orientee(orie){}

    virtual void setTitre(const QString& newTitre) = 0;
    virtual void setDescription(const QString& newDescription) = 0;
    virtual void setOrientee(bool boolVal) = 0;

    void ajouterCouple(Couple* newCouple);
    void supprimerCouple(Couple* supCouple);

    ~Relation(){
        for (int i=0; i < nbCouples; i++) delete couples[i];
        delete[] couples;
    }

    //implement iterator
    class iterator<Couple,Relation>;
    iterator begin() {return iterator(couples);}
    iterator end() {return iterator(couples+nbCouples);}
};

class RelationNormale: public Relation{
public:
    RelationNormale(const QString& titr, const QString& desc, int max=10, bool orie=true): Relation(titr, desc){}
    void setTitre(QString& newTitre) {titre = newTire;}
    void setDescription(QString& newDescription){description = newDescription;}
    void setOrientee(bool boolVal){orientee = boolVal;}
};

class RelationPreexistente: public Relation{
    void setTitre(const QString& newCouple){}
    void supprimerCouple(const QString& supCouple){}
    void setOrientee(bool boolVal){}

    static RelationPreexistente* instance_RelationPreexistente;
    RelationPreexistente(const RelationPreexistente&){}
    ~RelationPreexistente(){}
    RelationPreexistente& operator=(const RelationPreexistente&){}
    RelationPreexistente(): Relation("ref", "preexistente"){}

public:
    static RelationPreexistente& getRelationPreexistente(){
        if (!instance_RelationPreexistente){
            instance_RelationPreexistente = new RelationPreexistente();
            return *instance_RelationPreexistente;
        }
    }
    static void libererRelationPreexistente(){
        if (instance_RelationPreexistente)
            delete instance_RelationPreexistente;
    }
};

class RelationManager{
    Relation** relations;
    unsigned int nbRelations;
    unsigned int maxRelations;

    static RelationManager* instance_RelationManager;
    RelationManager(const RelationManager&){}
    RelationManager(){
        relations = new relation[maxRelations+10];
        maxRelations += 10;
        RelationPreexistente* RP = getRelationPreexistente();
        relations[0] = RP;
        nbRelations++;
    }
    RelationManager& operator=(const RelationManager&){}
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
    class iterator<Relation,RelationManager>;
    iterator begin() {return iterator(relations);}
    iterator begin() {return iterator(relations+nbRelations);}
};

#endif // RELATION_H
