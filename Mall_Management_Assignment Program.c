#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Shop {
    int shopID;
    char shopName[50];
    struct Shop* next;
};

struct Shop* head = NULL;

// Add shop at the end
void addShopEnd(int id, char name[]) {
    struct Shop* newShop = (struct Shop*)malloc(sizeof(struct Shop));
    newShop->shopID = id;
    strcpy(newShop->shopName, name);
    newShop->next = NULL;

    if (head == NULL) {   // If list is empty
        head = newShop;
        return;
    }

    struct Shop* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newShop;
}
// Insert after a given shop ID
void insertAfter(int id, int newID, char newName[]) {
    struct Shop* temp = head;

    while (temp != NULL && temp->shopID != id)
        temp = temp->next;

    if (temp == NULL) {
        printf("Shop with ID %d not found.\n", id);
        return;
    }

    struct Shop* newShop = (struct Shop*)malloc(sizeof(struct Shop));
    newShop->shopID = newID;
    strcpy(newShop->shopName, newName);

    newShop->next = temp->next;
    temp->next = newShop;
}

// Remove a shop using ID
void removeShop(int id) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Shop* temp = head;
    struct Shop* prev = NULL;

    // If head node is to be removed
    if (temp != NULL && temp->shopID == id) {
        head = temp->next;
        free(temp);
        printf("Shop %d removed successfully.\n", id);
        return;
    }

    while (temp != NULL && temp->shopID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Shop with ID %d not found.\n", id);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Shop %d removed successfully.\n", id);
}

// Search shop by name
void searchByName(char name[]) {
    struct Shop* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->shopName, name) == 0) {
            printf("Shop found! ID: %d, Name: %s\n", temp->shopID, temp->shopName);
            return;
        }
        temp = temp->next;
    }
    printf("Shop '%s' not found.\n", name);
}

// Display shops
void displayShops() {
    struct Shop* temp = head;
    if (temp == NULL) {
        printf("No shops in the corridor.\n");
        return;
    }

    printf("\nList of Shops:\n");
    while (temp != NULL) {
        printf("Shop ID: %d, Name: %s\n", temp->shopID, temp->shopName);
        temp = temp->next;
    }
}

int main() {
    int choice, id, afterID;
    char name[50];

    while (1) {
        printf("\n Shopping Complex Menu \n");
        printf("1. Add Shop at End\n");
        printf("2. Insert Shop After ID\n");
        printf("3. Remove Shop\n");
        printf("4. Search Shop by Name\n");
        printf("5. Display All Shops\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Shop ID: ");
                scanf("%d", &id);
                printf("Enter Shop Name: ");
                scanf(" %[^\n]", name);
                addShopEnd(id, name);
                break;

            case 2:
                printf("Enter Existing Shop ID to insert after: ");
                scanf("%d", &afterID);
                printf("Enter New Shop ID: ");
                scanf("%d", &id);
                printf("Enter New Shop Name: ");
                scanf(" %[^\n]", name);
                insertAfter(afterID, id, name);
                break;

            case 3:
                printf("Enter Shop ID to remove: ");
                scanf("%d", &id);
                removeShop(id);
                break;

            case 4:
                printf("Enter Shop Name to search: ");
                scanf(" %[^\n]", name);
                searchByName(name);
                break;

            case 5:
                displayShops();
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}
