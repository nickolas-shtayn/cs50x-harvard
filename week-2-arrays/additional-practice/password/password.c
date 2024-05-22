#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int length = strlen(password);
    bool uppercase = false;
    bool lowercase = false;
    bool digit = false;
    bool symbol = false;
    for (int i = 0; i < length; i++)
    {
        if (isdigit(password[i]) > 0)
        {
            digit = true;
        }
        else if (islower(password[i]) > 0)
        {
            lowercase = true;
        }
        else if (isupper(password[i]) > 0)
        {
            uppercase = true;
        }
        else if (isalpha(password[i]) == 0)
        {
            symbol = true;
        }
    }
    if (uppercase == true && lowercase == true && digit == true && symbol == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
