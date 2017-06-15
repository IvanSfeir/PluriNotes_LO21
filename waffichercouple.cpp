#include "waffichercouple.h"
#include "relation.h"
#include <QLabel>
#include <QListWidget>
#include <QLayout>
#include <QPushButton>

WindowAfficherCouple::WindowAfficherCouple(QString& relation_name, QWidget *parent):
    QWidget(parent) {

    setFixedSize(320,350);
    //NotesManager *NM = NotesManager::getInstance();
    RelationManager* RM = RelationManager::getRelationManager();
    Relation* r = RM->getRelationFromTitle(relation_name);

    titre_relation = new QHBoxLayout;
    titre_st = new QLabel("Les couples disponibles :");

    couples = new QListWidget(this);

    QString arrow;
    if (r->getOrientee()) arrow = "------>";
    else arrow = "------";

    for (Relation::iterator it = r->begin(); it != r->end(); it++) {
        couples->addItem((*it)->getLabel()+": "+(*it)->getNote1().getId() + arrow + (*it)->getNote2().getId());
    }


    fermer = new QPushButton("Fermer");
    QObject::connect(fermer, SIGNAL(clicked()),this, SLOT(close()));

    creer_couple = new QPushButton("Creer couple");
    //QObject::connect(creer_relation_orientee, SIGNAL(clicked()),this, SLOT(creerRelation()));

    supprimer_couple = new QPushButton("Supprimer couple");
    //QObject::connect(supprimer_relation, SIGNAL(clicked()),this, SLOT(supprimerRelation()));

    horiz1 = new QHBoxLayout;
    horiz1->addWidget(supprimer_couple);
    horiz1->addWidget(fermer);

    horiz2 = new QHBoxLayout;
    horiz2->addWidget(creer_couple);


    verti = new QVBoxLayout;
    verti->addLayout(titre_relation);
    verti->addWidget(couples);
    verti->addLayout(horiz1);
    verti->addLayout(horiz2);

    setLayout(verti);

}
