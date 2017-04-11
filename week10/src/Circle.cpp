
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
    textbox.size(90, 10);
    textbox.setAlignment(ci::TextBox::Alignment::CENTER);
    
    mTextBox = TextBox::create(textbox);
    mTextBox->setDrawBounds(false);
    mTextBox->setAlignment(po::scene::Alignment::CENTER_CENTER);
    addChild(mTextBox);
//    mTextBox->setPosition(5, 5);
    

}

void Circle::rotationAnimation()
{
    mCircle->setRotation(0.0f);
    ci::app::timeline().apply(&mCircle->getRotationAnim(), ci::toRadians(360.f), 1.5);
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
}
