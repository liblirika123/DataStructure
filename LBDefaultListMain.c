#include <stdio.h>
#include <stdlib.h>
#include "LBDefaultList.h"

int main(void) {
    List * list = createList();
    
    addListNode(list, 1);
    addListNode(list, 2);
    addListNode(list, 3);
    addListNode(list, 4);
    addListNode(list, 5);
    return 0;
}
