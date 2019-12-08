/*
	Example usage for Particle-Connectivity-Agent library by TK Brown.
*/

SYSTEM_MODE(MANUAL);

#include "ParticleAgent.h"

// Init the agent
ParticleAgent Agent = ParticleAgent();

void setup()
{    
}

void loop()
{
	//call during each loop
    Agent.Process();
}
