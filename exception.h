#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>

class Exception{
public:
    Exception(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};



#endif // NOTEEXCEPTION_H
