#ifndef NO1_H
#define NO1_H

#include <iostream>
using namespace std;

#define MAX 10
typedef int infotype;

struct Queue {
    infotype data[MAX];
    int front;
    int rear;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
