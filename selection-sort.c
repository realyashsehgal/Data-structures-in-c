#include <stdio.h>
#include<conio.h>
void selectionSort(int arr[], int size)
{

    int key;

    for (int i = 0; i < size - 1; i++)
    {
        key = i;
        for (int j = i + 1; j < size; j++)
        {

            if (arr[key] > arr[j])
            {
                key = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[key];
        arr[key] = temp;
    }
}

void printArr(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {

        printf("%d ", arr[i]);
    }
}

void main()
{

    int array[] = {12, 18, 5, 29, 4, 7};

    printf("before:\n");

    printArr(array, 6);

    selectionSort(array, 6);

    printf("\nafter:\n");

    printArr(array, 6);
}
