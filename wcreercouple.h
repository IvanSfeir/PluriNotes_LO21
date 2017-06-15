/*!
 * \file windowcreercouple.h
 * \class WindowCreerCouple windowcreercouple.h
 * \brief Définit la classe WindowCreerCouple : Emplacement pour créer une couple
 * \details Hérite de QWidget
 *   \brief note1 : Formulaire identifiant de la note 1 du couple
 *   \brief note2 : Formulaire identifiant de la note 2 du couple
 *   \brief label : Formulaire label du couple de la relation
    *\brief valider : Bouton valider
    *\brief annuler : Bouton annuler
 */
#ifndef WCREERCOUPLE_H
#define WCREERCOUPLE_H

#include <QObject>
#include <QWidget>

#include<QComboBox>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include "relation.h"

class WindowCreerCouple : public QWidget
{
  Q_OBJECT

  QVBoxLayout *V_window; /*!< Emplacemet vertical de la fenetre*/

  // ID
  QHBoxLayout *H_note1; /*!< emplacement horizontal de l'id*/
  QLabel *lbl_note1; /*!< label pour le champ id*/
  QLineEdit *note1; /*!< champ id */

  QHBoxLayout *H_note2; /*!< emplacement horizontal de l'id*/
  QLabel *lbl_note2; /*!< label pour le champ id*/
  QLineEdit *note2; /*!< champ id */

  QHBoxLayout *H_label; /*!< emplacement horizontal de l'id*/
  QLabel *lbl_label; /*!< label pour le champ id*/
  QLineEdit *label; /*!< champ id */

  QHBoxLayout *H_buttons;
  QPushButton *valider;
  QPushButton *annuler;

  public:
    WindowCreerCouple(QWidget *parent=0);

    QPushButton* getBoutonValider() {return valider;}

    QString getNote1() const { return note1->text() ;}
    QString getNote2() const { return note2->text();}
    QString getLabel() const { return label->text();}

    signals:

    private slots:

    public slots:
  };

  #endif // WCREERCOUPLE_H
