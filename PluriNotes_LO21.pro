QT += widgets
QT += multimedia
QT += gui
QT += xml
QT += core

QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

SOURCES += \
    main.cpp \
    relation.cpp \
    notesmanager.cpp \
    note.cpp \
    version.cpp \
    multimedia.cpp \
    centrenoteact.cpp \
    centrerelationorientee.cpp \
    centrerelationnonorientee.cpp \
    centrerelations.cpp \
    centreversion.cpp \
    droitearborescence.cpp \
    gauche.cpp \
    interface.cpp \
    centrenotearch.cpp \
    centreversionarticle.cpp


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
    centrenoteact.h \
    centrerelationorientee.h \
    centrerelationnonorientee.h \
    centrerelations.h \
    centreversion.h \
    droitearborescence.h \
    gauche.h \
    interface.h \
    centrenotearch.h \
    centreversionarticle.h
