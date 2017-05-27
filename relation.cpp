#include "relation.h"

#include <Qstring>

void Relation::ajouterCouple(Couple* newCouple){
    if (nbCouples == maxCouples){
        Couple** newCouples = new Couple[maxCouples+10];
        for (int i=0; i < nbCouples; i++) newCouples[i] = couples[i];
        Couple** oldCouples = couples;
        couples = newCouples;
        delete[] oldCouples;
        maxCouples += 10;
    }
    couples[++nbCouples] = newCouple;
}

void Relation::supprimerCouple(Couple* supCouple){
    int pos = -1;
    for (int i=0; i < nbCouples; i++){
        if (couples[i] == supCouple) pos = i;
    }

    if (pos != -1){
        for (int i=pos; i < nbCouples-1; i++){
            couples[i] = couples[i+1];
        }
        delete supCouple;
        nbCouples--;
    } throw RelationException("Le couple n'est pas existe!");
}

RelationPreexistente* RelationPreexistente::instance_RelationPreexistente = 0;

void RelationManager::ajouterRelation(Couple* newRelation){
    if (nbRelations == maxRelations){
        Couple** newRelations = new Couple[maxRelations+10];
        for (int i=0; i < nbRelations; i++) newRelations[i] = relations[i];
        Couple** oldRelations = relations;
        relations = newRelations;
        delete[] oldRelations;
        maxRelations += 10;
    }
    relations[++nbRelations] = newRelation;
}

void RelationManager::supprimerRelation(Relation* supRelation){
    int pos = -1;
    for (int i=1; i < nbRelations; i++){
        if (relations[i] == supRelation) pos = i;
    }

    if (pos != -1){
        for (int i=pos; i < nbRelations-1; i++){
            relations[i] = relations[i+1];
        }
        delete supRelation;
        nbRelations--;
    } throw RelationException("La relation n'est pas existe ou n'est pas supprime!");
}

RelationManager* RelationManager::instance_RelationManager = 0;

