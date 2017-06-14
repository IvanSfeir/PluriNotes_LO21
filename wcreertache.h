#ifndef WCREERTACHE_H
#define WCREERTACHE_H


#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include <QLineEdit>
#include <QString>
#include "tache.h"
#include "notesmanager.h"

class WindowCreerTache :public QWidget
{

    Q_OBJECT
    // Note
    QHBoxLayout *id_title;
    QLabel *id_label;
    QLabel *id_text;

    QHBoxLayout *titre_title;
    QLabel *titre_label;
    QLabel *titre_text;

    //Tache
    QHBoxLayout *action;
    QLabel *action_label;
    QTextEdit *action_box;

    QHBoxLayout *statut;
    QLabel *statut_label;
    QLineEdit *statut_box;

    QHBoxLayout *priorite;  //optionnelle
    QLabel *prio_label;
    QLineEdit *prio_box;

    QHBoxLayout *date_echeance_day;  //optionnelle
    QLabel *date_e_day_label;
    QLineEdit *date_e_day_box;

    QHBoxLayout *date_echeance_min;  //optionnelle
    QLabel *date_e_min_label;
    QLineEdit *date_e_min_box;

    QHBoxLayout *button_bar;
    QPushButton *button_create;
    QPushButton *button_close;

    QVBoxLayout *frame;

    QString identifiant;
    QString titre_version;


public:
    WindowCreerTache(QString& ident, QString& titre, QWidget *parent=0);
    QPushButton* getButtonCreate() {return button_create;}
    QTextEdit* getTextBox() {return action_box;}
    QLineEdit* getStatutBox() {return statut_box;}
    QLineEdit* getPrioBox() {return statut_box;}
    QLineEdit* getDate_e_DayBox() {return date_e_day_box;}
    QLineEdit* getDate_e_MinBox() {return date_e_min_box;}


signals:

private slots:

public slots:
    void create();


};

#endif // WCREERTACHE_H
