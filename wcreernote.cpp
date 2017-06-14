#include"wcreernote.h"

WindowCreerNote::WindowCreerNote(QWidget *parent) {

    typel = new QLabel("Type");
    typebox = new QComboBox();
    typebox->addItem("Article");
    typebox->addItem("Tache");
    typebox->addItem("Image");
    typebox->addItem("Audio");
    typebox->addItem("Video");
    valider = new QPushButton("Valider");
    horiz = new QHBoxLayout(parent);
    horiz->addWidget(typel);
    horiz->addWidget(typebox);
    horiz->addWidget(valider);

}
