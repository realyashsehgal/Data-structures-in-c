#include <stdio.h>
#include <conio.h>
int bubblesor(int *arr, int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[] = {4, 675, 1, 314, 87, 0, 8, 2, 34, 76};
    int i, j, size;
    size = sizeof(arr) / sizeof(arr[0]);
    printf("the given array before sorting is \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Now sorting the array\n");
    bubblesor(arr, size);
    getch();
    return 0;
}
