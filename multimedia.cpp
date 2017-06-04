#include "multimedia.h"


void Multimedia::showImg() const{
    QPixmap img(img_URL);
    QLabel label;

    label.setPixmap(img);

    label.show()
}

//QPixmap pm("path/to/your/image.jpg");
//  QLabel lbl;
//  lbl.setPixmap(pm);
//  lbl.show();
//  return app.exec();

void audio::startAudio() const {
    QMediaPlayer player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile(audio_URL));
    //player->setVolume(50);
    player->play();
}

void audio::pauseAudio() const {
    QMediaPlayer::pause();

}

void audio::stopAudio() const {
    QMediaPlayer::stop();
}

void video::playVideo() const { // with QVideoWidget
    QMediaPlayer player = new QMediaPlayer;

    playlist = new QMediaPlaylist(player);
    playlist->addMedia(QUrl(video_URL));

    videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);

    videoWidget->show();
    playlist->setCurrentIndex(1);
    player->play();


}

void video::pauseVideo() const {
    QMediaPlayer::pause();

}

void video::stopVideo() const {
    QMediaPlayer::stop();
}
