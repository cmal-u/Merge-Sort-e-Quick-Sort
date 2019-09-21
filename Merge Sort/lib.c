#include <stdio.h>
#include "lib.h"

<<<<<<< HEAD
=======
void MergeSort(int V[], int inicio, int fim)
{
    int m;
    if(inicio < fim) {
        m = (inicio + fim)/2;
        //printf("\n>>>>>%d\n", m);
        MergeSort(V, inicio, m);
        MergeSort(V, m+1, fim);
        Merge(V, inicio, m, fim);
    }
}
>>>>>>> 16f910d59f3dd4454fe4aad30dd938069a13a447

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

void ordenarArquivo(FILE *arq)
{
    int cont = 0, tamanho = 0;
    char linha[100], *primeiraLinha;

    fgets(linha, sizeof linha, arq);
    primeiraLinha = strtok(linha, " ");

    tamanho = atoi(primeiraLinha);
    int vetor[tamanho];

    while(!feof(arq)) {
        fscanf(arq, "%d", &vetor[cont++]);
    }

    fclose(arq);
    MergeSort(vetor, 0, tamanho-1);

    criarNovoArq(vetor, tamanho);


}

void criarNovoArq(int v[], int tam)
{
    FILE *arquivo = fopen("ArquivoOrdenado.txt", "w+");

    if (arquivo != NULL) {
        for(int i = 0; i < tam; i++) {
            fprintf(arquivo,"%d\n", v[i]);
        }
        fclose(arquivo);
        printf("Novo arquivo ordenado foi criado.\n\n");
    }
}
