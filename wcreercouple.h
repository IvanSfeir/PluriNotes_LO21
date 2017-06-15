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
