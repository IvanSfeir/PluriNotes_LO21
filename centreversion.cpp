#include "centreversion.h"
#include <QMessageBox>


/*
CentreVersion::CentreVersion (Version& vers, QWidget *parent):
    QWidget(parent), version(vers)
{

    id     = new QLineEdit(this);
    title  = new QLineEdit(this);
    text   = new QTextEdit(this);

    sauvegarder = new QPushButton("Sauvegarder", this);

    idl    = new QLabel("Identificateur",this);
    titlel = new QLabel("Titre", this);
    textl  = new QLabel("Texte", this);

    cid    = new QHBoxLayout;
    cid->addWidget(idl);
    cid->addWidget(id);

    ctitle = new QHBoxLayout;
    ctitle->addWidget(titlel);
    ctitle->addWidget(title);

    ctext  = new QHBoxLayout;
    ctext->addWidget(textl);
    ctext->addWidget(text);

    couche = new QVBoxLayout;
    couche->addLayout(cid);
    couche->addLayout(ctitle);
    couche->addLayout(ctext);
    couche->addWidget(sauvegarder);

    id->setReadOnly(true);

    id->setText(version->getId());
    title->setText(version->getTitle());
    text->setText(version->getText());

    sauvegarder->setEnabled(false);

    setLayout(couche);

    QObject::connect(sauvegarder, SIGNAL(clicked()), this, SLOT(sauvegarderVersion()));

    QObject::connect(title, SIGNAL(textEdited(QString)),this, SLOT(activerSauvegarde(QString)));
    QObject::connect(text, SIGNAL(textChanged()),this, SLOT(activerSauvegarde()));

}

void CentreVersion::sauvegarderVersion() {
    version->setTitle(title->text());
    version->setText(text->toPlainText());
    QMessageBox::information(this,"Sauvegarde","La nouvelle version a bien été sauvegardée");

    sauvegarder->setEnabled(false);
}

void CentreVersion::activerSauvegarde(QString) {
    sauvegarder->setEnabled(true);
}
*/
