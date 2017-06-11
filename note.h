#if !defined(_NOTES_H)
#define _NOTES_H


#include <QString>
#include <QDateTime>
#include <iostream>

#include "version.h"
#include "iterator.h"
#include "noteexception.h"
#include "notesmanager.h"

#include "versionexception.h"
//using namespace std;

enum Type_etat_note {active, archive, sursis};

class Version;

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
    const QDateTime & getDateCreation() const { return date_creation; }
    const Type_etat_note &getEtat() const { return etat; }

    void setEtat(const Type_etat_note e){etat=e;}

    Version& getVersion(const QString& title);
    const QString &getLastVersion() const {return versions[nbVersion]->getTitle();}

    void setVersion_title(const QString &newtitle);

    void ajouterVersion(Version *v);
    void supprimerVersion(Version *oldVersion);
    void restaurerVersion(Version *v);



    void save() const;


    // ********* ITERATOR ********
    class iterator_version : public iterator<Version,Note>{
    iterator_version begin() {return iterator_version(versions);}
    iterator_version end() {return iterator_version(versions+nbVersion);}
    iterator_version getIterator() const{
            return iterator_version(versions, nbVersion);
        }
};


}

//type ostream ? à revoir pour Qt
ostream& operator<<(ostream& f, const Note& n);// operateur affichage


#endif
