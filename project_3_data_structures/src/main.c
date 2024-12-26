#include <stdio.h>

#include "linked_list.h"

int main() {

    node *head = create_singly_linked_list(1);
    insert_node_end(head, 2);
    insert_node_end(head, 3);

    printf("%d\n", head->value);
    printf("node 2 from node 1 = %d\n", head->next->value);
    printf("Longitud de la linked list: %d\n", singly_linked_length(head));
    print_singly_linked_list(head);
    int found = search_singly_linked_list(head, 2);
    printf("%s\n", (found == 0) ? "found" : "not found");
    delete_head_singly_linked_list(&head);
    printf("deleted\n");
    print_singly_linked_list(head);
    printf("Longitud de la linked list: %d\n", singly_linked_length(head));
    delete_singly_linked_list(&head);
    print_singly_linked_list(head);
    printf("Longitud de la linked list: %d\n", singly_linked_length(head));
    return 0;
}
