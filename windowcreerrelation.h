/*!
 * \file windowcreerrelation.h
 * \class WindowCreerRelation windowcreerrelation.h
 * \brief Définit la classe WindowCreerRelation : Emplacement pour créer une relation
 * \details Hérite de QWidget
 *   \brief title: Formulaire titre de la relation
 *   \brief desc : Formulaire description de la relation
 *   \brief orientee : Formulaire orientation de la relation
    *\brief valider : Bouton valider
    *\brief annuler : Bouton annuler
 */
#ifndef WINDOWCREERRELATION_H
#define WINDOWCREERRELATION_H

#include <QObject>
#include <QWidget>

#include<QComboBox>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include "relation.h"

class WindowCreerRelation :public QWidget
{
  Q_OBJECT

  
  QVBoxLayout *V_window; /*!< Emplacemet vertical de la fenetre*/

  // ID
  QHBoxLayout *H_title; /*!< emplacement horizontal de l'id*/
  QLabel *lbl_title; /*!< label pour le champ id*/
  QLineEdit *title; /*!< champ id */

  QHBoxLayout *H_desc;
  QLabel *lbl_desc;
  QLineEdit *desc;

  QHBoxLayout *H_orientee;
  QLabel *lbl_orientee;
  QComboBox *orientee; //combo list : "orientee" "non orientee"

  QHBoxLayout *H_buttons;
  QPushButton *valider;
  QPushButton *annuler;

public:
    WindowCreerRelation(QWidget *parent=0);

    QComboBox* getComboType() {return orientee;}
    QPushButton* getBoutonValider() {return valider;}

    QString getTitle() const { return title->text() ;}
    QString getDesc() const { return desc->text();}
    QString getOrientation() const { return orientee->currentText();}

    signals:

    private slots:

    public slots:
};

#endif // WINDOWCREERRELATION_H
