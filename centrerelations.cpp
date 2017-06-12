#include "centrerelations.h"

CentreRelations::CentreRelations(QMainWindow *parent):
    QWidget(parent) {

    titre_relations = new QLabel(this);
    titre_relations->setText("Les relations disponibles :");

    relations = new QListWidget(this);
    relations->setFixedSize(320,100);
    relations->addItem("REFERENCE");
    relations->addItem("relation 2");
    relations->addItem("relation 3");
    relations->addItem("relation 4");
    relations->addItem("relation 5");
    relations->addItem("relation 6");

    afficher_relation = new QPushButton("Afficher couples",this);
    fermer = new QPushButton("Fermer",this);
    creer_relation = new QPushButton("Creer relation",this);
    supprimer_relation = new QPushButton("Supprimer relation",this);

    horiz1 = new QHBoxLayout;
    horiz1->addWidget(afficher_relation);
    horiz1->addWidget(supprimer_relation);

    horiz2 = new QHBoxLayout;
    horiz2->addWidget(creer_relation);
    horiz2->addWidget(fermer);

    verti = new QVBoxLayout;
    verti->addWidget(titre_relations);
    //verti->addWidget(titre_id2);
    //verti->addWidget(titre_id3);
    verti->addWidget(relations);
    verti->addLayout(horiz1);
    verti->addLayout(horiz2);

    setLayout(verti);

    setFixedSize(350,200);

}
