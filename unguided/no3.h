#ifndef NO3_H
#define NO3_H

#define MAX 5
typedef int infotype;

struct Queue {
    int data[MAX];
    int front;
    int rear;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype X);
void dequeue(Queue &Q);
void printQueue(Queue Q);

#endif
