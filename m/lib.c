#include <stdio.h>
#include "lib.h"

void Merge(int V[], int e, int m, int d)
{
    int i, j, k;                        // contadores
    int n1 = m - e + 1, n2 = d - m;     // tamanhos dos arrays temporarios
    int E[n1], D[n2];                   // arrays temporarios


    // adicionando os valores dos dois arrays
    for(i = 0; i < n1; i++)
        E[i] = V[e+i];
    for(j = 0; j < n2; j++)
        D[j] = V[m+1+j];

    i=0;
    j=0;
    k=e;

    // comparações das subpartes
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

    // terminando de preencher o array principal
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

void MergeSort(int V[], int e, int d)
{
    if(d > e) {
        int m = (e+d)/2;
        MergeSort(V, e, m);
        MergeSort(V, m+1, d);
        Merge(V, e, m, d);
    }
}
