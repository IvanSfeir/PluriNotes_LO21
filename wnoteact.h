#ifndef CENTRENOTEACT_H
#define CENTRENOTEACT_H

#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "note.h"


class CentreNoteAct : public QWidget {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

    QLabel *titre_id;
    //QLabel *titre_id2;
    //QLabel *titre_id3;
    QListWidget *versions;
    QPushButton *afficher;
    //QPushButton *arborescence;
    QPushButton *restaurer;
    QPushButton *fermer;

    QHBoxLayout *horiz;
    QVBoxLayout *verti;


public:
    // argument : la note concernee
    explicit CentreNoteAct(Note *it, QWidget* parent=0);
    QPushButton* getBoutonAfficherVersion() {return afficher;}

signals:

private slots:

public slots:

};

#endif // CENTRENOTEACT_H
