/*!
 *@file     wafficherimage.h
 *@author   Ngo Sy Toan
 * @date    June 2017
 * @brief   The widget to view view and edit image
 */
#ifndef WAFFICHERIMAGE_H
#define WAFFICHERIMAGE_H


#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QLineEdit>
#include"note.h"
#include"multimedia.h"

/*!
 * \brief The WindowAfficherImag class: Widget to view and edit image
 */
class WindowAfficherImage : public QWidget {

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
     * \brief desc_title: boxLayout description of the Widget
     */
    QHBoxLayout *desc_title;
    /*!
     * \brief desc_label: lable of the description
     */
    QLabel *desc_label;
    /*!
     * \brief desc_text: text space to view and edit text
     */
    QTextEdit *desc_text;
    /*!
     * \brief image_title: boxLayout title of the image
     */
    QHBoxLayout *image_title;
    /*!
     * \brief image_label: lable of the image
     */
    QLabel *image_label;
    /*!
     * \brief image_text: text space to view and edit image text
     */
    QLineEdit *image_text;
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
     * \brief Image: the choosed image to view and edit
     */
    image *Image;

public:
    /*!
     * \brief WindowAfficherImage: constructor of the Widget
     * \param im: pointer to selected image
     * \param parent: parent Widget
     */
    WindowAfficherImage(image *im, QWidget *parent=0);
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
     * \brief getDesc: get the text space
     * \return pointer to the text space
     */
    QTextEdit* getDesc() {return desc_text;}
    /*!
     * \brief getChemin: get to the line space directory
     * \return pointer to line space
     */
    QLineEdit* getChemin() {return image_text;}
    /*!
     * \brief getImage: get the selected image
     * \return pointer to the seleted iamge
     */
    image* getImage() {return Image;}

signals:

private slots:

public slots:
    //void save();
};

#endif // WAFFICHERIMAGE_H
