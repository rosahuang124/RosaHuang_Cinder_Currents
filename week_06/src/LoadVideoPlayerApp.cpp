#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"
#include "cinder/qtime/QuickTimeGl.h"

#include "VideoPlayer.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class LoadVideoPlayerApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void button() ;
    void switchButton( bool isPause() );
    VideoPlayerRef mPlayer;
    
    
    ci::Surface8u       mSurfacePlay;
    ci::Surface8u       mSurfacePause;
    
    gl::TextureRef      mTexFromSurface;
    gl::TextureRef      mTexPlayFromSurface;
    gl::TextureRef      mTexPauseFromSurface;
    
    Rectf uiModule();
    Rectf buttonRect();
};

void LoadVideoPlayerApp::setup()
{
    mPlayer = VideoPlayer::create();
    mPlayer-> loadVideoFile(getOpenFilePath());

    //load UI button img
    try {
        mSurfacePlay = loadImage(loadAsset("play.png"));
        mSurfacePause = loadImage(loadAsset("pause.png"));
    } catch (exception& e) {
        ci::app::console() << e.what() << std::endl;
    }
    
}

Rectf LoadVideoPlayerApp::uiModule()
{
    return Rectf( 0, getWindowHeight() * 0.9f, getWindowWidth(), getWindowHeight());
}

Rectf LoadVideoPlayerApp::buttonRect()
{
    return Rectf( mSurfacePlay.getBounds() ). getCenteredFit (uiModule(), true);
}



void LoadVideoPlayerApp::mouseDown( MouseEvent event )
{
    if (event.isLeft()){
        if ((mPlayer->isPause()) == true){
            mPlayer->play();
        }else{
            mPlayer->stop();
        };
    }
}


void LoadVideoPlayerApp::update()
{
    mPlayer->update();
}

void LoadVideoPlayerApp::draw()
{
	gl::clear( Color( 0.5, 0, 0.5 ) );
    mPlayer->draw();
    
    ci::gl::color(1, 1, 1);
    gl::drawSolidRect(uiModule());
    
    mTexPlayFromSurface = gl::Texture::create(mSurfacePlay);
    mTexPauseFromSurface = gl::Texture::create(mSurfacePause);
    
    if(mPlayer->isPause()){
        mTexFromSurface = mTexPlayFromSurface;
    }else{
        mTexFromSurface = mTexPauseFromSurface;
    }
    gl::draw(mTexFromSurface, buttonRect());
}

CINDER_APP( LoadVideoPlayerApp, RendererGl )
