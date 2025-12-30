#include <iostream>
#include "no3.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.front = -1;
    Q.rear  = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.front == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.rear + 1) % MAX == Q.front);
}

void enqueue(Queue &Q, infotype X) {
    if (isFullQueue(Q)) {
        cout << "Queue sudah penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.front = 0;
        Q.rear  = 0;
    } else {
        Q.rear = (Q.rear + 1) % MAX;
    }

    Q.data[Q.rear] = X;
}

void dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    if (Q.front == Q.rear) {
        Q.front = -1;
        Q.rear  = -1;
    } else {
        Q.front = (Q.front + 1) % MAX;
    }
}

void printQueue(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.front << " - " << Q.rear << " | Empty Queue" << endl;
        return;
    }

    cout << Q.front << " - " << Q.rear << " | ";
    int idx = Q.front;
    while (true) {
        cout << Q.data[idx] << " ";
        if (idx == Q.rear) break;
        idx = (idx + 1) % MAX;
    }
    cout << endl;
}
