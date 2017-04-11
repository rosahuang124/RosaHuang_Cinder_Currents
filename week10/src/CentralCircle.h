#pragma once

#include "poNodeContainer.h"
#include "poShape.h"
#include "CircleSample.h"

class CentralCircle;
typedef std::shared_ptr<CentralCircle> CentralCircleRef;

class CentralCircle:
public po::scene::NodeContainer
{
public:
    static CentralCircleRef create();
    void setup();
    
private:
    po::scene::ShapeRef mCentralCircle;
    ci::Color mCentralCircleColor = ci::Color::hex(0xF9D900);


};

