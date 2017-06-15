/*!
 *@file     winterface.h
 *@author   Ngo Sy Toan
 * @date    June 2017
 * @brief   The main window
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>
#include <QAction>
#include<typeinfo>

#include "NotesManager.h"
#include "relation.h"
#include "wrelations.h"
#include "wrelationdetails.h"
#include "wnoteact.h"
#include "wnotearch.h"
#include "wversion.h"
#include "wgauche.h"
#include "wcreernote.h"
#include "wcreerarticle.h"
#include "wcreerimage.h"
#include "wcreeraudio.h"
#include "wcreervideo.h"
#include "wcreertache.h"
#include "wafficherarticle.h"
#include "windowcreerrelation.h"
#include "wafficherimage.h"
#include "hafficheraudio.h"
#include "haffichervideo.h"
#include "waffichertache.h"
#include "waffichercouple.h"
#include "wcreercouple.h"
#include <QCloseEvent>

/*!
 * \brief The Interface class: heritate QMainWindow, this class is MainWindow of the program
 * \details All the widgets and events happen inside the Interface
 */
class Interface : public QMainWindow {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots


    /*!
     * \brief initilize widget to view note active and note archived
     */
    Gauche* window_gauche=0;
    /*!
     * \brief initilize widget to view note active and its versions
     */
    CentreNoteAct* window_note_act=0;
    /*!
     * \brief initilize widget to view note acrchived and its version
     */
    CentreNoteArch* window_note_arch=0;
    /*!
     * \brief initilize widget to create new note
     */
    WindowCreerNote* window_creer_note=0;
    /*!
     * \brief initilize widget to create new relation
     */
    CentreRelations* window_relations=0;
    /*!
     * \brief initilize widget to create new relation
     */
    WindowCreerRelation* window_creer_relation=0;
    /*!
     * \brief initilize widget to create new couple
     */
    WindowCreerCouple* window_creer_couple=0;
    /*!
     * \brief initilize widget to create new note - Type Article
     */
    WindowCreerArticle* window_creer_article=0;
    /*!
     * \brief initilize widget to create new note - Type Image
     */
    WindowCreerImage* window_creer_image=0;
    /*!
     * \brief initilize widget to create new note - Type Video
     */
    WindowCreerVideo* window_creer_video=0;
    /*!
     * \brief initilize widget to create new note - Type Audio
     */
    WindowCreerAudio* window_creer_audio=0;
    /*!
     * \brief initilize widget to create new note - Type Tache
     */
    WindowCreerTache* window_creer_tache=0;
    /*!
     * \brief initilize widget to view note - Type Article
     */
    WindowAfficherArticle* window_afficher_article=0;
    /*!
     * \brief initilize widget to view new note - Type Image
     */
    WindowAfficherImage* window_afficher_image=0;
    /*!
     * \brief initilize widget to view new note - Type Audio
     */
    WindowAfficherAudio* window_afficher_audio=0;
    /*!
     * \brief initilize widget to view new note - Type Video
     */
    WindowAfficherVideo* window_afficher_video=0;
    /*!
     * \brief initilize widget to view new note - Type Tache
     */
    WindowAfficherTache* window_afficher_tache=0;
    /*!
     * \brief initilize widget to view couples of a Relation
     */
    WindowAfficherCouple* window_afficher_couples=0;


    /*!
     * \brief menuNotes: menu for Note on the headline bar
     */
    QMenu *menuNotes;
    /*!
     * \brief menuRelations: menu for Relation on the headline bar
     */
    QMenu *menuRelations;
    /*!
     * \brief menuCorbeille: menu for Corbeille on the headline bar
     */
    QMenu *menuCorbeille;
    /*!
     * \brief menuQuitter: menu to quit the program
     */
    QMenu *menuQuitter;
    /*!
     * \brief afficherNotes: Action to view all the Notes
     * \details bind this action to button AfficherNotes in menuNotes
     */
    QAction *afficherNotes;
    /*!
     * \brief creerNote: Action to create Note
     * \details bind this action to button creerNote in menuNotes
     */
    QAction *creerNote;
    /*!
     * \brief afficherRelations: Action to view Relations
     * \details bind this action to button affricherRelations in menuRelations
     */
    QAction *afficherRelations;
    /*!
     * \brief actionQuitter: Action to turn off the program
     * \details bind this action to button quitter in menuQuitter
     */
    QAction *actionQuitter;

    /*!
     * \brief currentNote: current Note choosing in the ListNotes
     */
    Note* currentNote;
    /*!
     * \brief currentRelation: current Relation choosing in the ListRelations
     */
    Relation* currentRelation;

public:
    /*!
     * \brief Interface: initilize the Interface
     */
    Interface();
    /*!
     * \brief actionCorbeilleAuto: this action bind to check to empty Corbeille when close program
     */
    QAction *actionCorbeilleAuto;
    /*!
     * \brief fermer_droite: close whatever widgets which are opened on the right side of the Interface
     */
    void fermer_droite();
    /*!
     * \brief fermer_gauche: close whatever widgets which are opened on the left side of the Interface
     */
    void fermer_gauche();
    /*!
     * \brief fermer_centre: close whatever widgets which are opened on the centre of the Interface
     */
    void fermer_centre();
    /*!
     * \brief closeEvent: handle Event when click close button at the up-right corner of the Interface
     * \param bar: pointer to buttons
     */
    void closeEvent(QCloseEvent *bar);


signals:

private slots:

public slots:
    /*!
     * \brief avant_de_fermer: action perform before close totally program
     */
    void avant_de_fermer();
    /*!
     * \brief ouvrir_relations: construct and show widget to view all the Relations
     */
    void ouvrir_relations();
    /*!
     * \brief ouvrir_creer_relation: construct and show widget to create Relation
     */
    void ouvrir_creer_relation();
    /*!
     * \brief ouvrir_gauche: construct and show widget to view all the notes (active and archived)
     */
    void ouvrir_gauche();                                   //done
    /*!
     * \brief ouvrir_note_active_id: construct and show widget to view note active with its versions
     */
    void ouvrir_note_active_id();                           //done
    /*!
     * \brief ouvrir_note_archivee_id: construct and show widget to view note archived with its versions
     */
    void ouvrir_note_archivee_id();                         //done
    /*!
     * \brief ouvrir_creer_note: construct and show widget to create a new note
     */
    void ouvrir_creer_note();                               //done
    /*!
     * \brief forward_to_create_type: construct and show widget form accordingly to the type of the note
     */
    void forward_to_create_type();                          //done
    /*!
     * \brief restaurer_note: restore the note which is archived
     */
    void restaurer_note();
    /*!
     * \brief restaurer_version: restore a version of a note active
     */
    void restaurer_version();
    /*!
     * \brief ouvrir_version_act: construct and show widget to view inside a version of a note active
     */
    void ouvrir_version_act();
    /*!
     * \brief ouvrir_version_act: construct and show widget to view inside a version of a note archived
     */
    void ouvrir_version_arch();
    /*!
     * \brief sauver_article: save an Article
     */
    void sauver_article();
    /*!
     * \brief creer_relation: construct and show widget to create new relation
     */
    void creer_relation();
    /*!
     * \brief ouvrir_couples: construct and show widget to view couples inside a relation
     */
    void ouvrir_couples();
    /*!
     * \brief ouvrir_creer_couple: construct and show widget to create new couple
     */
    void ouvrir_creer_couple();
    /*!
     * \brief ouvrir_creer_couple: construct and show widget to create new couple
     */
    void creer_couple();


};

#endif // INTERFACE_H
