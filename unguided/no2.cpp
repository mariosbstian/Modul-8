#include <iostream>
#include "no2.h"
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

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.front = 0;
        Q.rear  = 0;
    } else {
        Q.rear = (Q.rear + 1) % MAX;
    }

    Q.buffer[Q.rear] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype hasil = Q.buffer[Q.front];

    if (Q.front == Q.rear) {
        Q.front = -1;
        Q.rear  = -1;
    } else {
        Q.front = (Q.front + 1) % MAX;
    }

    return hasil;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 - -1\t| empty queue" << endl;
        return;
    }

    cout << Q.front << " - " << Q.rear << "\t| ";

    int idx = Q.front;
    while (true) {
        cout << Q.buffer[idx] << " ";
        if (idx == Q.rear) break;
        idx = (idx + 1) % MAX;
    }
    cout << endl;
}
