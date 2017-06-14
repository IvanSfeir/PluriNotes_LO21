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
#include "wrelationdetails.h"
#include "wnoteact.h"
#include "wnotearch.h"
#include "wversion.h"
#include "wgauche.h"

class Interface : public QMainWindow {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

    Gauche* window_gauche=0;
    CentreRelations* window_relations=0;
    CentreRelationDetails* window_relation_details=0;


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
    void fermer_droite();
    void fermer_gauche();
    void ouvrir_gauche();


signals:

private slots:

public slots:
    void avant_de_fermer();
    void ouvrir_relations();
    void ouvrir_relation_details(unsigned int position);
    void ouvrir_note_active_id(const QString& ident);
    void ouvrir_note_archivee_id(const QString& ident);
    //void fermer_centre();

};

#endif // INTERFACE_H
