#ifndef ARTICLE_H
#define ARTICLE_H

#include "version.h"

class Article : public Version{
    QString text;

public:
    Article(const QString & t, QDateTime d, const QString &tx):
        Version(t,d), text(tx){}
    ~Article(){}

    const QString & getText() const {return text;}
    void setText(const QString & newText) {text=newText;}

};



#endif // ARTICLE_H
