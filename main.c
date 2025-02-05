#include <stdio.h>
#include "list.h"

int main()
{
    Node* head = createNode(10);
    setNext(head, createNode(20));
    setNext(getNext(head), createNode(30));

    printf("First node value: %d\n", getValue(head));

    setValue(head, 25);
    printf("Updated first node value: %d\n", getValue(head));

    printf("Next node value: %d\n", getValue(getNext(head)));


    Node* current = head;
    while (current != NULL)
    {
        printf("%d ", getValue(current));
        current = getNext(current);
    }

    printf("\n");
    // Cleanup: delete remaining nodes
    while (head)
    {
        Node* temp = head;
        head = getNext(head);
        deleteNode(temp);
    }


    return 0;
}
