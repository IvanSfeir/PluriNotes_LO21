#ifndef CENTRENOTEARCH_H
#define CENTRENOTEARCH_H

#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "note.h"


class CentreNoteArch : public QWidget {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

    QLabel *titre_id;
    //QLabel *titre_id2;
    //QLabel *titre_id3;
    QListWidget *versions;
    QPushButton *afficher;
    //QPushButton *restaurer;
    QPushButton *fermer;

    QHBoxLayout *horiz;
    QVBoxLayout *verti;


public:
    // argument : la note concernee
    explicit CentreNoteArch(Note *it, QWidget* parent=0);
    QPushButton* getBoutonAfficherVersion() {return afficher;}
    QListWidget* getListVersions() {return versions;}

signals:

private slots:

public slots:

};

#endif // CENTRENOTEARCH_H
