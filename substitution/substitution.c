#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool check_key(string text);
bool is_unique(string text);
char replace(char c, string k);
void ciphertext_string(string text, string key);

int main(int argc, string argv[])
{
    // Get key from command line
    // Make sure program run with one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Validate key
    if (check_key(argv[1]) == false)
    {
        return 1;
    }

    if (is_unique(argv[1]) == false)
    {
        printf("Key may not contain duplicate letters.\n");
        return 1;
    }

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    // Encipher
    // Print ciphertext
    printf("ciphertext: ");
    ciphertext_string(plaintext, argv[1]);
    printf("/n");
    return 0;
}

// Check that every character in key is a letter
// Make sure there are 26 letters

bool check_key(string text)
{
    if (strlen(text) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        char c = text[i];
        if (!isalpha(c))
        {
            printf("Key must contain only letters.\n");
            return false;
        }
    }
    return true;
}

// Make sure there are no repeated letters
bool is_unique(string text)
{
    int array[25] = {0};
    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        c = toupper(c);
        int index = c - 65;
        array[index]++;
        if (array[index] == 2)
        {
            return false;
        }
    }
    return true;
}

// Replace each character with key (Encipher)
char replace(char c, string k)
{
    if (!isalpha(c))
    {
        return c;
    }

    int index;
    char new_letter;
    if (isupper(c))
    {
        index = c - 65;
        new_letter = toupper(k[index]);
    }
    else
    {
        index = c - 97;
        new_letter = tolower(k[index]);
    }
    return new_letter;
}

// Make string of ciphertext by adding each replaced character
void ciphertext_string(string text, string key)
{
    char replaced = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        replaced = replace(text[i], key);
        printf("%c", replaced);
    }
    printf("\n");
}