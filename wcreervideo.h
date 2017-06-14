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
