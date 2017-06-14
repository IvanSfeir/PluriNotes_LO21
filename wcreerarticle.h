#ifndef WCREERARTICLE_H
#define WCREERARTICLE_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>

#include"version.h"


class WindowCreerArticle : public QWidget {

    Q_OBJECT

    QHBoxLayout *id_title;
    QLabel *id_label;
    QLabel *id_text;

    QHBoxLayout *titre_title;
    QLabel *titre_label;
    QLabel *titre_text;

    QHBoxLayout *text_title;
    QLabel *text_label;
    QTextEdit *text_box;

    QHBoxLayout *button_bar;
    QPushButton *button_create;
    QPushButton *button_close;

    QVBoxLayout *frame;

public:
    WindowCreerArticle(QString &i, QString &titre, QWidget *parent=0);
    QPushButton* getBoutonSauvegarder() {return sauvegarder;}

signals:

private slots:

public slots:
    void create(QString ident, QString titre);
};

#endif // WCREERARTICLE_H
