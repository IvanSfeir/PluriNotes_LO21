#include "wnotearch.h"

CentreNoteArch::CentreNoteArch(Note *note, QWidget *parent):
    QWidget(parent) {

    setFixedSize(300,350);
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

    for (Note::iterator it = note->begin(); it != note->end(); it++) {
            versions->addItem((*it)->getTitle());
    }

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


}
