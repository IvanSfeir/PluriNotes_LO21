/*!
 * \file wrelations.h
 * \class CentreRelations wrelations.h
 * \brief Définit la classe CentreRelations : Gestion des relations
 * \details Hérite de QWidget
 *   \brief relations : Liste des relations
  *  \brief afficher_relation : Bouton afficher relation
   * \brief supprimer_relation : Bouton supprimer relation
    * \brief creer_relation :Bouton créer relation
    *\brief fermer : Bouton fermer

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
    /*!
     * \brief Supprime une relation.
     */
    void supprimerRelation();


};

#endif // CENTRERELATIONS_H
