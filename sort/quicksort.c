
#include <stdio.h>

void quicksort(int array[], int start, int end)
{
    int pivot = start;

    quicksort(array, start, pivot);
    quicksort(array, pivot + 1, end);
}