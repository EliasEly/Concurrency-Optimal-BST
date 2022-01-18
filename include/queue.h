#ifndef __QUEUE_H__
#define __QUEUE_H__ 1

typedef struct queue {
    int* values;
    int size;
    int head;
    int tail;
} queue;

queue* create_queue(int size);

void delete_queue(queue* q);

int is_full(queue* q);

int is_empty(queue* q);

int push(queue* q, int v);

int pop(queue* q);

#endif