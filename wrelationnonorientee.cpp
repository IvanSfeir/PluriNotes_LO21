#include "wrelationnonorientee.h"

CentreRelationNonOrientee::CentreRelationNonOrientee(QMainWindow *parent):
    QWidget(parent) {

    // exemple
    QString relatexemple="R2 non orientee";

    titre_relation = new QLabel(this);
    titre_relation->setText("La relation non orientee de label : "+relatexemple);
    titre_relation->setFixedHeight(10);

    couples = new QListWidget(this);
    couples->setFixedSize(320,100);
    couples->addItem("id1 - id4");
    couples->addItem("id1 - id7");
    couples->addItem("id7 - id3");

    ajouter_couple = new QPushButton("Ajouter couple",this);
    supprimer_couple = new QPushButton("Supprimer couple",this);

    horiz = new QHBoxLayout;
    horiz->addWidget(ajouter_couple);
    horiz->addWidget(supprimer_couple);

    verti = new QVBoxLayout;
    verti->addWidget(titre_relation);
    verti->addWidget(couples);
    verti->addLayout(horiz);

    setLayout(verti);

    setFixedSize(350,200);

}
