#include "centrenotearch.h"

CentreNoteArch::CentreNoteArch(QMainWindow *parent):
    QWidget(parent) {

    // exemple
    QString idexemple="2";

    titre_id = new QLabel(this);
    titre_id->setText("La note archivee d'identifiant "+idexemple);
    //titre_id2 = new QLabel(this);
    //titre_id2->setText("La note d'identifiant "+idexemple);
    //titre_id3 = new QLabel(this);
    //titre_id3->setText("La note d'identifiant "+idexemple);
    titre_id->setFixedHeight(10);

    versions = new QListWidget(this);
    versions->setFixedSize(320,100);
    versions->addItem("version 1");
    versions->addItem("version 2");
    versions->addItem("version 3");
    versions->addItem("version 4");
    versions->addItem("version 5");
    versions->addItem("version 6");

    afficher = new QPushButton("Afficher",this);
    restaurer = new QPushButton("Restaurer",this);
    fermer = new QPushButton("Fermer",this);

    horiz = new QHBoxLayout;
    horiz->addWidget(afficher);
    horiz->addWidget(restaurer);
    horiz->addWidget(fermer);

    verti = new QVBoxLayout;
    verti->addWidget(titre_id);
    //verti->addWidget(titre_id2);
    //verti->addWidget(titre_id3);
    verti->addWidget(versions);
    verti->addLayout(horiz);

    setLayout(verti);

    setFixedSize(350,200);

}
