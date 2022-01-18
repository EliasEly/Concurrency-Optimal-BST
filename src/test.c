#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "test.h"
#include "bst.h"

#ifndef __QUEUE_H__
#include "queue.h"
#endif 

int main(int argc, char** argv){
    printf("Running tests...\n");
    printf("\tQueue tests...\n");
    queue_test();
    printf("\tBST tests...\n");
    bst_test();
    return 0;
}

void queue_test(){
    queue_t1();
}

void queue_t1(){
    queue* q = create_queue(128);
    assert(q->size == 128);
    assert(q->head == 0);
    assert(q->tail == 0);
    assert(is_empty(q));
}

void bst_test(){

}