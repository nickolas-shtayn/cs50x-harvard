#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
string score(string player1_choice, string player2_choice);

int main(void)
{
    string player1_choice = get_string("Player 1: ");
    string player2_choice = get_string("Player 2: ");

    printf("%s", score(player1_choice, player2_choice));
}

string score(string player1_choice, string player2_choice)
{
    int player1_score = 0;
    int player2_score = 0;
    int length_1 = strlen(player1_choice);
    int length_2 = strlen(player2_choice);

    // logic using a for loop to increment over each player score
    for (int i = 0; i < length_1; i++)
    {
        if (tolower(player1_choice[i]) >= 'a' && i <= 'z')
        {
            player1_score += POINTS[tolower(player1_choice[i]) - 'a'];
        }
    }
    for (int i = 0; i < length_2; i++)
    {
        if (tolower(player2_choice[i]) >= 'a' && i <= 'z')
        {
            player2_score += POINTS[tolower(player2_choice[i]) - 'a'];
        }
    }

    // evaluate the scores

    if (player1_score > player2_score)
    {
        return "Player 1 wins!\n";
    }
    else if (player1_score < player2_score)
    {
        return "Player 2 wins!\n";
    }
    else
    {
        return "Tie!\n";
    }
}
