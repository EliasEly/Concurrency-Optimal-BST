#ifndef __BST_H__
#define __BST_H__ 1

#include "queue.h"
#include "list.h"

typedef enum node_type { DATA , ROUTING } node_type;

typedef struct _bst {
    node_type type;
    int value;
    struct _bst* left;
    struct _bst* right;
} bst;

typedef struct last_visited {
    bst* gprev;
    bst* prev;
    bst* last;
} last_visited;

bst* create_node_typed(node_type type, int value, bst* left, bst* right);

bst* create_node(int value, bst* left, bst* right);

int add_node(bst* root, bst* node);

int delete_node(bst* root, bst* node);

int contains(bst* root, int value);

last_visited* traversal(bst* root, int value);

int is_leaf(bst* node);

int is_bst(bst* root);

void dfs(bst* root, queue* q, int* err);

#endif