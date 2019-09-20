#include <stdio.h>

void MergeSort(int V[], int inicio, int fim)
{
    int m;
    if(inicio < fim) {
        m = inicio + (fim - inicio)/2;
        //printf("\n>>>>>%d\n", m);
        MergeSort(V, inicio, m);
        MergeSort(V, m+1, fim);
        Merge(V, inicio, m, fim);
    }
}

void Merge(int V[], int inicio, int fim, int meio)
{
    int i, j, k;
    int t1 = meio - inicio + 1;
    int t2 = fim - meio;
    int E[t1], D[t2];

    for(i = 0; i < t1; i++)
        E[i] = V[inicio + i];
    for(i = 0; i < t2; i++)
        D[i] = V[meio + 1 + i];

    i = 0;
    j = 0;
    k = inicio;

    while(i < t1 && j < t2) {

        if(E[i] <= D[j]) {
            V[k] = V [i];
            i++;
        } else {
            V[k] = D[j];
            j++;
        }

        k++;
    }

    while(i < t1) {
        V[k] = E[i];
        i++;
        k++;
    }

    while(j < t2) {
        V[k] = D[j];
        j++;
        k++;
    }

}
