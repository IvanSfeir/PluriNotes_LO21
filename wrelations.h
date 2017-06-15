/*!
 * \file wrelations.h
 * \class CentreRelations wversionarticle.h
 * \brief Définit la classe CentreVersionArticle
 * \details Hérite de CentreVersion
 *      \a texte : Texte de l'article ;
 *   \a QLabel *textel;
*    \a QHBoxLayout *ctexte;
*   \a Article *article;
 */
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
#include "windowcreerrelation.h"

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
    QPushButton *getBoutonCreate(){return creer_relation;}
    QListWidget* getListRelation() {return relations;}
    unsigned int getIndiceRelation() {return relations->currentRow();}

signals:

private slots:

public slots:
    void supprimerRelation();


};

#endif // CENTRERELATIONS_H
