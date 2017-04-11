#pragma once

#include "poNodeContainer.h"
#include "poShape.h"
#include "CircleSample.h"
#include "poImage.h"

class CentralCircle;
typedef std::shared_ptr<CentralCircle> CentralCircleRef;

class CentralCircle:
public po::scene::NodeContainer
{
public:
    static CentralCircleRef create();
    void setup();
//    void showDog();
//    void showCat();
//    void showBird();
//    void showRabbit();
//    void update();
    
private:
    po::scene::ShapeRef mCentralCircle;
    ci::Color mCentralCircleColor = ci::Color::hex(0xF9D900);
    
//    po::scene::ShapeRef         mMask;
//    po::scene::ImageRef         mImage;
//    ci::gl::TextureRef          mTexture;
    
};

