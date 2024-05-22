#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user for the pyramid height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // Create pyramid
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i + j <= height - 2){
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
