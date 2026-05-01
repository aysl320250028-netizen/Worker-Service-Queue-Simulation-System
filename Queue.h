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
~Queue(){
    delete[]Worker;
}
void initializeQueue(){
        front = 0;
        rear = -1;
        count = 0;
        for (int i = 0; i < maxSize; i++){
            Worker[i] = 0;
        }
    cout<< "Queue is initialized!" << endl;
    }
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
         return count == maxSize;
    }
    void enqueue(int item){
        if(isFull()){
            cout<< "The queue is full" << endl;
            return false;
        }
        rear = (rear + 1) % maxSize;
        Worker[rear] = item;
        count++;
        cout<< item << " is added" << endl;
        return true;
    }
    Worker dequeue(){
         if (isEmpty()){
            cout<< "The queue is empty" << endl;
            return -1;
        }
        int deletedItem = Worker[front];
        Worker[front] = 0;
        front = (front + 1) % maxSize;
        count--;
        cout<< deletedItem << " is deleted" << endl;
        return deletedItem;
    }
void display(){
        if (isEmpty()){
            cout<< "The queue is empty" << endl;
            return;
        }
        cout<< "The queue contents are (from front to rear):" << endl;
        int index = front;
        for(int i = 0; i < count; i++){
            cout<< Worker[index] << " ";
            index = (index + 1) % maxSize;
        }
        cout<< endl;
        cout<< "Front: " << front << ", Rear: " << rear << ", Count: " << count
        << ", Maximum size: " << maxSize << endl;
    }

};

#endif
