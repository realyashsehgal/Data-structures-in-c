#include <stdio.h>
#include <conio.h>
int display(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
int selectionsort(int *arr, int size)
{
    int begin, key, i, j,temp;
    key = 0;
    for (i = 0; i < size; i++)
    {
        for( j = i + 1; j < size ; j++)
        {
            if(arr[key] > arr[j])
            {
                key = j ;
            }            
        }
        temp = arr[key];
        arr[key] = arr[i];
        arr[i] = temp;
    }
    return 0;
}
int main()
{
    int arr[] = {98, 4, 56, 12, 144, 44};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    printf("sorting the given array using selection sort\n");
    selectionsort(arr, size);
    display(arr,size);
    getch();
    return 0;
}
