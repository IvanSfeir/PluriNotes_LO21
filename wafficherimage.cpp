#include "wafficherimage.h"


WindowAfficherImage::WindowAfficherImage(image* im, QWidget* parent):
    Image(im), QWidget(parent) {

    setFixedSize(300, 350);

    frame = new QVBoxLayout;

    titre_title = new QHBoxLayout;
    titre_label = new QLabel("Titre: ");
    titre_text = new QLineEdit(Image->getTitle());

    desc_title = new QHBoxLayout;
    desc_label = new QLabel("Texte:");
    desc_text = new QTextEdit(Image->getDesc());

    image_title = new QHBoxLayout;
    image_label = new QLabel("Chemin image:");
    image_text = new QLineEdit(Image->getImg());

    button_bar = new QHBoxLayout;
    button_save = new QPushButton("Sauvegarder");
    //QObject::connect(button_save, SIGNAL(clicked()), this, SLOT(save()));
    button_close = new QPushButton("Fermer");
    QObject::connect(button_close, SIGNAL(clicked()), this, SLOT(close()));

    titre_title->addWidget(titre_label); titre_title->addWidget(titre_text);
    desc_title->addWidget(desc_label); desc_title->addWidget(desc_text);
    image_title->addWidget(image_label); image_title->addWidget(image_text);
    button_bar->addWidget(button_save); button_bar->addWidget(button_close);

    frame->addLayout(titre_title);
    frame->addLayout(desc_title);
    frame->addLayout(image_title);
    frame->addLayout(button_bar);
    //frame->addWidget(button_close);
    this->setLayout(frame);
}
