#include <stdio.h>

#define LEFT -1
#define RIGHT 1

typedef struct {
    int value;
    int dir;
} Element;

void printPermutation(Element p[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", p[i].value);
    printf("\n");
}

int getMobile(Element p[], int n)
{
    int mobile = 0, pos = -1;

    for (int i = 0; i < n; i++)
    {
        if (p[i].dir == LEFT && i != 0 &&
            p[i].value > p[i - 1].value &&
            p[i].value > mobile)
        {
            mobile = p[i].value;
            pos = i;
        }

        if (p[i].dir == RIGHT && i != n - 1 &&
            p[i].value > p[i + 1].value &&
            p[i].value > mobile)
        {
            mobile = p[i].value;
            pos = i;
        }
    }

    return pos;
}

void johnsonTrotter(int n)
{
    Element p[n];

    // Initialize permutation
    for (int i = 0; i < n; i++)
    {
        p[i].value = i + 1;
        p[i].dir = LEFT;
    }

    printPermutation(p, n);

    while (1)
    {
        int pos = getMobile(p, n);

        // No mobile element
        if (pos == -1)
            break;

        int swapPos;

        // Move mobile element
        if (p[pos].dir == LEFT)
            swapPos = pos - 1;
        else
            swapPos = pos + 1;

        Element temp = p[pos];
        p[pos] = p[swapPos];
        p[swapPos] = temp;

        pos = swapPos;

        // Reverse direction of larger elements
        for (int i = 0; i < n; i++)
        {
            if (p[i].value > p[pos].value)
                p[i].dir *= -1;
        }

        printPermutation(p, n);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("\nPermutations are:\n");
    johnsonTrotter(n);

    return 0;
}
