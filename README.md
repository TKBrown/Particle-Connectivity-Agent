# Particle-Connectivity-Agent

Particle's default connectivity agent is great for rapid benchtop protos, though becomes problematic for scenarios more in line with field use.

- Spotty WiFi will cause the agent to eventually go offline indefinitely; requiring a power cycle
- Internal clock is not automatically synchronized and drifts considerably over the course of a few days
- Upon boot, the Setup() function is delayed until WiFi connectivity is established

Due to these issues, I built my own class to manage the process with the "Manual" System Mode. Basic usage is simple: set the system mode to manual, instantiate the class, and call Update() during loops.

```c++

SYSTEM_MODE(MANUAL);

#include "ParticleAgent.h"

ParticleAgent Agent = ParticleAgent();

void setup()
{
}

void loop()
{
  Agent.Update();
}

```
