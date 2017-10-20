#ifndef __BINARY_TREE__
#define __BINARY_TREE__
#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct _bt {
    Data data;
    struct _bt * left;
    struct _bt * right;
}BTree;

BTree * createBTree(void) {
    BTree * newTree = (BTree *)malloc(sizeof(BTree));
    newTree->left = NULL;
    newTree->right = NULL;
}

void setData(BTree * bt, Data data) {
    bt->data = data;
}

Data getData(BTree * bt) {
    return bt->data;
}

BTree * getLeftSubTree(BTree * pt) {
    return pt->left;
}

BTree * getRightSubTree(BTree * pt) {
    return pt->right;
}

void makeLeftSubTree(BTree * pt, BTree * ct) {
    if(pt->left != NULL) {
	free(pt->left);
    }

    pt->left = ct;
}

void makeRightSubTree(BTree * pt, BTree * ct) {
    if(pt->right != NULL) {
	free(pt->right);
    }
    
    pt->right = ct;
}


#endif
