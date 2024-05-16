#include <ctype.h> //determine words, spaces, punctuation
#include <math.h>  //round
#include <stdio.h>
#include <string.h>
#include <cs50.h>

// function prototypes
string get_passage(void);
int letter_count(string passage);
int sen_count(string passage);
int word_count(string passage);
int cl_index(int letters, int sens, int words);

int main(void)
{
    string passage = get_passage(); // get passage
    int letters = letter_count(passage);
    int sens = sen_count(passage);
    int words = word_count(passage);
    int index = cl_index(letters, sens, words);

    // printf("Index Score: %i\n", index);

    // determine reading level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// determine the reading passage
string get_passage(void)
{
    string passage = get_string("Enter Text: ");
    return passage;
}

// count letters
int letter_count(string passage)
{
    int count = 0;
    for (int i = 0, length = strlen(passage); i < length; i++)
    {
        if (isalpha(passage[i]))
        {
            count++;
        }
    }
    return count;
}

// count sentences- by count punctuation
int sen_count(string passage)
{
    int count = 0;
    for (int i = 0, length = strlen(passage); i < length; i++)
    {
        if (ispunct(passage[i]))
        {
            if ((passage[i] == '.') || (passage[i] == '!') || (passage[i] == '?'))
            {
                count++;
            }
        }
    }
    return count;
}
// count words- by counting spaces and adding 1
int word_count(string passage)
{
    int count = 0;
    for (int i = 0, length = strlen(passage); i < length; i++)
    {
        if (isblank(passage[i]))
        {
            count++;
        }
    }
    count = count + 1;
    return count;
}

// cl index- Reading level score

int cl_index(int letters, int sens, int words)
{
    // index formula = 0.0588 * L - 0.296 * S - 15.8

    float fl = (float) letters;
    // printf("fl: %f\n", fl);
    float fs = (float) sens;
    // printf("fs: %f\n", fs);
    float l = fl / words * 100.0;
    // printf("l = %f\n", l);
    float s = fs / words * 100.0;
    // printf("s = %f\n", s);
    float index = (0.0588 * l) - (0.296 * s) - 15.8;
    index = round(index);
    // printf("index: %f\n", index);
    index = (int) index;
    return index;
}
