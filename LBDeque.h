#ifndef __DEQUE_H__
#define __DEQUE_H__
#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct _node {
    Data data;
    struct _node * next; // front에서만 사용하는 포인터
    struct _node * prev; // rear에서만 사용하는 포인터
}Node;

typedef struct _deque {
    struct _node * front; // == stack
    struct _node * rear; // == queue
}Deque;

Deque * createDeque(void) {
    Deque * dq = (Deque *)malloc(sizeof(Deque));
    dq->front = NULL;
    dq->rear = NULL;
}

void showFDeque(Deque * deque) {
    Node * cur = deque->front;

    fputs("data: ", stdout);
    while(cur != NULL) {
	printf("%d-", cur->data);
	cur = cur->next;
    }
    puts("");
}

void showRDeque(Deque * deque) {
    Node * cur = deque->rear;

    fputs("data: ", stdout);
    while(cur != NULL) {
	printf("%d-", cur->data);
	cur = cur->prev;
    }
    puts("");
}

void pushFront(Deque * deque, Data data) {
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->prev = NULL;
    newNode->next = deque->front;
    
    if(deque->front != NULL) {
	deque->front->prev = newNode;
    } else {
	deque->rear = newNode;
    }

    deque->front = newNode;
    showFDeque(deque);
}

void pushRear(Deque * deque, Data data) {
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = deque->rear;
    newNode->next = NULL;

    if(deque->rear != NULL) {
	deque->rear->next = newNode;
    } else {
	deque->front = newNode;
    }

    deque->rear = newNode;
    showRDeque(deque);
}

Data popFront(Deque * deque) {
    Node * delNode = deque->front;
    Data delData = -1;
    
    if(delNode != NULL) {
	if(delNode->next != NULL) {
	    delNode->next->prev = NULL;
	}
	
	delData = delNode->data;
	deque->front = delNode->next;
	free(delNode);
    }

    showFDeque(deque);
    return delData;
}

Data popRear(Deque * deque) {
    Node * delNode = deque->rear;
    Data delData = -1;

    if(delNode != NULL) {
	if(delNode->next != NULL) {
	    delNode->prev->next = NULL;
	}	    

	delData = delNode->data;
	deque->rear = delNode->prev;
	free(delNode);
    }

    showRDeque(deque);
    return delData;
}
#endif
