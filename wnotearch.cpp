#include "wnotearch.h"

CentreNoteArch::CentreNoteArch(Note *note, QWidget *parent):
    QWidget(parent) {

    setFixedSize(300,350);

    titre_id = new QLabel(this);
    titre_id->setText("La note archivee d'identifiant: "+note->getId());

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
    verti->addWidget(versions);
    verti->addLayout(horiz);

    setLayout(verti);


}
