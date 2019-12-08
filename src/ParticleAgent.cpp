/* Particle-Connectivity-Agent library by TK Brown
 */

#include "ParticleAgent.h"

ParticleAgent::ParticleAgent(unsigned long ConnectionRetryTime, unsigned long ClockSyncTime)
{
	this->ConnectionRetryTime = ConnectionRetryTime;
	this->ClockSyncTime = ClockSyncTime;
}

void ParticleAgent::Process()
{
	system_tick_t CurrentTime = millis();

	ConnectivityMaintenance();
	ClockMaintenance();
}

void ParticleAgent::ClockMaintenance()
{
	//time to sync clock?
	if(ClockSyncTime > millis())
		return; //no

	//disconnected from particle?
	if(!Particle.connected())
		return; //yes, go no further

	//did we already initiate a sync to the cloud?
	if(SyncPending)
	{
		//no pending sync?
		if(!Particle.syncTimeDone())
			return; //sync is not yet complete, give it more time
		else
			SyncPending = false; //no longer pending

		//check if sync was successful - time of last sync is less then the sync frequency
		if(millis() - Particle.timeSyncedLast() < ClockSyncTime)
		{
			//successful
			ClockSyncTime = millis() + ClockSyncTime;
		}
		else
		{
		}
	}	
	//no, let's try sync	
	else
	{
		SyncPending = true;
		Particle.syncTime();
	}
}

void ParticleAgent::ConnectivityMaintenance()
{	
	//connected to cloud?
	if(Particle.connected())
	{
		//process messages
		Particle.process();
		return;
	}	

	//do we need to wait before attempting another connection?
	if(ConnectionRetryTime > millis())
		return; //yes
	
	//attempt connection
	Particle.connect();

	//set the retry to some time in the future
	ConnectionRetryTime = millis() + ConnectionRetryTime;
}