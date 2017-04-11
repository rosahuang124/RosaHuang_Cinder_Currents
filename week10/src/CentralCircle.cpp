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



