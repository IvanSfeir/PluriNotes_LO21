#ifndef CENTRERELATIONS_H
#define CENTRERELATIONS_H

#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "relation.h"
#include "notesmanager.h"

class CentreRelations : public QWidget {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

    QLabel *titre_relations;
    QListWidget *relations;
    QPushButton *afficher_relation;
    QPushButton *supprimer_relation;
    QPushButton *creer_relation;
    QPushButton *fermer;

    QHBoxLayout *horiz1;
    QHBoxLayout *horiz2;
    QVBoxLayout *verti;

public:
    explicit CentreRelations(QMainWindow* parent=0);
    QPushButton* getBoutonAfficher() {return afficher_relation;}
    unsigned int getIndiceRelation() {return relations->currentRow();}

signals:

private slots:

public slots:
    void supprimerRelation();


};

#endif // CENTRERELATIONS_H
