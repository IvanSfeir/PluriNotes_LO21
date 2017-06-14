#include "wgauche.h"
#include <QDebug>

Gauche::Gauche(QMainWindow* parent) :
    QWidget(parent) {

    NotesManager *NM = NotesManager::getInstance();

    /*
    scrolleur = new QScrollArea(this);
    contenuScrolleur = new QWidget(this);
    section = new QWidget(this);
    section_actives = new QVBoxLayout();
    notes_actives = new QVBoxLayout();
    b1 = new QPushButton(parent);
    b1->setText("note 1");
    notes_actives->addWidget(b1);
    b2 = new QPushButton(parent);
    b2->setText("note 2");
    notes_actives->addWidget(b2);
    b3 = new QPushButton(parent);
    b3->setText("note 3");
    notes_actives->addWidget(b3);
    b4 = new QPushButton(parent);
    b4->setText("note 4");
    notes_actives->addWidget(b4);
    contenuScrolleur->setLayout(notes_actives);
    scrolleur->setWidget(contenuScrolleur);
    section_actives->addWidget(titre_section);
    section_actives->addWidget(scrolleur);
    QObject::connect(b1, SIGNAL(isClicked()), parent, SLOT(close()));
    */

    /////////////////Note Active//////////////////////////
    titre_act = new QLabel(this);
    titre_act->setText("Les notes actives :");

    notes_actives = new QListWidget(this);
    notes_actives->setFixedSize(330,200);

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
    //QObject::connect(bouton_afficher_arch,SIGNAL(clicked()),this,SLOT(ouvrirNoteArchiveeId(notes_archivees->currentText())));

    //for (NotesManager::iterator it = NM->end();it != NM->begin();--it) {
    //    if((*it)->is_archived()) {notes_archivees->addItem((*it)->getId());}
    //        else if((*it)->is_active()) {notes_actives->addItem((*it)->getId());}
    //}

    couche = new QVBoxLayout;

    couche->addWidget(titre_act);
    couche->addWidget(notes_actives);
    couche->addWidget(bouton_afficher_act);
    couche->addWidget(titre_arch);
    couche->addWidget(notes_archivees);
    couche->addWidget(bouton_afficher_arch);


    this->setLayout(couche);

    setFixedSize(350,350);

}
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

