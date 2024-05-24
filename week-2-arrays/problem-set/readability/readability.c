#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int reading_level(string user_text);

int main(void)
{
    string user_text = get_string("Text: ");
    int reading_result = reading_level(user_text);
    if (reading_result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (reading_result > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", reading_result);
    }
}
int reading_level(string user_text)
{
    int length = strlen(user_text);
    int word_amount = 0;
    int letter_amount = 0;
    int sentence_amount = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(user_text[i]) > 0)
        {
            letter_amount++;
        }
        if (isblank(user_text[i]) > 0)
        {
            word_amount++;
        }
        if (user_text[i] == '.' || user_text[i] == '?' || user_text[i] == '!')
        {
            sentence_amount++;
            if (i == length - 1)
            {
                word_amount++;
            }
        }
    }
    float letter_average = (float) letter_amount / (float) word_amount;
    float L = letter_average * 100;
    float sentence_average = (float) sentence_amount / (float) word_amount;
    float S = sentence_average * 100;
    int coleman_liau_index = (0.0588 * L - 0.296 * S - 15.8) + 0.5;

    return coleman_liau_index;
}
