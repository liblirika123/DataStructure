#ifndef __BINARY_TREE2__
#define __BINARY_TREE2__
#include "LBBinaryTree.h"

typedef void func(BTree * bt);

void preorderTraverse(BTree * bt, func action) {
    if(bt == NULL) {
	return;
    }
    action(bt);
    preorderTraverse(bt->left, action);
    preorderTraverse(bt->right, action);
}

void inorderTraverse(BTree * bt, func action) {
    if(bt == NULL) {
	return;
    }
    inorderTraverse(bt->left, action);
    action(bt);
    inorderTraverse(bt->right, action);
}

void postorderTraverse(BTree * bt, func action) {
    if(bt == NULL) {
	return;
    }

    postorderTraverse(bt->left, action);
    postorderTraverse(bt->right, action);
    action(bt);
}

void deleteBTree(BTree * bt) {
    if(bt != NULL) {
	printf("%d이 제거되었습니다.\n", bt->data);
	free(bt);
    }
}
#endif
