#include "wgauche.h"
#include <QDebug>

Gauche::Gauche(QMainWindow* parent) :
    QWidget(parent) {

    NotesManager *NM = NotesManager::getInstance();

    /////////////////Note Active//////////////////////////
    setFixedSize(300, 350);

    titre_act = new QLabel(this);
    titre_act->setText("Les notes actives :");

    notes_actives = new QListWidget(this);

    ///print all the notes which are active
    for (NotesManager::iterator it = NM->begin(); it != NM->end(); it++) {
        if ((*it)->is_active())
            notes_actives->addItem((*it)->getId());
    }
    ///button to show note in detail
    bouton_afficher_act = new QPushButton("Afficher Note");

    ///////////////////////////////////////////////////////
    /////////////////Note Archived/////////////////////////
    titre_arch = new QLabel(this);
    titre_arch->setText("Les notes archivees :");
    notes_archivees = new QComboBox(this);
    ///print all the note which are archived
    for (NotesManager::iterator it = NM->begin(); it != NM->end(); it++) {
        if ((*it)->is_archived())
            notes_archivees->addItem((*it)->getId());
    }
    ///////////////////////////////////////////////////////
    bouton_afficher_arch = new QPushButton("Afficher Archived",this);


    couche = new QVBoxLayout;

    couche->addWidget(titre_act);
    couche->addWidget(notes_actives);
    couche->addWidget(bouton_afficher_act);
    couche->addWidget(titre_arch);
    couche->addWidget(notes_archivees);
    couche->addWidget(bouton_afficher_arch);


    this->setLayout(couche);



}
//deplaces dans interface
//***********************
/*
void Gauche::ouvrirNoteActiveId(const QString& ident) {
    NotesManager *NM = NotesManager::getInstance();
    //fermer_centre();
    CentreNoteAct centrenoteact(&(NM->getNote(ident)),this);
}

void Gauche::ouvrirNoteArchiveeId(const QString& ident) {
    NotesManager *NM = NotesManager::getInstance();
    //fermer_centre();
    CentreNoteArch centrenotearch(&(NM->getNote(ident)),this);
}
*/

