/*!
 * \file wcreerimage.h
 * \class WindowdCreerImage wcreerimage.h
 * \brief Définit la classe WindowdCreerImage : Emplacement pour la création d'une note image
 * \details Hérite de QWidget
 *   \brief desc_box : Formulaire description de la image
 *   \brief image_URL : Formulaire lien fichier image de la image
 *   \brief image_title : Formulaire titre de la image
 *   \brief identifiant : Identifiant de la note à créer
 *   \brief titre_version : Titre de la version associée à la note à créer
 *
    *\brief button_create : Bouton créer note image
    *\brief button_close : Bouton fermer
 */

#ifndef WCREERMULTI_H
#define WCREERMULTI_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QLineEdit>



class WindowCreerImage : public QWidget {

    Q_OBJECT

    QHBoxLayout *id_title;
    QLabel *id_label;
    QLabel *id_text;

    QHBoxLayout *titre_title;
    QLabel *titre_label;
    QLabel *titre_text;

    QHBoxLayout *desc_title;
    QLabel *desc_label;
    QTextEdit *desc_box;

    QHBoxLayout *image_title;
    QLabel *image_label;
    QLineEdit *image_URL;

    QHBoxLayout *button_bar;
    QPushButton *button_create;
    QPushButton *button_close;

    QVBoxLayout *frame;

    QString identifiant;
    QString titre_version;

public:
    WindowCreerImage(QString& ident, QString& titre, QWidget *parent=0);
    QPushButton* getButtonCreate() {return button_create;}
    QTextEdit* getDescBox() {return desc_box;}
    QLineEdit* getImageBox() {return image_URL;}

signals:

private slots:

public slots:
    /*!
     * \fn void create()
     * \brief Récupère les données du formulaire et créer la note
     */
    void create();
};

#endif // WCREERMULTI_H
