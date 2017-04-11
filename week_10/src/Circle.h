
#pragma once

#include "poNodeContainer.h"
#include "poShape.h"
#include "poTextBox.h"



class Circle;
typedef std::shared_ptr<Circle> CircleRef;
typedef ci::signals::Signal<void(bool state)> CircleStateChangeSignal;


class Circle
: public po::scene::NodeContainer
{
public:
    static CircleRef create(std::string name, ci::Color color);
    void setup(std::string name,  ci::Color color);
    
    void rotationAnimation();
    void colorAnimation();
    void scaleAnimation();
    
//    void onMouseEvent(po::scene::MouseEvent &event);
//    CircleStateChangeSignal     mCircleStateChangeSignal;
//    bool                        mIsActivated;

    
protected:
    
private:
    po::scene::ShapeRef         mCircle;
    ci::Color                   mCircleColor;
    
    po::scene::TextBoxRef       mTextBox;
    ci::Color                   mTextColor;
    
   
    

    
};
