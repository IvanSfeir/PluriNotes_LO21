/*!
 *@file     waffichertache.h
 *@author   Ngo Sy Toan
 * @date    June 2017
 * @brief   The widget to view and edit tache
 */
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
    /*!
     * \brief titre_title: boxLayout titre of the Widget
     */
    QHBoxLayout *titre_title;
    /*!
     * \brief titre_label: label of the titre
     */
    QLabel *titre_label;
    /*!
     * \brief titre_text: Line space to view and edit titre
     */
    QLineEdit *titre_text;

    /*!
     * \brief action: boxLayout text space for the action
     */
    QHBoxLayout *action;
    /*!
     * \brief action_label: label of the action
     */
    QLabel *action_label;
    /*!
     * \brief action_box: text space to view and edit action
     */
    QTextEdit *action_box;
    /*!
     * \brief statut: boxLayout line space for the status
     */
    QHBoxLayout *statut;
    /*!
     * \brief statut_label: label of the status
     */
    QLabel *statut_label;
    /*!
     * \brief statut_box: line space to view and edit status
     */
    QLineEdit *statut_box;
    /*!
     * \brief priorite: boxLayout line space for the priority
     */
    QHBoxLayout *priorite;  //optionnelle
    /*!
     * \brief prio_label: label of the priority
     */
    QLabel *prio_label;
    /*!
     * \brief prio_box: line space to view and edit priority
     */
    QLineEdit *prio_box;
    /*!
     * \brief date_echeance_day: boxLayout line space for the date_echeance_day
     */
    QHBoxLayout *date_echeance_day;  //optionnelle
    /*!
     * \brief date_e_day_label: label of the date_e_day_label
     */
    QLabel *date_e_day_label;
    /*!
     * \brief date_e_day_box: line space of the date_e_day_box
     */
    QLineEdit *date_e_day_box;

//    QHBoxLayout *date_echeance_min;  //optionnelle
//    QLabel *date_e_min_label;
//    QLineEdit *date_e_min_box;
    /*!
     * \brief button_bar: bar button of the Widget
     */
    QHBoxLayout *button_bar;
    /*!
     * \brief button_save: button to save the article
     */
    QPushButton *button_save;
    /*!
     * \brief button_close: button to close the Widget
     */
    QPushButton *button_close;
    /*!
     * \brief frame: the frame of Widget
     */
    QVBoxLayout *frame;
    /*!
     * \brief tache: the choosed tache to view and edit
     */
    Tache *tache;

public:
    /*!
     * \brief WindowAfficherTache: contructor of the Widget
     * \param ta: the choosed tache to view and edit
     * \param parent: parent Widget
     */
    WindowAfficherTache(Tache *ta, QWidget *parent=0);
    /*!
     * \brief getButtonSave: get the button save
     * \return pointer to the button save
     */
    QPushButton* getButtonSave() {return button_save;}
    /*!
     * \brief getTitle: get the line space of titre
     * \return pointer to the line space of titre
     */
    QLineEdit* getTitle() {return titre_text;}
    /*!
     * \brief getTextBox: get action text space
     * \return pointer to the text space
     */
    QTextEdit* getTextBox() {return action_box;}
    /*!
     * \brief getTitle: get the line space of status
     * \return pointer to the line space of status
     */
    QLineEdit* getStatutBox() {return statut_box;}
    /*!
     * \brief getPrioBox: get the line space of priority
     * \return pointer to the line space of priority
     */
    QLineEdit* getPrioBox() {return statut_box;}
    /*!
     * \brief getDate_e_DayBox: get the line space of date_e_day_box
     * \return pointer to the line space of date_e_day_box
     */
    QLineEdit* getDate_e_DayBox() {return date_e_day_box;}
//    QLineEdit* getDate_e_MinBox() {return date_e_min_box;}

signals:

private slots:

public slots:
    //void save();
};

#endif // WAFFICHERTACHE_H
