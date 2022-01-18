#include <stdlib.h>
#include <stdio.h>

#include "list.h"

list* create_list(void* obj, list* next){
    list* l = (list*)malloc(sizeof(list));
    l->obj = obj;
    l->next = next;
    return l;
}

list* append(list* l, void* obj){
    while(l->next == NULL)
        l = l->next;
    l->next = create_list(obj, NULL);
    return l;
}

