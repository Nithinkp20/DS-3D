#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct Queue {
    struct ListNode* front;
    struct ListNode* rear;
};

struct Queue* enqueue(struct Queue* queue, int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    return queue;
}

struct Queue* dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return queue;
    }

    struct ListNode* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    printf("Dequeued element: %d\n", temp->data);
    free(temp);
    return queue;
}
void printQueue(struct Queue* queue) {
    printf("Queue: ");
    struct ListNode* current = queue->front;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue* myQueue = (struct Queue*)malloc(sizeof(struct Queue));
    myQueue->front = myQueue->rear = NULL;

    myQueue = enqueue(myQueue, 2);
    myQueue = enqueue(myQueue, 4);
    myQueue = enqueue(myQueue, 6);

    printQueue(myQueue);

    // Dequeuing elements from the queue
    myQueue = dequeue(myQueue);
    myQueue = dequeue(myQueue);

    printQueue(myQueue);
    while (myQueue->front != NULL) {
        struct ListNode* temp = myQueue->front;
        myQueue->front = myQueue->front->next;
        free(temp);
    }

    free(myQueue);

    return 0;
}
