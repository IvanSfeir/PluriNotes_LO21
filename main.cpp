#include <QApplication>
/*
#include "note.h"
#include "version.h"
#include "tache.h"
#include "relation.h"
*/
#include "interface.h"
#include "gauche.h"
#include "centrenoteact.h"
#include "centrenotearch.h"

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    Interface interface;
    interface.setFixedSize(1200, 400);

    Gauche gauche(&interface);
    //gauche.show();
    gauche.move(0,20);
/*
    CentreNoteAct centrenoteact(&interface);
    //centrenoteact.show();
    centrenoteact.move(400,20);
*/
    CentreNoteArch centrenotearch(&interface);
    //centrenotearch.show();
    centrenotearch.move(400,20);


    interface.show();







    return app.exec();
}
