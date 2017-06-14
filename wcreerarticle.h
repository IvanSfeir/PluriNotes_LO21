#ifndef WCREERARTICLE_H
#define WCREERARTICLE_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>

#include"version.h"


class WindowCreerArticle : public QWidget {

    Q_OBJECT

    QLabel *titrel;
    QPushButton *sauvegarder;
    QHBoxLayout *horiz;
    QVBoxLayout *verti;

public:
    WindowCreerArticle(QWidget *parent=0);
    QPushButton* getBoutonSauvegarder() {return sauvegarder;}

};

#endif // WCREERARTICLE_H
