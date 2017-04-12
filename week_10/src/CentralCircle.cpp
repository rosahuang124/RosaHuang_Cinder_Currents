#include "CentralCircle.h"

using namespace po::scene;

CentralCircleRef CentralCircle::create()
{
    CentralCircleRef circle(new CentralCircle());
    circle->setup();
    return circle;
}

void CentralCircle::setup()
{
    bearTexture = ci::gl::Texture::create(ci::loadImage (ci::app::loadAsset("bear.jpg")));
    dinosaurTexture = ci::gl::Texture::create(ci::loadImage (ci::app::loadAsset("dinosaur.jpg")));
    hedgehogTexture = ci::gl::Texture::create(ci::loadImage (ci::app::loadAsset("hedgehog.jpg")));
    tigerTexture = ci::gl::Texture::create(ci::loadImage (ci::app::loadAsset("tiger.jpg")));

//    CircleSampleRef checkCircle;
//    if(checkCircle->bearIsActive() == true)
//    {
//        showBear();
//        std::cout<<"bear is actived"<<std::endl;
//    }
    showBear();

}



void CentralCircle::showBear()
{
    mMask = po::scene::Shape::createCircle(180.f);
    mMask->setPosition( glm::vec2(187.5f, 253.f) );
    mMask->setAlignment(po::scene::Alignment::CENTER_CENTER);
    mMask->setDrawBounds(false);
    
    mImage = po::scene::Image::create(bearTexture);
    mImage->setPosition( glm::vec2(187.5f, 253.f) );
    mImage->setAlignment(po::scene::Alignment::CENTER_CENTER);
    addChild(mImage);
    setMask(mMask);

}

void CentralCircle::showDinosaur()
{
    mMask = po::scene::Shape::createCircle(180.f);
    mMask->setPosition( glm::vec2(187.5f, 253.f) );
    mMask->setAlignment(po::scene::Alignment::CENTER_CENTER);
    mMask->setDrawBounds(false);
    
    mImage = po::scene::Image::create(dinosaurTexture);
    mImage->setPosition( glm::vec2(187.5f, 253.f) );
    mImage->setAlignment(po::scene::Alignment::CENTER_CENTER);
    addChild(mImage);
    setMask(mMask);
    
}

void CentralCircle::showHedgehog()
{
    mMask = po::scene::Shape::createCircle(180.f);
    mMask->setPosition( glm::vec2(187.5f, 253.f) );
    mMask->setAlignment(po::scene::Alignment::CENTER_CENTER);
    mMask->setDrawBounds(false);
    
    mImage = po::scene::Image::create(hedgehogTexture);
    mImage->setPosition( glm::vec2(187.5f, 253.f) );
    mImage->setAlignment(po::scene::Alignment::CENTER_CENTER);
    addChild(mImage);
    setMask(mMask);
    
}

void CentralCircle::showTiger()
{
    mMask = po::scene::Shape::createCircle(180.f);
    mMask->setPosition( glm::vec2(187.5f, 253.f) );
    mMask->setAlignment(po::scene::Alignment::CENTER_CENTER);
    mMask->setDrawBounds(false);
    
    mImage = po::scene::Image::create(tigerTexture);
    mImage->setPosition( glm::vec2(187.5f, 253.f) );
    mImage->setAlignment(po::scene::Alignment::CENTER_CENTER);
    addChild(mImage);
    setMask(mMask);
}



