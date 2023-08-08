#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printListForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printListBackward(Node* tail) {
    Node* temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* insertAtPosition(Node* head, int data, int position) {
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 1; i < position-1  && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

Node* insertAfterNode(Node* head, int data, int targetData) {
    Node* newNode = createNode(data);
    Node* temp = head;
    while (temp != NULL && temp->data != targetData) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target node not found.\n");
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    return head;
}

Node* deleteFromPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (position == 1) {
        return deleteFromBeginning(head);
    }
    Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return head;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

Node* deleteAfterNode(Node* head, int targetData) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != targetData) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Target node not found or no node after target node.\n");
        return head;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    }
    free(nodeToDelete);
    return head;
}

int main() {
    Node* head = NULL;
    int choice, data, position, targetData;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Traverse the linked list in forward direction\n");
        printf("3. Traverse the linked list in backward direction\n");
        printf("4. Insert a node at the beginning of the linked list\n");
        printf("5. Insert a node at the end of the linked list\n");
        printf("6. Insert a node at a given location/position in the linked list\n");
        printf("7. Insert a node after a specific node in the linked list\n");
        printf("8. Delete a node from the beginning of the linked list\n");
        printf("9. Delete a node from the end of the linked list\n");
        printf("10. Delete a node from a given location/position in the linked list\n");
        printf("11. Delete a node after a specific node in the linked list\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 2:
                printListForward(head);
                break;
            case 3:
                printListBackward(head);
                break;
            case 4:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 5:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 6:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                printf("Enter the position to insert the new node: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 7:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                printf("Enter the data of the node after which to insert the new node: ");
                scanf("%d", &targetData);
                head = insertAfterNode(head, data, targetData);
                break;
            case 8:
                head = deleteFromBeginning(head);
                break;
            case 9:
                head = deleteFromEnd(head);
                break;
            case 10:
                printf("Enter the position of the node to delete: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 11:
                printf("Enter the data of the node after which to delete a node: ");
                scanf("%d", &targetData);
                head = deleteAfterNode(head, targetData);
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}