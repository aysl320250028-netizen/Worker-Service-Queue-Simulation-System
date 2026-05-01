#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size) {
    maxSize = size;
    arr = new int[maxSize];
    initializeQueue();
}
Queue::~Queue() {
    delete[] arr;
}
void Queue::initializeQueue(){
    front = -1;
    rear = -1;
    count = 0;
    cout<< "Queue is initialized!" << endl;
    }

bool Queue::isEmpty() {
    return count == 0;
}

bool Queue::isFull() {
    return count == maxSize;
}

void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!\n";
        return;
    }
     if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % maxSize;
    arr[rear] = value;
    count++;
    cout<< value << " is added" << endl;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return -1;
    }
    int deletedItem = arr[front];
    if (count == 1) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % maxSize;
    }
    count--;
    cout << "Deleted " << deletedItem << " from the queue.\n";
    return deletedItem;
}
void Queue::display(){
        if (isEmpty()){
            cout<< "The queue is empty" << endl;
            return;
        }
        cout<< "The queue contents are (from front to rear):" << endl;
        int index = front;
        for(int i = 0; i < count; i++){
            cout<< arr[index] << " ";
            index = (index + 1) % maxSize;
        }
        cout<< endl;
        cout<< "Front: " << front << ", Rear: " << rear << ", Count: " << count
        << ", Maximum size: " << maxSize << endl;
    }
