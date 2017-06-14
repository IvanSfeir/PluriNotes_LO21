#ifndef WCREERNOTE_H
#define WCREERNOTE_H

#include<QWidget>
#include<QComboBox>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>


class WindowCreerNote : public QWidget {

    Q_OBJECT

    QLabel *typel;
    QComboBox *typebox;
    QPushButton *valider;
    QHBoxLayout *horiz;

public:
    WindowCreerNote(QWidget *parent=0);
    QComboBox* getComboType() {return typebox;}
    QPushButton* getBoutonValider() {return valider;}

};

#endif // WCREERNOTE_H
