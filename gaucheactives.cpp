#include "gaucheactives.h"

GaucheActives::GaucheActives(QString* titre, QMainWindow* parent) :
    QWidget(parent) {

    titre_section = new QLabel(this);
    titre_section->setText(*titre);
    scrolleur = new QScrollArea(this);
    contenuScrolleur = new QWidget(this);

    section = new QWidget(this);

    section_actives = new QVBoxLayout();

    notes_actives = new QVBoxLayout();
    b1 = new QPushButton(parent);
    b1->setText("note 1");
    notes_actives->addWidget(b1);
    b2 = new QPushButton(parent);
    b2->setText("note 2");
    notes_actives->addWidget(b2);
    b3 = new QPushButton(parent);
    b3->setText("note 3");
    notes_actives->addWidget(b3);
    b4 = new QPushButton(parent);
    b4->setText("note 4");
    notes_actives->addWidget(b4);

    contenuScrolleur->setLayout(notes_actives);

    scrolleur->setWidget(contenuScrolleur);

    section_actives->addWidget(titre_section);
    section_actives->addWidget(scrolleur);

    QObject::connect(b1, SIGNAL(isClicked()), parent, SLOT(close()));
}
