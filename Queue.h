#ifndef QUEUE_H
#define QUEUE_H

#include "Worker.h"

class Queue {
private:
    int front, rear, count, maxSize;
    Worker* arr;

public:
    Queue(int size);
    bool isEmpty();
    bool isFull();
    void enqueue(Worker w);
    Worker dequeue();
};

#endif
