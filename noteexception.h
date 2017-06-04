#ifndef NOTEEXCEPTION_H
#define NOTEEXCEPTION_H

#include <QString>

class NotesException{
public:
    NotesException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};



#endif // NOTEEXCEPTION_H
