#ifndef TACHE_H
#define TACHE_H

#include "version.h"
#include <QDateTime>

enum Type_statut_tache {en_cours, attente, terminee};


class Tache : public Version{
    QString action;
    Type_statut_tache statut;
    unsigned int priorite;  //optionnelle
    QDateTime date_echeance;    //optionnelle

    Tache(TacheBuilder builder) {
        this->action = builder.action;
        this->statut = builder.statut;
        this->priorite = builder.priorite;
        this->date_echeance= builder.date_echeance;
      }

public:
//    Tache(const QString & t, QDateTime, d, const QString &a, Type_statut_tache & s=attente, const unsigned int p=0, const QDateTime &d_e=NULL): //valeur NULL possible avec QDate ?
//        Version(t,d), action(a), priorite(p), date_echeance(d_e), statut(s){}
    ~Tache(){}

    QString & getAction() const {return action;}
    unsigned int getPriorite() const {return priorite;}
    QDateTime & getDate_echeance() const {return date_echeance;}
    Type_statut_tache & getStatut() const {return statut;}

    // Design pattern Builder
    class TacheBuilder {
        friend class Tache;
        QString action;
        Type_statut_tache statut;
        unsigned int priorite;
        QDateTime date_echeance;

    public:
        static TacheBuilder(QString action, Type_statut_tache statut) {
            this->action = action;
            this->statut= statut;
            this->priorite=0;
            this->date_echeance=QDateTime();//constructs a NULL datetime
        }

        static TacheBuilder priorite(unsigned int priorite) {
          this->priorite= priorite;
          return this;
        }

    public:
        static TacheBuilder date_echeance(QDateTime date_echeance) {
          this->date_echeance= date_echeance;
          return this;
        }

        static Tache build(){
            return new Tache(this);
        }

};
    // à enlever ?
    Tache getTache(const QString &a, const Type_statut_tache &t){
        TacheBuilder newTache= new Tache::TacheBuilder(a,t);
        newTache.priorite(0);
        newTache.date_echeance=QDateTime();

        return newTache.build();

    }


// Plus nécessaire car Builder choisi ou garder ?
//    void setAction(const QString newAction) { action=newAction;}
//    void setPriorite(const unsigned int newPriorite) {priorite=newPriorite;}
//    void setDate_echeance(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec) {
//        QDateTime newDate(QDate(year,month,day), QTime(hour, min, sec));
//        date_echeance=newDate;}
//    void setStatut(const Type_statut_tache & newStatut) {statut=newStatut;}

};

//***** Construire une tache avec attribut facultatif
//Tache::TacheBuilder newT("g",attente);
//newT.priorite(5);
//newT.date_echeance(QDateTime());
//Tache newTask=newT.build();
//
//Tache::TacheBuilder newT2("g",attente);
//newT2.date_echeance(QDateTime());
//Tache newTask2=newT2.build();

#endif // TACHE_H
