// A C program to implement stack using linked list

#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
typedef struct node {
    int info; // data field
    struct node *next; // pointer to the next node
} STACK;

// A function to push an element to the stack
STACK *PUSH(STACK *top, int data) {
    STACK *nw = (STACK *)malloc(sizeof(STACK)); // allocate memory for the new node
    if (nw == NULL) { // check if memory allocation failed
        printf("Stack overflow\n");
        exit(0); // terminate the program
    }
    nw->info = data; // assign data to the new node
    nw->next = NULL; // initialize next pointer to NULL
    if (top == NULL) { // check if the stack is empty
        top = nw; // make the new node as the top node
    } else {
        nw->next = top; // link the new node with the top node
        top = nw; // update the top pointer to point to the new node
    }
    return top; // return the updated top pointer
}

// A function to pop an element from the stack
STACK *POP(STACK *top) {
    if (top == NULL) { // check if the stack is empty
        printf("No element to pop\n");
        return top; // return the same top pointer
    }
    STACK *temp = top; // get the top node
    int data = temp->info; // get the data from the top node
    top = top->next; // update the top pointer to point to the next node
    temp->next=NULL;
    free(temp); // free the memory of the top node
    printf("The popped element is %d\n", data); // print the popped data
    return top; // return the updated top pointer
}

// A function to display the stack from top to bottom
void display_Stack(STACK *top) {
    if (top == NULL) { // check if the stack is empty
        printf("No element to display\n");
        return; // exit the function
    }
    printf("Stack: ");
    STACK *temp = top; // get the top node
    while (temp != NULL) { // traverse the linked list until NULL is reached
        printf("%d\t", temp->info); // print the data of each node
        temp = temp->next; // move to the next node
    }
    printf("\n");
}

// A main function to test the program
int main() {
    STACK *top = NULL; // create an empty stack
    int ch, data;
    do {
        printf("\nThe menu:\n1: Push\n2: Pop\n3: Display\n4: Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                top = PUSH(top, data); // push data to the stack
                break;
            case 2:
                top = POP(top); // pop and print an element from the stack
                break;
            case 3:
                display_Stack(top); // display the stack
                break;
            case 4:
                printf("Program terminated\n");
                exit(0); // terminate the program
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);
    return 0;
}
