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
    mCentralCircle = po::scene::Shape::createCircle(200.f);
    mCentralCircle->setFillColor(mCentralCircleColor);
    mCentralCircle->setPosition( glm::vec2(187.5f, 253.f) );
    mCentralCircle->setAlignment(po::scene::Alignment::CENTER_CENTER);
    addChild(mCentralCircle);

}

//void CentralCircle::showDog()
//{
//    mMask = Shape::createCircle(60.f);
//    mMask->setAlignment(po::scene::Alignment::CENTER_CENTER);
//    
//    ci::gl::TextureRef dogTexture = ci::gl::Texture::create(ci::loadImage (ci::app::loadAsset("cat.jpg")));
//    mImage = Image::create(dogTexture);
//    mImage->setAlignment(po::scene::Alignment::CENTER_CENTER);
//    addChild(mImage);
//    setMask(mMask);
//}
//
//void CentralCircle::showCat()
//{
//    
//}
//
//void CentralCircle::showBird()
//{
//    
//}
//
//void CentralCircle::showRabbit()
//{
//    
//}
//
//void CentralCircle::update()
//{
//}

