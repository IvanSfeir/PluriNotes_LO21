#include <QApplication>

#include "note.h"
#include "version.h"
#include "tache.h"
#include "relation.h"

#include "winterface.h"
#include "wgauche.h"
#include "wnoteact.h"
#include "wnotearch.h"
#include "wrelations.h"
#include "wrelationdetails.h"

int main(int argc, char* argv[]) {


    //static CentreNoteAct centrenoteact=0;
    //static CentreNoteArch centrenotearch=0;

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    Interface* interface = new Interface();

    interface->setFixedSize(1200, 400);

    //Gauche gauche(interface);
    //gauche.show();
    //gauche.move(0,20);

    //CentreNoteAct centrenoteact(&interface);
    //centrenoteact.show();
    //centrenoteact.move(400,20);

    //CentreNoteArch centrenotearch(interface);
    //centrenotearch.show();
    //centrenotearch.move(400,20);

    //CentreRelations centrerelations(interface);
    //centrenotearch.show();
    //centrerelations.move(800,15);

    //CentreRelationNonOrientee centrerelationnonorientee(interface);
    //centrerelationnonorientee.move(800,205);

    //CentreRelationDetails centre(interface);
    //centre.show();

    interface->show();



    return app.exec();
    return 0;
}
