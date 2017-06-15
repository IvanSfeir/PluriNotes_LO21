#include <QString>
#include "note.h"
#include <iostream>

using namespace std;


Note::~Note(){
        for (int i=0; i < nbVersion; i++) delete versions[i];
        delete[] versions;
}



Version *Note::getVersion(const unsigned int p){
    if(p>nbVersion)
        throw Exception("error, nonexistent version");
    else
        return versions[p];


}

// à REVOIR si title unique pour Version.
    // Si oui : laisser comme ça
    // Sinon changer
void Note::ajouterVersion(Version * v){
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


void Note::restaurerVersion(const unsigned int p)
{
Version *v=getVersion(p);
this->ajouterVersion(v);

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
