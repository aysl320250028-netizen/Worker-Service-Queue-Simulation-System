#include <iostream>
#include "Simulation.h"
using namespace std;
int main() {
    //Queue part:
    Queue queue(5);
    cout<< " Circular queue " << endl;
    cout<< "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is the queue full? " << (queue.isFull() ? "Yes" : "No") << endl;
    
    cout<< "Adding the following elements:" << endl;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    
    queue.display();
    
    cout<< "Deleting the following elements:" << endl;
    queue.dequeue();
    queue.dequeue();
    
    queue.display();
    
    cout<< "Adding the following elements to prove circular behaviour:" << endl;
    queue.enqueue(60);
    queue.enqueue(70);
    
    queue.display();
    
    cout<< "Deleting the remaining elements (ending the queue):" << endl;
     while (!queue.isEmpty()) {
        queue.dequeue();
    }
    cout<<"Attempting to delete from an empty queue:" << endl;
    queue.dequeue();
    
    cout<< "Reinitializing the queue:" << endl;
    queue.initializeQueue();
    
    queue.display();
    
    cout << "Queue Simulation System Started..." << endl;
   Simulation sim1(20, 10, 1);
   Simulation sim2(20, 10, 2);
//Then say in report:
//“We compared system performance with different numbers of servers.”
    sim.run();
    return 0;
}
