/*!
 *@file     wcreerarticle.h
 *@author   Ngo Sy Toan
 * @date    June 2017
 * @brief   The widget to create new article
 */
#ifndef WCREERARTICLE_H
#define WCREERARTICLE_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>


/*!
 * \brief The WindowCreerArticle class: Widget to create new article
 */
class WindowCreerArticle : public QWidget {

    Q_OBJECT
    /*!
     * \brief id_title: boxLayout id of the Widget
     */
    QHBoxLayout *id_title;
    /*!
     * \brief id_label: label of the id
     */
    QLabel *id_label;
    /*!
     * \brief id_text: label text of the id
     */
    QLabel *id_text;
    /*!
     * \brief titre_title: boxLayout titre of the Widget
     */
    QHBoxLayout *titre_title;
    /*!
     * \brief titre_label: label of the titre
     */
    QLabel *titre_label;
    /*!
     * \brief titre_text: label text of the titre
     */
    QLabel *titre_text;

    /*!
     * \brief text_title: boxLayout titre text of the Widget
     */
    QHBoxLayout *text_title;
        /*!
         * \brief text_label: label text of the text
         */
    QLabel *text_label;
    /*!
     * \brief text_box: Line space to view and edit text
     */
    QTextEdit *text_box;
    /*!
     * \brief button_bar: bar button of the Widget
     */
    QHBoxLayout *button_bar;
    /*!
     * \brief button_save: button to save the article
     */
    QPushButton *button_create;
    /*!
     * \brief button_close: button to close the Widget
     */
    QPushButton *button_close;
    /*!
     * \brief frame: the frame of Widget
     */
    QVBoxLayout *frame;
    /*!
     * \brief identifiant: identifiant of the article
     */
    QString identifiant;
    /*!
     * \brief titre_article: titre of the article
     */
    QString titre_article;

public:
    /*!
     * \brief WindowCreerArticle: contructor of the Widget
     * \param ident: the identifiant of the new article
     * \param parent: parent Widget
     */
    WindowCreerArticle(QString& ident, QString& titre, QWidget *parent=0);
    /*!
     * \brief getButtonCreate: get the button create
     * \return pointer to the button create
     */
    QPushButton* getButtonCreate() {return button_create;}
    /*!
     * \brief getTextBox: get the line space
     * \return pointer to the line space
     */
    QTextEdit* getTextBox() {return text_box;}

signals:

private slots:

public slots:
    /*!
     * \brief create: create a new article
     */
    void create();
};

#endif // WCREERARTICLE_H
