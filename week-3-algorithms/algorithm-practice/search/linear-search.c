#include <cs50.h>
#include <stdio.h>

void find(int choice, int array[], int size);

int main(void)
{
    int choice = get_int("What number do you want to check? ");
    int array[] = {1, 7, 9, 121, 32, 65, 67, 36, 211, 2, 31, 68, 980, 61, 65, 71, 35};

    find(choice, array, 17);
}

void find(int choice, int array[], int size)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == choice)
        {
            found = true;
            printf("Found\n");
            break;
        }
    }
    if (!found)
    {
        printf("Not found in this array\n");
    }
}
