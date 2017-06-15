#include "wrelations.h"

CentreRelations::CentreRelations(QMainWindow *parent):
    QWidget(parent) {
    setFixedSize(320,350);
    NotesManager *NM = NotesManager::getInstance();
    RelationManager* RM = RelationManager::getRelationManager();

    titre_relations = new QLabel(this);
    titre_relations->setText("Les relations disponibles :");

    relations = new QListWidget(this);

    for (RelationManager::iterator it = RM->begin(); it != RM->end(); it++) {
        relations->addItem((*it)->getTitre());
    }


    afficher_relation = new QPushButton("Afficher Couples");
    //QObject::connect(afficher_relation, SIGNAL(Clicked()),this, SLOT(afficherRelation()));

    fermer = new QPushButton("Fermer");
    connect(fermer, SIGNAL(Clicked()),this, SLOT(close()));

    creer_relation = new QPushButton("Creer relation");
    //QObject::connect(creer_relation_orientee, SIGNAL(Clicked()),this, SLOT(creerRelation()));

    supprimer_relation = new QPushButton("Supprimer relation");
    //QObject::connect(supprimer_relation, SIGNAL(Clicked()),this, SLOT(supprimerRelation()));

    horiz1 = new QHBoxLayout;
    horiz1->addWidget(afficher_relation);
    horiz1->addWidget(supprimer_relation);
    horiz1->addWidget(fermer);

    horiz2 = new QHBoxLayout;
    horiz2->addWidget(creer_relation);


    verti = new QVBoxLayout;
    verti->addWidget(titre_relations);
    verti->addWidget(relations);
    verti->addLayout(horiz1);
    verti->addLayout(horiz2);

    setLayout(verti);



}

void CentreRelations::supprimerRelation() {}

