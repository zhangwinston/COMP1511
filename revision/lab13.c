#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    struct node *next;
    int          data;
};

// Return number of nodes in the list containing value.

int count(int value, struct node *head) {
    struct node *current = head;
    int counter = 0;
    while (current != NULL) {
        if (current->data == value) {
            counter++;
        }
        current = current->next;
    }
    return counter;
}

// Return a pointer to the node in  position n in the list.
// Position 0 is the first node in the list.
// Return NULL if the list has no n-th node.

struct node *get_nth(int n, struct node *head) {
    struct node *current = head;
    int counter = 0;
    int length = 0;
    while (current != NULL) {
        current = current->next;
        length++;
    }
    if (n == 0) {
        return head;
    }
    if (n > length || n < 0) {
        return NULL;
    }
    current = head;
    while (counter != n) {
        counter++;
        current = current->next;
    }
    return current;
}

// Delete the node in  position  n in the list.
// The deleted nodes is freed.
// The first node in the list is in position 0.
// Do nothing if there is no position n in the list.
// The head of the list is returned.

struct node *delete_nth(int n, struct node *head) {
    struct node *current = head;
    struct node *prev = head;
    if (n == 0 && head == NULL) {
        return head;
    }
    int i = 0;
    while (current != NULL) {
        current = current->next;
        i++;
    }
    if (n > i || n < 0) {
        return head;
    }
    current = head;
    if (n == 0) {
        if (i == 1) {
            free(head);
            return NULL;
        } else {
            current = head->next;
            free(head);
            return current;
        }
    }
    i = 0;
    current = head;
    while (i != n) {
        current = current->next;
        i++;
    }
    while (prev->next != current) {
        prev = prev->next;
    }
    if (prev->next != NULL) {
        prev->next = current->next;
        free(current);
    }
    return head;
}


// Delete all nodes in the list containing odd numbers.
// Any deleted nodes are freed.
// The head of the list is returned.

struct node *delete_odd(struct node *head) {
    if (head == NULL) {
        return head;
    }
    struct node *cur = head;
    struct node *temp = head;
    struct node *prev = head;
    while (head->data % 2 != 0) {
        temp = head;
        if (head->next == NULL) {
            free(head);
            return NULL;
        }
        head = head->next;
        free(temp);
    }
    cur = head->next;
    while (cur != NULL) {
        if (cur->data % 2 == 0) {
            cur = cur->next;
        } else if (cur->data % 2 != 0) {
            temp = cur;
            cur = cur->next;
            prev = head;
            while (prev->next != temp) {
                prev = prev->next;
            }
            if (prev->next != NULL) {
                prev->next = temp->next;
                free(temp);
            } else {
                free(temp);
            }
        }
    }
    return head;
}

// Insert new_node before position n in the list.
// The first node in the list is in position 0.
// If n == length of the list, new_node is appended to list.
// Otherwise do nothing if there is no position n in the list.
// The head of the list is returned.

struct node *insert_nth(int n, struct node *new_node, struct node *head) {
    struct node *cur = head;
    struct node *prev = head;
    int i = 0;
    while (cur != NULL) {
        cur = cur->next;
        i++;
    }
    if (n > i || n < 0) {
        return head;
    }
    cur = head;
    if (n == 0) {
        head = new_node;
        new_node->next = cur;
        return head;
    }
    cur = head;
    if (n == i) {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
        new_node->next = NULL;
        return head;
    }
    cur = head;
    i = 0;
    while (i + 1 != n) {
        cur = cur->next;
        i++;
    }
    prev = cur->next;
    cur->next = new_node;
    new_node->next = prev;
    
    return head;
}


// THE CODE BELOW HERE IS TO TEST YOUR FUNCTIONS
// DO NOT CHANGE IT

void print_list(struct node *head);
struct node *reverse(struct node *list);
struct node *create_node(int data, struct node *next);
int length(struct node *head);
struct node *last(struct node *head);
struct node *append(struct node *head, int value);
void free_list(struct node *head);
static void check_list(struct node *head, char *name, int original_list_length, struct node *original_nodes[], int original_data_fields[]);

#define MAX_LINE 4096

// simple main function to test delete_first, delete_last, delete_contains, reverse

int
main(int argc, char *argv[]) {
    char line[MAX_LINE];
    struct node *list_head = NULL;

    while (1) {
        // save state of of list so we can check student functions
        // only perform permitted operations
        int list_length = length(list_head);
        struct node *nodes[list_length+1]; // ensure non-zero length for VLA
        int data[list_length+1];
        int j = 0;
        struct node *n = list_head;
        while (n != NULL) {
            nodes[j] = n;
            data[j] = n->data;
            n = n->next;
            j++;
        }

        printf("list = ");
        print_list(list_head);
        printf("\n");

        printf("> ");
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            // free memory even though program is exiting
            // so we can check for memory not freed by other functions
            // by running dcc --leak-check
            free_list(list_head);
            return 0;
        }

        int i = 0;
        while (isalpha(line[i]) || line[i] == '_') {
            i++;
        }
        int argument = atoi(&line[i]);
        line[i] = '\0';

        if (strcmp(line, "append") == 0) {
            list_head = append(list_head, argument);
            continue; // need to skip check_list
        } else if (strcmp(line, "count") == 0) {
            printf("count(%d) returns %d\n", argument, count(argument, list_head));
        } else if (strcmp(line, "get_nth") == 0) {
            struct node *n = get_nth(argument, list_head);
            if (n == NULL) {
                printf("get_nth(%d) returned NULL\n", argument);
            } else {
                printf("get_nth(%d) returned a pointer to a node containing %d\n", argument, n->data);
            }
        } else if (strcmp(line, "delete_nth") == 0) {
            list_head = delete_nth(argument, list_head);
        } else if (strcmp(line, "insert_nth") == 0) {
            // insert a node containing 42
            struct node *new_node = create_node(42, NULL);
            list_head = insert_nth(argument, new_node, list_head);
            // include new node in nodes given to check_list
            nodes[list_length] = new_node;
            data[list_length] = new_node->data;
            list_length++;
        } else if (strcmp(line, "delete_odd") == 0) {
            list_head = delete_odd(list_head);
        } else if (strcmp(line, "") != 0) {
            printf("Unknown command: '%s'\n", line);
        }

        check_list(list_head, "returned list", list_length, nodes, data);
    }
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
    if (head == NULL || head->next == NULL) {
        return head;
    }
    return last(head->next);
}

