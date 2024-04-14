#include <stdio.h>
#include <conio.h>
int main()
{
    int arr[] = {3, 54, 1, 67, 87, 34};
    int  size, i, value;
    printf("Please enter the value you want to find the array");
    scanf("%d", &value);
    size = (sizeof(arr)) / sizeof(arr[0]);
    for (i = 0; i < size; i++)
    {
        if(value == arr[i])
        {
            printf("The value %d is found at the index %d\n",value,i);
            break;
        }
    }
    getch();
    return 0;
}
