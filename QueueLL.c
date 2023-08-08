// A C program to implement queue using linked list

#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
typedef struct queue {
    int info; // data field
    struct queue *next; // pointer to the next node
} Queue;

// A function to display the queue from front to rear
void display(Queue *front, Queue *rear) {
    if (front == NULL) { // check if the queue is empty
        printf("No element to display\n");
        return; // exit the function
    }
    printf("The queue is: ");
    Queue *p = front; // get the front node
    while (p != rear) { // traverse the linked list until rear is reached
        printf("%d\t", p->info); // print the data of each node
        p = p->next; // move to the next node
    }
    printf("%d\n", p->info); // print the data of the rear node
}

// A function to enqueue an element to the queue
Queue *enqueue(Queue *rear) {
    Queue *nw = (Queue *)malloc(sizeof(Queue)); // allocate memory for the new node
    if (nw == NULL) { // check if memory allocation failed
        printf("Memory allocation error\n");
        exit(0); // terminate the program
    }
    int data;
    printf("Enter element: ");
    scanf("%d", &data); // read data from user input
    nw->info = data; // assign data to the new node
    nw->next = NULL; // initialize next pointer to NULL
    if (rear == NULL) { // check if the queue is empty
        rear = nw; // make the new node as the rear node
    } else {
        rear->next = nw; // link the new node with the rear node
        rear = nw; // update the rear pointer to point to the new node
    }
    return rear; // return the updated rear pointer
}

// A function to dequeue an element from the queue
Queue *dequeue(Queue *front) {
    if (front == NULL) { // check if the queue is empty
        printf("Queue underflow\n");
        return front; // return the same front pointer
    }
    Queue *p = front; // get the front node
    int data = p->info; // get the data from the front node
    front = front->next; // update the front pointer to point to the next node
    free(p); // free the memory of the front node
    printf("The dequeued element is %d\n", data); // print the dequeued data
    return front; // return the updated front pointer
}

// A main function to test the program
int main() {
    Queue *front, *rear;
    front = rear = NULL; // create an empty queue

    int ch;
    do {
        printf("\nQueue operation\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                rear = enqueue(rear); // enqueue an element to the queue
                if (front == NULL) { // check if the queue was empty before enqueueing
                    front = rear; // make the front pointer point to the same node as rear pointer
                }
                break;
            case 2:
                front = dequeue(front); // dequeue and print an element from the queue
                break;
            case 3:
                display(front, rear); // display the queue
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
