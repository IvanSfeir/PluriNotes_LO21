#include "centreversion.h"
#include <QMessageBox>


/*
CentreVersion::CentreVersion (Version& vers, QWidget *parent):
    QWidget(parent), version(&vers)
{

    titre       = new QLineEdit(this);
    date_de_modif  = new QLineEdit(this);

    sauvegarder = new QPushButton("Sauvegarder", this);
    fermer      = new QPushButton("Fermer", this);

    titrel      = new QLabel("Titre", this);
    date_de_modifl = new QLabel("Date de modification", this);

    ctitre = new QHBoxLayout;
    ctitre->addWidget(titrel);
    ctitre->addWidget(titre);

    cdate  = new QHBoxLayout;
    cdate->addWidget(date_de_modifl);
    cdate->addWidget(date_de_modif);

    cboutons = new QHBoxLayout;
    cboutons->addWidget(sauvegarder);
    cboutons->addWidget(fermer);

    couche = new QVBoxLayout;
    couche->addLayout(ctitre);
    couche->addLayout(cdate);

    titre->setText(version->getTitle());
    // **************************************
    //TOSTRING WAS NOT DECLARED IN THIS SCOPE
    // **************************************
    //date_de_modif->setText(version->getDateModif());

    date_de_modif->setReadOnly(true);

    sauvegarder->setEnabled(false);

    //setLayout(couche);

    QObject::connect(sauvegarder, SIGNAL(clicked()), this, SLOT(sauvegarderVersion()));

    QObject::connect(titre, SIGNAL(textEdited(QString)),this, SLOT(activerSauvegarde(QString)));

}

void CentreVersion::sauvegarderVersion() {
    version->setTitle(titre->text());
    // *******************************
    // CHANGER LA DATE DE MODIFICATION
    // *******************************
    QMessageBox::information(this,"Sauvegarde","La nouvelle version a bien été sauvegardée");

    sauvegarder->setEnabled(false);
}

void CentreVersion::activerSauvegarde(QString) {
    sauvegarder->setEnabled(true);
}
*/
