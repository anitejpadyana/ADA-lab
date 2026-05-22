#include <stdio.h>

int a[10][10], indeg[10], n;

void topo()
{
    int i, j, count = 0;

    while(count < n)
    {
        for(i = 0; i < n; i++)
        {
            if(indeg[i] == 0)
            {
                printf("%d ", i + 1);
                indeg[i] = -1;
                count++;

                for(j = 0; j < n; j++)
                    if(a[i][j])
                        indeg[j]--;
            }
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(j = 0; j < n; j++)
        for(i = 0; i < n; i++)
            indeg[j] += a[i][j];

    printf("Topological Order: ");
    topo();

    return 0;
}
