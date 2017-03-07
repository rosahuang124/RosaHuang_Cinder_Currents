#include "VideoPlayer.h"


VideoPlayerRef VideoPlayer::create()
{
    VideoPlayerRef ref = std::shared_ptr<VideoPlayer>(new VideoPlayer());
    ref->setup();
    return ref;
}

VideoPlayer::VideoPlayer()
{
}

void VideoPlayer::setup()
{
}

void VideoPlayer::keyDown( KeyEvent event )
{
    if( event.getChar() == 'o' ) {
        fs::path videoPath = getOpenFilePath();
        if( ! videoPath.empty() )
            loadVideoFile( videoPath );
    }
}

void VideoPlayer::loadVideoFile(const fs::path &videoPath)
{
    try {
        mMovie = qtime::MovieGl::create( videoPath );
        mMovie->setLoop();
        mMovie->play();
    }
    catch( std::exception& e ) {
        ci::app::console() << "Failed to play video: " << e.what() << std::endl;
        mMovie.reset();
    }
    
    mFrameTexture.reset();}

void VideoPlayer::fileDrop(FileDropEvent event)
{
    loadVideoFile(event.getFile(0));
}

void VideoPlayer::update()
{
    if(mMovie){
        mFrameTexture = mMovie->getTexture();
    }
}

void VideoPlayer::play()
{
    if(mMovie){
        mMovie->play();
    }

}

void VideoPlayer::stop()
{
    if(mMovie){
        mMovie->stop();
    }
}

bool VideoPlayer::isPause()
{
    if(mMovie->isPlaying()){
        return false;
    } else {
        return true;
    }
}


void VideoPlayer::setLoop(bool bIsLoop)
{
    if (mMovie) {
        mMovie->setLoop();
    }
}



void VideoPlayer::draw()
{
    ci::Rectf videoModule = ci::Rectf(0,0, getWindowWidth(), getWindowHeight()*0.9f);
    
    if(mFrameTexture){
        ci::Rectf centeredRect = ci::Rectf( mFrameTexture->getBounds() ).getCenteredFit(videoModule, true );
        
        ci::gl::draw( mFrameTexture, centeredRect );
        
    }
}


