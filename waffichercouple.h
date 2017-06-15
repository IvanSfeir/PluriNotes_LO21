#ifndef WAFFICHERCOUPLE_H
#define WAFFICHERCOUPLE_H


#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include <QLabel>
#include <QListWidget>
#include <QLayout>
#include <QPushButton>
#include "relation.h"

class WindowAfficherCouple : public QWidget {

    Q_OBJECT

    QHBoxLayout *titre_relation;
    QLabel *titre_st;
    //QLabel *id_text;

    QListWidget *couples;

    QPushButton *fermer;
    QPushButton *creer_couple;
    QPushButton *supprimer_couple;

    QVBoxLayout *verti;
    QHBoxLayout *horiz1;
    QHBoxLayout *horiz2;


public:
    WindowAfficherCouple(QString& relation_name, QWidget *parent=0);
    QPushButton* getButtonCreateVersion() {return creer_couple;}
    //QTextEdit* getTextBox() {return text_box;}

signals:

private slots:

public slots:

};

#endif // WAFFICHERCOUPLE_H
