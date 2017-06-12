#ifndef VERSION_H
#define VERSION_H


#include <QString>
#include <QDateTime>
#include <QDate>
#include <QTime>

#include "versionexception.h"

class Version {
    QString title;
    QDateTime date_modif;
public:
    Version(const QString &t, const QDateTime & d): title(t), date_modif(d){}
    virtual ~Version()=0;

    virtual QString getTitle() const {return title;}
    virtual QDateTime getDateModif() const{return date_modif;}

    virtual void setTitle(const QString &newTitle){title=newTitle;}

};

#endif // VERSION_H
