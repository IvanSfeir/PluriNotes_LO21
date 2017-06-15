/*!
 * \file hafficheraudio.h
 * \class WindowAfficherAudio hafficheraudio.h
 * \brief Définit la classe WindowAfficherAudio : Emplacement pour afficher un audio
 * \details Hérite de QWidget
 *      \brief audio : Note audio
 *   \brief titre_text: Formulaire titre de la audio
 *   \brief desc_text: Formulaire description de la audio
 *   \brief image_text: Formulaire image de la audio
 *   \brief audio_text: Formulaire audio de la audio
    *\brief valider : Bouton valider
    *\brief annuler : Bouton annuler
 */
#ifndef HAFFICHERAUDIO_H
#define HAFFICHERAUDIO_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QLineEdit>
#include"note.h"
#include"multimedia.h"



class WindowAfficherAudio : public QWidget {

    Q_OBJECT

    QHBoxLayout *titre_title;
    QLabel *titre_label;
    QLineEdit *titre_text;

    QHBoxLayout *desc_title;
    QLabel *desc_label;
    QTextEdit *desc_text;

    QHBoxLayout *image_title;
    QLabel *image_label;
    QLineEdit *image_text;

    QHBoxLayout *audio_title;
    QLabel *audio_label;
    QLineEdit *audio_text;

    QHBoxLayout *button_bar;
    QPushButton *button_save;
    QPushButton *button_close;

    QVBoxLayout *frame;

    audio *Audio;

public:
    WindowAfficherAudio(audio *au, QWidget *parent=0);
    QPushButton* getButtonSave() {return button_save;}
    QLineEdit* getTitle() {return titre_text;}
    QTextEdit* getDesc() {return desc_text;}
    QLineEdit* getChemin() {return image_text;}
    QLineEdit* getCheminAudio() {return audio_text;}
    audio* getAudio() {return Audio;}

signals:

private slots:

public slots:
    //void save();
};

#endif // HAFFICHERAUDIO_H
