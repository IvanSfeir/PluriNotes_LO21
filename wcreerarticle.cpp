#include "wcreerarticle.h"
#include "notesmanager.h"
#include "article.h"
#include <QTextEdit>
#include <QDebug>


WindowCreerArticle::WindowCreerArticle(QString& ident, QString& titre, QWidget* parent):
    QWidget(parent) {
    //Keep ident, titre, desc to create the Note
    identifiant = ident;
    titre_article = titre;
    setFixedSize(300, 350);

    frame = new QVBoxLayout;

    id_title = new QHBoxLayout;
    id_label = new QLabel("Identifiant: ");
    id_text = new QLabel(ident);

    titre_title = new QHBoxLayout;
    titre_label = new QLabel("Titre: ");
    titre_text = new QLabel(titre);

    text_title = new QHBoxLayout;
    text_label = new QLabel("Texte:");
    text_box = new QTextEdit;

    button_bar = new QHBoxLayout;
    button_create = new QPushButton("Create");
    QObject::connect(button_create, SIGNAL(clicked()), this, SLOT(create()));
    button_close = new QPushButton("Close");
    QObject::connect(button_close, SIGNAL(clicked()), this, SLOT(close()));



    id_title->addWidget(id_label); id_title->addWidget(id_text);
    titre_title->addWidget(titre_label); titre_title->addWidget(titre_text);
    text_title->addWidget(text_label); text_title->addWidget(text_box);
    button_bar->addWidget(button_create); button_bar->addWidget(button_close);

    frame->addLayout(id_title);
    frame->addLayout(titre_title);
    frame->addLayout(text_title);
    frame->addLayout(button_bar);
    this->setLayout(frame);
}

void WindowCreerArticle::create() {
    QString text = getTextBox()->toPlainText();
    NotesManager* NM = NotesManager::getInstance();
    Note* newNote = new Note(identifiant);
    Article* newArticle = new Article(titre_article, QDateTime::currentDateTime(), text);
    newNote->ajouterVersion(newArticle);
    NM->ajouterNote(newNote);
    this->close();
}

