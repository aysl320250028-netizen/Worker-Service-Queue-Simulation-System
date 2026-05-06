#include "Server.h"

//Ensures the server starts idle with no work assigned.
Server::Server() {
    busy = false;
    remainingTime = 0;
}

//Safe access to internal state. const means they don’t change anything.
bool Server::isBusy() const {
    return busy;
}
int Server::getRemainingTime() const {
    return remainingTime;
}
Worker Server::getCurrentWorker() const {
    return currentWorker;
}

//Refined logic. Checks edge cases (already busy, invalid service time). Sets up the worker properly with a start time.
bool Server::assignWorker(const Worker& w, int currentTime) {
    if (busy) {
        return false; // reject if already busy
    }
    if (w.serviceTime <= 0) {
        return false; // invalid worker
    }
    busy = true;
    currentWorker = w;
    currentWorker.startTime = currentTime;
    remainingTime = w.serviceTime;
    return true;
}

//Simulates one time unit of work. If the worker finishes, returns them to the simulation for logging. Otherwise, returns a dummy worker.
Worker Server::process() {
    if (busy) {
        remainingTime--;
        if (remainingTime <= 0) {
            busy = false;
            Worker finished = currentWorker;
            currentWorker = Worker(); // reset
            return finished;
        }
    }
    return Worker(); // dummy if nothing finished
}

