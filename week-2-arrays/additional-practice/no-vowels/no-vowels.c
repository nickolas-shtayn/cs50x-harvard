#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
	if (argc != 2)
	{
	printf("Usage: ./no-vowels word\n");
	return 1;
	}
	string new_word = replace(argv[1]);
    printf("%s\n", new_word);
}
string replace(string word)
{
int length = strlen(word); // Unsure if this is good practice (watch video again)
	for (int i = 0; i < length; i++)
	{
		switch (word[i])
		{
			case 'a':
				word[i] = '6';
				break;

			case 'e':
				word[i] = '3';
				break;

			case 'i':
				word[i] = '1';
                break;

			case 'o':
				word[i] = '0';
                break;

			default:
                break;
		}
	}
	return word;
}
