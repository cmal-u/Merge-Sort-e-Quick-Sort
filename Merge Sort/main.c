#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[10] = {44, 47, 2, 6, -5, 1, 0, 12, 25, 37};

    for(int i = 0; i < 10; i++)
        printf(">>>%d\n", v[i]);

    printf("\n");

    //MergeSort(v, 0, 10);

    for(int i = 0; i < 10; i++)
        printf(">>>%d\n", v[i]);


    return 0;
}
