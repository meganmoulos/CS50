#include <stdio.h>
#include <cs50.h>
#include <math.h>

long long get_card_num(void);
int get_card_length(long long cardnum);
int sum_digits_odd(long long cardnum);
int sum_digits_even(long long cardnum);
int first_n_digits(long long cardnum, int n);

int main(void)
{

    // Call function to get card number
    long long cardnum = get_card_num();


    // Calculate checksum with Luhn's algorithm
    int total_sum_digits = sum_digits_odd(cardnum) + sum_digits_even(cardnum);


    // If the total's last digit is 0, number is valid
    if (total_sum_digits % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }


    // Call function to get card number length
    int cardlength = get_card_length(cardnum);


    // First two digits of card number
    int starting_two = first_n_digits(cardnum, 100);
    int starting_one = first_n_digits(cardnum, 10);


    // Check if American Express
    if (cardlength == 15 && (starting_two == 34 || starting_two == 37))
    {
        printf("AMEX\n");
        return 0;
    }

    // Check if Mastercard
    if (cardlength == 16 && (starting_two >= 51 && starting_two <= 55))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    // Check if Visa
    if ((cardlength == 13 || cardlength == 16) && starting_one == 4)
    {
        printf("VISA\n");
        return 0;
    }
    printf("INVALID\n");
    return 0;

}

//Prompt user for card number
long long get_card_num(void)
{
    long long cardnum;
    do
    {
        cardnum = get_long_long("Number: ");
    }
    while (cardnum < 0);

    return cardnum;
}

//Find card number length
int get_card_length(long long cardnum)
{
    long long rem = cardnum;
    int cardlength = 0;
    do
    {
        rem = (rem / 10);
        cardlength++;
    }
    while (rem > 0);

    return cardlength;
}

// Get every other digit from end, multiply each by 2, and then add products' digits
int sum_digits_odd(long long cardnum)
{
    int index = 0;
    int sum = 0;
    do
    {
        if ((index % 2) == 1)
        {
            int digit = cardnum % 10;
            int digitmult = digit * 2;
            if (digitmult <= 9)
            {
                sum = digitmult + sum;
            }
            else
            {
                sum = (digitmult % 10) + sum;
                sum = (digitmult / 10) + sum;
            }
        }

        cardnum = cardnum / 10;
        index++;
    }
    while (cardnum > 0);
    return sum;
}

//Get sum of remaining digits
int sum_digits_even(long long cardnum)
{
    int index = 0;
    int sum = 0;
    do
    {
        if ((index % 2) == 0)
        {
            int digit = cardnum % 10;
            sum = digit + sum;
        }

        cardnum = cardnum / 10;
        index++;
    }
    while (cardnum > 0);
    return sum;

}

// Get first two digits of card number
int first_n_digits(long long cardnum, int n)
{
    long long first_digits;
    first_digits = cardnum;

    while (first_digits >= n)
    {
        first_digits = first_digits / 10;
    }
    return first_digits;
}