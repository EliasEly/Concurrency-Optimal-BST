#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main(int argc, char** argv){
    printf("Hello World!\n");
    
    bst* root = create_node(5, NULL, NULL);
    add_node(root, create_node(3, NULL, NULL));
    add_node(root, create_node(6, NULL, NULL));

    printf("is bst: %s\n", is_bst(root) == 1 ? "true" : "false");
    return 0;
}