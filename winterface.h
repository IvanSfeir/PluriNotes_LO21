#ifndef INTERFACE_H
#define INTERFACE_H

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>
#include <QAction>

#include "NotesManager.h"
#include "relation.h"
#include "wrelations.h"
#include "wrelationnonorientee.h"
#include "wrelationorientee.h"
#include "wnoteact.h"
#include "wnotearch.h"
#include "wversion.h"
#include "wgauche.h"

class Interface : public QMainWindow {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

    Gauche *gauche;

    QMenu *menuNote;
    QMenu *menuRelations;
    QMenu *menuCorbeille;
    QMenu *menuQuitter;

    QAction *afficherNote;
    QAction *afficherRelations;
    QAction *actionQuitter;

public:
    Interface();
    QAction *actionCorbeilleAuto;

signals:

private slots:

public slots:
    void avant_de_fermer();
    //void ouvrir_relations();
    //void ouvrir_note();
    //void fermer_note();

};

#endif // INTERFACE_H
