#ifndef ARTICLE_H
#define ARTICLE_H

#include "version.h"

class Article : public Version{
    QString text;

public:
    Article(const QString & t, QDateTime, d, const QString &t):
        Version(t,d), text(t){}
    ~Article(){}

    QString & getText() const {return text;}
    void setText(const QString & newText) {text=newText;}

};



#endif // ARTICLE_H
