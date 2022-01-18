#include <stdlib.h>

#ifndef __QUEUE_H__
#include "queue.h"
#endif

queue* create_queue(int size){
    queue* q = (queue*)malloc(sizeof(queue));
    q->values = (int*)malloc(size*sizeof(int));
    for(int i = 0; i < size; i++)
        q->values[i] = -1;
    q->size = size;
    q->head = 0;
    q->tail = 0;
    return q;
}

void delete_queue(queue* q){
    if (q != NULL){
        free(q->values);
        free(q);
    }
}

int is_full(queue* q){
    int head = q->head, tail = q->tail;
    int* values = q->values;
    return head == tail && values[tail] != -1 ? 1 : 0;
}

int is_empty(queue* q){
    int head = q->head, tail = q->tail;
    int* values = q->values;
    return head == tail && values[tail] == -1 ? 1 : 0;
}

int push(queue* q, int v){
    if (!is_full(q)){
        int new_tail = (q->tail + 1) % q->size;
        q->values[q->tail] = v;
        q->tail = new_tail;
        return 0;
    }
    return -1;
}

int pop(queue* q){
    if(!is_empty(q)){
        int v, new_head;
        new_head = (q->head + 1) % q->size;
        v = q->values[q->head];
        q->values[q->head] = -1;
        q->head = new_head;
        return v;
    }
    return -1;
}