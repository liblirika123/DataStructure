#include "ABCircularQueue.h"

int main(void) {
    Queue * q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    showQueue(q);

    dequeue(q);
    dequeue(q);
    showQueue(q);

    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 10);
    showQueue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    showQueue(q);

    return 0;
}
