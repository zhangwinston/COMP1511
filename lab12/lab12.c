#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    struct node *next;
    int       data;
};

struct node *create_node(int data, struct node *next);
struct node *last(struct node *head);
struct node *append(struct node *head, int value);
void free_list(struct node *head);
struct node *delete_first(struct node *head);
struct node *delete_last(struct node *head);
struct node *delete_contains(int i, struct node *head);
void print_list(struct node *head);
struct node *reverse(struct node *list);

#define MAX_LINE 4096

// simple main function to test delete_first, delete_last, delete_contains, reverse

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    struct node *list_head = NULL;

    while (1) {
        printf("list = ");
        print_list(list_head);
        printf("\n");

        printf("> ");
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            free_list(list_head);
            return 0;
        }

        int i = 0;
        while (isalpha(line[i]) || line[i] == '_') {
            i++;
        }
        int argument = atoi(&line[i]);
        line[i] = '\0';

        if (strcmp(line, "quit") == 0) {
            free_list(list_head);
            return 0;
        } else if (strcmp(line, "append") == 0) {
            list_head = append(list_head, argument);
        } else if (strcmp(line, "delete_first") == 0) {
            list_head = delete_first(list_head);
        } else if (strcmp(line, "delete_last") == 0) {
            list_head = delete_last(list_head);
        } else if (strcmp(line, "delete_contains") == 0) {
            list_head = delete_contains(argument, list_head);
        } else if (strcmp(line, "reverse") == 0) {
            list_head = reverse(list_head);
        } else if (strcmp(line, "") != 0) {
            printf("Unknown command: '%s'\n", line);
        }
    }
}

// delete first node in list

struct node *delete_first(struct node *head) {
    struct node *n = head;
    if (head == NULL) {
        return head;
    }    
    head = n->next;
    free(n);
    return head;
}

// delete last node in list

struct node *delete_last(struct node *head) {
    struct node *n = head;
    if (head == NULL) {
        return head;
    } else if (n->next == NULL) {
        head = NULL;
        return head;
    }
    while (n->next->next != NULL) {
        n = n->next;
    }
    n->next = NULL;
    free(n->next);
    return head;
}

// delete first node containing specified int

struct node *delete_contains(int i, struct node *head) {

    if (head == NULL) {
        return head;
    }
    struct node *n = head;
    if (n->data == i) {
        if (n->next == NULL) {
            head = NULL;
        } else {
            head = n->next;
        }
        return head;
    } else if (n->next == NULL) {
        return head;
    }

    if (n->next->data == i) {
        if (n->next->next != NULL) {
            n->next = n->next->next;
        } else {
            free(n->next);
            n->next = NULL;
        }
    }

    while (n->next != NULL) {    
        if (n->next->data == i) {
            if (n->next->next != NULL) {
                n->next = n->next->next;
            } else {
                free(n->next);
                n->next = NULL; 
            }
            return head;
        }
        n = n->next;
    }
    return head;
}

// reverse the nodes in list

struct node *reverse(struct node *head) {

    if (head == NULL) {
        return head;
    }
    struct node *n = head->next;
    if (n == NULL) {
        return head;
    }
    struct node *previous = head;
    struct node *forward = head->next->next;

    if (n->next == NULL) {
        previous->next = NULL;
        n->next = previous;
        return n;
    }
    previous->next = NULL;
    int i = 0;
    struct node *temp = n;
    while (n->next != NULL) {
        temp = n;
        n->next = previous;
        previous = temp;
        n = forward;
        if (forward->next != NULL) {
            forward = forward->next;
        }
    }
    n->next = previous;
    return n;
}

// print contents of list in Python syntax

void print_list(struct node *head) {
    printf("[");
    for (struct node *n = head; n != NULL; n = n->next) {
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

// return pointer to last node in list
// NULL is returned if list is empty

struct node *last(struct node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct node *n = head;
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}

// create a new list node containing value
// and append it to end of list

struct node *append(struct node *head, int value) {
    // new node will be last in list, so next field is NULL
    struct node *n =  create_node(value, NULL);
    if (head == NULL) {
        // new node is now  head of the list
        return n;
    } else {
        // change next field of last list node
        // from NULL to new node
        last(head)->next = n;  /* append node to list */
        return head;
    }
}

// Create a new struct node containing the specified data,
// and next fields, return a pointer to the new struct node.

struct node *create_node(int data, struct node *next) {
    struct node *n;

    n = malloc(sizeof (struct node));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    n->data = data;
    n->next = next;
    return n;
}

void free_list(struct node *head) {
    struct node *n = head;
    while (n != NULL) {
        struct node *next_node = n->next;
        free(n);
        n = next_node;
    }
}

