#include "wrelationdetails.h"

CentreRelationDetails::CentreRelationDetails(QMainWindow *parent):
    QWidget(parent) {

    // exemple
    //QString relatexemple="R1 orientee";

    //titre_relation = new QLabel(this);
    //titre_relation->setText("La relation orientee de label : "+relatexemple);
    //titre_relation->setFixedHeight(10);

    titrel = new QLabel("Titre");
    titre = new QLineEdit();
    titreh = new QHBoxLayout();
    titreh->addWidget(titrel);
    titreh->addWidget(titre);

    descl = new QLabel("Description");
    desc = new QLineEdit();
    desch = new QHBoxLayout();
    desch->addWidget(descl);
    desch->addWidget(desc);

    orienteel = new QLabel("Orientee");
    orientee = new QLineEdit();
    orienteeh = new QHBoxLayout();
    orienteeh->addWidget(orienteel);
    orienteeh->addWidget(orientee);

    couples = new QListWidget(this);
    couples->setFixedSize(320,100);
    couples->addItem("id1 -> id4");
    couples->addItem("id2 -> id7");
    couples->addItem("id7 -> id3");

    ajouter_couple = new QPushButton("Ajouter couple",this);
    supprimer_couple = new QPushButton("Supprimer couple",this);

    horiz = new QHBoxLayout;
    horiz->addWidget(sauver);
    horiz->addWidget(ajouter_couple);
    horiz->addWidget(supprimer_couple);

    verti = new QVBoxLayout;
    verti->addLayout(titreh);
    verti->addLayout(desch);
    verti->addLayout(orienteeh);
    verti->addWidget(couples);
    verti->addLayout(horiz);

    setLayout(verti);

    setFixedSize(350,200);

}
