#include "no1.h"

void createQueue(Queue &Q) {
    Q.front = -1;
    Q.rear = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.front == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.rear == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.front = 0;
    }

    Q.rear++;
    Q.data[Q.rear] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype hasil = Q.data[Q.front];

    for (int i = Q.front; i < Q.rear; i++) {
        Q.data[i] = Q.data[i + 1];
    }

    Q.rear--;

    if (Q.rear < Q.front) {
        Q.front = -1;
        Q.rear = -1;
    }

    return hasil;
}

void printInfo(Queue Q) {
    cout << Q.front << " - " << Q.rear << " \t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.front; i <= Q.rear; i++) {
        cout << Q.data[i] << " ";
    }
    cout << endl;
}
