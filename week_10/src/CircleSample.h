
#pragma once

#include "poNodeContainer.h"
#include "Circle.h"
#include "CentralCircle.h"

class CircleSample;
typedef std::shared_ptr<CircleSample> CircleSampleRef;


class CircleSample
: public po::scene::NodeContainer
{
public:
    static CircleSampleRef create();

    void setup();
    void onMouseEvent(po::scene::MouseEvent &event);
    bool bearIsActive();
    bool dinosaurIsActive();
    bool hedgehogIsActive();
    bool tigerIsActive();

    
private:
    CircleRef mBearCircle;
    CircleRef mDinosaurCircle;
    CircleRef mHedgeHogCircle;
    CircleRef mTigerCircle;
    
};
