#ifndef QUEUE_H
#define QUEUE_H


class Queue {
private:
    int front, rear, count, maxSize;
    int* arr;

public:
    Queue(int size);
    ~Queue();
    void initializeQueue();
    bool isEmpty();
    bool isFull();
    void enqueue(int value);
    int dequeue();
    void display();
       
    };

#endif
