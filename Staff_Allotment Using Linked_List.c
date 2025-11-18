#include <stdio.h>
#include <stdlib.h>

struct Staff {
    int id;
    char name[50];
    char dept[20];
    struct Staff *next;
};

typedef struct Staff Staff;

Staff *head = NULL;

void copyString(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// 1. Add at Beginning
void addAtBeginning(int id, char name[], char dept[]) {
    Staff *newStaff = (Staff *)malloc(sizeof(Staff));
    newStaff->id = id;
    copyString(newStaff->name, name);
    copyString(newStaff->dept, dept);
    newStaff->next = head;
    head = newStaff;
}

// 2. Add at End
void addAtEnd(int id, char name[], char dept[]) {
    Staff *newStaff = (Staff *)malloc(sizeof(Staff));
    newStaff->id = id;
    copyString(newStaff->name, name);
    copyString(newStaff->dept, dept);
    newStaff->next = NULL;

    if (head == NULL) {
        head = newStaff;
        return;
    }

    Staff *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newStaff;
}

// 3. Insert at Position
void insertAtPosition(int id, char name[], char dept[], int pos) {
    Staff *newStaff = (Staff *)malloc(sizeof(Staff));
    newStaff->id = id;
    copyString(newStaff->name, name);
    copyString(newStaff->dept, dept);

    if (pos == 1) {
        newStaff->next = head;
        head = newStaff;
        return;
    }

    Staff *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newStaff);
        return;
    }

    newStaff->next = temp->next;
    temp->next = newStaff;
}

// 4. Delete by Position
void deleteByPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Staff *temp = head;

    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    Staff *prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// 5. Search by ID or Name
void searchStaff() {
    int idChoice;
    char nameChoice[50];
    int option;

    printf("Search by:\n1. ID\n2. Name\nEnter choice: ");
    scanf("%d", &option);

    Staff *temp = head;

    if (option == 1) {
        printf("Enter Staff ID: ");
        scanf("%d", &idChoice);

        while (temp != NULL) {
            if (temp->id == idChoice) {
                printf("Found: %d | %s | %s\n", temp->id, temp->name, temp->dept);
                return;
            }
            temp = temp->next;
        }
    }
    else if (option == 2) {
        printf("Enter Staff Name: ");
        scanf("%s", nameChoice);

        while (temp != NULL) {
            int i = 0, match = 1;
            while (nameChoice[i] != '\0') {
                if (nameChoice[i] != temp->name[i]) {
                    match = 0;
                    break;
                }
                i++;
            }
            if (match && temp->name[i] == '\0') {
                printf("Found: %d | %s | %s\n", temp->id, temp->name, temp->dept);
                return;
            }
            temp = temp->next;
        }
    }

    printf("Staff not found.\n");
}

// 6. Display all Staff
void displayList() {
    Staff *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d | %s | %s\n", temp->id, temp->name, temp->dept);
        temp = temp->next;
    }
}

int main() {
    int choice, id, pos;
    char name[50], dept[20];

    while (1) {
        printf("\n Staff Allotment Menu \n");
        printf("1. Add at Beginning\n");
        printf("2. Add at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Search Staff\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID, Name, Dept: ");
                scanf("%d %s %s", &id, name, dept);
                addAtBeginning(id, name, dept);
                break;

            case 2:
                printf("Enter ID, Name, Dept: ");
                scanf("%d %s %s", &id, name, dept);
                addAtEnd(id, name, dept);
                break;

            case 3:
                printf("Enter ID, Name, Dept, Position: ");
                scanf("%d %s %s %d", &id, name, dept, &pos);
                insertAtPosition(id, name, dept, pos);
                break;

            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteByPosition(pos);
                break;

            case 5:
                searchStaff();
                break;

            case 6:
                displayList();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}
