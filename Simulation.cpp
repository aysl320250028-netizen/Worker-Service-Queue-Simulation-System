#include "Simulation.h"
#include <iostream>
using namespace std;

Simulation::Simulation(int simTime, int queueSize)
    : queue(queueSize) {
    time = 0;
    maxTime = simTime;
}

void Simulation::run() {
    int workerID = 1;

    for (time = 0; time < maxTime; time++) {
        cout << "Time: " << time << endl;

        // Simulate worker arrival every 2 units
        if (time % 2 == 0) {
            Worker w(workerID++, time, 3);
            queue.enqueue(w);
            cout << "Worker " << w.id << " arrived\n";
        }

        // Assign worker if server is free
        if (!server.busy && !queue.isEmpty()) {
            Worker w = queue.dequeue();
            server.assignWorker(w, time);
            cout << "Worker " << w.id << " is being served\n";
        }

        // Process server
        server.process();

        cout << "------------------\n";
    }
}
