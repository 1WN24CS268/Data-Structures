#include <stdio.h>
#define M 100
typedef struct {
    int key;
    int used;
} Record;

int hash(int k) {
    return k % M;
}

void insert(Record ht[], int k) {
    int i = hash(k);
    int start = i;

    while (ht[i].used) {
        i = (i + 1) % M;
        if (i == start)
            return;
    }

    ht[i].key = k;
    ht[i].used = 1;
}

int search(Record ht[], int k) {
    int i = hash(k);
    int start = i;

    while (ht[i].used) {
        if (ht[i].key == k)
            return i;
        i = (i + 1) % M;
        if (i == start)
            break;
    }
    return -1;
}

int main() {
    Record ht[M];
    int n, k, i, choice, pos;
    for (i = 0; i < M; i++)
        ht[i].used = 0;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter 4-digit key: ");
        scanf("%d", &k);
        insert(ht, k);
    }

    do {
        printf("Enter key to search: ");
        scanf("%d", &k);

        pos = search(ht, k);
        if (pos == -1)
            printf("Not Found\n");
        else
            printf("Found at address %02d\n", pos);

        printf("Search another key? (1-Yes / 0-No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return 0;
}
