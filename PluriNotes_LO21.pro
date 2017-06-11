QT += widgets
QT += multimedia
QT += gui
QT += xml

QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

SOURCES += \
    main.cpp \
    relation.cpp \
    notesmanager.cpp \
    note.cpp \
    version.cpp \
    multimedia.cpp \
    centrenote.cpp \
    centrerelation.cpp \
    centrerelations.cpp \
    centreversion.cpp \
    droitearborescence.cpp \
    gaucheactives.cpp \
    gauchearchivees.cpp \
    interface.cpp \


HEADERS += \
    iterator.h \
    note.h \
    relation.h \
    noteexception.h \
    notesmanager.h \
    version.h \
    versionexception.h \
    multimedia.h \
    article.h \
    tache.h \
    centrenote.h \
    centrerelation.h \
    centrerelations.h \
    centreversion.h \
    droitearborescence.h \
    gaucheactives.h \
    gauchearchivees.h \
    interface.h
