#include "interface.h"

Interface::Interface() {
    QMenu *menuNotes = menuBar()->addMenu("Notes");
    QMenu *menuRelations = menuBar()->addMenu("Relations");    
    QMenu *menuCorbeille = menuBar()->addMenu("Corbeille");

    QAction *actionCorbeilleAuto = new QAction("Corbeille automatiquement detruite");
    menuCorbeille->addAction(actionCorbeilleAuto);
    actionCorbeilleAuto->setCheckable(true);

    QMenu *menuQuitter = menuBar()->addMenu("Quitter");

    QAction *actionQuitter = new QAction("Quitter application");
    menuQuitter->addAction(actionQuitter);

    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(close()));

}
