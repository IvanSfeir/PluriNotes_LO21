#ifndef TACHE_H
#define TACHE_H

/**
 * \file tache.h
 */



#include "version.h"
#include <QDateTime>

enum Type_statut_tache {en_cours, attente, terminee};


class Tache : public Version{
    QString action;
    Type_statut_tache statut;
    unsigned int priorite;  //optionnelle
    QDateTime date_echeance;    //optionnelle



public:
    Tache(const QString &t, QDateTime & d, const QString &a, const Type_statut_tache & s=attente, const unsigned int p=0/*, const QDateTime &d_e=NULL*/): //valeur NULL possible avec QDate ?
        Version(t,d), action(a), priorite(p), /*date_echeance(d_e),*/ statut(s){}
    //Tache(const QString &t, QDateTime &d, const QString &a, const Type_statut_tache & s=attente, const unsigned int p=0): //valeur NULL possible avec QDate ?
        //Version(t,d), action(a), statut(s), priorite(p){}
    Tache(const QString &t, QDateTime &d, const QString &a, const Type_statut_tache & s=attente/*, const QDateTime &d_e=NULL*/): //valeur NULL possible avec QDate ?
        Version(t,d), action(a), /*date_echeance(d_e),*/ statut(s){}

    ~Tache(){}

    QString getAction() const {return action;}
    unsigned int getPriorite() const {return priorite;}
    QDateTime getDate_echeance() const {return date_echeance;}
    Type_statut_tache getStatut() const {return statut;}



    void setAction(const QString newAction) { action=newAction;}
    void setPriorite(const unsigned int newPriorite) {priorite=newPriorite;}
    void setDate_echeance(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec) {
        QDateTime newDate(QDate(year,month,day), QTime(hour, min, sec));
        date_echeance=newDate;}
    void setStatut(const Type_statut_tache & newStatut) {statut=newStatut;}

};


#endif // TACHE_H
