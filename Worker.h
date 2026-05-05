#ifndef WORKER_H
#define WORKER_H

class Worker {
public:
    int id;
    int arrivalTime;
    int serviceTime;
    int startTime;

    Worker(int id, int arrivalTime, int serviceTime);
    void display() const;
};

#endif
