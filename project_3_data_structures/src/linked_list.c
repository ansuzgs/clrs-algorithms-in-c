#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

static node *create_node(const int value) {
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
        return NULL;
    n->value = value;
    n->next = NULL;
    return n;
}

void insert_node_end(node *head, const int value) {
    node *n = create_node(value);
    if (n == NULL)
        perror("error inserting node");
    node *curr_node = head;
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
    }
    curr_node->next = n;
    printf("Inserted node\n");
}

node *create_singly_linked_list(const int value) {
    node *head = create_node(value);
    return (head == NULL) ? NULL : head;
}

void print_singly_linked_list(node *head) {
    node *curr_node = head;
    while (curr_node != NULL) {
        printf("%d -> ", curr_node->value);
        curr_node = curr_node->next;
    }
    printf("NULL\n");
}

int search_singly_linked_list(node *head, const int value) {
    node *curr_node = head;
    while (curr_node != NULL) {
        if (curr_node->value == value)
            return 0;
        curr_node = curr_node->next;
    }
    return 1;
}

void delete_head_singly_linked_list(node **head) {
    node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void delete_singly_linked_list(node **head) {
    while (*head != NULL) {
        delete_head_singly_linked_list(head);
    }
}

int singly_linked_length(node *head) {
    int len = 0;
    while (head != NULL) {
        head = head->next;
        len++;
    }
    return len;
}
