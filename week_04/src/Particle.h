#pragma once
#include <memory>

class Particle;

typedef std::shared_ptr<Particle> ParticleRef;

class Particle {
public:
    static ParticleRef create(glm::vec2 position, float lifespan, glm::vec2 acceleration);
    glm::vec2 getPosition(){return mPosition;}

    float getTimerleft();
    float getLifespan(){return mLifespan;};
    void update();

    void applyForce(glm::vec2 force);
    ~Particle();
private:
    Particle();
    
    void setup(glm::vec2 position, float lifespan, glm::vec2 acceleration);

    glm::vec2 mPosition;
    float     mFriction;
    float     mLifespan;
    glm::vec2 mVelocity;
    glm::vec2 mAcceleration;
    ci::Timer mTimer;
};
