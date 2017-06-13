#include "wrelationorientee.h"

CentreRelationOrientee::CentreRelationOrientee(QMainWindow *parent):
    QWidget(parent) {

    // exemple
    QString relatexemple="R1 orientee";

    titre_relation = new QLabel(this);
    titre_relation->setText("La relation orientee de label : "+relatexemple);
    titre_relation->setFixedHeight(10);

    couples = new QListWidget(this);
    couples->setFixedSize(320,100);
    couples->addItem("id1 -> id4");
    couples->addItem("id2 -> id7");
    couples->addItem("id7 -> id3");

    ajouter_couple = new QPushButton("Ajouter couple",this);
    supprimer_couple = new QPushButton("Supprimer couple",this);
    fermer = new QPushButton("Fermer",this);

    horiz = new QHBoxLayout;
    horiz->addWidget(ajouter_couple);
    horiz->addWidget(supprimer_couple);
    horiz->addWidget(fermer);

    verti = new QVBoxLayout;
    verti->addWidget(titre_relation);
    verti->addWidget(couples);
    verti->addLayout(horiz);

    setLayout(verti);

    setFixedSize(350,200);

}
