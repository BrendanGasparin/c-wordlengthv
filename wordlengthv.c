/*
    wordlengthv.c
    Author: BrendanGasparin <Brendan.Gasparin@gmail.com>
    Date: 20 April 2024
    Program to read the standard input and then output the
    length of each word to a vertical histogram.
*/

#include <stdio.h>

#define IN  1   // inside a word
#define OUT 0   // outside a word
#define MAX_LENGTH  45  // maximum length of a word

int main()
{
    int word_lengths[MAX_LENGTH];
    int highest_count, letter_count, state, c;
    highest_count = letter_count = 0;
    state = OUT;
    for (int i = 0; i < MAX_LENGTH; i++)
        word_lengths[i] = 0;

    // Read standard input until EOF
    // and store word lengths in an array
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (letter_count > MAX_LENGTH)
                letter_count = MAX_LENGTH;
            if (letter_count > 0)
                word_lengths[letter_count - 1]++;
            letter_count = 0;
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            letter_count++;
        }
        else
            letter_count++;
    }

    // get highest count of word length occurrences
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (word_lengths[i] > highest_count)
            highest_count = word_lengths[i];
    }

    // print histogram
    for (int row = highest_count - 1; row >= 0; row--) {
        for (int col = 0; col < MAX_LENGTH; col++) {
            if (word_lengths[col] >= row + 1)
                printf(" # ");
            else
                printf("   ");
        }
        printf("\n");
    }

    // print histogram key
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        printf("---");
    }
    printf("\n");
    for (int i = 0; i < MAX_LENGTH; i++)
        printf("%2d ", i + 1);
    printf("\n");
}
