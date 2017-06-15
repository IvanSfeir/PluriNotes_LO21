#include "wafficherarticle.h"
#include <QDebug>


WindowAfficherArticle::WindowAfficherArticle(Article* art, QWidget* parent):
    article(art), QWidget(parent) {

    setFixedSize(300, 350);

    frame = new QVBoxLayout;

    titre_title = new QHBoxLayout;
    titre_label = new QLabel("Titre: ");
    titre_text = new QLineEdit(article->getTitle());

    text_title = new QHBoxLayout;
    text_label = new QLabel("Texte:");
    text_box = new QTextEdit(article->getText());

    button_bar = new QHBoxLayout;
    //button_save = new QPushButton("Sauvegarder");
    //QObject::connect(button_save, SIGNAL(clicked()), this, SLOT(save()));
    //button_close = new QPushButton("Fermer");
    //QObject::connect(button_close, SIGNAL(clicked()), this, SLOT(close()));

    titre_title->addWidget(titre_label); titre_title->addWidget(titre_text);
    text_title->addWidget(text_label); text_title->addWidget(text_box);
    //button_bar->addWidget(button_save); button_bar->addWidget(button_close);

    frame->addLayout(titre_title);
    frame->addLayout(text_title);
    //frame->addLayout(button_bar);
    this->setLayout(frame);
}


/*
void WindowAfficherArticle::save() {
    QString title = getTitle()->text();
    QString text = getText()->toPlainText();
    //Note* newNote = new Note(identifiant);
    Article* newArticle = new Article(title, QDateTime::currentDateTime(), text);
    newNote->ajouterVersion(newArticle);
    this->close();
}
*/
