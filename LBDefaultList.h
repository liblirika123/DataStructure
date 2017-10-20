#ifndef	__LLDIST_H__
#define __LLDIST_H__
typedef int Data;

typedef struct _node {
    Data data;
    struct _node * next;
}Node;

typedef struct _list {
    Node * head;
}List;

List * createList(void) {
    List * newList = (List *)malloc(sizeof(List));
    newList->head = (Node *)malloc(sizeof(Node));
    newList->head->next = NULL;
    return newList;
}

void showList(List * list) {
    Node * cur = list->head->next;

    printf("data: ");
    while(cur != NULL) {
	printf("%d-", cur->data);
	cur = cur->next;
    }
    puts("");
}

void addListNode(List * list, Data data) {
    Node **curNode = &list->head;
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    while(*curNode !=  NULL) {
	curNode = &curNode[0]->next;
    }

    *curNode = newNode; 
    showList(list);
}

Data delListNode(List * list, Data data) {
    Node ** curNode = &list->head->next;
    Node * befNode = list->head;
    Node * delNode = NULL;
    Data delData = -1;

    while(curNode != NULL) {
	if(curNode[0]->data == data) {
	    delNode = *curNode;
	    delData = delNode->data;
	    befNode->next = delNode->next;
	    free(delNode);  
	    break;
	}

	befNode = *curNode;
	curNode = &curNode[0]->next;
    }

    showList(list);
    return delData;
}
#endif
