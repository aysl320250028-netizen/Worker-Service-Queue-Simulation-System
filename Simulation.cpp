#include "Simulation.h"
#include <iostream>
using namespace std;

Simulation::Simulation(int simTime, int queueSize, int n)
    : queue(queueSize) {

    time = 0;
    maxTime = simTime;
    numServers = n;

    servers = new Server[numServers];

    // ✅ Initialize statistics
    totalWaitingTime = 0;
    servedWorkers = 0;
    maxQueueLength = 0;
}

void Simulation::run() {
    int workerID = 1;

    for (time = 0; time < maxTime; time++) {

        cout << "==============================" << endl;
        cout << "Time = " << time << endl;
        cout << "------------------------------" << endl;

        // ✅ Worker arrival (every 2 time units)
        if (time % 2 == 0) {
            Worker w(workerID++, time, 3);
            queue.enqueue(w);
            cout << "Worker " << w.id << " arrived\n";
        }

        // ✅ Track max queue length
        if (queue.getSize() > maxQueueLength) {
            maxQueueLength = queue.getSize();
        }

        // ✅ Assign workers to free servers
        for (int i = 0; i < numServers; i++) {
            if (!servers[i].isBusy() && !queue.isEmpty()) {

                Worker w = queue.dequeue();

                if (servers[i].assignWorker(w, time)) {
                    cout << "Worker " << w.id
                         << " assigned to Server " << i << endl;
                }
            }
        }

        // ✅ Process servers + handle finished workers
        for (int i = 0; i < numServers; i++) {

            Worker finished = servers[i].process();

            if (finished.id != 0) {

                int waitingTime = finished.startTime - finished.arrivalTime;

                cout << "Worker " << finished.id
                     << " finished at Server " << i
                     << " | Waiting Time = " << waitingTime << endl;

                totalWaitingTime += waitingTime;
                servedWorkers++;
            }
        }

        // ✅ Show queue status
        cout << "Queue size: " << queue.getSize() << endl;

        // ✅ Show servers status
        cout << "Servers Status:\n";
        for (int i = 0; i < numServers; i++) {
            if (servers[i].isBusy()) {
                cout << "Server " << i
                     << ": BUSY (Remaining Time = "
                     << servers[i].getRemainingTime() << ")\n";
            } else {
                cout << "Server " << i << ": FREE\n";
            }
        }

        cout << "==============================\n";
    }

    // ✅ FINAL RESULTS
    cout << "\n==================================\n";
    cout << "        SIMULATION RESULTS\n";
    cout << "==================================\n";

    cout << "Total Workers Served      : " << servedWorkers << endl;

    cout << "Total Waiting Time        : " << totalWaitingTime << endl;

    cout << "Average Waiting Time      : "
         << (servedWorkers > 0 ? (double)totalWaitingTime / servedWorkers : 0)
         << endl;

    cout << "Maximum Queue Length      : " << maxQueueLength << endl;

    cout << "Number of Servers         : " << numServers << endl;

    cout << "Simulation Time           : " << maxTime << endl;

    cout << "==================================\n";
}
