#include "winterface.h"
#include "notesmanager.h"
#include "relation.h"
#include "article.h"
#include "note.h"
#include <QDebug>

Interface::Interface() {

    //////////////////////////////////////////////
    //init for testing////////////////////////////
    //////////////////////////////////////////////
    NotesManager* NM = NotesManager::getInstance();
    Note* newNote = new Note("note1"); //id=1
    Article* a1 = new Article("testA1",QDateTime::currentDateTime(),"testestsetsetstest");
    Article* a2 = new Article("testA2",QDateTime::fromString("13.06.2017-10:30:14","dd.MM.yyyy-hh:mm:ss"),"testestsetsetstest2");
    Article* a3 = new Article("testA3",QDateTime::fromString("13.06.2017-10:32:14","dd.MM.yyyy-hh:mm:ss"),"testestsetsetstest3");
    newNote->ajouterVersion(a1);
    newNote->ajouterVersion(a2);
    newNote->ajouterVersion(a3);
    NM->ajouterNote(newNote);
    qDebug() << NM->getNote("note1")->getVersion(0)->getTitle() << "\n";
    ///////////
    Note* newNoteArch = new Note("noteArch"); //id=1
    a1 = new Article("testA1'",QDateTime::currentDateTime(),"testestsetsetstest");
    a2 = new Article("testA2'",QDateTime::fromString("13.06.2017-10:30:14","dd.MM.yyyy-hh:mm:ss"),"testestsetsetstest2");
    a3 = new Article("testA3'",QDateTime::fromString("13.06.2017-10:32:14","dd.MM.yyyy-hh:mm:ss"),"testestsetsetstest3");
    newNoteArch->ajouterVersion(a1);
    newNoteArch->ajouterVersion(a2);
    newNoteArch->ajouterVersion(a3);
    newNoteArch->setEtat(archive);
    NM->ajouterNote(newNoteArch);
    ///////////
    newNoteArch = new Note("noteArch2"); //id=1
    a1 = new Article("testA1''",QDateTime::currentDateTime(),"testestsetsetstest");
    a2 = new Article("testA2''",QDateTime::fromString("13.06.2017-10:30:14","dd.MM.yyyy-hh:mm:ss"),"testestsetsetstest2");
    a3 = new Article("testA3''",QDateTime::fromString("13.06.2017-10:32:14","dd.MM.yyyy-hh:mm:ss"),"testestsetsetstest3");
    newNoteArch->ajouterVersion(a1);
    newNoteArch->ajouterVersion(a2);
    newNoteArch->ajouterVersion(a3);
    newNoteArch->setEtat(archive);
    NM->ajouterNote(newNoteArch);
    ///////////////////////////////////////////////
    ///////////////////////////////////////////////
    ///////////////////////////////////////////////



    QMenu *menuNotes = menuBar()->addMenu("Notes");
    QAction *afficherNotes = new QAction("Afficher notes");
    menuNotes->addAction(afficherNotes);
    QObject::connect(afficherNotes, SIGNAL(triggered()), this, SLOT(ouvrir_gauche()));
    QAction *creerNote = new QAction("Creer note");
    menuNotes->addAction(creerNote);
    QObject::connect(creerNote, SIGNAL(triggered()), this, SLOT(ouvrir_creer_note()));

    QMenu *menuRelations = menuBar()->addMenu("Relations");
    QAction *afficherRelations = new QAction("Afficher Relations");
    menuRelations->addAction(afficherRelations);
    QObject::connect(afficherRelations, SIGNAL(triggered()), this, SLOT(ouvrir_relations()));

    QMenu *menuCorbeille = menuBar()->addMenu("Corbeille");
    QAction *actionCorbeilleAuto = new QAction("Corbeille automatiquement detruite");
    menuCorbeille->addAction(actionCorbeilleAuto);
    actionCorbeilleAuto->setCheckable(true);

    QMenu *menuQuitter = menuBar()->addMenu("Quitter");
    QAction *actionQuitter = new QAction("Quitter application");
    menuQuitter->addAction(actionQuitter);
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(avant_de_fermer()));


    //////////////////////////////////////////////////////////////////////////////////////

    //QString id = "idE";
    //QString titre = "titreE";
    //window_creer_article = new WindowCreerArticle(id,titre, this);
    //window_creer_article->move(0,20);
    //window_creer_article->show();
}


