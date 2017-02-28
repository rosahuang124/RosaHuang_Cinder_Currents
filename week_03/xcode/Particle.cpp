#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

Particle::Particle(glm::vec2 startPosition)
{

    mPosition = startPosition;
    mVelocity = glm::vec2(0.f, 0.f);
    mAcceleration = glm::vec2(0.f, 0.f);
    mFriction = 0.95f;
    
    try {
        mTexture = cinder::gl::Texture::create( loadImage( cinder::app::loadAsset( "particle.png" ) ) );
        mSurface = loadImage(ci::app::loadAsset("particle.png"));
        
    } catch (exception& e) {
        
        ci::app::console() << e.what() << std::endl;
    }
    
}

Particle::~Particle()
{
}

Rectf Particle::getRectf(glm::vec2 startingPoint, glm::vec2 size, glm::vec2 scale)
{
    return Rectf(startingPoint.x, startingPoint.y, (size.x + startingPoint.x) * scale.x, (size.y + startingPoint.y) * scale.y);
}


void Particle::update()
{
    mVelocity += mAcceleration;
    mVelocity *= mFriction;
    mPosition += mVelocity;
    mAcceleration *= 0.f;
}

void Particle::bounceForce(float damping, bool isVertical){
    
    if (isVertical){
        mVelocity.y = -mVelocity.y * damping;
    }
    else{
        mVelocity.x = -mVelocity.x * damping;
    }
}

void Particle::applyForce(glm::vec2 force)
{
    mAcceleration += force;
}

void Particle::draw()
{

    float radius = ci::length(abs(mVelocity)) * 20.f;
    
    mTexFromSurface = gl::Texture::create(mSurface);
    gl::draw(mTexFromSurface, getRectf(glm::vec2(mPosition), glm::vec2(2+ radius, 2 + radius)));
  
}
