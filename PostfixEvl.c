#include <stdio.h>
#include <ctype.h>
void push(char);
int pop();
int operato(char);

void posteval(char[]);
char stack[100], postfix[100];
int top = -1;
int main()
{
    printf("enter the postfix expression:");
    scanf("%s", postfix);
    posteval(postfix);
}

void posteval(char postfix[100])
{
    int op1, op2, res = 0, i, n;
    char ch;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            n = ch - 48;                      
            push(n);
        }
        if (operato(ch))
        {
            op2 = pop();
            op1 = pop();
            switch (ch)
            {
            case '+':
                res = op1 + op2;
                push(res);
                break;
            case '-':
                res = op1 - op2;
                push(res);
                break;
            case '*':
                res = op1 * op2;
                push(res);
                break;
            case '/':
                res = op1 / op2;
                push(res);
                break;
            case '^':
                res = op1 ^ op2;
                push(res);
                break;
            default:
                printf("wrong ch");
            }
        }
    }
    printf("the result of postfix expression is %d\n", pop());
}
int operato(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
        break;
    default:
        return 0;
    }
}

void push(char ch)
{
    top = top + 1;
    stack[top] = ch;
}
int pop()
{
    int v;
    v = stack[top];
    top = top - 1;
    return v;
} 