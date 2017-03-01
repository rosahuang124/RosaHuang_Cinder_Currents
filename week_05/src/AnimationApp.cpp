#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Timeline.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class AnimationApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    ci::Anim<ci::vec2> subButtonOnePos;
    ci::Anim<ci::vec2> subButtonTwoPos;
    ci::Anim<ci::vec2> subButtonThreePos;
    
    ci::Anim<ci::vec2> subButtonOnePos_after;
    ci::Anim<ci::vec2> subButtonTwoPos_after;
    ci::Anim<ci::vec2> subButtonThreePos_after;
    
    
    int circleNum = 5;
    int size;
    
};

void AnimationApp::setup()
{
    size = 15;
    setWindowSize(800, 600);

    subButtonOnePos = getWindowCenter();
    subButtonTwoPos = getWindowCenter();
    subButtonThreePos = getWindowCenter();
    
    subButtonOnePos_after = vec2(500,280);
    subButtonTwoPos_after = vec2(400,200);
    subButtonThreePos_after = vec2(300,280);
    
}




void AnimationApp::mouseDown( MouseEvent event )
{
    if (event.isLeft()){
        timeline().apply( &subButtonOnePos, (vec2)subButtonOnePos_after, 1.5f, EaseInOutCubic());
        timeline().apply( &subButtonTwoPos, (vec2)subButtonTwoPos_after, 1.0f, EaseInOutCubic());
        timeline().apply( &subButtonThreePos, (vec2)subButtonThreePos_after, 0.7f, EaseInOutCubic());

    };
    
    if (event.isRight()){
        timeline().apply( &subButtonOnePos_after, getWindowCenter(), 0.7f, EaseInOutBack());
        timeline().apply( &subButtonTwoPos_after, getWindowCenter(), 1.0f, EaseInOutBack());
        timeline().apply( &subButtonThreePos_after, getWindowCenter(), 1.5f, EaseInOutBack());
    };
    
    
    

}

void AnimationApp::update()
{

}

void AnimationApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    
    gl::color( Color(0.15f, 0.7f, 0.51f) );
    gl::drawSolidCircle( subButtonOnePos , 18 );
    
    gl::color( Color(0.15f, 0.7f, 0.51f) );
    gl::drawSolidCircle( subButtonTwoPos , 18 );
    
    gl::color( Color(0.15f, 0.7f, 0.51f) );
    gl::drawSolidCircle( subButtonThreePos , 18 );
    
    gl::color( Color(0.9f, 0.3f, 0.5f) );
    gl::drawSolidCircle( getWindowCenter(), 30);
    
    
   
    
    
}

CINDER_APP( AnimationApp, RendererGl )
