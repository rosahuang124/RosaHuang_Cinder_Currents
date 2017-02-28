#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "cinder/Rand.h"
#include "cinder/Perlin.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MoreParticleSystemApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
 
    const int	NUM_PARTICLES = 80;
    const float  RANDOM_RANGE = 10.f;
    const float  RANDOM_FORCE_RANGE = 4.f;
    const float LIFE_SPAN = 3.f;
    
    std::vector<ParticleRef> mParticles;
    float                    mTime;
    float                    mFrequency = 1 / 200.0f;
};

void MoreParticleSystemApp::setup()
{
    
}

void MoreParticleSystemApp::mouseDown( MouseEvent event )
{
    if(event.isLeft()){
        
        for (int i = 0; i < NUM_PARTICLES; i++){
        
            mParticles.push_back(Particle::create((glm::vec2)event.getPos() + glm::vec2(ci::randFloat(-RANDOM_RANGE, RANDOM_RANGE), ci::randFloat(-RANDOM_RANGE, RANDOM_RANGE)), LIFE_SPAN, glm::vec2(ci::randFloat(-RANDOM_FORCE_RANGE, RANDOM_FORCE_RANGE), ci::randFloat(-RANDOM_FORCE_RANGE, RANDOM_FORCE_RANGE))));
        }
    
    }
}

void MoreParticleSystemApp::update()
{
    
    mTime = ci::app::getElapsedSeconds() * 100.f;
    
    for (auto& p: mParticles){
        p->update();
    }
    
    for (auto p = mParticles.begin(); p != mParticles.end();)
    {
        if ( (*p)->getTimerleft() < 0) {
            p = mParticles.erase(p);
        } else {
            ++p;
        }
    }
    
    
}

void MoreParticleSystemApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    
    gl::ScopedBlendAdditive blend;
    
   
    ci::gl::begin(GL_LINES);
    for (auto& p: mParticles){
        ci::gl::color(ci::ColorA(0.3f ,-(p->getTimerleft()/p->getLifespan() - 1.f), 1.f - (p->getTimerleft()/p->getLifespan()) * 0.5f, p->getTimerleft()/p->getLifespan()));
        
        vec2 gravity = vec2(0.f, 0.08f);
        p->applyForce(gravity);

        ci::gl::drawSolidCircle(p->getPosition(), 3 * (p->getTimerleft()/p->getLifespan()));
    }
    ci::gl::end();
    
}

CINDER_APP( MoreParticleSystemApp, RendererGl )
