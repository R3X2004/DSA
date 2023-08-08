#include <stdio.h>
#include <stdlib.h>


typedef struct Poly
{
    double coef;
    int expo;
    struct Poly *next;
} Poly;

Poly *create_poly(Poly *head)
{
    int opt;
    Poly *nw, *p;
    do
    {
        nw = (Poly *)malloc(sizeof(Poly));
        printf("Enter the coefficient & exponent:");
        scanf("%lf %d", &nw->coef, &nw->expo);
        nw->next = NULL;
        if (head == NULL)
            head = p = nw;
        else
            p->next = nw;
        p = nw;
        printf("Another term(1/0):");
        scanf("%d", &opt);
    } while (opt == 1);
    return head;
}

Poly *add_poly(Poly *head1, Poly *head2)
{
    Poly *nw, *res, *p = head1, *q = head2, *head3 = NULL;
    while (p && q)
        {
            nw = (Poly *)malloc(sizeof(Poly));
            nw->next = NULL;
            if (p->expo > q->expo)
            {
                nw->coef = p->coef;
                nw->expo = p->expo;
                p = p->next;
            }
            else if (p->expo < q->expo)
            {
                nw->coef = q->coef;
                nw->expo = q->expo;
                q = q->next;
            }
            else
            {
                nw->coef = p->coef + q->coef;
                nw->expo = p->expo; // OR nw->expo=q->expo;
                p = p->next;
                q = q->next;
            }
            if (head3 == NULL)
                head3 = nw;
            else
                res->next = nw;
            res = nw;
        }
    if (p == NULL)
        res->next = q;
    else
        res->next = p;
    return head3;
}

void print_poly(Poly *head)
{
    Poly *p = head;
    if (head == NULL)
        printf("\nEmpty Polynomial (No terms)\n");
    else
    {
        while (p)
        {
            printf("%lfx^%d", p->coef, p->expo);
            if ((p->next != NULL) && (p->next->coef >= 0.0))
                putchar('+');
            p = p->next;
        }
        putchar('\n');
    }
}

int main()
{
    Poly *poly1, *poly2, *poly3;
    int ch;
    poly1 = poly2 = poly3 = NULL;
    do
    {
        printf("1.CREATION\n");
        printf("2.ADDITION\n");
        printf("3.EXIT\n");
        printf("\nENTER U'R CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nFor First Polynomial\n");
            poly1 = create_poly(poly1);
            printf("\nThe first polynomial is:\n");
            print_poly(poly1);
            printf("\nFor Second Polynomial\n");
            poly2 = create_poly(poly2);
            printf("\nThe second polynomial is:\n");
            print_poly(poly2);
            break;
        case 2:
            poly3 = add_poly(poly1, poly2);
            printf("\nAfter addition, third polynomial is:\n");
            print_poly(poly3);
            break;
    
        case 3:
            exit(0);
        }
    } while (1);
    system("PAUSE");
    return 0;
}