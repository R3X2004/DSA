#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node* createnode();
struct node* createlist(struct node *);
void traverse(struct node *);
struct node* sorting(struct node *);
int main()
{
	struct node *head=NULL;
	head=createlist(head);
	printf("the list is ");
	traverse(head);
	head=sorting(head);
	printf("\nthe sorted list is ");
	traverse(head);
	return 0;
	
}
struct node* createnode()
{
	int data;
	struct node *nw;
	nw=(struct node*)malloc(sizeof(struct node));
	if(nw==NULL)
	  printf("memory allocation not possible");
	else
	{
		printf("enter the data:");
		scanf("%d",&data);
		nw->info=data;
		nw->link=NULL;
		
	}  
	return nw;
	
}
struct node* createlist(struct node *head)
{
	int i,n;
	struct node *nw,*temp;
	
	printf("enter the no.of nodes:");
	scanf("%d",&n);
	
	if(n>=1)
	{
		nw=createnode();
		head=nw;
		temp=nw;
		for(i=1;i<n;i++)
		{
			nw=createnode();
			temp->link=nw;
			temp=nw;
		}
	}
	else
	  printf("list not possible");
	return head;
}
struct node* sorting(struct node *head)
{
	struct node *ptr,*cptr;
	int temp;
	ptr=head;
	while(ptr->link!=NULL)
	{
		cptr=ptr->link;
		while(cptr!=NULL)
		{
			if(ptr->info > cptr->info)
			{
				temp=ptr->info;
				ptr->info=cptr->info;
				cptr->info=temp;
			}
			cptr=cptr->link;
		}
		ptr=ptr->link;
		
	}
	return head;
}
void traverse(struct node *head)
{
	struct node *temp;
	temp=head;
	printf("the element in the list are\n");
	while(temp->link!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->link;
	}
	printf("%d",temp->info);
}