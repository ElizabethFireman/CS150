// libraries
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// function prototypes
int letter_check(string s);
string get_plaintext(void);
int repeat_check(string s);
int char_count(string s);
string get_plaintext(void);
char sub_letter(char ciphertext, char *key);

// get key using command line argument- using int argc string argv[]-- argv is an array of strings
int main(int argc, string argv[])
{
    if (argc != 2) // check command line argument single key is given
    {
        printf("length Usage: ./substitution key\n"); // error if too many or fewarguments are enterd
        return 1;
    }
    else
    {
        // 1 check if key is 26 letters
        int charcount = char_count(argv[1]);
        if (charcount == 1)
        {
            printf("Usage: ./caesar key\n"); // error if not a digit
            return 1;
        }

        // 2 check key to make sure they are letters
        int lettercount = letter_check(argv[1]);
        if (lettercount == 1)
        {
            printf("Usage: ./caesar key\n"); // error if not a digit
            return 1;
        }

        // 3 check key so there are no repeat letters
        int repeat = repeat_check(argv[1]);
        if (repeat == 1)
        {
            printf("Usage: ./caesar key\n"); // error if not a digit
            return 1;
        }
    }

    // setting up the key and plain text
    char key[27];         // declare key array (26 + 1 for the null at the end)
    strcpy(key, argv[1]); // copy argv into key array

    string plaintext = get_plaintext(); // get plain text
    int length = strlen(plaintext);     // get length of text
    char ciphertext[length + 1];        // declare array called cipher text
    strcpy(ciphertext, plaintext);      // copy plain text into cipher text so that you can change i

    // sub letters from key into cipher text
    for (int i = 0; ciphertext[i] != '\0'; i++)
    {
        ciphertext[i] = sub_letter(ciphertext[i], key);
    }
    printf("ciphertext: %s\n", ciphertext); // print the ciphered message
}

// validate key (1-3)
// 1. Key check to makes sure there are 26 characters
int char_count(string s)
{
    int count = strlen(s);
    if (count != 26)
    {
        printf("length Usage: ./substitution key\n"); // error not 26 characters
        return 1;
    }
    return 0;
}
// 2. Key check to make sure letters
int letter_check(string s) // checks to see if characters are digits
{
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (!isalpha(s[i]))
        {
            return 1;
        }
    }
    return 0;
}

// 3. Key check for repeated characters (no matter the case)
int repeat_check(string s)
{
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        for (int j = i + 1; j < length - 1; j++)
        {
            if (tolower(s[i]) == tolower(s[j]))
            {
                return 1;
            }
        }
    }

    return 0;
}

// get string from user plaintext:
string get_plaintext(void)
{
    string plaintext = get_string("Enter Plaintext:  ");
    return plaintext;
}

// take character in ciphertext and replace it with character in key based on index
char sub_letter(char ciphertext, char *key)
{
    char sub = ciphertext;

    // check to see if character in plain text is a letter (isalpha)
    if (isalpha(ciphertext)) // is i a letter
    {
        if (isupper(ciphertext)) // if upper case (isupper)
        {
            int pos = ciphertext - 'A'; // shift all letters so A= 0
            sub = key[pos];             // subsitute and make capital again
            sub = toupper(sub);
        }
        else if (islower(ciphertext)) // if lower case (islower)
        {
            int pos = ciphertext - 'a'; // shift all letters so a= 0
            sub = key[pos];
            sub = tolower(sub);
        }
    }
    return sub;
}
