/*!
 * \file multimedia.h
 * \class Multimedia multimedia.h
 * \brief Définit la classe Multimedia et ses classes filles (image, audio, video)
 * \details Classe abstraite
 *      \a desc: Description
 *      \a img_URL : Fichier image
 */

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
    ~virtual Multimedia()=0;

    const QString& getDesc() const {return desc;}
    const QString & getimg_URL() const{return img_URL;}

    void setDesc(const QString& newDesc) {desc=newDesc;}
    void setImg_URL(const QString& newImg_URL) {img_URL=newImg_URL;}

    /*!
     * Affiche le fichier image
     */
    void showImg() const;

};

/*!
 * \class image multimedia.h
 * \brief Classe image hérite de Multimedia
 * \details Note image
 * \a img : QString lien vers le fichier image. Ce lien est identique à celui de Multimedia
 */
class image : public Multimedia{
    QString img;    //=img_URL de Multimedia
    
public:
    image(const QString & t, QDateTime d, const QString &desc, const QString &i):
    Multimedia(t,d,desc,i), img(i) {}
    ~image(){}

    const QString & getImg() const {return img;}
    void setImg(const QString & img_URL) {img=img_URL;}

};

/*!
 * \class audio multimedia.h
 * \brief Classe audio hérite de Multimedia
 * \details Note audio
 * \a img : QString lien vers le fichier audio.
 */
class audio : public Multimedia{
    QString audio_URL;
    QMediaPlayer* playeraudio;

public:
    audio(const QString & t, QDateTime d, const QString &desc, const QString &i, QString au):
    Multimedia(t,d,desc,i), audio_URL(au) {}
    ~audio(){}

    /*!
     * Lance le fichier audio
     */
    void playAudio() const;

    /*!
     * Met en pause le fichier audio
     */
    void pauseAudio() const;

    /*!
     * Stop le fichier audio en cours de lecture
     */
    void stopAudio() const;

    const QString&  getAudio_URL() const {return audio_URL;}
    void  setAudio_URL(const QString & aud_URL) {audio_URL=aud_URL;}
};

/*!
 * \class video multimedia.h
 * \brief Classe video hérite de Multimedia
 * \details Note video
 * \a img : QString lien vers le fichier video.
 */
class video : public Multimedia{
    QString video_URL;
    QMediaPlayer* playervideo;
    QMediaPlaylist* playlist;
public:
    video(const QString & t, QDateTime d, const QString &desc, const QString &i, QString vid):
    Multimedia(t,d,desc,i), video_URL(vid) {}
    ~video(){}

    const QString&  getVideo_URL() const {return video_URL;}

    /*!
     * Lance le fichier video
     */
    void playVideo() const;
    /*!
     * Met en pause le fichier audio
     */
    void pauseVideo() const;
    /*!
     * Stop le fichier video
     */
    void stopVideo() const;



};




#endif // MULTIMEDIA_H
