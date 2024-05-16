#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gloabl variable: letter points
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// functions
string one_word(void);
string two_word(void);
int calc_score(string word);

int main(void)
{

    string player_one_word = one_word(); // player ones word
    string player_two_word = two_word(); // player twos word

    int one_points = calc_score(player_one_word);
    int two_points = calc_score(player_two_word);

    // determine a winner
    if (one_points > two_points)
    {
        printf("Player 1 wins!\n");
    }
    else if (two_points > one_points)
    {
        printf("Player 2 wins!\n");
    }
    else if (one_points == two_points)
    {
        printf("Tie!\n");
    }
}

// get word from player 1
string one_word(void)
{
    string word_one = get_string("Player 1 enter a word: ");
    return word_one;
}

// get word from player 2
string two_word(void)
{
    string word_two = get_string("Player 2 enter a word: ");
    return word_two;
}

// calc values of both words
int calc_score(string word)
{
    int score = 0; // initialize variable and start with 0

    // get a score for each character & add them together

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isupper(word[i]))
        {
            score = score + points[word[i] - 'A']; // aliging letter to location in array using ASCII ex: H is 72 and A is 65. 72-
                                                   // 65 = 7 and H is the 7 position in array
        }
        else if (islower(word[i]))
        {
            score = score + points[word[i] - 'a']; // does the same as above for lower case letters
        }
    }
    return score;
}
