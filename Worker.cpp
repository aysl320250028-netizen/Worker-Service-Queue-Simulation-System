#include "Worker.h"
#include <iostream>
using namespace std;

Worker::Worker() {  //default constructor
    id = 0;
    arrivalTime = 0;
    serviceTime = 0;
}

Worker::Worker(int id, int arrivalTime, int serviceTime) {
    this->id = id;
    this->arrivalTime = arrivalTime;
    this->serviceTime = serviceTime;
    this->startTime = 0; 
}


void Worker::display() const {
    cout << "Worker [ID: " << id
         << " | Arrival Time: " << arrivalTime
         << " | Service Time: " << serviceTime << "]" << endl;
}

