#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Asks user to input name
    string answer = get_string("What is your name?\n");
    printf("hello, %s\n", answer);
}