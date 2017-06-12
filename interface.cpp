#include "interface.h"
#include <qDebug>

Interface::Interface() {
    QMenu *menuNote = menuBar()->addMenu("Note");

    QAction *afficherNote = new QAction("Afficher note");
    menuNote->addAction(afficherNote);

    QMenu *menuRelations = menuBar()->addMenu("Relations");

    QAction *afficherRelations = new QAction("Afficher Relations");
    menuRelations->addAction(afficherRelations);

    QMenu *menuCorbeille = menuBar()->addMenu("Corbeille");

    QAction *actionCorbeilleAuto = new QAction("Corbeille automatiquement detruite");
    menuCorbeille->addAction(actionCorbeilleAuto);
    actionCorbeilleAuto->setCheckable(true);

    QMenu *menuQuitter = menuBar()->addMenu("Quitter");

    QAction *actionQuitter = new QAction("Quitter application");
    menuQuitter->addAction(actionQuitter);



    RelationManager *RM = RelationManager::getRelationManager();



    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(avant_de_fermer()));

}

void Interface::avant_de_fermer() {

    //if ((NM->corbeilleIsEmpty()) and (!actionCorbeilleAuto->isChecked())) {
    actionCorbeilleAuto->setChecked(true);
    bool booleen = actionCorbeilleAuto->isChecked();
    if (booleen == true) {
        QMessageBox::information(this,"checked","checked");
        // int reponse = QMessageBox::question(this,"Corbeille","Voulez-vous supprimer definitivement les notes de la corbeille ?");
        // save(NM, reponse);
    }

    this->close();

}
