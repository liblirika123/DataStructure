#ifndef __STACK_H__
#define __STACK_H__
#include <stdio.h>
#include <stdlib.h>
#include "LBDefaultList.h"

typedef struct _stack {
    List * list;
}Stack;

Stack * createStack(void) {
    Stack * newStack = (Stack *)malloc(sizeof(Stack));
    newStack->list = createList();
    return newStack;
}

void showStack(Stack * stack) {
    showList(stack->list);
}

void push(Stack * stack, Data data) {
    List * sl = stack->list;
    Node ** cur = &sl->head->next;
    Node * newNode = (Node *)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = *cur;
    sl->head->next = newNode;
    
    showList(sl);
}

Data pop(Stack * stack) {
    if(stack->list->head->next == NULL) {
	puts("#스택이 비었습니다.");
	return -1;
    }

    return delListNode(stack->list, stack->list->head->next->data);
}
#endif
