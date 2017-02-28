#include "Particle.h"

class ParticleSystem;

typedef std::shared_ptr<Particle> ParticleListRef;

class ParticleSystem{

public:
    
   
    ParticleSystem(glm::vec2 postition);
    void update(glm::vec2 force);
    void draw();

    // have all value that is not going to change in here
    const int	NUM_PARTICLES = 50;
    const float  RANDOM_RANGE = 10.f;
    const float  RANDOM_FORCE_RANGE = 2.f;
    const float LIFE_SPAN = 3.f;
    
    // declare your value
    std::vector<ParticleRef> mParticles;
    float                    mTime;
    float                    mFrequency = 1 / 200.0f;



};
