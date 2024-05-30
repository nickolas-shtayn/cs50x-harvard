#include <cs50.h>
#include <stdio.h>

void selection_sort(int array[], int length);

int main(void)
{
    int numbers[6] = {5, 2, 1, 3, 6, 4};

    selection_sort(numbers, 6);
}

void selection_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_index = i;
        int temp = 0;

        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
            else
            {
                continue;
            }
        }
        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}
