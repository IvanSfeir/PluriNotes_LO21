#include "winterface.h"

Interface::Interface() {

    QMenu *menuNote = menuBar()->addMenu("Note");
    QAction *afficherNote = new QAction("Afficher note");
    menuNote->addAction(afficherNote);

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

    window_gauche = new Gauche(this);
    window_gauche->move(800,15);
    window_gauche->show();

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
    QObject::connect(window_relations, SIGNAL((window_relations->getBoutonAfficher())->clicked()), this, SLOT(ouvrir_relation_details(getIndiceRelation())));
}
/*
void ouvrir_note() {
}

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

