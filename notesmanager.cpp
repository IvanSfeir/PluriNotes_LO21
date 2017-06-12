#include <typeinfo>
#include <string>

#include <QString>
#include "notesmanager.h"
#include "tache.h"
#include "multimedia.h"
#include "article.h"

using namespace std;

//********* SINGLETON ***************
NotesManager* NotesManager::instance_NotesManager = nullptr;

NotesManager* NotesManager::getInstance(){ //méthode qui vérifie qu'il n'y ait qu'une seule instance de NotesManager
    if(NotesManager::instance_NotesManager==nullptr)   // si l'instance n'existe pas
        NotesManager::instance_NotesManager = new NotesManager;    // on crée une instance
    return NotesManager::instance_NotesManager;
}

void NotesManager::libererInstance(){
    if(NotesManager::instance_NotesManager != nullptr) // si l'instance existe
        delete NotesManager::instance_NotesManager;    // on la supprime
    NotesManager::instance_NotesManager=nullptr;   // réinitialisation à nullptr
}


NotesManager::NotesManager():tab_notes(nullptr),nbNotes(0),nbMaxNotes(50) {}

NotesManager::~NotesManager(){  // relation de composition avec note => il faut supprimer toutes les notes
    saveNotesManager("NotesManager");
    for(unsigned int i=0; i<nbNotes; i++) delete tab_notes[i];
    delete[] tab_notes;
}


