#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for a string of text
    string text = get_string("Text: ");

    // Number of letters in text
    int letterCount = count_letters(text);

    // Number of words in text
    int wordCount = count_words(text);

    // Number of sentences in text
    int sentenceCount = count_sentences(text);

    // Plug values into Coleman-Liau index
    float L = ((float) letterCount / wordCount) * 100;
    float S = ((float) sentenceCount / wordCount) * 100;
    float index_float = (float) 0.0588 * L - 0.296 * S - 15.8;
    int index = round(index_float);

    // Print grade level
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Function to count letters
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalnum(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Function to count words
int count_words(string text)
{
    int count = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            count ++;
        }
    }
    return count;
}

// Function to count sentences
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

