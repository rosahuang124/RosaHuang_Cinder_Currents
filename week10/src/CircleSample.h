
#pragma once

#include "poNodeContainer.h"
#include "Circle.h"

class CircleSample;
typedef std::shared_ptr<CircleSample> CircleSampleRef;

class CircleSample
: public po::scene::NodeContainer
{
public:
    static CircleSampleRef create();
    
    void setup();
    
protected:
    
private:
    CircleRef mDogCircle;
    CircleRef mCatCircle;
    CircleRef mBirdCircle;
    CircleRef mRabbitCircle;
    
};
