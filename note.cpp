#include <QString>
#include "note.h"

Note::~Note(){
        for (int i=0; i < nbVersion; i++) delete versions[i];
        delete[] versions;
}


NotesManager::~NotesManager(){  // relation de composition avec note => il faut supprimer toutes les notes
    save();
    for(unsigned int i=0; i<nbNotes; i++) delete tab_notes[i];
    delete[] tab_notes;
}


Note& Note::getVersion(const QString& title){
    for(unsigned int i=0; i<nbVersion; i++){
        if (versions[i]->getTitle()==title) return *versions[i];
    }
    throw VersionException("error, nonexistent version");
}

// à REVOIR si title unique pour Version.
    // Si oui : laisser comme ça
    // Sinon changer
void Note::ajouterVersion(Version * v){
    // recherche si titre existe déjà
    for(unsigned int i=0; i<nbVersion; i++){
        if (versions[i]->getTitle()==v->getTitle()) throw VersionException("error, creation of an already existent version");
    }
    // capacité max ?
    if (nbVersion==nbMaxVersion){
        Note** newTab_Version= new Note*[nbMaxVersion+5];
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
        throw NotesException("error, deletion of a non existant note.");

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


void Note::save() const {
    ofstream fout(filename);
    for(unsigned int i=0; i<nbVersion; i++){
        fout<<*versions[i];
    }
    fout.close();
}


ostream& operator<<(ostream& f, const Note& n){
    f<<n.getId()<<endl;
    f<<n.getDateCreation()<<endl;
    f<<n.getEtat()<<endl;
    f<<n.getLastVersion()<<endl;    // titre de la dernière version
    return f;
}

// à ENLEVER si TITLE est non unique
void Note::setVersion_title(const QString &newTitle) {
    // recherche si title existe déjà
    for(unsigned int i=0; i<nbVersion; i++){
        if (versions[i]->getTitle()==newTitle) throw VersionException("error, modification of an already existent title");
    }

    // si new title est unique alors OK
    if(i==nbVersion)
        versions[i]->setTitle(newTitle);

}
