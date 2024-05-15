#include <cs50.h>
#include <stdio.h>

bool luhn_check(long number);
void card_type(long number);

int main(void)
{
    // Ask user for the credit card number
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 1);

    // Validate the card using Luhn's algorithm
    if (luhn_check(number))
    {
        // Determine and print the type of card
        card_type(number);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool luhn_check(long number)
{
    int sum = 0;
    bool alternate = false;
    while (number > 0)
    {
        int digit = number % 10;
        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit % 10) + 1;
            }
        }
        sum += digit;
        number /= 10;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}

void card_type(long number)
{
    // Determine the number of digits
    int digits = 0;
    long temp = number;
    while (temp > 0)
    {
        temp /= 10;
        digits++;
    }

    // Determine the starting digits
    long start = number;
    while (start >= 100)
    {
        start /= 10;
    }

    // Determine the type of card
    if ((start == 34 || start == 37) && digits == 15)
    {
        printf("AMEX\n");
    }
    else if (start >= 51 && start <= 55 && digits == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 4) && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
