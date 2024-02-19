#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node* next;
};

// Pointer to last node in the list
struct node* last = NULL;

// Function to insert a node in the
// starting of the list
void insertAtFront(int data)
{
	// Initialize a new node
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	// If the new node is the only
	// node in the list
	if (last == NULL) {
		temp->info = data;
		temp->next = temp;
		last = temp;
	}

	// Else last node contains the
	// reference of the new node and
	// new node contains the reference
	// of the previous first node
	else {
		temp->info = data;
		temp->next = last->next;

		// last node now has reference
		// of the new node temp
		last->next = temp;
	}
}

void addatlast(int data)
{
    // Initialize a new node
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
 
    // If the new node is the
    // only node in the list
    if (last == NULL) {
        temp->info = data;
        temp->next = temp;
        last = temp;
    }
 
    // Else the new node will be the
    // last node and will contain
    // the reference of head node
    else {
        temp->info = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void insertafter()
{
    // Stores data and element after
    // which new node is to be inserted
    int data, value;
 
    // Initialize a new node
    struct node *temp, *n;
 
    // Input data
    printf("\nEnter number after which"
           " you want to enter number: \n");
    scanf("%d", &value);
    temp = last->next;
 
    do {
 
        // Element after which node is
        // to be inserted is found
        if (temp->info == value) {
            n = (struct node*)malloc(sizeof(struct node));
 
            // Input Data
            printf("\nEnter data to be"
                   " inserted : \n");
            scanf("%d", &data);
            n->info = data;
            n->next = temp->next;
            temp->next = n;
 
            // If temp is the last node
            // so now n will become the
            // last node
            if (temp == last)
                last = n;
            break;
        }
        else
            temp = temp->next;
    } while (temp != last->next);
}

void deletefirst()
{
    struct node* temp;
    if(last->next == last){
    	last = NULL;
    }
    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");
 
    // Else last node now contains
    // reference of the second node
    // in the list because the
    // list is circular
    else {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }
}

void deletelast()
{
    struct node* temp;
    if(last->next == last){
    	last = NULL;
    }
    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");
 
    temp = last->next;
 
    // Traverse the list till
    // the second last node
    while (temp->next != last)
        temp = temp->next;
 
    // Second last node now contains
    // the reference of the first
    // node in the list
    temp->next = last->next;
    free(last);
    last = temp;
}

void deleteAtIndex()
{
    // Stores the index at which
    // the element is to be deleted
    int pos, i = 1;
    struct node *temp, *position;
    temp = last->next;
    if(last->next == last){
    	last = NULL;
    }
    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");
 
    // Else
    else {
 
        // Input Data
        printf("\nEnter value to delete : ");
        scanf("%d", &pos);
 
        // Traverse till the node to
        // be deleted is reached
        while (i <= pos - 1) {
            temp = temp->next;
            i++;
        }
 
        // After the loop ends, temp
        // points at a node just before
        // the node to be deleted
 
        // Reassigning links
        position = temp->next;
        temp->next = position->next;
 
        free(position);
    }
}

// Function to print the list
void viewList()
{
    // If list is empty
    if (last == NULL)
        printf("\nList is empty\n");
 
    // Else print the list
    else {
        struct node* temp;
        temp = last->next;
        do {
            printf("\nData = %d", temp->info);
            temp = temp->next;
        } while (temp != last->next);
    }
}

// Driver Code
int main()
{
	int choice, data;

    while (1) {
        printf("\nCircular Linked list operations\n");
        printf("1. insert At Front\n");
        printf("2. insert at last\n");
        printf("3. insert after a position\n");
        printf("4. delete first\n");
        printf("5. delete last\n");
        printf("6. delete At Index\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert At Front: ");
                scanf("%d", &data);
                insertAtFront(data);
                viewList();
                break;
            case 2:
                printf("Enter data to insert At last: ");
                scanf("%d", &data);
                addatlast(data);
                viewList();
                break;
            case 3:
                insertafter();
                viewList();
                break;
            case 4:
                deletefirst();
                viewList();
                break;
            case 5:
                deletelast();
                viewList();
                break;
            case 6:
                deleteAtIndex();
                viewList();
                break;
            case 7:
                viewList();
                break;
            case 8:
            	viewList();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
	}

	return 0;
}

