#include <stdio.h>
#include "SUM.h"
#include <stdlib.h>

int *SUM(int **pointer, int *col, int *arr, int *arr2, int **pointer2) {
    int sum = 0, sumAns = -60000;
    int iAns=0, jAns=0;
    int col2=0;
    for (int i = 0; i < *col; i++) {
        for (int j = 0; j < *col; j++) {
            for (int z = i; z <= j; z++) {
                sum = sum + arr[z];
            }
            if (sumAns < sum && i <= j) {
                sumAns = sum;
                iAns = i;
                jAns = j;
            }
            sum = 0;
        }
        sum = 0;
    }
    col2 = jAns - iAns;
    col2 ++;
    int iAns1=iAns;
    *pointer2 = malloc((col2) * sizeof(int));
    arr2 = *pointer2;
    for (int i = 0; i < col2; i++) {
        arr2[i]=arr[iAns];
        iAns++;
    }
    printf("arr2 = ");
    for(int i=0; i < col2; i++){
        printf("%d ", arr2[i]);
    }

    printf("\n");
    printf("arr = ");
    while (col2) {
        for (int i = iAns1; i < *col-1; i++) {
            arr[i] = arr[i + 1];
        }
        *col = *col - 1;
        *pointer = realloc(arr, (*col) * sizeof(int));
        arr = *pointer;

        col2--;
    }
    for (int i = 0; i < *col; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("sum = %d\n", sumAns);
    if(arr == NULL){
        *pointer = realloc(arr, 2 * sizeof(int));
        arr = *pointer;
    }
    free(arr2);
    return arr;
}

