#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo;

    arquivo = fopen("instancias-num/num.1000.4.in", "r");

    if(arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
        return -1;
    }

    ordenarArquivo(arquivo);


    return 0;
}
