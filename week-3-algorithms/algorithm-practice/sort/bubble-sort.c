#include <cs50.h>
#include <stdio.h>

void bubble_sort(int array[], int length);

int main(void)
{
    int numbers[6] = {5, 2, 1, 3, 6, 4};

    bubble_sort(numbers, 6);
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
