#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "text/Font.h"

//reference: https://www.youtube.com/watch?v=EPXHKCJcikw

using namespace ci;
using namespace ci::app;
using namespace std;


class DigitalClockProjectApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    time_t rawTime;
    struct tm * currentTime;
    char a[100];
    
    Font myFont;
    
};

void DigitalClockProjectApp::setup()
{
    ci::app::setWindowSize(500.f, 300.f);
    myFont = Font(loadAsset( "04B_30_.ttf"), 30);
    
}

void DigitalClockProjectApp::mouseDown( MouseEvent event )
{
}

void DigitalClockProjectApp::update()
{
}

void DigitalClockProjectApp::draw()
{
	gl::clear( Color( 0.f, 0.f, 0.f ) );
    
    rawTime = std::time(NULL);
    currentTime = std::localtime(&rawTime);
    strftime(a, 100, "%I :%M :%S", currentTime);
    
    gl::drawString( a, ci::vec2( 140.f, 140.f ),Color::white(),myFont);
}

CINDER_APP( DigitalClockProjectApp, RendererGl )
