#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <QString>
#include <QMediaPlayer>
#include <QPixmap>
#include <QLabel>
#include "version.h"


class Multimedia : public Version {

    QString desc;
    QUrl img_URL;

public:
    Multimedia(const QString & t, QDateTime, d, const QString &desc, const QUrl &i):
        Version(t,d),desc(desc), img_URL(i){}
    ~Multimedia(){}

    QString &getDesc() const {return desc;}
    QUrl & getimg_URL() const{return img_URL;}

    void setDesc(const QString newDesc) {desc=newDesc;}
    void setImg_URL(const QUrl newImg_URL) {img_URL=newImg_URL;}

    void showImg() const;   // ou alors renvoi juste le label pour affichage ensuite dans l'onterface

};


class image : public Multimedia{
    QUrl image;

public:
    image(const QString & t, QDateTime, d, const QString &desc, const QUrl &i, QUrl im):
    Multimedia(t,d,desc,i), image(im) {}
    ~image(){}
};

class audio : public Multimedia{
    QUrl audio_URL;

public:
    audio(const QString & t, QDateTime, d, const QString &desc, const QUrl &i, QUrl au):
    Multimedia(t,d,desc,i), audio_URL(au) {}
    ~audio(){}

    void playAudio() const;
    void pauseAudio() const;
    void stopAudio() const;

};

class video : public Multimedia{
    QUrl video_URL;

public:
    video(const QString & t, QDateTime, d, const QString &desc, const QUrl &i, QUrl vid):
    Multimedia(t,d,desc,i), video_URL(vid) {}
    ~video(){}

    void playVideo() const;
    void pauseVideo() const;
    void stopVideo() const;

};




#endif // MULTIMEDIA_H
