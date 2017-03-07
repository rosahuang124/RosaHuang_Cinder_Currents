#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Surface.h"
#include "cinder/qtime/QuickTimeGl.h"


#include <stdio.h>


#pragma once

using namespace ci;
using namespace ci::app;
using namespace std;


class VideoPlayer;

typedef std::shared_ptr<VideoPlayer> VideoPlayerRef;

class VideoPlayer
{
public:
    static VideoPlayerRef create();
    void setup();
    void loadVideoFile( const cinder::fs::path &videoPath );
    void keyDown( KeyEvent event );
    void fileDrop( FileDropEvent event );
    void update();
    void play();
    void stop();
    void setLoop(bool bIsLoop);
    void draw();
    
    bool isPause();

    
    
    
private:
    VideoPlayer();
    
    ci::gl::TextureRef      mFrameTexture;
    ci::qtime::MovieGlRef   mMovie;
    
};
