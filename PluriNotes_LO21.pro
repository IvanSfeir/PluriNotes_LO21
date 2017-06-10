QT += widgets
QT += multimedia
QT += gui
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

SOURCES += \
    main.cpp \
    relation.cpp \
    notesmanager.cpp \
    note.cpp \
    version.cpp \
    multimedia.cpp

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
    tache.h
