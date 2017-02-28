#include "ParticleSystem.h"
#include "cinder/Rand.h"


ParticleSystem::ParticleSystem(glm::vec2 postition){
    
}

void ParticleSystem::update(glm::vec2 force){
    
    for (int i = 0; i < NUM_PARTICLES; i++){
        mParticles.push_back(Particle::create((glm::vec2)event.getPos(), LIFE_SPAN, glm::vec2(ci::randFloat(-RANDOM_FORCE_RANGE, RANDOM_FORCE_RANGE), ci::randFloat(-RANDOM_FORCE_RANGE, RANDOM_FORCE_RANGE))));
    }
    
    
};

void ParticleSystem::draw(){
    
 
    
};
