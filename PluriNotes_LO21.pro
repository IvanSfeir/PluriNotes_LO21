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
    wnoteact.cpp \
    wrelationdetails.cpp \
    wrelations.cpp \
    wversion.cpp \
    warborescence.cpp \
    wgauche.cpp \
    winterface.cpp \
    wnotearch.cpp \
    wversionarticle.cpp \
    tache.cpp


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
    wnoteact.h \
    wrelationdetails.h \
    wrelations.h \
    wversion.h \
    warborescence.h \
    wgauche.h \
    winterface.h \
    wnotearch.h \
    wversionarticle.h
