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



class WindowAfficherArticle : public QWidget {

    Q_OBJECT

    QHBoxLayout *titre_title;
    QLabel *titre_label;
    QLineEdit *titre_text;

    QHBoxLayout *text_title;
    QLabel *text_label;
    QTextEdit *text_box;

    QHBoxLayout *button_bar;
    QPushButton *button_save;
    QPushButton *button_close;

    QVBoxLayout *frame;

    Article *article;

public:
    WindowAfficherArticle(Article *art, QWidget *parent=0);
    QPushButton* getButtonSave() {return button_save;}
    QLineEdit* getTitle() {return titre_text;}
    QTextEdit* getText() {return text_box;}
    Article* getArticle() {return article;}

signals:

private slots:

public slots:
    //void save();
};

#endif // WAFFICHERARTICLE_H
