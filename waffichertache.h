#ifndef WAFFICHERTACHE_H
#define WAFFICHERTACHE_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QLineEdit>
#include<QString>
#include<QDateTime>
#include"note.h"
#include"version.h"
#include"tache.h"



class WindowAfficherTache : public QWidget {

    Q_OBJECT

    QHBoxLayout *titre_title;
    QLabel *titre_label;
    QLineEdit *titre_text;

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

//    QHBoxLayout *date_echeance_min;  //optionnelle
//    QLabel *date_e_min_label;
//    QLineEdit *date_e_min_box;

    QHBoxLayout *button_bar;
    QPushButton *button_save;
    QPushButton *button_close;

    QVBoxLayout *frame;

    Tache *tache;

public:
    WindowAfficherTache(Tache *ta, QWidget *parent=0);
    QPushButton* getButtonSave() {return button_save;}
    QLineEdit* getTitle() {return titre_text;}
    QTextEdit* getTextBox() {return action_box;}
    QLineEdit* getStatutBox() {return statut_box;}
    QLineEdit* getPrioBox() {return statut_box;}
    QLineEdit* getDate_e_DayBox() {return date_e_day_box;}
//    QLineEdit* getDate_e_MinBox() {return date_e_min_box;}

signals:

private slots:

public slots:
    //void save();
};

#endif // WAFFICHERTACHE_H
