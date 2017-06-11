#include "centrenoteact.h"

CentreNoteAct::CentreNoteAct(QMainWindow *parent):
    QWidget(parent) {

    // exemple
    //int idexemple=1;

    titre_id = new QLabel(this);
    titre_id->setText("La note d'identifiant !");
    //titre_id2 = new QLabel(this);
    //titre_id2->setText("La note d'identifiant "+idexemple);
    //titre_id3 = new QLabel(this);
    //titre_id3->setText("La note d'identifiant "+idexemple);

    versions = new QListWidget(this);
    //versions->setFixedSize(350,100);

    versions->addItem("version 1");
    versions->addItem("version 2");

    afficher = new QPushButton("Afficher",this);
    arborescence = new QPushButton("Arborescence",this);
    fermer = new QPushButton("Fermer",this);

    horiz = new QHBoxLayout(this);
    horiz->addWidget(afficher);
    horiz->addWidget(arborescence);
    horiz->addWidget(fermer);

    verti = new QVBoxLayout(this);
    verti->addWidget(titre_id);
    //verti->addWidget(titre_id2);
    //verti->addWidget(titre_id3);
    verti->addWidget(versions);
    verti->addLayout(horiz);

    setLayout(verti);

    setFixedSize(350,150);

}
