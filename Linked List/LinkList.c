#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;  
}N;
N *head, *newnode, *temp;


void newNode(int choice){
    N *head, *newnode, *temp;
    head=0;
    while(choice){
        newnode = (N*) malloc(sizeof(N));
        printf("enter the value: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if(head == 0)
            head = newnode;
        else{
            temp->next = newnode;
            temp = newnode; 
        }
    }
    
}

void printList(){
    temp = head;
    while (temp!=0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}

void main()
{
    int choice;
    while(1){
        switch (choice)
        {
        case 1:
            newNode(1);
            break;
        case 2:
            printList();
            break;
        default:
            exit(0);
            break;
        }
    }
}
