#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *createlist(struct node *);

void traverse(struct node *);
struct node *insertafnod(struct node *);
struct node *deleteafnod(struct node *);
int main()
{
    int ch;
    struct node *head = NULL;
    head = createlist(head);
    while (1)
    {
        printf("\n1.Traverse 2.insert after a node 3.delete after a node\n");
        printf("ente the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            traverse(head);
            break;
        case 2:
            head = insertafnod(head);
            break;
        case 3:
            head = deleteafnod(head);
            break;
        default:
            printf("wrong choice:");
            exit(0);
        }
    }
}
void traverse(struct node *head)
{
    struct node *p;
    p = head;
    do
    {
        printf("%d\t", p->data);
        p = p->link;
    } while (p != head);
}
struct node *createlist(struct node *head)
{
    struct node *nw, *p;
    int i, n;
    printf("enter the no.of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        nw = (struct node *)malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d", &nw->data);
        nw->link = NULL;
        if (head == NULL)
        {
            head = p = nw;
            nw->link = head;
        }
        else
        {
            p->link = nw;
            nw->link = head;
        }
        p = nw;
    }
    return head;
}
struct node *insertafnod(struct node *head)
{
    struct node *nw, *p;
    int i = 1, n;
    printf("enter the value of node after which insertion to be done:");
    scanf("%d", &n);
    nw = (struct node *)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d", &nw->data);
    nw->link = NULL;

    p = head;
    while (n != p->data)
    {
        p = p->link;
    }

    nw->link = p->link;
    p->link = nw;

    return head;
}
struct node *deleteafnod(struct node *head)
{
    struct node *p, *temp, *q;
    int n, i;
    printf("enter the node to be deleted:");
    scanf("%d", &n);
    p = head;

    while (n != p->data)
    {
        temp = p;
        q = p;
        p = p->link;
    }
    q = p->link;
    temp->link = q;
    printf("the node deleted is %d\t", p->data);
    free(p);
    return head;
}