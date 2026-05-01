#include <iostream>
#include "Queue.h"
#include "Simulation.h"
using namespace std;
int main() {
    //Queue part:
   Queue q(5);
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;
    q.enqueue(60);
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    
    cout << "Queue Simulation System Started..." << endl;
   Simulation sim1(20, 10, 1);
   Simulation sim2(20, 10, 2);
//Then say in report:
//“We compared system performance with different numbers of servers.”
    sim.run();
    return 0;
}
