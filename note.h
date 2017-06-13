#ifndef NOTE_H
#define NOTE_H


#include <QString>
#include <QDateTime>
#include <iostream>

#include "version.h"
#include "iterator.h"
#include "noteexception.h"
//#include "notesmanager.h"

#include "versionexception.h"
//using namespace std;

enum Type_etat_note {active, archive, sursis};

char* enum_etat_to_string(Type_etat_note t);

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
    const QString &getNbVersion() const { return nbVersion; }
    const QString &getNbMaxVersion() const { return nbMaxVersion; }
    const QDateTime & getDateCreation() const { return date_creation; }
    const Type_etat_note &getEtat() const { return etat; }

    void setEtat(const Type_etat_note e){etat=e;}

    Version& getVersion(const QString& title);
    QString getLastVersion() const { return versions[nbVersion]->getTitle();}


    void ajouterVersion(Version *v);
    void supprimerVersion(Version *oldVersion);
    void restaurerVersion(Version *v);

    bool is_active(){return etat==active;}
    bool is_archived(){return etat==archive;}
    bool is_reprieved(){return etat==sursis;}



    // ********* ITERATOR ********
    //class iterator_version : public iterator<Version,Note>{
    //iterator_version begin() {return iterator_version(versions);}
    //iterator_version end() {return iterator_version(versions+nbVersion);}
    //iterator_version getIterator() const{
    //        return iterator_version(versions, nbVersion);
    //    }
//};
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
