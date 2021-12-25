
#include <stdio.h>

void quicksort(int array[], int start, int end)
{
    int pivot = start;
    int left = start;
    int right = end;
    int temp;
    if (start >= end)
        return;

    while (left < right)
    {
        while (array[left] < array[pivot] && left < right)
        {
            left++;
        }
        while (array[right] >= array[pivot] && left < right)
        {
            right--;
        }
        if (left < right)
        {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
    temp = array[pivot];
    array[pivot] = array[right];
    array[right] = temp;
    printf("%d %d \n", left, right);
    for (int i = 0; i <= end; i++)
    {
        printf("%d ", array[i]);
        if (i == end)
            printf("/");
    }
    printf("\n");
    quicksort(array, start, right - 1);
    quicksort(array, right + 1, end);
}

int main(void)
{
    int array[10] = {9, 4, 3, 5, 7, 6, 8, 9, 1, 2};
    quicksort(array, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
}
