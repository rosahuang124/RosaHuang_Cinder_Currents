#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/ip/EdgeDetect.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Particle
{
public:
    Particle(glm::vec2 startPosition);
    ~Particle();
    void update();
    void draw();
    void applyForce(glm::vec2 force);
    void bounceForce(float damping, bool isVertical);
    glm::vec2 getPosition(){ return mPosition; }
    Rectf getRectf(glm::vec2 startingPoint, glm::vec2 size, glm::vec2 scale = glm::vec2(1.f, 1.f));
    
private:
    
    float	  mFriction;
    glm::vec2 mPosition;
    glm::vec2 mVelocity;
    glm::vec2 mAcceleration;
    
    ci::Surface8u       mSurface;
    cinder::gl::TextureRef      mTexture;
    cinder::gl::TextureRef      mTexFromSurface;
    
};

