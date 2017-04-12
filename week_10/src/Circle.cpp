
#include "Circle.h"
#include "poShape.h"

using namespace po::scene;

CircleRef Circle::create(std::string name, ci::Color color)
{
    CircleRef ref (new Circle());
    ref->setup(name, color);
    return ref;
}

void Circle::setup(std::string name, ci::Color color)
{
 
    mCircle = Shape::createCircle(65.f);
    mCircleColor = color;
    mCircle->setFillColor(color);
    mCircle->setDrawBounds(false);
    mCircle->setAlignment(po::scene::Alignment::CENTER_CENTER);
    addChild(mCircle);
    
    // Text box
    ci::TextBox textbox = ci::TextBox();
    textbox.text(name);
    textbox.color(ci::Color(1, 1, 1));
    textbox.size(90, 15);
    textbox.setAlignment(ci::TextBox::Alignment::CENTER);
    
    mTextBox = TextBox::create(textbox);
    mTextBox->setDrawBounds(false);
    mTextBox->setAlignment(po::scene::Alignment::CENTER_CENTER);
    mTextBox->setFillColor(0.3f, 0.3f, 0.3f);
    addChild(mTextBox);
    
    getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&Circle::onMouseEvent, this, std::placeholders::_1));
    getSignal(po::scene::MouseEvent::UP_INSIDE).connect(std::bind(&Circle::onMouseEvent, this, std::placeholders::_1));
    getSignal(po::scene::MouseEvent::UP).connect(std::bind(&Circle::onMouseEvent, this, std::placeholders::_1));



    

}

void Circle::onMouseEvent(po::scene::MouseEvent &event)
{
    switch (event.getType()) {
        case po::scene::MouseEvent::DOWN_INSIDE:
            mIsActivated = !mIsActivated;
            if (mIsActivated){
                
                rotationAnimation();
                scaleAnimation();
                colorAnimation();
                
                mCircleStateChangeSignal.emit(true);
            }else{
                mCircleStateChangeSignal.emit(false);
            }
            break;
        case po::scene::MouseEvent::UP_INSIDE:
            
            break;
        case po::scene::MouseEvent::UP:
            
            break;
        default:
            break;
    }
}


void Circle::rotationAnimation()
{
    mCircle->setRotation(0.0f);
    ci::app::timeline().apply(&mCircle->getRotationAnim(), ci::toRadians(360.f), 0.5);
    
    mTextBox->setRotation(0.0f);
    ci::app::timeline().apply(&mTextBox->getRotationAnim(), ci::toRadians(360.f), 0.5);
    
    
}

void Circle::colorAnimation()
{
    ci::Color white = ci::Color::white();
    
    ci::app::timeline().apply(&mCircle->getFillColorAnim(), white, 0.5);
    ci::app::timeline().appendTo(&mCircle->getFillColorAnim(), mCircleColor, 0.5);
}

void Circle::scaleAnimation()
{
    ci::app::timeline().apply(&mCircle->getScaleAnim(), ci::vec2(1.1f, 1.1f), 0.5);
    ci::app::timeline().appendTo(&mCircle->getScaleAnim(), ci::vec2(1.0f, 1.0f), 0.5);
    ci::app::timeline().apply(&mTextBox->getScaleAnim(), ci::vec2(1.1f, 1.1f), 0.5);
    ci::app::timeline().appendTo(&mTextBox->getScaleAnim(), ci::vec2(1.0f, 1.0f), 0.5);
}



