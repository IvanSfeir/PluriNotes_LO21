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

class Interface : public QMainWindow {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

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

    NotesManager *NM;
    RelationManager *RM;

signals:

private slots:

public slots:
    void avant_de_fermer();

};

#endif // INTERFACE_H
