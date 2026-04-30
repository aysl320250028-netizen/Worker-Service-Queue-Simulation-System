#ifndef WORKER_H
#define WORKER_H

class Worker {
public:
    int id;
    int arrivalTime;
    int serviceTime;
    int startTime;

    Worker(int id = 0, int arrival = 0, int service = 0);
};

#endif
