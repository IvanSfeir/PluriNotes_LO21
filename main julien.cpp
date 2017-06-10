#include "interface.h"
#include "gaucheactives.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Interface interf;
    interf.setFixedSize(1200, 400);

    QString *titre = new QString;
    *titre = "AFFICHAGE DES NOTES ACTIVES :";

    GaucheActives gaucheact(titre, &interf);

    interf.show();
    app.exec();
}
