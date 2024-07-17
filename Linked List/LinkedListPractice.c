#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}N;

void insert_begining(N** head, int value){
    N* new_node = ((N*) malloc(sizeof(N)));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_pos(N* prevNode, int value){
    if(prevNode == NULL){
        printf("previous node is invalid");
        return;
    }
    N* new_node = ((N*) malloc(sizeof(N)));
    new_node->data = value;
    new_node->next = prevNode->next;
    prevNode->next = new_node;
}

void insert_last(N** head, int value){
    N* new_node = ((N*) malloc(sizeof(N)));
    new_node->data = value;
    new_node->next = NULL;
    N* last_node = *head;
    if(*head == NULL){
        *head = new_node;
    }
    while(last_node->next != NULL) last_node = last_node->next;
    last_node->next = new_node;
    return;
}

void del_first(N** head){
    if(*head == NULL){
        printf("Linked List is empty");
        return;
    }
    N* first_node = *head;
    *head = first_node->next;
    free(first_node);
    return;
}

void printList(N* node) {
    while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
    }
}

int main(){
    N* head = NULL;
    insert_last(&head, 1);
    insert_begining(&head, 2);
    insert_begining(&head, 3);
    insert_last(&head, 4);
    insert_at_pos(head->next, 5);

    printf("Linked list: ");
    printList(head);
    printf("\n");

    printf("\nAfter deleting an element: ");
    del_first(&head);
    printList(head);
    return 0;
}