#include <stdio.h>
#include "listS.h"


void insert_at_head(Node** head, int value) {
    Node* newNode = createNode(value);
    setNext(newNode, *head);
    *head = newNode;
}


void insert_mid(Node* head, int index, int value) {
    Node* next = head;
    int count = 0;

    while (next != NULL && count < index - 1) {
        next = getNext(next);
        count++;
    }

    if (next == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    Node* newNode = createNode(value);
    setNext(newNode, getNext(next));
    setNext(next, newNode);
}


void insert_end(Node* head, int value) {
    Node* next = head;
    while (getNext(next) != NULL) {
        next = getNext(next);
    }

    Node* newNode = createNode(value);
    setNext(next, newNode);
}

int main() {
    
    Node* head = createNode(0);
    setNext(head, createNode(1));
    setNext(getNext(head), createNode(2));
    //the list that we are gonna work with
    
    printf("Enter the value of your node: ");
    int value; scanf("%d", &value);

    printf("Enter the index where u want to insert: ");
    int index; scanf("%d", &index);

    if (index == 0) {
        insert_at_head(&head, value); 
    } else {
        int count = 0;
        Node* next = head;
        while (next != NULL) {
            if (count == index - 1) {
                insert_mid(next, index, value);
                break;
            }
            next = getNext(next);
            count++;
        }

        if (next == NULL) {
            insert_end(head, value);
        }
    }
    printList(head);

    return 0;
}