void Interface::avant_de_fermer() {
    NotesManager *NM = NotesManager::getInstance();
    //if (!(NM->corbeilleIsEmpty()) and (!actionCorbeilleAuto->isChecked())) {
    actionCorbeilleAuto->setChecked(true);
    bool booleen = actionCorbeilleAuto->isChecked();
    if (booleen == true) {
        QMessageBox::information(this,"checked","checked");
        // int reponse = QMessageBox::question(this,"Corbeille","Voulez-vous supprimer definitivement les notes de la corbeille ?");
        // save(NM, reponse);
    }
    NotesManager::libererInstance();
    RelationManager::libererRelationManager();
    this->close();
}

void Interface::ouvrir_relations() {
    fermer_droite();
    window_relations = new CentreRelations(this);
    window_relations->move(800,15);
    window_relations->show();
    QObject::connect(window_relations->getBoutonAfficher(), SIGNAL(clicked()), this, SLOT(ouvrir_relation_details(getIndiceRelation())));
}


/*
void fermer_centre() {
    if(centrenoteact) centrenoteact->close();
    if(centrenotearch) centrenotearch->close();
    if(centreversion) centreversion->close();
    if(centrerelations) centrerelations->close();
    if(centrerelationdetails) centrerelationdetails->close();
}
*/

void Interface::ouvrir_relation_details(unsigned int position) {
    RelationManager *RM = RelationManager::getRelationManager();
    RelationManager::iterator it = RM->begin();
    for(unsigned int i=0; i!=position; i++) {it++;}
    window_relation_details = new CentreRelationDetails((*it), this);
}

void Interface::fermer_droite() {
    if(window_relations) window_relations->close();
    if(window_relation_details) window_relation_details->close();
}

void Interface::fermer_gauche() {
    if(window_gauche) window_gauche->close();
}

void Interface::fermer_centre() {
    if(window_note_act) window_note_act->close();
    if(window_note_arch) window_note_arch->close();
    //if(window_version) window_version->close();
}

////////////////////////////PARTY SHOW NOTES/////////////////////////
/////////////////////////////////////////////////////////////////////
void Interface::ouvrir_gauche() {
    window_gauche = new Gauche(this);
    window_gauche->move(0,20);
    QObject::connect(window_gauche->getBoutonAfficherAct(),SIGNAL(clicked()),this,SLOT(ouvrir_note_active_id()));
    QObject::connect(window_gauche->getBoutonAfficherArch(),SIGNAL(clicked()),this,SLOT(ouvrir_note_archivee_id()));
    window_gauche->show();
}

void Interface::ouvrir_note_active_id() {
    if (QListWidgetItem* ident = window_gauche->getNotesActives()->currentItem()){
        NotesManager *NM = NotesManager::getInstance();
        fermer_centre();
        window_note_act = new CentreNoteAct (NM->getNote(ident->text()),this);
        window_note_act->move(400,15);
        window_note_act->show();
    }
}

void Interface::ouvrir_note_archivee_id() {
    QString ident = window_gauche->getNotesArchivees()->currentText();
    NotesManager *NM = NotesManager::getInstance();
    fermer_centre();
    window_note_arch = new CentreNoteArch(NM->getNote(ident),this);
    window_note_arch->move(400,15);
    window_note_arch->show();
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

////////////////////////////PARTY CREATE NOTE////////////////////////
/////////////////////////////////////////////////////////////////////
void Interface::ouvrir_creer_note() {
    fermer_centre();
    window_creer_note = new WindowCreerNote(this);
    connect(window_creer_note->getBoutonValider(), SIGNAL(clicked(bool)), this, SLOT(forward_to_create_type()));
    window_creer_note->move(400,15);
    window_creer_note->show();
}

void Interface::forward_to_create_type(){
    QString typeNote = window_creer_note->getTypeNote();
    QString id = window_creer_note->getId();
    QString titre = window_creer_note->getTitle();
    if(typeNote=="Article")
        fermer_gauche();
        window_creer_article = new WindowCreerArticle(id,titre, this);
        window_creer_article->move(800,15);
        window_creer_article->show();
}


