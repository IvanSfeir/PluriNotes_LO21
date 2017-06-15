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
    RelationManager* RM = RelationManager::getRelationManager();
    qDebug() << RM->getNbRelations();


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

    NM->saveNotesManager("test_type_save.xml");
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
}

void Interface::closeEvent(QCloseEvent *bar){
    NotesManager *NM = NotesManager::getInstance();
    NM->saveNotesManager("save_test.xml");
    NM->libererInstance();
    bar->accept();
}

void Interface::avant_de_fermer() {
    //NotesManager *NM = NotesManager::getInstance();
    //if (!(NM->corbeilleIsEmpty()) and (!actionCorbeilleAuto->isChecked())) {
    actionCorbeilleAuto->setChecked(true);
    bool booleen = actionCorbeilleAuto->isChecked();
    if (booleen == true) {
        //QMessageBox::information(this,"checked","checked");
        QMessageBox msgBox;
        msgBox.setText("Corbeille");
        msgBox.setInformativeText("Voulez-vous supprimer definitivement les notes de la corbeille ?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
//        int ret = msgBox.exec();
//        // int reponse = QMessageBox::question(this,"Corbeille","Voulez-vous supprimer definitivement les notes de la corbeille ?");
//        // save(NM, reponse);
//        switch (ret) {
//////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! EN CHANTIER ...  !!!!!!!!!!!!!!!!!////////////////////////////
//          case QMessageBox::Save:
//              // Save was clicked
//            close();
//              break;
//          case QMessageBox::Discard:
//              // Don't Save was clicked
//            close();
//              break;
////          case QMessageBox::Cancel:
////              // Cancel was clicked
////              break;
////          default:
////              // should never be reached
//              break;
//        }
    }
    NotesManager::libererInstance();
    RelationManager::libererRelationManager();
    this->close();
}

///////////////////RELATION////////////////////////////
void Interface::ouvrir_relations() {
    fermer_droite();
    window_relations = new CentreRelations(this);
    window_relations->move(800,15);
    window_relations->show();
    QObject::connect(window_relations->getBoutonAfficher(), SIGNAL(clicked()), this, SLOT(ouvrir_couples()));
    //QObject::connect(window_relations->getBoutonAfficher(), SIGNAL(clicked()), this, SLOT(ouvrir_relation_details()));
    QObject::connect(window_relations->getBoutonCreate(), SIGNAL(clicked()), this, SLOT(ouvrir_creer_relation()));
    //QObject::connect(window_creer_relation->get, SIGNAL(clicked()),this, SLOT(ouvrir_creer_relation()));

}

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
    if(window_creer_note) window_creer_note->close();
    if(window_creer_article) window_creer_article->close();
    if(window_creer_image) window_creer_image->close();
    if(window_creer_audio) window_creer_audio->close();
    if(window_creer_video) window_creer_video->close();
    if(window_creer_tache) window_creer_tache->close();
}

void Interface::fermer_centre() {
    if(window_note_act) window_note_act->close();
    if(window_note_arch) window_note_arch->close();
    if(window_afficher_article) window_afficher_article->close();
    if(window_afficher_image) window_afficher_image->close();
}

void Interface::ouvrir_creer_relation()
{
    fermer_droite();
    window_creer_relation = new WindowCreerRelation(this);
    connect(window_creer_relation->getBoutonValider(), SIGNAL(clicked(bool)), this, SLOT(creer_relation()));
    window_creer_relation->move(800,15);
    window_creer_relation->show();
}

void Interface::creer_relation()
{
    fermer_droite();
    QString titre = window_creer_relation->getTitle();
    QString descr = window_creer_relation->getDesc();
    QString orient = window_creer_relation->getOrientation();
    if(orient=="Non orientee"){
        RelationPreexistente *rp= RelationPreexistente::getRelationPreexistente();        
    }
    if(orient=="Orientee"){
       RelationNormale *rn = new RelationNormale(titre,descr,1);
    }
}
///////////////////////////PARTIE SHOW NOTES/////////////////////////
/////////////////////////////////////////////////////////////////////
void Interface::ouvrir_gauche() {
    fermer_gauche();
    window_gauche = new Gauche(this);
    window_gauche->move(0,20);
    QObject::connect(window_gauche->getBoutonAfficherAct(),SIGNAL(clicked()),this,SLOT(ouvrir_note_active_id()));
    QObject::connect(window_gauche->getBoutonAfficherArch(),SIGNAL(clicked()),this,SLOT(ouvrir_note_archivee_id()));
    QObject::connect(window_gauche->getBoutonRestaurer(), SIGNAL(clicked()),this,SLOT(restaurer_note()));
    window_gauche->show();
}

void Interface::ouvrir_note_active_id() {
    if (QListWidgetItem* ident = window_gauche->getNotesActives()->currentItem()){
        NotesManager *NM = NotesManager::getInstance();
        fermer_centre();
        currentNote = NM->getNote(ident->text());
        window_note_act = new CentreNoteAct (currentNote,this);
        QObject::connect(window_note_act->getBoutonRestaurerVersion(),SIGNAL(clicked()),this,SLOT(restaurer_version()));
        QObject::connect(this->window_note_act->getBoutonAfficherVersion(), SIGNAL(clicked()), this, SLOT(ouvrir_version_act()));
        window_note_act->move(400,15);
        window_note_act->show();
    }
}

void Interface::ouvrir_note_archivee_id() {
    QString ident = window_gauche->getNotesArchivees()->currentText();
    NotesManager *NM = NotesManager::getInstance();
    fermer_centre();
    window_note_arch = new CentreNoteArch(NM->getNote(ident),this);
    QObject::connect(this->window_note_arch->getBoutonAfficherVersion(), SIGNAL(clicked()), this, SLOT(ouvrir_version_arch()));
    window_note_arch->move(400,15);
    window_note_arch->show();
}



