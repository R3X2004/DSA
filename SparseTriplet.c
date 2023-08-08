#include <stdio.h>
void readmatrix(int[][10], int, int);
void displaymatrix(int[][10], int, int);
void createtriplet(int[][10], int, int, int[][3]);
void displaytriplet(int[][3]);
int main()
{
    int a[10][10], r, c, b[10][3];
    printf("enter the no.of rows and columns of matrix:");
    scanf("%d%d", &r, &c);
    printf("enter the matrix element:");
    readmatrix(a, r, c);
    printf("the matrix is:\n");
    displaymatrix(a, r, c);
    createtriplet(a, r, c, b);
    printf("\nthe triplet form is:\n");
    displaytriplet(b);
    return 0;
}
void readmatrix(int a[10][10], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void displaymatrix(int a[10][10], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
void createtriplet(int a[10][10], int r, int c, int b[][3])
{
    int i, j, k = 1;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }
    b[0][0] = r;
    b[0][1] = c;
    b[0][2] = k - 1;
}
void displaytriplet(int b[][3])
{
    int i, j;
    for (i = 0; i <= b[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}