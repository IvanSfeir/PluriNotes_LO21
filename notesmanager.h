/*!
 *
 */
#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H



#include "note.h"
#include <QString>
#include "iterator.h"
#include "version.h"

class Note;

class NotesManager {

private:
    Note** tab_notes;
    unsigned int nbNotes;
    unsigned int nbMaxNotes;


    NotesManager();
    ~NotesManager();

    //****** SINGLETON ******
    /*!
     *
     * @param m
     */
    NotesManager(const NotesManager& m);    // empêche recopie pour singleton et composition
    NotesManager& operator=(const NotesManager& m); // empêche affectation et composition
    static NotesManager * instance_NotesManager;

public:
    Note& getNote(const QString& id);
    void ajouterNote(Note* n);
    void supprimerNote(Note* oldNote);
    void restaurerNote(Note* n);

    // à conserver pour XML ?
    void load(const QString& f);
    void save() const;


    // ******** ITERATOR *************
    class iterator<Note,NotesManager>;
    iterator begin() {return iterator(tab_notes);}
    iterator end() {return iterator(tab_notes+nbNotes);}
    iterator getIterator() const{
            return iterator(tab_notes, nbNotes);
        }

    // ********* SINGLETON *************
    static NotesManager* getInstance();
    static void libererInstance();


//    class const_iterator{
//            Article **current;
//            const_iterator(Article **a):current(a){}

//            friend class NotesManager;
//        public:
//            const_iterator():current(nullptr){}

//            const Article &operator*() const {
//                return **current;
//            }

//            const_iterator &operator++(){
//                ++current;
//                return *this;
//            }

//            bool operator!=(const_iterator it) const{
//                return current != it.current;
//            }

//        };
//    const_iterator getIterator() const{
//            return const_iterator(tab_notes, nbNotes);
//        }

};



#endif // NOTESMANAGER_H
