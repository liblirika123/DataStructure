#include "LBBinaryTree.h"

void InorderTraverse(BTree * bt) {
    if(bt == NULL) {
	return;
    }

    InorderTraverse(bt->left);
    printf("%d\n", bt->data);
    InorderTraverse(bt->right);
}

int main(void ) {
    BTree * bt1 = createBTree();
    BTree * bt2 = createBTree();
    BTree * bt3 = createBTree();
    BTree * bt4 = createBTree();

    setData(bt1, 1);
    setData(bt2, 2);
    setData(bt3, 3);
    setData(bt4, 4);

    makeLeftSubTree(bt1, bt2);
    makeRightSubTree(bt1, bt3);
    makeLeftSubTree(bt2, bt4);

    InorderTraverse(bt1);
    return 0;
}
