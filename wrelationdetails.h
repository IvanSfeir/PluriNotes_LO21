/*!
 * \file wrelationsdetails.h
 * \class CentreRelationsDetails wrelationsdetails.h
 * \brief Définit la classe CentreRelationDetails : Gestion d'une relation en particulière
 * \details Hérite de QWidget
 *     \brief  titre : Champ titre relation
 *   \brief desc : Champ description relation
 *   \brief orientee : Champ orientation relation
  *  \brief couples : Liste de couples d'une relation
   * \brief supprimer_relation : Bouton supprimer relation
    *\brief sauver: Bouton sauver
    *\brief ajouter_couple : Bouton pour ajouter couple
    *\brief supprimer_couple : Bouton pour supprimer couple
 */

#ifndef CENTRERELATIONORIENTEE_H
#define CENTRERELATIONORIENTEE_H

#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

#include "relation.h"

class CentreRelationDetails : public QWidget {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

    QLabel *titrel;
    QLineEdit *titre;
    QHBoxLayout *titreh;

    QLabel *descl;
    QLineEdit *desc;
    QHBoxLayout *desch;

    QLabel *orienteel;
    QLineEdit *orientee;
    QHBoxLayout *orienteeh;

    QListWidget *couples;
    QPushButton *sauver;
    QPushButton *ajouter_couple;
    QPushButton *supprimer_couple;

    QHBoxLayout *horiz;
    QVBoxLayout *verti;

public:
    // argument : la relation concernee
    explicit CentreRelationDetails(Relation* relat, QMainWindow* parent=0);

signals:

private slots:

public slots:

};

#endif // CENTRERELATIONORIENTEE_H
