#pragma once

#include "Particle.h"

class ParticleAgent
{
	public:		
		ParticleAgent(unsigned long ConnectionRetryTime = DefaultConnectionRetryTime, unsigned long ClockSyncTime = DefaultClockSyncTime); //times in MS

		void Process();

	private:		
		static const unsigned long DefaultConnectionRetryTime = 1 * 60 * 1000; //1 minute
		static const unsigned long DefaultClockSyncTime = 1 * 60 * 60 * 1000; //1 hours
		
		unsigned long ConnectionRetryTime = 0;
		unsigned long ClockSyncTime = 0;
		
		boolean SyncPending = false;
		boolean CloudSyncFailure = false;

		void ConnectivityMaintenance();
		void ClockMaintenance();
};