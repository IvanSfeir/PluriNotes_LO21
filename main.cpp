#include <QApplication>
#include "note.h"
#include "version.h"
#include "tache.h"
#include "relation.h"
#include "interface.h"
#include "gauche.h"

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    Interface interf;
    interf.setFixedSize(1200, 400);



    Gauche gauche(&interf);
    gauche.show();
    gauche.move(0,20);


    interf.show();







    return app.exec();
}
