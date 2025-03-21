#include "queue.h"
#include <stdlib.h>

Queue* queue_create() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        return NULL;
    }
    q->head = q->tail = NULL;
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q == NULL) return;
    Node *node = new_node(d);
    if (node == NULL) return;
    if (q->tail == NULL) {
        q->head = q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
}

Data queue_dequeue(Queue* q) {
    if (q == NULL || q->head == NULL) return -1; 
    Node *temp = q->head;
    Data value = temp->data;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->head = NULL;
    }
    delete_node(temp);
    return value;
}

bool queue_is_empty(Queue* q) {
    return q == NULL || q->head == NULL;
}

Data queue_front(Queue* q) {
    if (q == NULL || q->head == NULL) return -1;
    return q->head->data;
}

void queue_empty(Queue* q) {
    while (!queue_is_empty(q)) {
        queue_dequeue(q);
    }
}

void queue_delete(Queue* q) {
    if (q == NULL) return;
    queue_empty(q);
    free(q);
}