#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size) {
    maxSize = size;
    arr = new Worker[maxSize];
    front = 0;
    rear = -1;
    count = 0;
}

bool Queue::isEmpty() {
    return count == 0;
}

bool Queue::isFull() {
    return count == maxSize;
}

void Queue::enqueue(Worker w) {
    if (isFull()) {
        cout << "Queue is full!\n";
        return;
    }
    rear = (rear + 1) % maxSize;
    arr[rear] = w;
    count++;
}

Worker Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return Worker();
    }
    Worker w = arr[front];
    front = (front + 1) % maxSize;
    count--;
    return w;
}
