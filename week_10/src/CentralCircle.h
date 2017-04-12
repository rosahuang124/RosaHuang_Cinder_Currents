#pragma once

#include "poNodeContainer.h"
#include "poShape.h"
#include "poImage.h"
#include "CircleSample.h"

class CentralCircle;
typedef std::shared_ptr<CentralCircle> CentralCircleRef;

class CentralCircle:
public po::scene::NodeContainer
{
public:
    static CentralCircleRef create();
    void setup();
    void onCircleStateChange(bool state);
    void showBear();
    void showDinosaur();
    void showHedgehog();
    void showTiger();
//    void update();
    
private:
    
    
    po::scene::ShapeRef         mMask;
    po::scene::ImageRef         mImage;
    
    ci::gl::TextureRef bearTexture;
    ci::gl::TextureRef dinosaurTexture;
    ci::gl::TextureRef hedgehogTexture;
    ci::gl::TextureRef tigerTexture;
    
//    CircleSampleRef checkCircle;
    
};

