#include "wcreertache.h"
#include <QString>

WindowCreerTache::WindowCreerTache(QString& ident, QString& titre, QWidget *parent):
    QWidget(parent)
{
    identifiant=ident;
    titre_version=titre;
    setFixedSize(300, 350);

    frame = new QVBoxLayout;

    id_title = new QHBoxLayout;
    id_label = new QLabel("Identifiant: ");
    id_text = new QLabel(ident);

    titre_title = new QHBoxLayout;
    titre_label = new QLabel("Titre: ");
    titre_text = new QLabel(titre);

    //Tache
    action = new QHBoxLayout;
    action_label = new QLabel("Action :");
    action_box = new QTextEdit;

    statut = new QHBoxLayout;
    statut_label = new QLabel("Statut :");
    statut_box = new QLineEdit;

    priorite = new QHBoxLayout;
    prio_label = new QLabel("Priorite :");
    prio_box = new QLineEdit;

    date_echeance_day = new QHBoxLayout;
    date_e_day_label= new QLabel("Date de la date d'echeance :(dd.MM.yyyy)");
    date_e_day_box = new QLineEdit;

    date_echeance_min= new QHBoxLayout;
    date_e_min_label= new QLabel("Temps de la date d'echeance :(hh::mm:ss)");
    date_e_min_box= new QLineEdit;

    button_bar = new QHBoxLayout;
    button_create = new QPushButton("Create");
    QObject::connect(button_create, SIGNAL(clicked()), this, SLOT(create()));
    button_close = new QPushButton("Close");
    QObject::connect(button_close, SIGNAL(clicked()), this, SLOT(close()));


    id_title->addWidget(id_label); id_title->addWidget(id_text);
    titre_title->addWidget(titre_label); titre_title->addWidget(titre_text);
    action->addWidget(action_label); action->addWidget(action_box);
    statut->addWidget(statut_label); action->addWidget(statut_box);
    priorite->addWidget(prio_label); priorite->addWidget(prio_box);
    date_echeance_day->addWidget(date_e_day_label); date_echeance_day->addWidget(date_e_day_box);
    date_echeance_min->addWidget(date_e_min_label); date_echeance_min->addWidget(date_e_min_box);
    button_bar->addWidget(button_create); button_bar->addWidget(button_close);

    frame->addLayout(id_title);
    frame->addLayout(titre_title);
    frame->addLayout(action);
    frame->addLayout(statut);
    frame->addLayout(priorite);
    frame->addLayout(date_echeance_day);
    frame->addLayout(date_echeance_min);
    frame->addLayout(button_bar);
    this->setLayout(frame);
}

void WindowCreerTache::create() {
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




