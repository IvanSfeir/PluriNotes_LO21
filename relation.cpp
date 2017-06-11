#include "relation.h"
#include <Qstring>

#include <QFile>
#include <QXmlStreamWriter>

void Relation::ajouterCouple(Couple* newCouple){
    if (nbCouples == maxCouples){
        Couple** newCouples = new Couple*[maxCouples+10];
        for (unsigned int i=0; i < nbCouples; i++) newCouples[i] = couples[i];
        Couple** oldCouples = couples;
        couples = newCouples;
        delete[] oldCouples;
        maxCouples += 10;
    }
    couples[++nbCouples] = newCouple;
}

void Relation::supprimerCouple(Couple* supCouple){
    int pos = -1;
    for (unsigned int i=0; i < nbCouples; i++){
        if (couples[i] == supCouple) pos = i;
    }

    if (pos != -1){
        for (unsigned int i=pos; i < nbCouples-1; i++){
            couples[i] = couples[i+1];
        }
        delete supCouple;
        nbCouples--;
    } throw exception("Le couple n'est pas existe!");
}

RelationPreexistente* RelationPreexistente::instance_RelationPreexistente = 0;

void RelationManager::ajouterRelation(Relation* newRelation){
    if (nbRelations == maxRelations){
        Relation** newRelations = new Relation*[maxRelations+10];
        for (unsigned int i=0; i < nbRelations; i++) newRelations[i] = relations[i];
        Relation** oldRelations = relations;
        relations = newRelations;
        delete[] oldRelations;
        maxRelations += 10;
    }
    relations[++nbRelations] = newRelation;
}

void RelationManager::supprimerRelation(Relation* supRelation){
    int pos = -1;
    for (unsigned int i=1; i < nbRelations; i++){
        if (relations[i] == supRelation) pos = i;
    }

    if (pos != -1){
        for (unsigned int i=pos; i < nbRelations-1; i++){
            relations[i] = relations[i+1];
        }
        delete supRelation;
        nbRelations--;
    } throw exception("La relation n'est pas existe ou n'est pas supprime!");
}

RelationManager* RelationManager::instance_RelationManager = 0;

////////////////////////////////////////////////////////////////////
/////////////////////method save, load//////////////////////////////
////////////////////////////////////////////////////////////////////
void RelationManager::saveRelationManager(const QString & filename){
    QFile newFile(filename);
    if (!newFile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw exception(QString("Error open file xml: cannot save file"));
    QXmlStreamWriter stream(&newFile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    for (unsigned int i=0; i < nbRelations; i++){
        stream.writeStartElement("relation");
        stream.writeStartElement("titre", relations[i]->getTitre());
        stream.writeStartElement("description", relations[i]->getDescription());
        if (relations[i]->getOrientee()) stream.writeStartElement("orientation","true");
        else stream.writeStartElement("orientation","false");
        for (Relation::iterator couple = relations[i]->begin(); couple != relations[i]->end(); couple++){
            stream.writeStartElement("couple");
            stream.writeStartElement("label", (*couple)->getLabel());
            stream.writeStartElement("note1", (*couple)->getNote1().getId());
            stream.writeEndElement();
        }
        stream.writeEndElement();
    }
    stream.writeEndElement();
    newFile.close();
}

void loadRelationManager(const QString & filename){
    QFile loadFile(filename);
}


