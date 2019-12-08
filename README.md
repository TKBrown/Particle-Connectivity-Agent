# Particle Connectivity Agent Library

Particle's default connectivity agent is great for rapid benchtop protos, though becomes problematic for scenarios which require long-term connectivity and non-blocking operation.

- Spotty WiFi will cause the agent to eventually go offline indefinitely; requiring a power cycle
- Internal clock is not automatically synchronized and drifts considerably over the course of a few days
- Upon boot, the Setup() will not be invoked until WiFi connectivity is established - preventing initialization of IO
- Cloud connection related functions will block execution of the application

Due to these issues, I built my own class to manage connectivity with the Particle Cloud. Basic usage is simple: set the system mode to manual, instantiate the class, and call Process() during loops.

```c++

SYSTEM_MODE(MANUAL);

#include "ParticleAgent.h"

ParticleAgent Agent = ParticleAgent();

void setup()
{
}

void loop()
{
  Agent.Process();
}

```

Enjoy!

TK
