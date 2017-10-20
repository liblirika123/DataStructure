#include <stdio.h>
#include "LBBinaryTree2.h"

void showData(Data data) {
    printf("%d ", data);
}

int main(void) {
    BTree * bt1 = createBTree();
    BTree * bt2 = createBTree();
    BTree * bt3 = createBTree();
    BTree * bt4 = createBTree();
    BTree * bt5 = createBTree();
    BTree * bt6 = createBTree();

    setData(bt1, 1);
    setData(bt2, 2);
    setData(bt3, 3);
    setData(bt4, 4);
    setData(bt5, 5);
    setData(bt6, 6);
    
    makeLeftSubTree(bt1, bt2);
    makeRightSubTree(bt1, bt3);
    makeLeftSubTree(bt2, bt4);
    makeRightSubTree(bt2, bt5);
    makeRightSubTree(bt3, bt6);
    
    puts("inorder traverse : ");
    inorderTraverse(bt1, deleteBTree);
    puts("");
    return 0;
}
