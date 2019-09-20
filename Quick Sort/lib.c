#include <stdio.h>
#include "lib.h"



int Partition(int V[], int inicio, int fim)
{
    int pivo = V[inicio], i = inicio-1, j = fim+1;

    while(1) {
        do i++;
        while(V[i] <= pivo);

        do j--;
        while(V[j] > pivo);

        if(i >= j) break;
        trocar(V, i, j);
    }

    trocar(V, inicio, j);
    return j;
}



void trocar(int V[], int i, int j)
{
    int aux = V[i];
    V[i] = V[j];
    V[j] = aux;
}



void QuickSort(int V[], int esq, int dir)
{
    int q;
    if(esq < dir) {
        q = Partition(V, esq, dir);
        QuickSort(V, esq, q-1);
        QuickSort(V, q+1, dir);
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

    QuickSort(vetor, 0, tamanho-1);

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
