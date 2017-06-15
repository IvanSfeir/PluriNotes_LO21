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
     * \brief afficherNotes: Action to create Note
     * \details bind this action to button creerNote in menuNotes
     */
    QAction *creerNote;
    /*!
     * \brief afficherNotes: Action to create Note
     * \details bind this action to button creerNote in menuNotes
     */
    QAction *afficherRelations;
    QAction *actionQuitter;

    Note* currentNote;
    Relation* currentRelation;

public:
    Interface();
    QAction *actionCorbeilleAuto;
    void fermer_droite();
    void fermer_gauche();
    void fermer_centre();
    void closeEvent(QCloseEvent *bar);


signals:

private slots:

public slots:
    void avant_de_fermer();
    void ouvrir_relations();
    void ouvrir_relation_details(unsigned int position);
    void ouvrir_creer_relation();
    void ouvrir_gauche();                                   //done
    void ouvrir_note_active_id();                           //done
    void ouvrir_note_archivee_id();                         //done
    void ouvrir_creer_note();                               //working
    void forward_to_create_type();                          //done
    void restaurer_note();
    void restaurer_version();
    //void fermer_centre();
    void ouvrir_version_act();
    void ouvrir_version_arch();
    void sauver_article();
    void creer_relation();
    void ouvrir_couples();
    void ouvrir_creer_couple();
    void creer_couple();


};

#endif // INTERFACE_H
