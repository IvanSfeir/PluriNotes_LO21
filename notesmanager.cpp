#include <typeinfo>
#include <string>

#include <QString>
#include "notesmanager.h"
#include "tache.h"
#include "multimedia.h"
#include "article.h"
#include "note.h"

using namespace std;

//********* SINGLETON ***************
NotesManager* NotesManager::instance_NotesManager = nullptr;

NotesManager* NotesManager::getInstance(){ //méthode qui vérifie qu'il n'y ait qu'une seule instance de NotesManager
    if(NotesManager::instance_NotesManager==nullptr)  // si l'instance n'existe pas
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
    throw Exception("error, nonexistent note");
}

void NotesManager::ajouterNote(Note * n){
    // recherche si note existe déjà
    for(unsigned int i=0; i<nbNotes; i++){
        if (tab_notes[i]->getId()==n->getId()) throw Exception("error, creation of an already existent note");
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
        throw Exception("error, deletion of a non existant note.");

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
    if (!fin) throw Exception("error, file does not exist");
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
        throw  Exception(QString("Error open file xml: cannot save file"));

    QXmlStreamWriter stream(&newFile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    for (unsigned int i=0; i < nbNotes; i++){
      stream.writeStartElement("Note");
        stream.writeStartElement("id", tab_notes[i]->getId());
        QString nbV;
        QString nbMaxV;
        nbV.setNum(tab_notes[i]->getNbVersion());
        nbMaxV.setNum(tab_notes[i]->getNbMaxVersion());
        stream.writeStartElement("nbVersion", nbV);
        stream.writeStartElement("nbMaxVersion", nbMaxV);
        string s_etat = enum_etat_to_string(tab_notes[i]->getEtat());
        stream.writeStartElement("Type_etat_note", QString::fromStdString( s_etat));
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
                        image *img =  dynamic_cast<image*>(*it_note);
                        stream.writeStartElement("type", "image");
                       stream.writeStartElement("img", img->getImg());
                       stream.writeStartElement("desc",  img-> getDesc());
                       stream.writeStartElement("img_URL",  img->getimg_URL());
                }
            else if(type_version=="audio"){
                        audio *aud = dynamic_cast<audio*>(*it_note);
                        stream.writeStartElement("type", "audio");
                       stream.writeStartElement("audio_URL", aud->getAudio_URL());
                       //stream.writeStartElement("playeraudio", enum_statut_to_string( (*it_note)->getImg_URL()));
                       stream.writeStartElement("desc", aud->getDesc());
                       stream.writeStartElement("img_URL", aud->getimg_URL());
               }
            else if(type_version=="video"){
                       video *vid = dynamic_cast<video*>(*it_note);
                       stream.writeStartElement("type", "video");
                       stream.writeStartElement("video_URL", vid->getVideo_URL());
                       stream.writeStartElement("desc", vid->getDesc());
                       stream.writeStartElement("img_URL",  vid->getimg_URL());

}
            else if(type_version=="Tache"){
                        Tache *tach =dynamic_cast<Tache*>(*it_note);
                        stream.writeStartElement("type", "Tache");
                       stream.writeStartElement("action", tach->getAction());
                       if(tach->getPriorite())
                       {
                           string n = std::to_string((tach->getPriorite()));

                           stream.writeStartElement("priorite", QString::fromStdString(n));
                       }
                       if((tach->getDate_echeance()).QDateTime::isNull()) stream.writeStartElement("Date_echeance", tach->getDate_echeance().toString("dd.MM.yyyy hh::mm:ss"));
                       string s_statut=enum_statut_to_string( tach->getStatut());
                       stream.writeStartElement("statut", QString::fromStdString(s_statut));
            }
            else if (type_version=="Article")
            {
              stream.writeStartElement("type", "Article");
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

void NotesManager::saveNotesManager_no_reprieve(const QString & filename){
        QFile newFile(filename);
        if (!newFile.open(QIODevice::WriteOnly | QIODevice::Text))
            throw  Exception(QString("Error open file xml: cannot save file"));

        QXmlStreamWriter stream(&newFile);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        for (unsigned int i=0; i < nbNotes; i++){
            if(!(tab_notes[i]->is_reprieved())) // si la note n'est pas en sursis
            {
            stream.writeStartElement("Note");
            stream.writeStartElement("id", tab_notes[i]->getId());
            QString nbV;
            QString nbMaxV;
            nbV.setNum(tab_notes[i]->getNbVersion());
            nbMaxV.setNum(tab_notes[i]->getNbMaxVersion());
            stream.writeStartElement("nbVersion", nbV);
            stream.writeStartElement("nbMaxVersion", nbMaxV);
            string s_etat = enum_etat_to_string(tab_notes[i]->getEtat());
            stream.writeStartElement("Type_etat_note", QString::fromStdString( s_etat));
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
                            image *img =  dynamic_cast<image*>(*it_note);
                            stream.writeStartElement("type", "image");
                           stream.writeStartElement("img", img->getImg());
                           stream.writeStartElement("desc",  img-> getDesc());
                           stream.writeStartElement("img_URL",  img->getimg_URL());
                    }
                else if(type_version=="audio"){
                            audio *aud = dynamic_cast<audio*>(*it_note);
                            stream.writeStartElement("type", "audio");
                           stream.writeStartElement("audio_URL", aud->getAudio_URL());
                           //stream.writeStartElement("playeraudio", enum_statut_to_string( (*it_note)->getImg_URL()));
                           stream.writeStartElement("desc", aud->getDesc());
                           stream.writeStartElement("img_URL", aud->getimg_URL());
                   }
                else if(type_version=="video"){
                           video *vid = dynamic_cast<video*>(*it_note);
                           stream.writeStartElement("type", "video");
                           stream.writeStartElement("video_URL", vid->getVideo_URL());
                           stream.writeStartElement("desc", vid->getDesc());
                           stream.writeStartElement("img_URL",  vid->getimg_URL());

    }
                else if(type_version=="Tache"){
                            Tache *tach =dynamic_cast<Tache*>(*it_note);
                            stream.writeStartElement("type", "Tache");
                           stream.writeStartElement("action", tach->getAction());
                           if(tach->getPriorite())
                           {
                               string n = std::to_string((tach->getPriorite()));

                               stream.writeStartElement("priorite", QString::fromStdString(n));
                           }
                           if((tach->getDate_echeance()).QDateTime::isNull()) stream.writeStartElement("Date_echeance", tach->getDate_echeance().toString("dd.MM.yyyy hh::mm:ss"));
                           string s_statut=enum_statut_to_string( tach->getStatut());
                           stream.writeStartElement("statut", QString::fromStdString(s_statut));
                }
                else if (type_version=="Article")
                {
                  stream.writeStartElement("type", "Article");
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
}
/*QString dateStr = "2014-03-18 09:30:36";
QString fmt = "yyyy-MM-dd hh:mm:ss";
QDateTime dt = QDateTime::fromString(dateStr, fmt);
QString timeStr = dt.toString("hh:mm");
*/

void NotesManager::loadNotesManager(const QString & filename){
  NotesManager *NM= NotesManager::getInstance();
    QFile loadFile(filename);
    if (!loadFile.open(QIODevice::ReadOnly | QIODevice::Text))
        throw Exception(QString("Error open file xml: cannot load file"));
    QXmlStreamReader xml(&loadFile);

    while(!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        if(token == QXmlStreamReader::StartDocument) continue;
         while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "Note")){
            xml.readNext();
            if (xml.tokenString() == QXmlStreamReader::StartElement){
                QString id;
                QString s_etat;
                QDateTime date_creation;
                QString s_date;
                QString nbVersion;
                QString nbMaxVersion;
                Type_etat_note etat;
                unsigned int nbV;
                unsigned int nbMaxV;
                if (xml.name() == "id"){
                    xml.readNext();
                    id = xml.text().toString();
                }
                if (xml.name() == "nbVersion"){
                    xml.readNext();
                    nbVersion = xml.text().toString();
                    nbV=nbVersion.toInt(0,10);//int dec = str.toInt(&ok, 10);       // dec == 0, ok == false
                }
                if (xml.name() == "nbMaxVersion"){
                    xml.readNext();
                    nbMaxVersion = xml.text().toString();
                    nbMaxV=nbMaxVersion.toInt(0,10);//int dec = str.toInt(&ok, 10);       // dec == 0, ok == false

                }
                if (xml.name() == "Type_etat_note"){
                    xml.readNext();
                    s_etat = xml.text().toString();
                    etat=string_to_enum_etat(s_etat.QString::toStdString());

                }
                if (xml.name() == "Date_creation"){
                    xml.readNext();
                    s_date=xml.text().toString();
                    date_creation=QDateTime::fromString(s_date, "dd.MM.yyyy hh::mm:ss"); // voir la doc

                }
                Note * newNote= new Note(id,nbMaxV,etat);
                NM->ajouterNote(newNote);

                // if (titre == "\ref") relation = relations[0];
                // else relation = new RelationNormale(titre, description, orientee);
                //loop to get Couple
                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "Version")){
                    QString titre;
                    QString s_datemodif;
                    QDateTime dateModif;
                  if (xml.tokenString() == QXmlStreamReader::StartElement){
                        if (xml.name() == "Titre"){
                            xml.readNext();
                            titre=xml.text().toString();

                        }
                        if (xml.name() == "Date_derniere_modification"){
                            xml.readNext();
                            s_datemodif=xml.text().toString();
                            dateModif=QDateTime::fromString(s_datemodif, "dd.MM.yyyy hh::mm:ss"); // voir la doc

                        }

                        QString type_version;  //get the type of the object
                        if (xml.name() == "type"){
                            xml.readNext();
                            type_version=xml.text().toString();
                        }
                        if (type_version=="image") {
                         image *newImg;
                         QString img;
                         QString img_URL;
                         QString desc;

                         newImg->setTitle(titre);
                         newImg->setDate(dateModif);
                         if (xml.name() == "desc"){
                             xml.readNext();
                             desc=xml.text().toString();
                              newImg->setDesc(desc);
                         }

                          if (xml.name() == "img"){
                              xml.readNext();
                              img=xml.text().toString();
                              newImg->setImg(img);
                          }

                          if (xml.name() == "img_URL"){
                              xml.readNext();
                              img_URL=xml.text().toString();
                              newImg->setImg_URL(img_URL);
                          }

                         newNote->ajouterVersion(newImg);

                            }
                        else if(type_version=="audio"){
                            audio *newAudio;
                            QString aud_URL;
                            QString img_URL;
                            QString desc;

                            newAudio->setTitle(titre);
                            newAudio->setDate(dateModif);
                            if (xml.name() == "desc"){
                                xml.readNext();
                                desc=xml.text().toString();
                                 newAudio->setDesc(desc);
                            }
                            if (xml.name() == "img_URL"){
                                xml.readNext();
                                img_URL=xml.text().toString();
                                newAudio->setImg_URL(img_URL);
                            }
                             if (xml.name() == "audio_URL"){
                                 xml.readNext();
                                 aud_URL=xml.text().toString();
                                 newAudio->setAudio_URL(aud_URL);
                             }



                            newNote->ajouterVersion(newAudio);
                           }
                        else if(type_version=="video"){
                          audio *newVid;
                          QString vid_URL;
                          QString img_URL;
                          QString desc;

                          newVid->setTitle(titre);
                          newVid->setDate(dateModif);
                          if (xml.name() == "desc"){
                              xml.readNext();
                              desc=xml.text().toString();
                               newVid->setDesc(desc);
                          }
                          if (xml.name() == "img_URL"){
                              xml.readNext();
                              img_URL=xml.text().toString();
                              newVid->setImg_URL(img_URL);
                          }
                           if (xml.name() == "audio_URL"){
                               xml.readNext();
                               vid_URL=xml.text().toString();
                               newVid->setAudio_URL(vid_URL);
                           }
                          newNote->ajouterVersion(newVid);

                        }
                        else if(type_version=="Tache"){
                          Tache *newTache;                          
                          string s_stat;
                          QString etat;
                          QString action;
                          QString s_prio;
                          QString s_date_e;
                          QDateTime date_e;

                          newTache->setTitle(titre);
                          newTache->setDate(dateModif);
                          if (xml.name() == "action"){
                              xml.readNext();
                              action=xml.text().toString();
                               newTache->setAction(action);
                          }
                          if (xml.name() == "statut"){
                              xml.readNext();
                              etat=xml.text().toString();
                              s_stat=etat.QString::toStdString();
                              newTache->setStatut(string_to_enum_statut(s_stat));
                          }
                           if (xml.name() == "priorite"){
                               xml.readNext();
                               s_prio=xml.text().toString();
                               newTache->setPriorite(s_prio.toInt(0,10));
                           }
                           if (xml.name() == "Date_echeance"){
                               xml.readNext();
                               s_date_e=xml.text().toString();
                               date_e=QDateTime::fromString(s_date_e, "dd.MM.yyyy hh::mm:ss"); // voir la doc
                               newTache->setDate_echeance(date_e);
                           }
                          newNote->ajouterVersion(newTache);
                        }
                        else if (type_version=="Article")
                        {
                          Article *newArt;
                          QString txt;


                          newArt->setTitle(titre);
                          newArt->setDate(dateModif);
                          if (xml.name() == "text"){
                              xml.readNext();
                              txt=xml.text().toString();
                               newArt->setText(txt);
                          }

                          newNote->ajouterVersion(newArt);
                        }
                    }
                    xml.readNext();
                }                
            }
        }
    }
    if(xml.hasError()) {
        throw Exception("Error parsing xml : cannot read file");
    }
    xml.clear();
}
