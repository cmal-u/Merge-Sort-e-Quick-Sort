#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[10] = {44, 47, 2, 6, -5, 1, 0, 12, 25, 37};

    for(int i = 0; i < 10; i++)
        printf(">>>%d\n", v[i]);

    printf("\n");

    MergeSort(v, 0, 9);

    for(int i = 0; i < 10; i++)
        printf(">>>%d\n", v[i]);


    return 0;
}

void MergeSort(int V[], int e, int d)
{
    if(d > e) {
        int m = (e+d)/2;
        MergeSort(V, e, m);
        MergeSort(V, m+1, d);
        Merge(V, e, m, d);
    }
}




void Merge(int V[], int e, int m, int d)
{
    int i, j, k;
    int n1 = m - e + 1;
    int n2 = d - m;

    int E[n1], D[n2];


    for(i = 0; i < n1; i++)
        E[i] = V[e+i];
    for(j = 0; j < n2; j++)
        D[j] = V[m+1+j];

    i=0;
    j=0;
    k=e;
    while(i < n1 && j < n2) {
        if(E[i] <= D[j]) {
            V[k] = E[i];
            i++;
        } else {
            V[k] = D[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        V[k] = E[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        V[k] = D[j];
        j++;
        k++;
    }
}
