#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node_t, *node_ptr_t;

typedef struct linked_list {
    node_t *head;
    int size;
} ll_t, *ll_ptr_t;

// prototypes
ll_t* create_default_list();
bool addNode(int data);
bool removeNode(int data);
void print_list();

// globals
ll_t *list;

void main(int argc, char *argv) {
    list = create_default_list();
    print_list();

    addNode(3);
    print_list();
    removeNode(3);
    print_list();
}

void print_list() {
    node_t *tmp = list->head;
    while (tmp->next != NULL) {
        printf("%d <-> ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->data);
}

node_t *create_new_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
}

ll_t* create_default_list() {
    list = malloc(sizeof(ll_t));
    if (list == NULL) {
        return NULL;
    }
    list->size = 0;

    for (int i = 1; i <= 5; i++) {
        addNode(i);
    }
    return list;
}

// iterate linked list from beginning
// add in sorted order
bool addNode(int data) {
    node_t *new_node = create_new_node(data);

    if (list->size == 0) {   // empty list
        list->head = new_node;
        list->size++;
        return true;
    }

    node_t *ptr = list->head;
    while (ptr->next != NULL && ptr->data <= new_node->data) {
        ptr = ptr->next;
    }
    assert(ptr->next == NULL || new_node->data < ptr->data);

    // special head case
    if (new_node->data < list->head->data) {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }

    else if (ptr->data < new_node->data) {
        new_node->next = ptr->next;
        new_node->prev = ptr;
        if (ptr->next != 0)
            ptr->next->prev = new_node;
        ptr->next = new_node;
    }

    else if (ptr == NULL) {
        ptr->prev->next = new_node;
        new_node->prev = ptr->prev;
    }
    else if (new_node->data < ptr->data) {
        new_node->next = ptr;
        new_node->prev = ptr->prev;
        ptr->prev->next = new_node;
    }
    list->size++;
    return true;
}

bool removeNode(int data) {
    node_t *tmp = list->head;
    while (tmp != NULL) {
        if (tmp->data == data) {
            if (tmp == list->head) {
                list->head = list->head->next;
                return true;
            } else {
                tmp->prev->next = tmp->next;
                if (tmp->next != 0) {
                    tmp->next->prev = tmp->prev;
                }
                return true;
            }
        }
        tmp = tmp->next;
    }

    return false;
}

