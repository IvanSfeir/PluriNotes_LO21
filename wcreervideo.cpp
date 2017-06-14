#include "wcreervideo.h"
#include "notesmanager.h"
#include "multimedia.h"
#include <QTextEdit>
#include <QDebug>


WindowCreerVideo::WindowCreerVideo(QString& ident, QString& titre, QWidget* parent):
    QWidget(parent) {
    //Keep ident, titre, desc to create the Note
    identifiant = ident;
    titre_version = titre;
    setFixedSize(300, 350);

    frame = new QVBoxLayout;

    id_title = new QHBoxLayout;
    id_label = new QLabel("Identifiant: ");
    id_text = new QLabel(ident);

    titre_title = new QHBoxLayout;
    titre_label = new QLabel("Titre: ");
    titre_text = new QLabel(titre);

    desc_title = new QHBoxLayout;
    desc_label = new QLabel("Description:");
    desc_box = new QTextEdit;

    image_title = new QHBoxLayout;
    image_label = new QLabel("Chemin image:");
    image_URL = new QLineEdit;

    video_title = new QHBoxLayout;
    video_label = new QLabel("Chemin video:");
    video_URL = new QLineEdit;

    button_bar = new QHBoxLayout;
    button_create = new QPushButton("Create");
    QObject::connect(button_create, SIGNAL(clicked()), this, SLOT(create()));
    button_close = new QPushButton("Close");
    QObject::connect(button_close, SIGNAL(clicked()), this, SLOT(close()));



    id_title->addWidget(id_label); id_title->addWidget(id_text);
    titre_title->addWidget(titre_label); titre_title->addWidget(titre_text);
    desc_title->addWidget(desc_label); desc_title->addWidget(desc_box);
    image_title->addWidget(image_label); image_title->addWidget(image_URL);
    video_title->addWidget(video_label); video_title->addWidget(video_URL);
    button_bar->addWidget(button_create); button_bar->addWidget(button_close);

    frame->addLayout(id_title);
    frame->addLayout(titre_title);
    frame->addLayout(desc_title);
    frame->addLayout(image_title);
    frame->addLayout(video_title);
    frame->addLayout(button_bar);
    this->setLayout(frame);
}

void WindowCreerVideo::create() {
    QString desc = getDescBox()->toPlainText();
    QString imageURL = getImageBox()->text();
    QString videoURL = getVideoBox()->text();
    NotesManager* NM = NotesManager::getInstance();
    Note* newNote = new Note(identifiant);
    video* newVideo = new video(titre_version, QDateTime::currentDateTime(), desc, imageURL, videoURL);
    newNote->ajouterVersion(newVideo);
    NM->ajouterNote(newNote);
    this->close();
}

