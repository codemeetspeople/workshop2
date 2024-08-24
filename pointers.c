#include <stdio.h>
#include <stdlib.h>


void arrayPrintClassic(int array[], int size) {
    int last = size - 1;

    for ( int i = 1; i < size; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

// Do not use ;)
void arrayPrintPervert(int array[], int size) {
    int last = size - 1;

    for ( int i = 1; i < size; i++ ) {
        printf("%d ", i[array]);
    }
    printf("%d\n", last[array]);
}

void arrayPrintAriphmetic(int* array, int size) {
    int last = size - 1;

    for ( int i = 1; i < size; i++ ) {
        printf("%d ", *(array+i));
    }
    printf("%d\n", *(array+last));
}

void arrayPrint(int* array, int size) {
    for ( int i = 1; i < size; i++, array++ ) {
        printf("%d ", *array);
    }
    printf("%d\n", *array);
}

int main() {
    int* arr1 = (int*)malloc(5*sizeof(int));

    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 4;
    arr1[4] = 5;
    
    int arr2[5] = {6, 7, 8, 9, 10};
    int arr3[5] = {-1, -2, -3, -4, -5};

    int** pointer = (int**)malloc(3*sizeof(int*));

    pointer[0] = arr1;
    pointer[1] = arr2;
    pointer[2] = arr3;

    for ( int i = 0; i < 3; i++ ) {
        arrayPrint(pointer[i], 5);
    }

    free(pointer);
    free(arr1);

    return 0;
}
