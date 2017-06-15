/*!
 *@file     wcreeraudio.h
 *@author   Ngo Sy Toan
 * @date    June 2017
 * @brief   The widget to create audio
 */
#ifndef WCREERAUDIO_H
#define WCREERAUDIO_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QLineEdit>


/*!
 * \brief The WindowCreerAudio class: Widget to create new audio
 */
class WindowCreerAudio : public QWidget {

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
     * \brief desc_title: boxLayout description text of the Widget
     */
    QHBoxLayout *desc_title;
    /*!
     * \brief desc_label: label description
     */
    QLabel *desc_label;
    /*!
     * \brief desc_box: line space for description
     */
    QTextEdit *desc_box;
    /*!
     * \brief image_title: boxLayout title of the image
     */
    QHBoxLayout *image_title;
    /*!
     * \brief image_label: label of the image
     */
    QLabel *image_label;
    /*!
     * \brief image_URL: line space for URL of the image
     */
    QLineEdit *image_URL;
    /*!
     * \brief audio_title: boxLayout title of the audio
     */
    QHBoxLayout *audio_title;
    /*!
     * \brief audio_label: label of the audio
     */
    QLabel *audio_label;
    /*!
     * \brief audio_URL: line space for URL of the audio
     */
    QLineEdit *audio_URL;
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
     * \brief identifiant: identifiant of the audio
     */
    QString identifiant;
    /*!
     * \brief titre_version: titre of the audio
     */
    QString titre_version;

public:/*!
     * \brief WindowCreerAudio: contructor of the Widget
     * \param ident: the identifiant of the new audio
     * \param parent: parent Widget
     */
    WindowCreerAudio(QString& ident, QString& titre, QWidget *parent=0);
    /*!
     * \brief getButtonCreate: get the button create
     * \return pointer to the button create
     */
    QPushButton* getButtonCreate() {return button_create;}
    /*!
     * \brief getDescBox: get the line space
     * \return pointer to the line space
     */
    QTextEdit* getDescBox() {return desc_box;}
    /*!
     * \brief getImageBox: get the line space
     * \return pointer to the line space
     */
    QLineEdit* getImageBox() {return image_URL;}
    /*!
     * \brief getAudioBox: get the line space
     * \return pointer to the line space
     */
    QLineEdit* getAudioBox() {return audio_URL;}

signals:

private slots:

public slots:
    /*!
     * \brief create: create a new audio
     */
    void create();
};

#endif // WCREERAUDIO_H
