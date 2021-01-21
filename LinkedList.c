#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct linked_list {
    node_t *head;
    int size;
    node_t *tail;
} ll_t, *ll_ptr_t;

typedef struct node {
    int data;
    node_t *prev;
    node_t *next;
} node_t, *node_ptr_t;

// prototypes
ll_t* create_default_list();
bool add(node_t *new_node);

// globals
ll_t *list;

void main(int argc, char *argv) {
    list = create_default_list();

}

ll_t* create_default_list() {
    ll_t *list = malloc(sizeof(ll_t));
    if (list == NULL) {
        return NULL;
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = 1;
    new_node->prev = NULL;
    new_node->next = NULL;
    add(new_node);

}

// iterate linked list from beginning
// 
bool add(node_t *new_node) {
    

}

