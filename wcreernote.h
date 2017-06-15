/*!
 * \file wcreernote.h
 * \class WindowdCreerNote wcreernote.h
 * \brief Définit la classe WindowdCreerNote: Emplacement pour la création d'une note
 * \details Hérite de QWidget
 *   \brief id: Formulaire identifiant de la note
 *   \brief title : Formulaire titre de la version associée à la note
 *   \brief type_note : Formulaire type de la note (Article, Tache, image, video, audio)
    *\brief valider : Bouton valider création de la note
    *\brief annuler: Bouton annuler
 */

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

signals:

private slots:

public slots:

};

#endif // WCREERNOTE_H
