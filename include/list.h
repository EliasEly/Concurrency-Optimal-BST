#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__ 1

typedef struct list {
    void* obj;
    struct list* next;
} list;

list* create_list(void* obj, list* next);

#endif