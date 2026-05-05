#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <class Type>
class Queue {
private:
    int front, rear, count, maxSize;
    Type* arr;

public:
    Queue(int size = 100);
    ~Queue();
    void initializeQueue();
    bool isEmpty();
    bool isFull();
    void enqueue(Type value);
    Type dequeue();
    int getSize();
    void display();
};

#endif
