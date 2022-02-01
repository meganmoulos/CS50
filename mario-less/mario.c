#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt user for height
    int size;
    do
    {
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);

    //Height of pyramid loop
    for (int i = 0; i < size; i++)
    {
        //Adding spaces
        for (int j = size - 1; j > i; j--)
        {
            printf(" ");
        }

        //Adding hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}