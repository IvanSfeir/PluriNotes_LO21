#ifndef CENTRERELATION_H
#define CENTRERELATION_H

#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

class CentreRelation : public QWidget {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

    QLabel *titre_relation;
    QListWidget *couples;
    QPushButton *ajouter_couple;
    QPushButton *supprimer_couple;
    QPushButton *fermer;

    QHBoxLayout *horiz;
    QVBoxLayout *verti;

public:
    // argument : la relation concernee
    explicit CentreRelation(QMainWindow* parent=0);

signals:

private slots:

public slots:

};

#endif // CENTRERELATION_H
