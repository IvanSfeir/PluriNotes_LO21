#include "notesmanager.h"
#include <QString>


//********* SINGLETON ***************
NotesManager* NotesManager::instance = nullptr;

NotesManager& NotesManager::getInstance(){ //méthode qui vérifie qu'il n'y ait qu'une seule instance de NotesManager
    if(NotesManager::instance==nullptr)   // si l'instance n'existe pas
        NotesManager::instance = new NotesManager;    // on crée une instance
    return *NotesManager::instance;
}

void NotesManager::libererInstance(){
    if(NotesManager::instance != nullptr) // si l'instance existe
        delete NotesManager::instance;    // on la supprime
    NotesManager::instance=nullptr;   // réinitialisation à nullptr
}


NotesManager::NotesManager():tab_notes(nullptr),nbNotes(0),nbMaxNotes(50) {}

NotesManager::~NotesManager(){  // relation de composition avec note => il faut supprimer toutes les notes
    save();
    for(unsigned int i=0; i<nbNotes; i++) delete tab_notes[i];
    delete[] tab_notes;
}


Note& NotesManager::getNote(const Qstring& id){
    for(unsigned int i=0; i<nbNotes; i++){
        if (tab_notes[i]->getId()==id) return *tab_notes[i];
    }
    throw NotesException("error, nonexistent note");
}

void NotesManager::ajouterNote(Note * n){
    // recherche si note existe déjà
    for(unsigned int i=0; i<nbNotes; i++){
        if (tab_notes[i]->getId()==n->getId()) throw NotesException("error, creation of an already existent note");
    }
    // capacité max ?
    if (nbNotes==nbMaxNotes){
        Note** newTab_Note= new Note*[nbMaxNotes+10];
        for(unsigned int i=0; i<nbMaxNotes; i++) newTab_Note[i]=tab_notes[i];
        Article** oldTab_note=tab_notes;
        tab_notes=newTab_Note;
        nbMaxNotes+=10;
        if (oldTab_note) delete[] oldTab_note;
    }
    //ajout de la note
    tab_notes[nbNotes++]=n;
}

void NotesManager::supprimerNote(Note * oldNote){
    // recherche si note existe déjà
    unsigned int i=0;
    while((tab_notes[i]->getId()!=oldNote->getId()) && i<nbNotes)
    {
        ++i;
    }
    // si la note n'est pas trouvé
    if(i==nbNotes)
        throw NotesException("error, deletion of a non existant note.");

    // décalage à gauche du tableau
    for(unsigned int j=i; j<nbNotes-1; j++){
        tab_notes[j]=tab_notes[j+1];
    }

    // suppression de la dernière note (en double) de tab_notes[j=nbNotes-1];
    delete tab_notes[nbNotes];
    delete oldNote;

    //actualisation du nombre de notes
    --nbNotes;
}

// TO DO : D'où restaurer une note ??
void NotesManager::restaurerNote(Note * n)
{


}

void NotesManager::load(const Qstring& f) {
    if (filename!=f) save();
    filename=f;
    ifstream fin(filename); // open file
    if (!fin) throw NotesException("error, file does not exist");
    while(!fin.eof()&&fin.good()){
        char tmp[1000];
        fin.getline(tmp,1000); // get id on the first line
        if (fin.bad()) throw NotesException("error reading note id on file");
        Qstring id=tmp;
        fin.getline(tmp,1000); // get title on the next line
        if (fin.bad()) throw NotesException("error reading note title on file");
        Qstring title=tmp;
        fin.getline(tmp,1000); // get text on the next line
        if (fin.bad()) throw NotesException("error reading note text on file");
        Qstring text=tmp;
        Note* n=new Note(id,title,text);
        ajouterNote(n);
        if (fin.peek()=='\r') fin.ignore();
        if (fin.peek()=='\n') fin.ignore();
    }
    fin.close(); // close file
}

void NotesManager::save() const {
    ofstream fout(filename);
    for(unsigned int i=0; i<nbNotes; i++){
        fout<<*tab_notes[i];
    }
    fout.close();
}




