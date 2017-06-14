#ifndef WCREERNOTE_H
#define WCREERNOTE_H

#include<QWidget>
#include<QComboBox>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include <QFormLayout>
#include "wcreerarticle.h"
#include <QLineEdit>

class WindowCreerNote : public QWidget {

    Q_OBJECT

    //** MTL
    QVBoxLayout *V_window; /*!< Emplacemet vertical de la fenetre*/

    // ID
    QHBoxLayout *H_id; /*!< emplacement horizontal de l'id*/
    QLabel *lbl_id; /*!< label pour le champ id*/
    QLineEdit *id; /*!< champ id */

    QHBoxLayout *H_title;
    QLabel *lbl_title;
    QLineEdit *title;

    QHBoxLayout *H_type_note;
    QLabel *lbl_type_note;
    QComboBox *type_note; //combo list

    QHBoxLayout *H_buttons;
    QPushButton *valider;
    QPushButton *annuler;



public:
    WindowCreerNote(QWidget *parent=0);

    QComboBox* getComboType() {return type_note;}
    QPushButton* getBoutonValider() {return valider;}

    QString getId() const { return id->text() ;}
    QString getTitle() const { return title->text();}
    QString getTypeNote() const { return type_note->currentText();}


    void forward_to_create_type(QWidget* parent);

}
#endif // WCREERNOTE_H
