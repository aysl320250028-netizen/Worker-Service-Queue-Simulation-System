#include "Worker.h"
#include <iostream>
using namespace std;

Worker::Worker(int id, int arrivalTime, int serviceTime) {
    this->id = id;
    this->arrivalTime = arrivalTime;
    this->serviceTime = serviceTime;
}

void Worker::display() const {
    cout << "Worker [ID: " << id
         << " | Arrival Time: " << arrivalTime
         << " | Service Time: " << serviceTime << "]" << endl;
}

