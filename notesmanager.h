/*!
 *  \file NotesManager.h
 *  \brief Définit la classe NotesManager : Permet de d'ajouter, supprimer, restaurer une Note. Permet de sauvegarder/charger la session dans/à partir d'un fichier XML.
 *
 *  \details Design Pattern : Singleton et Iterator.
 *   \a tab_notes : tableau de pointeur de Notes
 *   \a nbNotes : nombre de notes dans tab_notes
 *   \a nbMaxNotes : nombre de notes maximales dans tab_notes
 *   \a instance_NotesManager : Instance static de NotesManager
 */
#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H



#include "note.h"
#include <QString>
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

    static NotesManager * instance_NotesManager;

public:
    Note* getNote(const QString& id);
    /*!
     *  \brief Fontion pour ajouter des notes
     * @param n : Pointeur vers la note à ajouter
     */
    void ajouterNote(Note* n);

    /*!
     * \brief Supprimer une note : change l'état de la note de active à en sursis ou archivé
     * @param oldNote : La note à supprimer
     */
    void supprimerNote(Note* oldNote);

    /*!
     * \brief Restaurer une note : change l'état de la note à active
     * @param id : L'id de la note à restaurer
     */
    void restaurerNote(const QString & id);

    /*!
     * \brief Cherche s'il y a des notes supprimées et en sursis
     * @return 1 s'il y a des notes en sursis, 0 sinon
     */
    bool is_bin_empty();
    \/*!
     * Cherche s'il y a des notes supprimées et archivées
     * @return  1 s'il y a des notes archivées, 0 sinon
     */
    bool is_archived_in_bin();
    /*!
     * Cherche si la note est impliquée dans une relation \b Reference
     * @param id : id d'une note
     * @return 1 si la note est référencée, 0 sinon
     */
    bool is_note_refed(const QString & id); //cherche si une note est référencée ou non

    /*!
     * \class Template method pour la classe Iterator sur une note
     */
    class iterator: public Iterator<Note>{
     friend class NotesManager;
     iterator(Note** c): Iterator(c){}
    };
    iterator begin() {return iterator(tab_notes);}
    iterator end() {return iterator(tab_notes+nbNotes);}

    // ********* SINGLETON *************
    /*!
     *
     * @return Pointeur sur l'instance singleton NotesManager
     */
    static NotesManager* getInstance();
    /*!
     * \brief Libère l'instance singleton NotesManager
     */
    static void libererInstance();

    /*!
     * \brief Charge les notes à partir d'un fichier XML
     * @param filename : Nom du fichier XML à charger
     */
    void loadNotesManager(const QString & filename);
    /*!
     * \brief Enregistre les notes dans un fichier XML
     * @param filename : Le nom du fichier XML où les notes seront sauvegardées
     */
    void saveNotesManager(const QString & filename);
    /*!
     *  \brief Enregistre les notes \b qui ne sont pas en sursis dans un fichier XML
     * @param filename : Le nom du fichier XML où les notes seront sauvegardées
     */
    void saveNotesManager_no_reprieve(const QString & filename);

/*!
 * \brief Cherche si l'id d'une note est unique ou non.
 * @param id : L'id de la note
 * @return 1 si l'id est déjà pris, 0 sinon
 */
bool is_id_taken(const QString &id);
};



#endif // NOTESMANAGER_H
