/*!
 *  \file NotesManager.h
 *  \brief Définit la classe NotesManager : Permet de d'ajouter, supprimer, restaurer une Note. Permet de sauvegarder/charger la session dans/à partir d'un fichier XML.
 *
 *  \details Design Pattern : Singleton et Iterator.
 *   \a tab_notes : tableau de pointeur de Notes
 *   \a nbNotes : nombre de notes dans tab_notes
 *   \a nbMaxNotes : nombre de notes maximales dans tab_notes
 */
#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H



#include "note.h"
#include <QString>
#include <QDebug>
#include "iterator.h"
#include "version.h"
#include "relation.h"
#include "notesmanager.h"
#include <Qstring>

#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>



class NotesManager {

private:
    Note** tab_notes;
    unsigned int nbNotes;
    unsigned int nbMaxNotes;


    NotesManager();
    ~NotesManager();

    //****** SINGLETON ******

    NotesManager(const NotesManager& m){}    // empêche recopie pour singleton et composition
    NotesManager& operator=(const NotesManager& m){} // empêche affectation et composition

    /*!
 *  \brief
 * @param m
 */
    static NotesManager * instance_NotesManager;

public:
    Note* getNote(const QString& id);
    void ajouterNote(Note* n);
    void supprimerNote(Note* oldNote);
    void restaurerNote(const QString & id);

    bool is_bin_empty();
    bool is_archived_in_bin();
    bool is_note_refed(const QString & id); //cherche si une note est référencée ou non

    // ******** ITERATOR *************
    //class iterator<Note,NotesManager>;
    //iterator begin() {return iterator(tab_notes);}
    //iterator end() {return iterator(tab_notes+nbNotes);}
    //iterator getIterator() const{
    //        return iterator(tab_notes, nbNotes);
    //    }

    //implement iterator
    class iterator: public Iterator<Note>{
     friend class NotesManager;
     iterator(Note** c): Iterator(c){}
    };
    iterator begin() {return iterator(tab_notes);}
    iterator end() {return iterator(tab_notes+nbNotes);}

    // ********* SINGLETON *************
    static NotesManager* getInstance();
    static void libererInstance();

    void loadNotesManager(const QString & filename); 
    void saveNotesManager(const QString & filename);
    void saveNotesManager_no_reprieve(const QString & filename);

    bool is_id_taken(const QString &id);
};


    
#endif // NOTESMANAGER_H
