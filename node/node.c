#include <stdio.h>
#include <stdlib.h>

struct product {
    int id;
    char name[50];
    float price;
};

struct node {
    struct product data;
    struct node *next;
    struct node *prev;
};

struct node *header = NULL;

struct node *getnode(int n) {
    struct node *ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL) {
        printf("Memory Allocation failed..");
        exit(0);
    }
    ptrnew->data.id = n;
    ptrnew->next = NULL;
    ptrnew->prev = NULL;
    return ptrnew;
}

void insertFirst(struct node *ptrnew) {
    if (header != NULL) {
        header->prev = ptrnew;
    }
    ptrnew->next = header;
    ptrnew->prev = NULL;
    header = ptrnew;
}

void insertLast(struct node *ptrnew){
    struct node *ptrthis = header;
    if (header == NULL) {
        header = ptrnew;
    } else {
        while (ptrthis->next != NULL) {
            ptrthis = ptrthis->next;
        }
        ptrthis->next = ptrnew;
        ptrnew->prev = ptrthis;
    }
}

void display() {
    struct node *ptrthis = header;
    if (header == NULL) {
        printf("List is Empty..\n");
    } else {
        printf("List Contains:\n");
        while (ptrthis != NULL) {
            printf("%d ", ptrthis->data.id);
            ptrthis = ptrthis->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int i;
    printf(".............DOUBLY LINKED LIST....................\n");
    for (i = 0; i < 10; i++) {
        insertFirst(getnode(i + 1));
    }
    display();

    do {
        printf("Enter your choice\n");
        printf("1. Insert First\n2. Insert At last\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter the value to insert at the beginning: ");
                int val1;
                scanf("%d", &val1);
                insertFirst(getnode(val1));
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                int val2;
                scanf("%d", &val2);
                insertLast(getnode(val2));
                break;
            case 3: 
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (1);

    return 0;
}
