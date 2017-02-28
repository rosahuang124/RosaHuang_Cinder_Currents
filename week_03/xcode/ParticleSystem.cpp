#include "ParticleSystem.h"
#include "cinder/Rand.h"

ParticleSystem::ParticleSystem()
{

    mParticleNum = 20;
    
    mRange = 40.f;
    
    mRepulsionFactor = 0.02f;

    ci::Rand::randomize();
    
    for (int i = 0; i < mParticleNum; i++)
    {
        Particle singleParticle(ci::app::getWindowCenter() + glm::vec2(ci::randFloat(-mRange , mRange ), ci::randFloat(-mRange, mRange)));
        mParticles.push_back(singleParticle);
    }
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::repulseFrom(glm::vec2 position)
{

    for (auto& p : mParticles){
        float distanceDiff = ci::length(p.getPosition() - position);
        if (distanceDiff < 20.f){
            glm::vec2 repulsion = (p.getPosition().y - position) * mRepulsionFactor;
            p.applyForce(repulsion);
        }
    }
    
}

void ParticleSystem::bounceFromeEdge()
{
    for (auto& p : mParticles){
       
        if (p.getPosition().x <= 0.f || p.getPosition().x >= ci::app::getWindowWidth()){
            p.bounceForce(0.95, false);
        }
        
        if (p.getPosition().y <= 0.f || p.getPosition().y >= ci::app::getWindowHeight()){
            p.bounceForce(0.95, true);
        }
    }
}

void ParticleSystem::update()
{
    bounceFromeEdge();
    
    for (int i = 0; i < mParticles.size(); i++){
        
        for (int j = 0; j < mParticles.size(); j++){
            
            if (i == j) continue;
            
            float distanceDiff = ci::length(mParticles[i].getPosition() - mParticles[j].getPosition());
            
            if (distanceDiff < 5.f){
                glm::vec2 repulsion = (mParticles[i].getPosition() - mParticles[j].getPosition()) * mRepulsionFactor;
                mParticles[i].applyForce(repulsion);
            }
        }
    }
    
    for (auto& p : mParticles){
        p.update();
    }
}


void ParticleSystem::draw()
{
    for (auto& p : mParticles){
        p.draw();
    }
}



