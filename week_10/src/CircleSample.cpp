
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
    
    // Dog--------------
    mDogCircle = Circle::create("DOG", ci::Color(80.f/255, 227.f/255, 194.f/255));
    mDogCircle->setPosition(ci::vec2(116.f, 183.f));
    mDogCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::colorAnimation, mDogCircle));
    mDogCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::rotationAnimation, mDogCircle));
    mDogCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::scaleAnimation, mDogCircle));
    addChild(mDogCircle);
    

    // Cat--------------
    mCatCircle = Circle::create("CAT", ci::Color(248.f/255, 150.f/255, 128.f/255));
    mCatCircle->setPosition(ci::vec2(258.f, 183.f));
    mCatCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::colorAnimation, mCatCircle));
    mCatCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::rotationAnimation, mCatCircle));
    mCatCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::scaleAnimation, mCatCircle));
    addChild(mCatCircle);
    
    // Bird--------------
    mBirdCircle = Circle::create("BIRD", ci::Color(255.f/255, 160.f/255, 78.f/255));
    mBirdCircle->setPosition(ci::vec2(116.f, 324.f));
    mBirdCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::colorAnimation, mBirdCircle));
    mBirdCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::rotationAnimation, mBirdCircle));
    mBirdCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::scaleAnimation, mBirdCircle));
    
    addChild(mBirdCircle);
    
    // Rabbit--------------
    mRabbitCircle = Circle::create("RABBIT", ci::Color(201.f/255, 234.f/255, 124.f/255));
    mRabbitCircle->setPosition(ci::vec2(258.f, 324.f));
    mRabbitCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::colorAnimation, mRabbitCircle));
    mRabbitCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::rotationAnimation, mRabbitCircle));
    mRabbitCircle->getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::scaleAnimation, mRabbitCircle));
    addChild(mRabbitCircle);
    
    
}
