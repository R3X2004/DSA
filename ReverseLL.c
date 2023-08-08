#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
	int info;
	struct node *next; // replace link with next
} node;				   // use node as the alias
node *createnode();
node *createlist(node *);
void traverse(node *);
node *reverse(node *);
int main()
{
	node *head = NULL;
	head = createlist(head);

	head = reverse(head);
	printf("the reversed list is \n");

	traverse(head);
	return 0;
}
node *createnode()
{
	int data;
	node *nw;
	nw = (node *)malloc(sizeof(node));
	if (nw == NULL)
		printf("memory allocation not possible");
	else
	{
		printf("enter the data:");
		scanf("%d", &data);
		nw->info = data;
		nw->next = NULL; // replace link with next
	}
	return nw;
}
node *createlist(node *head)
{
	int i, n;
	node *nw, *temp;

	printf("enter the no.of nodes:");
	scanf("%d", &n);

	if (n >= 1)
	{
		nw = createnode();
		head = temp = nw;
		for (i = 1; i < n; i++)
		{
			nw = createnode();
			temp->next = nw; // replace link with next
			temp = nw;
		}
	}
	else
		printf("list not possible");
	return head;
}
void traverse(node *head)
{
	node *temp;
	temp = head;
	while (temp->next != NULL) // replace link with next
	{
		printf("%d\t", temp->info);
		temp = temp->next; // replace link with next
	}
	printf("%d", temp->info);
}
node *reverse(node *head)
{
	node *curr, *fwd = NULL, *prev = NULL;
	curr = head;
	while (curr != NULL)
	{
		fwd = curr->next;  // replace link with next
		curr->next = prev; // replace link with next
		prev = curr;
		curr = fwd;
	}
	head = prev;
	return head;
}
