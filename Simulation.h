#ifndef SIMULATION_H
#define SIMULATION_H

#include "Queue.h"
#include "Server.h"

class Simulation {
private:
    int time;
    int maxTime;
   Queue<Worker> queue;

    Server* servers;
    int numServers;

public:
    Simulation(int simTime, int queueSize, int numServers);
    void run();
};

#endif
