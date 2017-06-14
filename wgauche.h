#ifndef GAUCHE_H
#define GAUCHE_H

#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QObject>
#include <QMainWindow>
#include "notesmanager.h"
#include "note.h"
#include "wnoteact.h"
#include "wnotearch.h"

#include <QListWidget>
#include <QComboBox>


class Gauche : public QWidget {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots



    QLabel *titre_act;
    QVBoxLayout *couche;
    QListWidget *notes_actives;
    QPushButton *bouton_afficher_act;
    QLabel *titre_arch;
    QComboBox *notes_archivees;
    QPushButton *bouton_afficher_arch;

    /*
    QScrollArea *scrolleur;
    QWidget *contenuScrolleur;
    QWidget *section;

    QVBoxLayout *section_actives;
    QVBoxLayout *notes_actives;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;
    */



public:
    explicit Gauche(QMainWindow* parent=0);
    QListWidget* getNotesActives() {return notes_actives;}
    QPushButton* getBoutonAfficherAct() {return bouton_afficher_act;}
    QComboBox* getNotesArchivees() {return notes_archivees;}
    QPushButton* getBoutonAfficherArch() {return bouton_afficher_arch;}


    void ouvrir_note();

signals:

private slots:
    //transportes dans interface :
    //****************************
    //void ouvrirNoteActiveId(const QString& ident);
    //void ouvrirNoteArchiveeId(const QString& ident);

public slots:

};

#endif // GAUCHE_H
