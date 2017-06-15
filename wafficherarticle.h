/*!
 *@file     wafficherarticle.h
 *@author   Ngo Sy Toan
 * @date    June 2017
 * @brief   The widget to view and edit article
 */
#ifndef WAFFICHERARTICLE_H
#define WAFFICHERARTICLE_H


#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QLineEdit>
#include"article.h"
#include"note.h"


/*!
 * \brief The WindowAfficherArticle class: Widget to view and edit article
 */
class WindowAfficherArticle : public QWidget {

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
     * \brief text_title: boxLayout titre of the Widget
     */
    QHBoxLayout *text_title;
    /*!
     * \brief text_label: lable of the text
     */
    QLabel *text_label;
    /*!
     * \brief text_box: text space to view and edit text
     */
    QTextEdit *text_box;

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
     * \brief article: the choosed article to view and edit
     */
    Article *article;

public:
    /*!
     * \brief WindowAfficherArticle: contructor of the Widget
     * \param art: the choosed article to view and edit
     * \param parent: parent Widget
     */
    WindowAfficherArticle(Article *art, QWidget *parent=0);
    /*!
     * \brief getButtonSave: get the button save
     * \return pointer to the button save
     */
    QPushButton* getButtonSave() {return button_save;}
    /*!
     * \brief getTitle: get the line space
     * \return pointer to the line space
     */
    QLineEdit* getTitle() {return titre_text;}
    /*!
     * \brief getText: get the text space
     * \return pointer to the text space
     */
    QTextEdit* getText() {return text_box;}
    /*!
     * \brief getArticle: get the choosed article
     * \return pointer to the choosed article
     */
    Article* getArticle() {return article;}

signals:

private slots:

public slots:
    //void save();
};

#endif // WAFFICHERARTICLE_H
