#include <cs50.h>
#include <stdio.h>

void bubble_sort(int array[], int length);
void binary_search(int array[], int length, int target);

int main(void)
{
    int numbers[15] = {11, 23, 8, 14, 30, 9, 6, 17, 22, 28, 25, 15, 7, 10, 19};
    bubble_sort(numbers, 15);
    binary_search(numbers, 15, 19);
}

void bubble_sort(int array[], int length)
{
    int hold_value = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
            if (array[j] > array[j + 1])
            {
                hold_value = array[j];
                array[j] = array[j + 1];
                array[j + 1] = hold_value;
            }
            else if (array[j] < array[j + 1] || array[j] == array[j + 1])
            {
                continue;
            }
    }
}

void binary_search(int array[], int length, int target)
{
    int start = 0;
    int end = length -1;
    bool found = false;

    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (array[middle] != target)
        {
            if (array[middle] < target)
            {
                start = middle + 1;
            }
            else if (array[middle] > target)
            {
                end = middle - 1;
            }
        }
        else
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not found\n");
    }
}
