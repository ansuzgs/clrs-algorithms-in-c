typedef struct node {
        int value;
        struct node *next;
} node;

void insert_node_end(node *head, const int value);
node *create_singly_linked_list(const int value);
void print_singly_linked_list(node *head);
int search_singly_linked_list(node *head, const int value);
void delete_head_singly_linked_list(node **head);
void delete_singly_linked_list(node **head);
int singly_linked_length(node *head);
