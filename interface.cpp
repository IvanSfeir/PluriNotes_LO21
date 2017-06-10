#include "interface.h"

Interface::Interface() {
    QMenu *menuNotes = menuBar()->addMenu("Notes");
    QMenu *menuRelations = menuBar()->addMenu("Relations");
    QMenu *menuCorbeille = menuBar()->addMenu("Corbeille");

}
