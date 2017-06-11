#ifndef GAUCHEACTIVES_H
#define GAUCHEACTIVES_H

#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QObject>
#include <QMainWindow>
#include "interface.h"

class GaucheActives : public QWidget {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

    QLabel *titre_section;
    QScrollArea *scrolleur;
    QWidget *contenuScrolleur;
    QWidget *section;

    QVBoxLayout *section_actives;
    QVBoxLayout *notes_actives;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;


public:
    // le dernier parametre du constructeur est le tableau de tab_notes de NotesManager
    explicit GaucheActives(QString* titre, QMainWindow* parent=0);

signals:

private slots:

public slots:

};

#endif // GAUCHEACTIVES_H