Note& NotesManager::getNote(const QString& id){
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
        Note** oldTab_note=tab_notes;
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
/*void NotesManager::restaurerNote(Note * n)
{


}
*/
/*void NotesManager::load(const QString& f) {
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
}*/

/*void NotesManager::save() const {
    ofstream fout(filename);
    for(unsigned int i=0; i<nbNotes; i++){
        fout<<*tab_notes[i];
    }
    fout.close();
}*/



void NotesManager::saveNotesManager(const QString & filename){
    QFile newFile(filename);
    if (!newFile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw  NotesException(QString("Error open file xml: cannot save file"));

    QXmlStreamWriter stream(&newFile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    for (unsigned int i=0; i < nbNotes; i++){
        stream.writeStartElement("Note");
        stream.writeStartElement("id", tab_notes[i]->getId());
        QString s_etat = enum_etat_to_string(tab_notes[i]->getEtat());
        stream.writeStartElement("Type_etat_note", s_etat);
        stream.writeStartElement("Date_creation", tab_notes[i]->getDateCreation().toString("dd.MM.yyyy hh::mm:ss"));
        //if (tab_notes[i]->getOrientee()) stream.writeStartElement("orientation","true");
        //else stream.writeStartElement("orientation","false");
        for (Note::iterator it_note = tab_notes[i]->begin(); it_note != tab_notes[i]->end(); it_note++){
            stream.writeStartElement("Version");
            stream.writeStartElement("Titre", (*it_note)->getTitle());
            stream.writeStartElement("Date_derniere_modification", (*it_note)->getDateModif().toString("dd.MM.yyyy hh::mm:ss"));

            string type_version= typeid((*it_note)).name();
            type_version=type_version.substr(1,type_version.length()-1); // on renvoie le nom du type de l'objet, sans le 1er char (la longueur du nom)

            if (type_version=="image") {

                       //image *img = *(it_note);
                        image *img =  dynamic_cast<image*>(*it_note);
                       stream.writeStartElement("img", img->getImg());
                       stream.writeStartElement("desc",  img-> getDesc());
                       stream.writeStartElement("img_URL",  img->getimg_URL());
                }
            else if(type_version=="audio"){
                        audio *aud = dynamic_cast<audio*>(*it_note);
                       stream.writeStartElement("audio_URL", aud->getAudio_URL());
                       //stream.writeStartElement("playeraudio", enum_statut_to_string( (*it_note)->getImg_URL()));
                       stream.writeStartElement("desc", aud->getDesc());
                       stream.writeStartElement("img_URL", aud->getimg_URL());
               }
            else if(type_version=="video"){
                       video *vid = dynamic_cast<video*>(*it_note);
                       stream.writeStartElement("video_URL", vid->getVideo_URL());
                       stream.writeStartElement("desc", vid->getDesc());
                       stream.writeStartElement("img_URL",  vid->getimg_URL());

}
            else if(type_version=="Tache"){
                        Tache *tach =dynamic_cast<Tache*>(*it_note);
                       stream.writeStartElement("action", tach->getAction());
                       if(tach->getPriorite())
                       {
                           string n = std::to_string((tach->getPriorite()));

                           stream.writeStartElement("priorite", QString::fromStdString(n));
                       }
                       if((tach->getDate_echeance()).QDateTime::isNull()) stream.writeStartElement("Date_echeance", tach->getDate_echeance().toString("dd.MM.yyyy hh::mm:ss"));
                       stream.writeStartElement("statut", enum_statut_to_string( tach->getStatut()));
            }
            else if (type_version=="Article")
            {
                        Article *art=dynamic_cast<Article*>(*it_note);
                       stream.writeStartElement("text", art->getText());
            }

            stream.writeEndElement();
        }
        stream.writeEndElement();
    }
    stream.writeEndElement();
    newFile.close();
}
/*
void NotesManager::saveNotesManager_not_reprieved(const QString & filename){
    QFile newFile(filename);
    if (!newFile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw exception(QString("Error open file xml: cannot save file"));

    QXmlStreamWriter stream(&newFile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    for (unsigned int i=0; i < nbNotes; i++){
        if(*tab_notes[i]->getEtat()!=sursis)
        {
        stream.writeStartElement("Note");
        stream.writeStartElement("id", tab_notes[i]->getId());
        QString s_etat = enum_etat_to_string(tab_notes[i]->getEtat());
        stream.writeStartElement("Type_etat_note", s_etat);
        stream.writeStartElement("Date_creation", tab_notes[i]->getDateCreation().toString("dd.MM.yyyy hh::mm:ss"));
        //if (tab_notes[i]->getOrientee()) stream.writeStartElement("orientation","true");
        //else stream.writeStartElement("orientation","false");

        for (Note::iterator it_note = tab_notes[i]->begin(); it_note != tab_notes[i]->end(); it_note++){
            stream.writeStartElement("Version");
            stream.writeStartElement("Titre", (*it_note)->getTitle());
            stream.writeStartElement("Date_derniere_modification", (*it_note)->getDateModif());

            string type_version= typeid((*it_note)).name();
            type_version=type_version.substr(1,type_version.length()-1); // on renvoie le nom du type de l'objet, sans le 1er char (la longueur du nom)


            switch (type_version) {
                   case "image":
                       stream.writeStartElement("type", "image");
                       stream.writeStartElement("img",  (*it_note)->getImg());
                       stream.writeStartElement("desc", (*it_note)->getDesc());
                       stream.writeStartElement("img_URL", (*it_note)->getImg_URL());
                       break;

                   case "audio":
                       stream.writeStartElement("type", "audio");
                       stream.writeStartElement("audio_URL", (*it_note)->getAudio_URL());
                       //stream.writeStartElement("playeraudio", enum_statut_to_string( (*it_note)->getImg_URL()));
                       stream.writeStartElement("desc", (*it_note)->getDesc());
                       stream.writeStartElement("img_URL", (*it_note)->getImg_URL());
                       break;
                   case "video":
                       stream.writeStartElement("type", "video");
                       stream.writeStartElement("video_URL",  (*it_note)->getVideo_URL());
                       stream.writeStartElement("desc", (*it_note)->getDesc());
                       stream.writeStartElement("img_URL", (*it_note)->getImg_URL());
                       break;

                   case "Tache":
                       stream.writeStartElement("type", "Tache");
                       stream.writeStartElement("action", (*it_note)->getAction());
                       if((*it_note)->getPriorite()) stream.writeStartElement("priorite", (*it_note)->getPriorite());
                       if((*it_note)->getDate_echeance()) stream.writeStartElement("Date_echeance", (*it_note)->getDate_echeance().toString("dd.MM.yyyy hh::mm:ss"));
                       stream.writeStartElement("statut", enum_statut_to_string( (*it_note)->getStatut()));
                       break;
                   case "Article":
                      stream.writeStartElement("type", "Article");
                       stream.writeStartElement("text", (*it_note)->getText());
                       break;
                    }

            stream.writeEndElement();
        }
        stream.writeEndElement();
    }
    stream.writeEndElement();
    newFile.close();
    }
    }

/*QString dateStr = "2014-03-18 09:30:36";
QString fmt = "yyyy-MM-dd hh:mm:ss";
QDateTime dt = QDateTime::fromString(dateStr, fmt);
QString timeStr = dt.toString("hh:mm");
*/
/*
void NotesManager::loadNotesManager(const QString & filename){
    QFile loadFile(filename);
    if (!loadFile.open(QIODevice::ReadOnly | QIODevice::Text))
        throw exception(QString("Error open file xml: cannot load file"));
    QXmlStreamReader xml(&loadFile);

    while(!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        if(token == QXmlStreamReader::StartDocument) continue;
         while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "Note")){
            xml.readNext();
            if (xml.tokenString() == QXmlStreamReader::StartElement){
                QString id;
                QString etat;
                QDateTime date_creation;
                QString s_date;
                bool orientee;
                if (xml.name() == "id"){
                    xml.readNext();
                    id = xml.text().toString();
                }
                if (xml.name() == "Type_etat_note"){
                    xml.readNext();
                    etat = xml.text().toString();
                }
                if (xml.name() == "Date_creation"){
                    xml.readNext();
                    s_date=xml.text().toString();
                    s_date=QDateTime::fromString(s_date); // voir la doc
                }

                Version* vers;
                if (titre == "\ref") relation = relations[0];
                else relation = new RelationNormale(titre, description, orientee);
                //loop to get Couple
                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "couple")){
                    QString label;
                    QString note1;
                    QString note2;
                    if (xml.tokenString() == QXmlStreamReader::StartElement){
                        if (xml.name() == "label"){
                            xml.readNext();
                            label=xml.text().toString();
                        }
                        if (xml.name() == "note1"){
                            xml.readNext();
                            note1=xml.text().toString();
                        }
                        if (xml.name() == "note2"){
                            xml.readNext();
                            note2=xml.text().toString();
                        }
                    }
                    xml.readNext();
                    Couple* newCouple = new Couple(&NotesManager->getNote(note1), &NotesManager->getNote(note2), label);
                    relation->ajouterCouple(newCouple);
                }
                if (titre != "\ref") ajouterRelation(relation);
            }
        }
    }
    if(xml.hasError()) {
        throw exception("Error parsing xml : cannot read file");
    }
    xml.clear();
}
*/
