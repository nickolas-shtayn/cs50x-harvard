#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_chars_once(string key);
void cipher(string plaintext, string key);

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
                cipher(plaintext, argv[1]);
                printf("ciphertext: %s\n", plaintext);
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

void cipher(string plaintext, string key)
{
    int length = strlen(plaintext);
    int corresponding_char = 0;

    for (int i = 0; i < length; i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            corresponding_char = plaintext[i] - 'A';
            plaintext[i] = toupper(key[corresponding_char]);
        }
        else if (islower(plaintext[i]) != 0)
        {
            corresponding_char = plaintext[i] - 'a';
            plaintext[i] = tolower(key[corresponding_char]);
        }
        else
        {
            continue;
        }
    }
}
