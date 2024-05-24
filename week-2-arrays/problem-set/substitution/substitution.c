#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_chars_once(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (only_chars_once(argv[1]))
        {
            int key_length = strlen(argv[1]);
            if (key_length != 26)
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
            else
            {
                string plaintext = get_string("plaintext: ");
                printf("ciphertext: \n");
                return 0;
            }
        }
        else
        {
            printf("Key must contain 26 characters and they cannot repeat more than once.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

bool only_chars_once(string key)
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            return false;
        }
        else
        {
            for (int j = 0; j < length; j++)
            {
                if (i != j && key[i] == key[j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

char cypher(string plaintext)
{
    // substitute each plaintext index with its corresponding index in the cyphertext
}
