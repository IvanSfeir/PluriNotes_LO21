#include "wnoteact.h"
#include "article.h"

CentreNoteAct::CentreNoteAct(Note *la_note, QWidget *parent):
    note(la_note), QWidget(parent) {

    setFixedSize(300,350);

    titre_id = new QLabel(this);
    titre_id->setText("La note active d'identifiant "+note->getId());

    versions = new QListWidget(this);

    for (Note::iterator it = note->begin(); it != note->end(); it++) {
            versions->addItem((*it)->getTitle());
    }

    afficher = new QPushButton("Afficher",this);
    arborescence = new QPushButton("Arborescence",this);
    restaurer = new QPushButton("Restaurer",this);
    fermer = new QPushButton("Fermer",this);
    connect(fermer, SIGNAL(clicked()), this, SLOT(close()));

    horiz = new QHBoxLayout;
    horiz->addWidget(afficher);
    horiz->addWidget(restaurer);
    horiz->addWidget(arborescence);
    horiz->addWidget(fermer);

    verti = new QVBoxLayout;
    verti->addWidget(titre_id);
    verti->addWidget(versions);
    verti->addLayout(horiz);

    setLayout(verti);

}

/*
void CentreNoteAct::saveVersion() {
    QString title =
    Article* newArticle = new Article(title, QDateTime::currentDateTime(), text);
    note->ajouterVersion(newArticle);
}
*/
