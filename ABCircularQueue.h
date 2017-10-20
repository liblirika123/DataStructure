#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct _queue {
    int * list;
    int front;
    int rear;
    int size;
}Queue;

Queue * createQueue(void) {
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q->list = (int *)malloc(sizeof(int) * 5);
    q->size = 5;
    q->list = (int *)malloc(sizeof(int) * q->size);
    return q;
}

void enqueue(Queue * q, Data data) {
    if(q->front % q->size == (q->rear + 1) % q->size) {
	puts("큐가 다찼음");
	return;
    }

    if(q->rear + 1 == q->size) {
	q->rear = -1;
    }
    q->list[++q->rear] = data;
}

Data dequeue(Queue * q) {
    if(q->front == q->rear) {
	puts("큐가 비었음");
	return -1;
    }

    if(q->front + 1 == q->size) {
	q->front = -1;
    }
    q->list[++q->front] = 0;
}

void showQueue(Queue * q) {
    int front = q->front;
    int rear = q->rear;
    int i=0;

    printf("----------------\n");
    while(front != rear) {
	if(front +1  == q->size) {
	    front = -1;
	}
	
	++front;
	printf("f,r(%d,%d) : %d\n", front, rear,  q->list[front]);
    }
    printf("----------------\n");
}
