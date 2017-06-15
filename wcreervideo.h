/*!
 * \file wcreervideo.h
 * \class WindowdCreerVideo wcreervideo.h
 * \brief Définit la classe WindowdCreerVideo : Emplacement pour la création d'une note vidéo
 * \details Hérite de QWidget
 *   \brief desc_box : Formulaire description de la vidéo
 *   \brief image_URL : Formulaire lien fichier image de la vidéo
 *   \brief video_title : Formulaire titre de la vidéo
 *   \brief identifiant : Identifiant de la note à créer
 *   \brief titre_version : Titre de la version associée à la note à créer
 *
    *\brief button_create : Bouton créer note vidéo
    *\brief button_close : Bouton fermer
 */

#ifndef WCREERVIDEO_H
#define WCREERVIDEO_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QLineEdit>



class WindowCreerVideo : public QWidget {

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

    QHBoxLayout *video_title;
    QLabel *video_label;
    QLineEdit *video_URL;

    QHBoxLayout *button_bar;
    QPushButton *button_create;
    QPushButton *button_close;

    QVBoxLayout *frame;

    QString identifiant;
    QString titre_version;

public:
    WindowCreerVideo(QString& ident, QString& titre, QWidget *parent=0);
    QPushButton* getButtonCreate() {return button_create;}
    QTextEdit* getDescBox() {return desc_box;}
    QLineEdit* getImageBox() {return image_URL;}
    QLineEdit* getVideoBox() {return video_URL;}

signals:

private slots:

public slots:
    void create();
};

#endif // WCREERVIDEO_H
