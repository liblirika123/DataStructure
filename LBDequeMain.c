#include "LBDeque.h"

int main(void) {
    Deque * deque = createDeque();
    
    pushFront(deque, 1);
    pushFront(deque, 2);
    pushFront(deque, 3);
    pushRear(deque, 4);
    pushRear(deque, 5);
    pushRear(deque, 6);
    
    popRear(deque);
    popRear(deque);
    popFront(deque);
    popFront(deque);
    popFront(deque);
    popFront(deque);
    popFront(deque);

    return 0;
}