/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

///////////////////////////PARTIE CREATE NOTE////////////////////////
/////////////////////////////////////////////////////////////////////
void Interface::ouvrir_creer_note() {
    fermer_gauche();
    window_creer_note = new WindowCreerNote(this);
    connect(window_creer_note->getBoutonValider(), SIGNAL(clicked(bool)), this, SLOT(forward_to_create_type()));
    window_creer_note->move(0,20);
    window_creer_note->show();
}

void Interface::forward_to_create_type(){
    QString typeNote = window_creer_note->getTypeNote();
    QString id = window_creer_note->getId();
    QString titre = window_creer_note->getTitle();
    if(typeNote=="Article"){
        fermer_gauche();
        window_creer_article = new WindowCreerArticle(id,titre, this);
        window_creer_article->move(0,20);
        window_creer_article->show();
    }
    if(typeNote=="Image"){
        fermer_gauche();
        window_creer_image = new WindowCreerImage(id,titre, this);
        window_creer_image->move(0,20);
        window_creer_image->show();
    }
    if(typeNote=="Video"){
        fermer_gauche();
        window_creer_video = new WindowCreerVideo(id,titre, this);
        window_creer_video->move(0,20);
        window_creer_video->show();
    }
    if(typeNote=="Audio"){
        fermer_gauche();
        window_creer_audio = new WindowCreerAudio(id,titre, this);
        window_creer_audio->move(0,20);
        window_creer_audio->show();
    }
    if(typeNote=="Tache"){
        fermer_gauche();
        window_creer_tache = new WindowCreerTache(id,titre, this);
        window_creer_tache->move(0,20);
        window_creer_tache->show();
    }
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

///////////////////////////PARTIE MANIPULATE NOTE////////////////////
/////////////////////////////////////////////////////////////////////
void Interface::restaurer_note(){
    QString ident = window_gauche->getNotesArchivees()->currentText();
    NotesManager *NM = NotesManager::getInstance();
    NM->restaurerNote(ident);
    ouvrir_gauche();
}

void Interface::restaurer_version(){
    int index = window_note_act->getListVersions()->currentRow();
    if (index != -1 && currentNote->getNbVersion() - 1 == index){
    qDebug() << currentNote->getVersion(index)->getTitle() << "\n";
    qDebug() << currentNote->getNbVersion() <<"\n";
    //currentNote->ajouterVersion(currentNote->getVersion(index));
    //currentNote->restaurerVersion(index);
    ouvrir_note_active_id();
    }
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

///////////////////////////PARTIE AFFICHE VERSION////////////////////
/////////////////////////////////////////////////////////////////////


void Interface::ouvrir_version_act() {
    unsigned int pos = window_note_act->getListVersions()->currentRow();
    Version* vers = currentNote->getVersion(pos);
    fermer_centre();
    if(typeid(*vers)==typeid(Article)) {
        window_afficher_article = new WindowAfficherArticle(dynamic_cast<Article*>(vers), this);
        window_afficher_article->move(400,20);
        window_afficher_article->show();
    }
    if(typeid(*vers)==typeid(image)) {
        window_afficher_image = new WindowAfficherImage(dynamic_cast<image*>(vers), this);
        window_afficher_image->move(400,20);
        window_afficher_image->show();
    }
//    if(typeid(*vers)==typeid(Article)) {
//        window_afficher_article = new WindowAfficherArticle(vers, this);
//        window_afficher_article->move(400,20);
//        window_afficher_article->show();
    //    }
//    if(typeid(*vers)==typeid(Article)) {
//        window_afficher_article = new WindowAfficherArticle(vers, this);
//        window_afficher_article->move(400,20);
//        window_afficher_article->show();
//    }
}

void Interface::ouvrir_version_arch() {
    unsigned int pos = window_note_arch->getListVersions()->currentRow();
    Version* vers = currentNote->getVersion(pos);
    fermer_centre();
    if(typeid(*vers)==typeid(Article)) {
        window_afficher_article = new WindowAfficherArticle(dynamic_cast<Article*>(vers), this);
        window_afficher_article->move(400,20);
        window_afficher_article->show();
        window_afficher_article->getText()->setReadOnly(true);
        window_afficher_article->getTitle()->setReadOnly(true);
    }
    if(typeid(*vers)==typeid(image)) {
        window_afficher_image = new WindowAfficherImage(dynamic_cast<image*>(vers), this);
        window_afficher_image->move(400,20);
        window_afficher_image->show();
        window_afficher_image->getDesc()->setReadOnly(true);
        window_afficher_image->getTitle()->setReadOnly(true);
        window_afficher_image->getChemin()->setReadOnly(true);
    }
//    if(typeid(*vers)==typeid(Article)) {
//        window_afficher_article = new WindowAfficherArticle(vers, this);
//        window_afficher_article->move(400,20);
//        window_afficher_article->show();
    //    }
//    if(typeid(*vers)==typeid(Article)) {
//        window_afficher_article = new WindowAfficherArticle(vers, this);
//        window_afficher_article->move(400,20);
//        window_afficher_article->show();
//    }
}

///////////////////////////////////////////////
//////////////PARTIE COUPLES///////////////////

void Interface::ouvrir_couples(){
    QString rela = window_relations->getListRelation()->currentItem()->text();
    fermer_droite();
    window_afficher_couples = new WindowAfficherCouple(rela, this);
    window_afficher_couples->move(800,15);
    window_afficher_couples->show();
}
