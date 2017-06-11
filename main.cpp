#include <QApplication>
#include "note.h"
#include "version.h"
#include "tache.h"
#include "relation.h"
#include "interface.h"
#include "gauche.h"
#include "centrenoteact.h"

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    Interface interface;
    interface.setFixedSize(1200, 400);

    Gauche gauche(&interface);
    gauche.show();
    gauche.move(0,20);

    CentreNoteAct centrenoteact(&interface);
    centrenoteact.move(400,70);


    interface.show();







    return app.exec();
}
