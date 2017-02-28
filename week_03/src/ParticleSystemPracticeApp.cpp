#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ParticlesApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void mouseMove(MouseEvent event) override;
    void update() override;
    void draw() override;
    
    ParticleSystem mParticleSystem;
};

void ParticlesApp::setup()
{
    ci::app::setFrameRate(30.f);
}

void ParticlesApp::mouseDown( MouseEvent event )
{
    
}

void ParticlesApp::mouseMove(MouseEvent event)
{
    mParticleSystem.repulseFrom(event.getPos());
}

void ParticlesApp::update()
{
    mParticleSystem.update();
}

void ParticlesApp::draw()
{
    gl::clear( ci::Color::black() );
    mParticleSystem.draw();

}

CINDER_APP( ParticlesApp, RendererGl )
