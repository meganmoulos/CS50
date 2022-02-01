#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string text);
char rotate(char c, int n);
void ciphertext_string(string text, int k);

int main(int argc, string argv[])
{
    // Make sure program run with one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every char in argv[1] is a digit
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a string to an int
    int key = atoi(argv[1]);
    printf("key: %i\n", key);

    // Prompt user for plaintext
    string plaintext = get_string("Plaintext: ");

    // For each char, shift by the key
    // Iterate through each char of plaintext, call rotate on each
    printf("Ciphertext: ");
    ciphertext_string(plaintext, key);
}

// Function to make sure each character is a digit
bool only_digits(string text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        char c = text[i];
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

// Function to rotate through letters
char rotate(char c, int k)
{
    char new_index = 0;
    char new_c = 0;
    int index;
    if (isalpha(c))
    {
        if (isupper(c))
        {
            index = c - 65;
            new_index = (index + k) % 26;
            new_c = new_index + 65;
            return new_c;
        }
        if (islower(c))
        {
            index = c - 97;
            new_index = (index + k) % 26;
            new_c = new_index + 97;
            return new_c;
        }
    }
    return c;
}

// make string of ciphertext by adding each rotated char
void ciphertext_string(string text, int k)
{
    char rotated = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        rotated = rotate(text[i], k);
        printf("%c", rotated);
    }
    printf("\n");
}