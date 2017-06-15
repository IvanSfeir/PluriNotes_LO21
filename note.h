/*!
 * \file note.h
 * \class Note note.h
 * \brief Définit la classe Notes : Permet de d'ajouter, supprimer, restaurer une Version à une Note.
 *
 * \details Design Pattern : Iterator.
 *   \a id : identifiant de la note : \b unique
 *   \a version : tableau de pointeur de Version
 *   \a nbVersion : nombre de versions de la note
 *   \a nbMaxVersion : nombre de versions maximales de la note
 *   \a etat : Etat de la note
 *   \a date_creation : Date de création de la note
 */

#ifndef NOTE_H
#define NOTE_H


#include <QString>
#include <QDateTime>
#include <iostream>

#include "version.h"
#include "iterator.h"
#include "exception.h"

using namespace std;

/*!
 * \brief Enumeration des états des notes
 * \enum Type_etat_note
 * \a active : La note est active
 * \a archive : La note est archivée (supprimée mais encore liée par une relation de Reference)
 * \a sursis : La note est en sursis (supprimée et liée à aucune relation de Reference)
 */
enum Type_etat_note {active, archive, sursis};


/*!
 * \fn string enum_etat_to_string(Type_etat_note t)
 *  \brief : Convertit un Type_etat_note vers une string.
 * @param t : enum à convertir
 * @return  string de l'enum
 */
string enum_etat_to_string(Type_etat_note t);

/*!
 * \fn Type_etat_note string_to_enum_etat(const string &s)
 * \brief Convertit une string vers un Type_etat_note
 * @param s : string à convertir
 * @return enum de la string
 */
Type_etat_note string_to_enum_etat(const string &s);


class Note {
    QString id; //unique
    Version **versions; //tableau de pointeurs vers une version
    unsigned int nbVersion;
    unsigned int nbMaxVersion;
    Type_etat_note etat;
    const QDateTime date_creation=QDateTime::currentDateTime();// initialisation const dans classe ok en C++11

    //Composition => On met le constructeur de recopie et l'opérateur d'affectation en private pour empêcher la duplication de Note
    Note(const Note & n);
    Note & operator=(const Note & n);

public:
    Note(const QString& id, unsigned int nbmax=10, const Type_etat_note &e=active):id(id), etat(e), nbVersion(0), nbMaxVersion(nbmax){
        versions= new Version*[10];
    }
    ~Note();

    const QString &getId() const { return id; }
    unsigned int getNbVersion() const { return nbVersion; }
    unsigned int getNbMaxVersion() const { return nbMaxVersion; }
    const QDateTime & getDateCreation() const { return date_creation; }
    const Type_etat_note &getEtat() const { return etat; }

    void setEtat(const Type_etat_note e){etat=e;}

    Version* getVersion(const unsigned int p);
    Version * getLastVersion() const { return versions[nbVersion];}

/*!
 * \fn     void ajouterVersion(Version *v)
 * \brief
 * @param v : Version d'une note
 */
    void ajouterVersion(Version *v);
    void supprimerVersion(Version *oldVersion);
    void restaurerVersion(const unsigned int p);

    bool is_active(){return etat==active;}
    bool is_archived(){return etat==archive;}
    bool is_reprieved(){return etat==sursis;}


    //implement iterator
    class iterator: public Iterator<Version>{
     friend class Note;
     iterator(Version** c): Iterator(c){}
    };
    iterator begin() {return iterator(versions);}
    iterator end() {return iterator(versions+nbVersion);}

};

//type ostream ? à revoir pour Qt
//ostream& operator<<(ostream& f, const Note& n);// operateur affichage


#endif
