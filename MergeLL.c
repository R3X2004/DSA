#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node* createnode();
struct node* createlist(struct node *);
void traverse(struct node *);
struct node* merge(struct node *,struct node *);
struct node* sorting(struct node *);
int main()
{
	struct node *head=NULL,*head1=NULL,*head2=NULL;
	printf("enter the first sorted list:");
	head1=createlist(head1);
	printf("enter the second sorted list:");
	head2=createlist(head2);
	head1=merge(head1,head2);
	printf("the merged list is\n");
	traverse(head1);
	head1=sorting(head1);
	printf("\nthe sorted list is\n");
	traverse(head1);
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
		nw->next=NULL;
		
	}  
	return nw;
	
}
struct node* createlist(struct node *head)
{
	int i,n;
	struct node *nw,*temp;
	
	printf("\nEnter the no.of nodes:");
	scanf("%d",&n);
	
	if(n>=1)
	{
		nw=createnode();
		head=nw;
		temp=nw;
		for(i=1;i<n;i++)
		{
			nw=createnode();
			temp->next=nw;
			temp=nw;
		}
	}
	else
	  printf("list not possible");
	return head;
}
void traverse(struct node *head1)
{
	struct node *temp;
	temp=head1;
	printf("the element in the list are\n");
	while(temp->next!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
	}
	printf("%d",temp->info);
}
struct node* merge(struct node *head1,struct node *head2)
{
	struct node *p;
	p=head1;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head2;
	return head1;
}
struct node* sorting(struct node *head)
{
	struct node *ptr,*cptr;
	int temp;
	ptr=head;
	while(ptr->next!=NULL)
	{
		cptr=ptr->next;
		while(cptr!=NULL)
		{
			if(ptr->info > cptr->info)
			{
				temp=ptr->info;
				ptr->info=cptr->info;
				cptr->info=temp;
			}
			cptr=cptr->next;
		}
		ptr=ptr->next;
		
	}
	return head;
}