int length(struct node *head) {
    int len = 0;
    for (struct node *n = head; n != NULL; n = n->next) {
        len++;
    }
    return len;
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
    if (head != NULL) {
        free_list(head->next);
        free(head);
    }
}

// You are not expected to understand the following code.
// It uses complex internal compiler features to
// print informative messages for student errors.

// detect clang address-sanitizer
#ifdef __has_feature
#if __has_feature(address_sanitizer)
// clang address-sanitizer
#define HAVE_ASAN
#endif
#endif

// detect gcc address-sanitizer
#ifdef __SANITIZE_ADDRESS__
#define HAVE_ASAN
#endif

#ifdef HAVE_ASAN
#include <sanitizer/asan_interface.h>
#include <stdint.h>
#include <string.h>

// return NULL if p appears to be a valid pointer to a malloc'ed region of size size
// otherwise return string describing pointer

static char *check_address_is_heap_pointer(void *p, size_t size) {
    if (!p)
        return NULL;
    if ((sizeof(p) == 8 && (uintptr_t)p == 0xbebebebebebebebe) || (sizeof(p) == 4 && (uintptr_t)p == 0xbebebebe))
        return "uninitialized";
    if (__asan_region_is_poisoned(p, size))
        return "invalid";
    char name[8]; // unused but required by __asan_locate_address
    void *region_address;
    size_t region_size;
    if (strcmp(__asan_locate_address(p, name, sizeof name, &region_address, &region_size), "heap") != 0)
        return "invalid (not from malloc)";
    return NULL;
}

// Use address-sanitizer and other methods to detect invalid pointers in a malloc'ed linked list
// name should be a string describing the list
// If original_nodes != NULL then every node is checked to ensure it is the array original_nodes
// If original_data_fields != NULL then every data field is checked to see if matches the element
// of original_data_fields at the same index as it node appears in original_nodes
// original_nodes and original_data_fields should be of length original_list_length

static void check_list(struct node *head, char *name, int original_list_length, struct node *original_nodes[], int original_data_fields[]) {
    char *pointer_description;
    if ((pointer_description = check_address_is_heap_pointer(head, sizeof *head))) {
        fprintf(stderr, "\nError: the head of %s is %s (%p)\n", name, pointer_description, head);
        exit(1);
    }
    int position = 0;
    for (struct node *n = head; n != NULL; n = n->next, position++) {
        // If you're getting an error here,
        // you have returned an invalid list
        int error = 0;
        if ((unsigned)n->data == 0xbebebebe) {
            fprintf(stderr, "Error: %s is invalid.\n", name);
            fprintf(stderr, "       The data field of node %d is uninitialized.\n", position);
            error = 1;
        }
        if ((pointer_description = check_address_is_heap_pointer(n->next, sizeof *(n->next)))) {
            if (!error)
                fprintf(stderr, "Error: %s is invalid.\n", name);
            fprintf(stderr, "       The next field of node %d is %s (%p).\n", position, pointer_description, n->next);
            error = 1;
        }
        if (error) {
            if (position) {
                fprintf(stderr, "       The data fields of nodes 0..%d in the list contain: [", position);
                for (struct node *m = head; m != n; m = m->next) {
                    fprintf(stderr, "%d, ", m->data);
                }
                fprintf(stderr, "%d]\n", n->data);
            }
            exit(1);
        }


        int position1 = 0;
        for (struct node *o = head;; o = o->next, position1++) {
            if (o == n->next) {
                if (position == position1) {
                    fprintf(stderr, "Error: %s is invalid.\n", name);
                    fprintf(stderr, "       The next field of node %d points to itself\n", position);
                } else  {
                    fprintf(stderr, "Error: %s is invalid.\n", name);
                    fprintf(stderr, "       The next field of node %d points to node %d.\n", position, position1);
                    fprintf(stderr, "       In other words, %s is circular.\n", name);
                }
                exit(1);
            }
            if (o == n)
                break;
        }

        if (original_list_length && original_nodes) {
            int i;
            for (i = 0; i < original_list_length; i++) {
                if (original_nodes[i] == n)
                    break;
            }

            if (i == original_list_length) {
                fprintf(stderr, "Error: %s is invalid.\n", name);
                fprintf(stderr, "       The node in position %d is not in the list it was given.\n", position);
                fprintf(stderr, "       Do not create new nodes with malloc\n");
                exit(1);
            }

            if (original_data_fields && original_data_fields[i] != n->data) {
                fprintf(stderr, "Error: %s is invalid.\n", name);
                fprintf(stderr, "       The node in position %d data field has been changed from %d to %d.\n", position, original_data_fields[i], n->data);
                fprintf(stderr, "       Do not change the data fields of nodes\n");
                exit(1);
            }
        }
    }
}
#else
static void check_list(struct node *head, char *name, int original_list_length, struct node *original_nodes[], int original_data_fields[]) {
}
#endif
