#include <QString>
#include "note.h"
#include <iostream>

using namespace std;


Note::~Note(){
        for (int i=0; i < nbVersion; i++) delete versions[i];
        delete[] versions;
}



Version & Note::getVersion(const QString& title){
    for(unsigned int i=0; i<nbVersion; i++){
        if (versions[i]->getTitle()==title) return *versions[i];
    }
    throw Exception("error, nonexistent version");
}

// à REVOIR si title unique pour Version.
    // Si oui : laisser comme ça
    // Sinon changer
void Note::ajouterVersion(Version * v){
    // recherche si titre existe déjà
    for(unsigned int i=0; i<nbVersion; i++){
        if (versions[i]->getTitle()==v->getTitle()) throw Exception("error, creation of an already existent version");
    }
    // capacité max ?
    if (nbVersion==nbMaxVersion){
        Version** newTab_Version= new Version*[nbMaxVersion+5];
        for(unsigned int i=0; i<nbMaxVersion; i++) newTab_Version[i]=versions[i];
        Version** oldTab_version=versions;
        versions=newTab_Version;
        nbMaxVersion+=5;
        if (oldTab_version) delete[] oldTab_version;
    }
    //ajout de la note
    versions[nbVersion++]=v;
}

void Note::supprimerVersion(Version * oldVersion){
    // recherche si note existe déjà
    unsigned int i=0;
    while((versions[i]->getTitle()!=oldVersion->getTitle()) && i<nbVersion)
    {
        ++i;
    }
    // si la version n'est pas trouvé
    if(i==nbVersion)
        throw Exception("error, deletion of a non existant note.");

    // décalage à gauche du tableau
    for(unsigned int j=i; j<nbVersion-1; j++){
        versions[j]=versions[j+1];
    }

    // suppression de la dernière version (en double) de versions[j=nbVersion-1];
    delete versions[nbVersion];
    delete oldVersion;

    //actualisation du nombre de version
    --nbVersion;
}

// TO DO : Comment/D'où restaurer une Version ??
void Note::restaurerVersion(Version *v)
{
/////////

}







string enum_etat_to_string(Type_etat_note t){
    if (t==active)
        return "active";
    if (t==archive)
        return "archive";
    if (t==sursis)
        return "sursis";
 }

Type_etat_note string_to_enum_etat(const string &s){
    if(s=="active")
        return active;
    if(s=="archive")
        return archive;
    if(s=="sursis")
        return sursis;

}
