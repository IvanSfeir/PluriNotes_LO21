/*!
 * \file wgauche.h
 * \class Gauche wgauche.h
 * \brief Définit la classe Gauche : Affichage des notes actives et archivées
 * \details Hérite de QWidget
 *   \brief notes_actives : Liste des notes actives
 *   \brief notes_archivees : Liste des notes archivées
    *\brief bouton_afficher_act: Bouton afficher notes actives
    *\brief bouton_afficher_arch: Bouton afficher notes archivées
    *\brief restaurer : Bouton restaurer
    *\brief arborescence : Bouton arborescence
 */
#ifndef GAUCHE_H
#define GAUCHE_H

#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QObject>
#include <QMainWindow>
#include "notesmanager.h"
#include "note.h"
#include "wnoteact.h"
#include "wnotearch.h"

#include <QListWidget>
#include <QComboBox>


class Gauche : public QWidget {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots



    QLabel *titre_act;
    QVBoxLayout *couche;
    QListWidget *notes_actives;
    QPushButton *bouton_afficher_act;
    QLabel *titre_arch;
    QComboBox *notes_archivees;
    QPushButton *bouton_afficher_arch;
    QPushButton *restaurer;
    QHBoxLayout *button_box;
    QPushButton *arborescence;
    QHBoxLayout* button_arch_box;


public:
    explicit Gauche(QMainWindow* parent=0);
    QListWidget* getNotesActives() {return notes_actives;}
    QPushButton* getBoutonAfficherAct() {return bouton_afficher_act;}
    QComboBox* getNotesArchivees() {return notes_archivees;}
    QPushButton* getBoutonAfficherArch() {return bouton_afficher_arch;}
    QPushButton* getBoutonAfficherArboresence() {return arborescence;}
    QPushButton* getBoutonRestaurer() {return restaurer;}




signals:

private slots:


public slots:

};

#endif // GAUCHE_H
