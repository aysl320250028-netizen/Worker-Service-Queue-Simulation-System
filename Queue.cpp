#include "Queue.h"
#include <iostream>
using namespace std;

template <class Type>
Queue<Type>::Queue(int size) {
    maxSize = size;
    arr = new Type[maxSize];
    initializeQueue();
}

template <class Type>
Queue<Type>::~Queue() {
    delete[] arr;
}

template <class Type>
void Queue<Type>::initializeQueue() {
    front = -1;
    rear = -1;
    count = 0;
    cout << "Queue is initialized!" << endl;
}

template <class Type>
bool Queue<Type>::isEmpty() {
    return count == 0;
}

template <class Type>
bool Queue<Type>::isFull() {
    return count == maxSize;
}

template <class Type>
void Queue<Type>::enqueue(Type value) {
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
    cout << value << " is added" << endl; 
}

template <class Type>
Type Queue<Type>::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return Type();
    }
    Type deletedItem = arr[front];
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

template <class Type>
int Queue<Type>::getSize() {
    return count;
}

template <class Type>
void Queue<Type>::display() {
    if (isEmpty()) {
        cout << "The queue is empty" << endl;
        return;
    }
    cout << "The queue contents are (from front to rear):" << endl;
    int index = front;
    for (int i = 0; i < count; i++) {
        cout << arr[index] << " ";
        index = (index + 1) % maxSize;
    }
    cout << endl;
    cout << "Front: " << front << ", Rear: " << rear << ", Count: " << count
         << ", Maximum size: " << maxSize << endl;
}
