/*!
 * \file tache.h
 * \class Tache tache.h
 * \brief Définit la classe Tache
 * \details Hérite de \b Version
 *      \a action : Action de la tâche
 *      \a statut : Statut de la tâche
 *      \a priorite : Priorité de la tâche (optionnelle)
 *      \a date_echeance : date d'échaance de la tâche (optionnelle)
 */
#ifndef TACHE_H
#define TACHE_H



#include "version.h"
#include <QDateTime>
#include <iostream>

using namespace std;

/*!
 * \brief Enumeration des statut des tâches
 * \enum Type_statut_tache
 * \a en_cours : La tache est en cours.
 * \a attente : La tache est en attente (par défaut).
 * \a terminee : La tache est en terminée.
 */
enum Type_statut_tache {en_cours, attente, terminee};


/*!
 * \fn string enum_statut_to_string(Type_statut_tache t);
 *  \brief : Convertit un Type_statut_tache vers une string.
 * @param t : enum à convertir
 * @return  string de l'enum
 */
string enum_statut_to_string(Type_statut_tache t);

/*!
 * \fn Type_statut_tache string_to_enum_statut(const string &s);
 * \brief Convertit une string vers un Type_statut_tache
 * @param s : string à convertir
 * @return enum de la string
 */
Type_statut_tache string_to_enum_statut(const string &s);

/*!
 * \fn QString enum_statut_to_qstring(Type_statut_tache t);
 *  \brief : Convertit un Type_statut_tache vers une string.
 * @param t : enum à convertir
 * @return  Qstring de l'enum
 */
QString enum_statut_to_qstring(Type_statut_tache t);

/*!
 * \fn Type_statut_tache qstring_to_enum_statut(const QString &s);
 * \brief Convertit une string vers un Type_statut_tache
 * @param s : Qstring à convertir
 * @return enum de la string
 */
Type_statut_tache qstring_to_enum_statut(const QString &s);

class Tache : public Version{
    QString action;
    Type_statut_tache statut;
    unsigned int priorite;  //optionnelle
    QDateTime date_echeance;    //optionnelle



public:
    Tache(const QString &t, QDateTime d, const QString &a, const Type_statut_tache &s=attente): //valeur NULL possible avec QDate ?
        Version(t,d), action(a), statut(s){}       

    ~Tache(){}

    // Getteurs
    QString getAction() const {return action;}
    unsigned int getPriorite() const {return priorite;}
    QDateTime getDate_echeance() const {return date_echeance;}
    Type_statut_tache getStatut() const {return statut;}

    //Setteurs
    void setAction(const QString newAction) { action=newAction;}
    void setPriorite(const unsigned int newPriorite) {priorite=newPriorite;}
    void setDate_echeance(QDateTime & newDate) {date_echeance=newDate;}
    void setStatut(const Type_statut_tache & newStatut) {statut=newStatut;}

};


#endif // TACHE_H
