#ifndef VERSIONEXCEPTION_H
#define VERSIONEXCEPTION_H

#include <QString>

class VersionException{
public:
    VersionException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};



#endif // VERSIONEXCEPTION_H
