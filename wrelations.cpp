#include "wrelations.h"

CentreRelations::CentreRelations(QMainWindow *parent):
    QWidget(parent) {

    NotesManager *NM = NotesManager::getInstance();
    RelationManager* RM = RelationManager::getRelationManager();

    titre_relations = new QLabel(this);
    titre_relations->setText("Les relations disponibles :");

    relations = new QListWidget(this);
    relations->setFixedSize(320,100);
/*
    relations->addItem("REFERENCE");
    relations->addItem("relation 2");
    relations->addItem("relation 3");
    relations->addItem("relation 4");
    relations->addItem("relation 5");
    relations->addItem("relation 6");
*/
    //print out all relation we have in the RelationManager
    for (RelationManager::iterator it = RM->begin(); it != RM->end(); it++) {
        relations->addItem((*it)->getTitre());
    }


    afficher_relation = new QPushButton("Afficher details",this);
    QObject::connect(afficher_relation, SIGNAL(Clicked()),this, SLOT(afficherRelation()));

    fermer = new QPushButton("Fermer",this);
    QObject::connect(fermer, SIGNAL(Clicked()),this, SLOT(close()));

    creer_relation_orientee = new QPushButton("Creer relation orientee",this);
    QObject::connect(creer_relation_orientee, SIGNAL(Clicked()),this, SLOT(creerRelationOrientee()));

    creer_relation_non_orientee = new QPushButton("Creer relation non orientee",this);
    QObject::connect(creer_relation_non_orientee, SIGNAL(Clicked()),this, SLOT(creerRelationNonOrientee()));

    supprimer_relation = new QPushButton("Supprimer relation",this);
    QObject::connect(supprimer_relation, SIGNAL(Clicked()),this, SLOT(supprimerRelation()));

    horiz1 = new QHBoxLayout;
    horiz1->addWidget(afficher_relation);
    horiz1->addWidget(supprimer_relation);
    horiz1->addWidget(fermer);

    horiz2 = new QHBoxLayout;
    horiz2->addWidget(creer_relation_orientee);
    horiz2->addWidget(creer_relation_non_orientee);


    verti = new QVBoxLayout;
    verti->addWidget(titre_relations);
    verti->addWidget(relations);
    verti->addLayout(horiz1);
    verti->addLayout(horiz2);

    setLayout(verti);

    setFixedSize(350,200);


}

void CentreRelations::supprimerRelation() {}

