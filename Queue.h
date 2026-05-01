#ifndef QUEUE_H
#define QUEUE_H

#include "Worker.h"

class Queue {
private:
    int front, rear, count, maxSize;
    Worker* arr;

public:
    Queue(int size){
        maxSize = size;
        front = 0;
        rear = -1;
        count = 0;
        Worker = new int[maxSize];
    }

void initializeQueue();

    bool isEmpty();
       
    bool isFull();
    
    bool enqueue(Worker w);
    Worker dequeue();
    void display();
       
    }

};

#endif
