#ifndef TACHE_H
#define TACHE_H

/**
 * \file tache.h
 */



#include "version.h"
#include <QDateTime>
#include <iostream>

using namespace std;

enum Type_statut_tache {en_cours, attente, terminee};
string enum_statut_to_string(Type_statut_tache t);
Type_statut_tache string_to_enum_statut(const string &s);

class Tache : public Version{
    QString action;
    Type_statut_tache statut;
    unsigned int priorite;  //optionnelle
    QDateTime date_echeance;    //optionnelle



public:
    Tache(const QString &t, QDateTime d, const QString &a, const Type_statut_tache &s=attente): //valeur NULL possible avec QDate ?
        Version(t,d), action(a), statut(s){}       
//    Tache(const QString &t, QDateTime  d, const QString &a, const Type_statut_tache & s=attente, const unsigned int p=0, QDateTime d_e=QDateTime()): //valeur NULL possible avec QDate ?
//        Version(t,d), action(a), priorite(p), date_echeance(d_e), statut(s){}
//    Tache(const QString &t, QDateTime d, const QString &a, const Type_statut_tache & s=attente, const unsigned int p=0): //valeur NULL possible avec QDate ?
//        Version(t,d), action(a), statut(s), priorite(p){}
//    Tache(const QString &t, QDateTime d, const QString &a, const Type_statut_tache & s=attente, QDateTime d_e=QDateTime()): //valeur NULL possible avec QDate ?
//        Version(t,d), action(a), date_echeance(d_e), statut(s){}

    ~Tache(){}

    QString getAction() const {return action;}
    unsigned int getPriorite() const {return priorite;}
    QDateTime getDate_echeance() const {return date_echeance;}
    Type_statut_tache getStatut() const {return statut;}



    void setAction(const QString newAction) { action=newAction;}
    void setPriorite(const unsigned int newPriorite) {priorite=newPriorite;}
    void setDate_echeance(QDateTime & newDate) {date_echeance=newDate;}
    void setStatut(const Type_statut_tache & newStatut) {statut=newStatut;}

};


#endif // TACHE_H
