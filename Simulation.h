#ifndef SIMULATION_H
#define SIMULATION_H
#include "Queue.h"
#include "Server.h"
#include "Worker.h"

class Simulation {
private:
    int time;
    int maxTime;

    Queue<Worker> queue;   // ✅ FIXED

    Server* servers;
    int numServers;

    int totalWaitingTime;
    int servedWorkers;
    int maxQueueLength;

public:
    Simulation(int simTime, int queueSize, int numServers);
    void run();
};

#endif
