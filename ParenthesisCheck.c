#include <stdio.h>
#include <stdlib.h>
char stack[100];
int top = -1;
void push(char);
char pop();
int main()
{
    char exp[100], ch;
    int i;
    printf("enter the expression:");
    scanf("%s", exp);
    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];
        if (ch == '(')
            push(ch);
        if (ch == ')')
        {
            if (top == -1)
            {
                printf("not a balanced expression\n");
                exit(0);
            }
            else
                pop();
        }
    }
    if (top == -1)
        printf("Balanced expression\n");
    else
        printf("Not a Balanced expression\n");
    return 0;
}
void push(char e)
{
    top = top + 1;
    stack[top] = e;
}
char pop()
{
    char v;
    v = stack[top];
    top = top - 1;
    return v;
}