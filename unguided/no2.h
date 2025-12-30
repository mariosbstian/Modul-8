#ifndef NO2_H
#define NO2_H

#define MAX 5
typedef int infotype;

struct Queue {
    infotype buffer[MAX];
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
