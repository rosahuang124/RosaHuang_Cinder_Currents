#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/ip/EdgeDetect.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class InteractiveImageProjectApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void createEdgeTexture( const Channel &src );
    void twirl(Surface8u *surface, Area area, float maxAngle);
    
    Rectf getRectf(glm::vec2 startingPoint, glm::vec2 size, glm::vec2 scale = glm::vec2(1.f, 1.f));
    
    gl::TextureRef      mTexture;
    
    gl::TextureRef      mTexTwirlFromSurface;
    
    ci::Surface8u       mSurface;
    ci::Surface8u       mSurfaceTwirl;
    
    float               mWidth;
    float               mHeight;
    int               mTwirl;
};

void InteractiveImageProjectApp::setup()
{
    mTwirl = 2;
    mWidth = 500.f;
    mHeight = 500.f;
    
    ci::app::setWindowSize(glm::vec2(1280.f, 720.f));
    
    try {
        mTexture = gl::Texture::create( loadImage( loadAsset( "cat.png" ) ) );
        mSurfaceTwirl = loadImage(ci::app::loadAsset("cat.png"));
        
    } catch (exception& e) {
    
        ci::app::console() << e.what() << std::endl;
    }
    
    
   
}

void InteractiveImageProjectApp::twirl(Surface8u *surface, Area area, float maxAngle)
{
    // clone the surface, or any changes make to *surface will affect directly on the variable
    ci::Surface8u inputSurface = surface->clone();
    
    ci::Surface::Iter inputIter(inputSurface.getIter());
    ci::Surface::Iter outputIter(surface->getIter(area));
    
    // get max radius. usually diagnal distance
    
    float maxDistance = ci::length((glm::vec2)area.getSize())/mTwirl;
    
    glm::vec2 mid = (area.getUL() + area.getLR()) / 2;
    
    
    while( inputIter.line() && outputIter.line() ) {
        while( inputIter.pixel() && outputIter.pixel() ) {
            // getting the current pixel position, and get the distance between it and image center
            glm::vec2 current = (glm::vec2)inputIter.getPos() - mid;
            // get length of a vec2
            float r = length(current);
            
            float twirlAngle = r / maxDistance * maxAngle;
            float angle = atan2(current.x, current.y);
            glm::vec2 outSameple(r * cos( angle + twirlAngle  ), r * sin( angle + twirlAngle ));
            glm::vec2 out = outSameple - current;
            outputIter.r() = inputIter.rClamped( out.x, out.y );
            outputIter.g() = inputIter.gClamped( out.x, out.y );
            outputIter.b() = inputIter.bClamped( out.x, out.y );
            
        }
    }
}

Rectf InteractiveImageProjectApp::getRectf(glm::vec2 startingPoint, glm::vec2 size, glm::vec2 scale)
{
    return Rectf(startingPoint.x, startingPoint.y, (size.x + startingPoint.x) * scale.x, (size.y + startingPoint.y) * scale.y);
}


void InteractiveImageProjectApp::mouseDown( MouseEvent event )
{
    if(event.isLeft())
    {
        mTwirl +=10;
        twirl(&mSurfaceTwirl, mSurfaceTwirl.getBounds(), 10.f);
        
    }
    ci::app::console() << mTwirl << std::endl;
}

void InteractiveImageProjectApp::update()
{
    
    
}

void InteractiveImageProjectApp::draw()
{
	
    gl::clear( Color( 0.7, 0.1, 0.3 ) );
    
    mTexTwirlFromSurface = gl::Texture::create(mSurfaceTwirl);
    gl::draw(mTexTwirlFromSurface, getRectf(glm::vec2(390.f, 110.f), glm::vec2(mWidth, mHeight)));
    

}

CINDER_APP( InteractiveImageProjectApp, RendererGl )
