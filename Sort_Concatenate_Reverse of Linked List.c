#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Sort list (simple bubble sort)
void sortList(struct Node** head) {
    struct Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Reverse list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Concatenate lists
void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;

    // Original List 1
    insertEnd(&list1, 10);
    insertEnd(&list1, 20);
    insertEnd(&list1, 30);
    insertEnd(&list1, 40);

    printf("Original List 1 : ");
    printList(list1);

    // Sorted List
    sortList(&list1);
    printf("List 1 sorted -> ");
    printList(list1);

    // Reversed List
    list1 = reverseList(list1);
    printf("List 1 reversed -> ");
    printList(list1);

    // Second list for concatenation
    insertEnd(&list2, 100);
    insertEnd(&list2, 200);

    concatenate(&list1, list2);
    printf("Concatenation done\n");
    printList(list1);

    return 0;
}
