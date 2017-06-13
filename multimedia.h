#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <QString>
#include <QApplication>
#include <QMediaPlayer>
#include <QPixmap>
#include <QLabel>
//#include <QVideoWidget>
#include "version.h"


class Multimedia : public Version {

    QString desc;
    QString img_URL;

public:
    Multimedia(const QString & t, QDateTime d, const QString &desc, const QString &i):
        Version(t,d),desc(desc), img_URL(i){}
    ~Multimedia(){}

    const QString& getDesc() const {return desc;}
    const QString & getimg_URL() const{return img_URL;}

    void setDesc(const QString& newDesc) {desc=newDesc;}
    void setImg_URL(const QString& newImg_URL) {img_URL=newImg_URL;}

    void showImg() const;   // ou alors renvoi juste le label pour affichage ensuite dans l'onterface

};


class image : public Multimedia{
    QString img;    //=img_URL de Multimedia
    
public:
    image(const QString & t, QDateTime d, const QString &desc, const QString &i):
    Multimedia(t,d,desc,i), img(i) {}
    ~image(){}

    const QString & getImg() const {return img;}
    void setImg(const QString & img_URL) {img=img_URL;}

};

class audio : public Multimedia{
    QString audio_URL;
    QMediaPlayer* playeraudio;

public:
    audio(const QString & t, QDateTime d, const QString &desc, const QString &i, QString au):
    Multimedia(t,d,desc,i), audio_URL(au) {}
    ~audio(){}

    void playAudio() const;
    void pauseAudio() const;
    void stopAudio() const;

    const QString&  getAudio_URL() const {return audio_URL;}
    void  setAudio_URL(const QString & aud_URL) {audio_URL=aud_URL;}
};

class video : public Multimedia{
    QString video_URL;
    QMediaPlayer* playervideo;
    QMediaPlaylist* playlist;
public:
    video(const QString & t, QDateTime d, const QString &desc, const QString &i, QString vid):
    Multimedia(t,d,desc,i), video_URL(vid) {}
    ~video(){}

    void playVideo() const;
    void pauseVideo() const;
    void stopVideo() const;

    const QString&  getVideo_URL() const {return video_URL;}


};




#endif // MULTIMEDIA_H
