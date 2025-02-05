#include<stdio.h>
#include "listDLL.h"

Node* reversed (Node* head){
    if(head == NULL) return NULL;

    Node* current = head ;
    Node* newHead = NULL;
    

    while (current){
        Node* prev = getPrev(current);
        setPrev(current , getNext(current));
        setNext(current , prev);
        newHead = current;
        current = getPrev(current);
    }
   
    return newHead;

}

int main (){

Node* head = createNode(0);
setNext(head , createNode(1));
setPrev(getNext(head), head);
setNext(getNext(head) , createNode(2));
setPrev(getNext(getNext(head)), getNext(head));

    printf("// the origanl DLL: \n");
    printList(&head);

    head = reversed(head);
    printf("\n");
    
    printf("// The reversed DLL:\n");
    printList(head);
 
    printf("\n");

    return 0;
}





