/*!
 *@file     waffichercouple.h
 *@author   Ngo Sy Toan
 * @date    June 2017
 * @brief   The widget to view all couples of a relation
 */
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

/*!
 * \brief The WindowAfficherCouple class: the Widget to view all couplees of a relation
 */
class WindowAfficherCouple : public QWidget {

    Q_OBJECT
    /*!
     * \brief titre_relation: the boxLayout to show titre of the choosed relation
     */
    QHBoxLayout *titre_relation;
    /*!
     * \brief titre_st: the titre of the choosed relation
     */
    QLabel *titre_st;

    /*!
     * \brief couples: list of couples of the relation
     */
    QListWidget *couples;

    /*!
     * \brief fermer: button to close the Widget
     */
    QPushButton *fermer;
    /*!
     * \brief creer_couple: button to create a couple
     */
    QPushButton *creer_couple;
    /*!
     * \brief supprimer_couple: button to delete a couple
     */
    QPushButton *supprimer_couple;

    /*!
     * \brief verti: overall boxLayout for the Widget
     */
    QVBoxLayout *verti;
    /*!
     * \brief horiz1: boxLayout of the first line of buttons
     */
    QHBoxLayout *horiz1;
    /*!
     * \brief horiz2: boxLayout of the second line of buttons
     */
    QHBoxLayout *horiz2;


public:
    /*!
     * \brief WindowAfficherCouple: constructor of the Widget
     * \param relation_name: the name of choosed relation
     * \param parent: parent Widget
     */
    WindowAfficherCouple(QString& relation_name, QWidget *parent=0);
    /*!
     * \brief getButtonCreateVersion: get the button to create couple
     * \return
     */
    QPushButton* getButtonCreateVersion() {return creer_couple;}
    //QTextEdit* getTextBox() {return text_box;}

signals:

private slots:

public slots:

};

#endif // WAFFICHERCOUPLE_H
