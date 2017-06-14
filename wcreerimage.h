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
    void create();
};

#endif // WCREERMULTI_H
