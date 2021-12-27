#include <stdio.h>

void display(int *array, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void quicksort(int array[], int start, int end)
{
    int pivot = end;
    int left = start;
    int right = end;
    int temp;
    if (left >= right)
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
    display(array, start, end); 
    printf("%d %d \n",start, right);
    quicksort(array, start, right - 1);
    quicksort(array, right + 1, end);
}

int main(void)
{
    int i[4] = {2, 0, 3, 1};
    int array[10] = {5, 9, 8, 1, 3, 5, 7, 0, 2, 4};
    quicksort(i, 0, 3);
    display(i, 0, 3);
}