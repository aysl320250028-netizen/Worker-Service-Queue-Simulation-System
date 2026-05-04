#include <iostream>
#include "Queue.h"
#include "Worker.h"
#include "Simulation.h"
using namespace std;
int main() {
    //Queue part:
   Queue q(5);
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;
    q.enqueue(60);
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.enqueue(70);
    q.display();

     // Worker Part
    const int NUM_WORKERS = 5;

    Worker workers[NUM_WORKERS] = {
        Worker(1,  0, 4),   // ID, arrivalTime, serviceTime
        Worker(2,  3, 6),
        Worker(3,  5, 3),
        Worker(4,  8, 5),
        Worker(5, 10, 2)
    };

    cout << "\n=== Generated Workers ===" << endl;
    for (int i = 0; i < NUM_WORKERS; i++) {
        workers[i].display();
    }

    cout << "\n=== Queueing Workers by Arrival Time ===" << endl;
    Queue workerQueue(NUM_WORKERS);

    for (int i = 0; i < NUM_WORKERS; i++) {
        workerQueue.enqueue(workers[i].id);
    }

    workerQueue.display();

    cout << "\n=== Serving Workers ===" << endl;
    while (!workerQueue.isEmpty()) {
        int servedID = workerQueue.dequeue();
        cout << "Serving Worker ID: " << servedID
             << " | Service Time: " << workers[servedID - 1].serviceTime
             << " units" << endl;
    }
   // 
    cout << "Queue Simulation System Started..." << endl;
   Simulation sim1(20, 10, 1);
   Simulation sim2(20, 10, 2);
//Then say in report:
//“We compared system performance with different numbers of servers.”
    sim.run();
    return 0;
}

