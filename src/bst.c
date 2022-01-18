#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

bst* create_node_typed(node_type type, int value, bst* left, bst* right) {
    bst* node = malloc(sizeof(bst));
    node->type = type;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

bst* create_node(int value, bst* left, bst* right){
    bst* node = malloc(sizeof(bst));
    node->type = DATA;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

int add_node(bst* root, bst* node){
    last_visited* lv = traversal(root, node->value);
    if (lv->last != NULL){
        if (lv->last->type == DATA){
            return -1;
        } else {
            lv->last->type = DATA;
        }
    } else {
        if (lv->prev->value > node->value) {
                lv->prev->left = node;
        } else {
            lv->prev->right = node;
        }
    }
    free(lv);
    return 1;
}

int delete_node(bst* root, bst* node){
    last_visited* lv = traversal(root, node->value);
    if (lv->last == NULL || lv->last->type != DATA)
        return -1;

    if (lv->last->left != NULL && lv->last->right != NULL){
        lv->last->type = ROUTING;
    } else if (lv->last->left != NULL || lv->last->right != NULL) {
        bst* child;
        if (lv->last->left != NULL)
            child = lv->last->left;
        else
            child = lv->last->right;

        if (lv->last->value < lv->prev->value)
            lv->prev->left = child;
        else
            lv->prev->right = child;

        free(lv->last);
    } else if (is_leaf(lv->last)){
        if (lv->prev->type == DATA) {
            if (lv->last == lv->prev->left)
                lv->prev->left = NULL;
            else 
                lv->prev->right = NULL;
        } else {
            bst* child;
            if (lv->last == lv->prev->left)
                child = lv->prev->right;
            else 
                child = lv->prev->left;
            
            if (lv->prev == lv->gprev->left)
                lv->gprev->left = child;
            else
                lv->gprev->right = child;
            
        }
        free(lv->last);
    }
    
    free(lv);
    return 1;
}

int contains(bst* root, int value){
    last_visited* lv = traversal(root, value);
    int res = lv->last != NULL && lv->last->type == DATA && lv->last->value == value ? 1 : 0;
    free(lv);
    return res;
}


last_visited* traversal(bst* root, int value){
    last_visited* lv = (last_visited*)malloc(sizeof(last_visited));
    lv->gprev = NULL, lv->prev = NULL, lv->last = root;
    
    while(lv->last != NULL){
        if (lv->last->value == value){
            break;
        } else {
            lv->gprev = lv->prev;
            lv->prev = lv->last;
            if(lv->last->value < value)
                lv->last = lv->last->right;
            else 
                lv->last = lv->last->left;
        }
    }

    return lv;
}

int is_leaf(bst* node){
    return node != NULL && node->left == NULL && node->right == NULL ? 1 : 0;
}

int is_bst(bst* root){
    queue* q = create_queue(128);
    int err = 0;
    dfs(root, q, &err);

    if(is_empty(q))
        goto EXIT;

    int previous = pop(q), current;
    while(!is_empty(q)){
        current = pop(q);
        if (previous > current)
            return -1;
        else
            previous = current;
    }
    
    EXIT:
        free(q);
        return 1;
}

void dfs(bst* root, queue* q, int* err){
    if(is_full(q))
        *err = -1;
    
    if(root == NULL || *err == -1)
        return;
    
    dfs(root->left, q, err);
    if(root->type == DATA)
        push(q, root->value);
    dfs(root->right, q, err);
}

