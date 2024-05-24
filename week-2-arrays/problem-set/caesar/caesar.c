#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool only_digits(string key);
char rotate(char original, int rotated_amount);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (only_digits(argv[1]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            int converted_key = atoi(argv[1]);
            string plaintext = get_string("plaintext: ");
            int length = strlen(plaintext);
            char cyphertext[length+1];
                for (int i = 0; i < length; i++)
                {
                    char cyphered = rotate(plaintext[i], converted_key);
                    cyphertext[i] = cyphered;
                }
                cyphertext[length] = '\0';

                printf("ciphertext: %s\n", cyphertext);
                return 0;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
bool only_digits(string key)
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(key[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

char rotate(char original, int rotated_amount)
{
    char rotated_char = original + rotated_amount;
    if (original >= 'a' && original <= 'z')
    {
        if (rotated_char < 97 || rotated_char >=122)
        {
            rotated_char = (rotated_char - 'a') % 26;
            return rotated_char + 'a';
        }
        else
        {
            return rotated_char;
        }
    }
    else if (original >= 'A' && original <= 'Z')
    {
        if (rotated_char < 65 || rotated_char > 90)
        {
            rotated_char = (rotated_char - 'A') % 26;
            return rotated_char + 'A';
        }
        else
        {
            return rotated_char;
        }
    }
    return original;
}
