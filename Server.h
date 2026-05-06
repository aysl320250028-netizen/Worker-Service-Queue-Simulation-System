#ifndef SERVER_H
#define SERVER_H

#include "Worker.h"

class Server {
private: 
    bool busy;
    int remainingTime;
    Worker currentWorker;

public:
    Server();

//Accessors
    bool isBusy() const;
    int getRemainingTime() const;
    Worker getCurrentWorker() const;
    //Getter methods. They allow controlled access to private data, so other parts of the program can check server status without modifying it.

 //Core methods
    bool assignWorker(const Worker& w, int currentTime);
    Worker process(); 
    //Core functionality. assignWorker starts a job, process advances time and returns a finished worker when done.
};

#endif
