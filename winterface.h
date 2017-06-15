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
#include <QCloseEvent>

class Interface : public QMainWindow {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots



    Gauche* window_gauche=0;
    CentreNoteAct* window_note_act=0;
    CentreNoteArch* window_note_arch=0;
    WindowCreerNote* window_creer_note=0;
    CentreRelations* window_relations=0;
    CentreRelationDetails* window_relation_details=0;
    WindowCreerRelation* window_creer_relation=0;
    WindowCreerArticle* window_creer_article=0;
    WindowCreerImage* window_creer_image=0;
    WindowCreerVideo* window_creer_video=0;
    WindowCreerAudio* window_creer_audio=0;
    WindowCreerTache* window_creer_tache=0;
    WindowAfficherArticle* window_afficher_article=0;
    WindowAfficherImage* window_afficher_image=0;
    WindowAfficherAudio* window_afficher_audio=0;
    WindowAfficherVideo* window_afficher_video=0;


    QMenu *menuNotes;
    QMenu *menuRelations;
    QMenu *menuCorbeille;
    QMenu *menuQuitter;

    QAction *afficherNotes;
    QAction *creerNote;
    QAction *afficherRelations;
    QAction *actionQuitter;

    Note* currentNote;

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
    //void sauver_article();
    void creer_relation();

};

#endif // INTERFACE_H
