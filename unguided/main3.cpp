#include <iostream>
#include "no3.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;

    printQueue(Q);
    enqueue(Q, 5); printQueue(Q);
    enqueue(Q, 2); printQueue(Q);
    enqueue(Q, 7); printQueue(Q);
    dequeue(Q);    printQueue(Q);
    dequeue(Q);    printQueue(Q);
    enqueue(Q, 4); printQueue(Q);
    dequeue(Q);    printQueue(Q);
    dequeue(Q);    printQueue(Q);

    return 0;
}
