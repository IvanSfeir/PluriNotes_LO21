#ifndef CENTRERELATIONNONORIENTEE_H
#define CENTRERELATIONNONORIENTEE_H


#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

class CentreRelationNonOrientee : public QWidget {

    Q_OBJECT // macro pour pouvoir utiliser signals et slots

    QLabel *titre_relation;
    QListWidget *couples;
    QPushButton *ajouter_couple;
    QPushButton *supprimer_couple;

    QHBoxLayout *horiz;
    QVBoxLayout *verti;

public:
    // argument : la relation concernee
    explicit CentreRelationNonOrientee(QMainWindow* parent=0);

signals:

private slots:

public slots:

};


#endif // CENTRERELATIONNONORIENTEE_H
