#ifndef HAFFICHERVIDEO_H
#define HAFFICHERVIDEO_H
#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QLineEdit>
#include"note.h"
#include"multimedia.h"



class WindowAfficherVideo : public QWidget {

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

    QHBoxLayout *video_title;
    QLabel *video_label;
    QLineEdit *video_text;

    QHBoxLayout *button_bar;
    QPushButton *button_save;
    QPushButton *button_close;

    QVBoxLayout *frame;

    video *Video;

public:
    WindowAfficherVideo(video* vi, QWidget *parent=0);
    QPushButton* getButtonSave() {return button_save;}
    QLineEdit* getTitle() {return titre_text;}
    QTextEdit* getDesc() {return desc_text;}
    QLineEdit* getChemin() {return image_text;}
    QLineEdit* getCheminVideo() {return video_text;}
    video* getVideo() {return Video;}

signals:

private slots:

public slots:
    //void save();
};
#endif // HAFFICHERVIDEO_H
