
#include "CircleSample.h"

using namespace po::scene;

CircleSampleRef CircleSample::create()
{
    CircleSampleRef node(new CircleSample());
    node->setup();
    return node;
}

void CircleSample::setup()
{
    
    // Bear--------------
    mBearCircle = Circle::create("Bear", ci::Color(80.f/255, 227.f/255, 194.f/255));
    mBearCircle->setPosition(ci::vec2(116.f, 183.f));
    mBearCircle->getCircleStateChangeSignal();
    addChild(mBearCircle);
    

    // Dinosaur--------------
    mDinosaurCircle = Circle::create("Dinosaur", ci::Color(248.f/255, 150.f/255, 128.f/255));
    mDinosaurCircle->setPosition(ci::vec2(258.f, 183.f));
    mDinosaurCircle->getCircleStateChangeSignal();
    addChild(mDinosaurCircle);
    
    // Hedgehog--------------
    mHedgeHogCircle = Circle::create("Hedgehog", ci::Color(255.f/255, 160.f/255, 78.f/255));
    mHedgeHogCircle->setPosition(ci::vec2(116.f, 324.f));
    mHedgeHogCircle->getCircleStateChangeSignal();
    addChild(mHedgeHogCircle);
    
    // Tiger--------------
    mTigerCircle = Circle::create("Tiger", ci::Color(201.f/255, 234.f/255, 124.f/255));
    mTigerCircle->setPosition(ci::vec2(258.f, 324.f));
    mTigerCircle->getCircleStateChangeSignal();
    addChild(mTigerCircle);
    
}

bool CircleSample::bearIsActive()
{
    if ( mBearCircle-> mIsActivated == true) {
        return true;
    } else {
        return false;
    }
}


