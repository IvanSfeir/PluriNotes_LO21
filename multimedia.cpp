#include "multimedia.h"


void Multimedia::showImg() const{
    QPixmap img(img_URL);
    QLabel label;

    label.setPixmap(img);

    label.show();
}

//QPixmap pm("path/to/your/image.jpg");
//  QLabel lbl;
//  lbl.setPixmap(pm);
//  lbl.show();
//  return app.exec();

void audio::playAudio() const {
    QMediaPlayer* playeraudio = new QMediaPlayer;

    playeraudio->setMedia(QUrl::fromLocalFile(audio_URL));
    //player->setVolume(50);
    playeraudio->play();
}

void audio::pauseAudio() const {
    if (playeraudio->state() == QMediaPlayer::PlayingState)
        playeraudio->QMediaPlayer::pause();
}

void audio::stopAudio() const {
    playeraudio->QMediaPlayer::stop();
}

void video::playVideo() const { // with QVideoWidget
    QMediaPlayer* playervideo = new QMediaPlayer;

    //QVideoWidget* videoWidget = new QVideoWidget;
    //playervideo->setVideoOutput(videoWidget);

    playervideo->setMedia(QUrl::fromLocalFile(video_URL));
    //videoWidget->show();
    playervideo->play();

}

void video::pauseVideo() const {
    playervideo->QMediaPlayer::pause();

}

void video::stopVideo() const {
    playervideo->QMediaPlayer::stop();
}
