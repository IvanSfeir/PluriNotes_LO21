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
