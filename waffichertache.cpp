#include "waffichertache.h"
#include <QString>

WindowAfficherTache::WindowAfficherTache(Tache *ta, QWidget *parent):
    tache(ta), QWidget(parent)
{
    setFixedSize(300, 350);

    frame = new QVBoxLayout;

    titre_title = new QHBoxLayout;
    titre_label = new QLabel("Titre: ");
    titre_text = new QLineEdit(tache->getTitle());

    //Tache
    action = new QHBoxLayout;
    action_label = new QLabel("*Action :");
    action_box = new QTextEdit(tache->getAction());

    statut = new QHBoxLayout;
    statut_label = new QLabel("*Statut : (en_cours, attente, terminee)");
    statut_box = new QLineEdit(enum_statut_to_qstring(tache->getStatut()));

    priorite = new QHBoxLayout;
    prio_label = new QLabel("Priorite (>=0) :");
    //QString tmp = to_string(tache->getPriorite());
    //prio_box = new QLineEdit(to_string(tache->getPriorite()));

    date_echeance_day = new QHBoxLayout;
    date_e_day_label= new QLabel("Date d'echeance : (i.e 01.01.2000)");
    //date_e_day_box = new QLineEdit(toString(tache->getDate_echeance()));

//    date_echeance_min= new QHBoxLayout;
//    date_e_min_label= new QLabel("Temps de l'echeance : (i.e. 12:00:00)");
//    date_e_min_box= new QLineEdit;

    button_bar = new QHBoxLayout;
    button_save = new QPushButton("Sauvegarder");
    //QObject::connect(button_create, SIGNAL(clicked()), this, SLOT(create()));
    button_close = new QPushButton("Fermer");
    QObject::connect(button_close, SIGNAL(clicked()), this, SLOT(close()));


    titre_title->addWidget(titre_label); titre_title->addWidget(titre_text);
    action->addWidget(action_label); action->addWidget(action_box);
    statut->addWidget(statut_label); statut->addWidget(statut_box);
    priorite->addWidget(prio_label); priorite->addWidget(prio_box);
    date_echeance_day->addWidget(date_e_day_label); date_echeance_day->addWidget(date_e_day_box);
    //date_echeance_min->addWidget(date_e_min_label); date_echeance_min->addWidget(date_e_min_box);
    button_bar->addWidget(button_save); button_bar->addWidget(button_close);

    frame->addLayout(titre_title);
    frame->addLayout(action);
    frame->addLayout(statut);
    frame->addLayout(priorite);
    frame->addLayout(date_echeance_day);
    //frame->addLayout(date_echeance_min);
    frame->addLayout(button_bar);
    this->setLayout(frame);
}
/*
void WindowAfficherTache::save() {
    QString text_act = getTextBox()->toPlainText();
    QString s_statut = getStatutBox()->text();
    QString s_prio = getPrioBox()->text();  //optionnelle
    QString s_date_day = getDate_e_DayBox()->text();//optionnelle
    QString s_date_min = getDate_e_MinBox()->text();//optionnelle

    NotesManager* NM = NotesManager::getInstance();

    Type_statut_tache statut_task=string_to_enum_statut(s_statut.QString::toStdString());


    Note* newNote = new Note(identifiant);
//Tache()
    Tache *newTache= new Tache(titre_version,QDateTime::currentDateTime(),text_act,statut_task);
    if(!s_prio.QString::isNull())   //si priorite est rempli
    {
        newTache->setPriorite(s_prio.toUInt(0,10));
    }
    if(!(s_date_day.QString::isNull()) && !(s_date_min.QString::isNull()))  //si les dates sont remplies
    {
        QString s_date = s_date_day + "-" +s_date_min;
        QDateTime newDate=QDateTime::fromString(s_date);
        newTache->setDate_echeance(newDate);
    }
    newNote->ajouterVersion(newTache);
    NM->ajouterNote(newNote);
    this->close();
}
*/



