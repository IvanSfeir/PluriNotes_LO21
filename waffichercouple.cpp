#include "waffichercouple.h"
#include "relation.h"
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QPushButton>

waffichercouple::waffichercouple(Relation* r, QMainWindow *parent):
    QWidget(parent) {

    setFixedSize(320,350);
    //NotesManager *NM = NotesManager::getInstance();
    //RelationManager* RM = RelationManager::getRelationManager();

    titre_relation = new QHBoxLayout;
    titre_st = new QLabel("Les couples disponibles :");

    couples = new QListWidget(this);

    QString arrow;
    if (r->getOrientee()) arrow = "------>";
    else arrow = "------";

    for (Relation::iterator it = r->begin(); it != r->end(); it++) {
        couples->addItem((*it)->getNote1()->getId() + arrow + (*it)->getNote2()->getId());
    }


    afficher_relation = new QPushButton("Afficher Couples");
    //QObject::connect(afficher_relation, SIGNAL(Clicked()),this, SLOT(afficherRelation()));

    fermer = new QPushButton("Fermer");
    QObject::connect(fermer, SIGNAL(Clicked()),this, SLOT(close()));

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
