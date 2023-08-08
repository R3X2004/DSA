#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void backtraverse(Node *head)
{
    if(head==NULL)
    {
        return;
    }
    else{
        backtraverse(head->next);
        printf("%d ", head->data);
    }
    printf("NULL\n");
}

void search(Node *head)
{
	int n,k=0;
	Node *p=NULL;
	printf("\nEnter the element to be serached:");
	scanf("%d",&n);
	
	
		p=head;
		while(p!=NULL)
		{
			if(p->data==n)
			{
				k=1;
				break;
			}
			else
			    p=p->next;
		}
		if(k==1)
		  printf("Search is successfull");
		else
		  printf("Search is not succesfull");  
	
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
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
    return head;
}

Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertAfterSpecificNode(Node* head, int data, int specificNodeData) {
    Node* newNode = createNode(data);
    Node* temp = head;
    while (temp != NULL && temp->data != specificNodeData) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Specific node not found\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteFromPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return head;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return head;
}

Node* deleteSpecificNode(Node* head, int specificNodeData) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->data == specificNodeData) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != specificNodeData) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Specific node not found\n");
        return head;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return head;
}

int main() {
    Node* head = NULL;
    int choice, data, position, specificNodeData;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a Linked List\n");
        printf("2. Forward Traverse a Linked List\n");
        printf("3. Backward Traverse a Linked List\n");
        printf("4. Search a Node From The List\n");
        printf("5. Insert a node at the Beginning of the Linked List\n");
        printf("6. Insert a node at the End of the Linked List\n");
        printf("7. Insert a node at a given Location/Position in the Linked List\n");
        printf("8. Insert a node after a Specific Node in the Linked List\n");
        printf("9. Delete a node from the Beginning of the Linked List\n");
        printf("10. Delete a node from the End of the Linked List\n");
        printf("11. Delete a node from a given Location/Position from the Linked List\n");
        printf("12. Delete a particular node from the Linked List\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                backtraverse(head);
                break;
            case 4:
                search(head);
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 6:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 7:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                head = insertAtPosition(head, data, position);
                break;
            case 8:
                printf("Enter data and specific node data: ");
                scanf("%d %d", &data, &specificNodeData);
                head = insertAfterSpecificNode(head, data, specificNodeData);
                break;
            case 9:
                head = deleteFromBeginning(head);
                break;
            case 10:
                head = deleteFromEnd(head);
                break;
            case 11:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 12:
                printf("Enter specific node data: ");
                scanf("%d", &specificNodeData);
                head = deleteSpecificNode(head, specificNodeData);
                break;
            case 13:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}