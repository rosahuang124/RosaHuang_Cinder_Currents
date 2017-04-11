
#pragma once

#include "poNodeContainer.h"
#include "poShape.h"
#include "poTextBox.h"


class Circle;
typedef std::shared_ptr<Circle> CircleRef;

class Circle
: public po::scene::NodeContainer
{
public:
    static CircleRef create(std::string name, ci::Color color);
    void setup(std::string name,  ci::Color color);
    
    void rotationAnimation();
    void colorAnimation();
    void scaleAnimation();

    
protected:
    
private:
    po::scene::ShapeRef             mCircle;
    ci::vec2                        mCirclePos;
    ci::Color                       mCircleColor;
    
    po::scene::TextBoxRef           mTextBox;
    ci::Color                       mTextColor;
    

    

    void                    showIndicator();
    
};
