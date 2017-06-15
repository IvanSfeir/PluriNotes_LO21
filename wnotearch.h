/*!
 * \file wnotearch.h
 * \class CentreNoteArch wnotearch.h
 * \brief Définit la classe CentreNoteArch : Affiche les versions d'une note archivée
 * \details Hérite de QWidget
 *   \brief versions : Liste des versions de la note archivée
    *\brief afficher : Bouton afficher
    *\brief fermer : Bouton fermer
 */
#ifndef CENTRENOTEARCH_H
#define CENTRENOTEARCH_H

#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "note.h"


class CentreNoteArch : public QWidget {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

    QLabel *titre_id;
    QListWidget *versions;
    QPushButton *afficher;
    QPushButton *fermer;

    QHBoxLayout *horiz;
    QVBoxLayout *verti;


public:
    // argument : la note concernee
    explicit CentreNoteArch(Note *it, QWidget* parent=0);
    QPushButton* getBoutonAfficherVersion() {return afficher;}
    QListWidget* getListVersions() {return versions;}

signals:

private slots:

public slots:

};

#endif // CENTRENOTEARCH_H
