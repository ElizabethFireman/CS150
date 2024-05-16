#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//functions
int digit_check(string s);
string get_plaintext(void);
char rotate(char i, int key);

int main(int argc, string argv[])
{
    //initialize variables
    int key = 0;

    //command line arugment, check, and define key
    if (argc != 2) //get one command line argument from user
    {
        printf("Usage: ./caesar key\n"); //error if to many arguments are enterd
        return 1;
    }
    else
    {
        int check = digit_check(argv[1]); //make sure arguments are digits
        if (check == 0)
        {
            key = atoi(argv[1]); //convert string to int and set key
        }
        if (check == 1)
        {
            printf("Usage: ./caesar key\n"); //error if not a digit
            return 1;
        }
    }
    //printf("Key: %i\n", key);

    string plaintext = get_plaintext(); //get plain text
    int length = strlen(plaintext); //get length of text
    char ciphertext[length + 1]; // decalre array called cipher text
    strcpy(ciphertext, plaintext); //copy plain text into cipher text so that you can change it

    //using the key rotate letters in the cipher text array and restore them
    for (int i = 0; ciphertext[i] != '\0'; i++)
    {
        ciphertext[i] = rotate(ciphertext[i], key);
    }
    printf("ciphertext: %s\n", ciphertext); //print the ciphered message
}



//check if digits
int digit_check(string s)
{
        for(int j= 0; s[j] != '\0'; j++) // checks to see if characters are digits
        {
            if(!isdigit(s[j]))
            {
                return 1;
            }
        }
        return 0;
}

//get string from user plaintext:

string get_plaintext(void)
{
    string plaintext = get_string("Enter Message:  ");
    return plaintext;
}

char rotate(char i, int key)
{
    //check to see if character is a letter (isalpha)
    if(isalpha(i)) //is i a letter
    {
        if(isupper(i)) //if upper case (isupper)
        {
            i = i - 'A'; //shift all letters so A= 0
            i = (i + key) % 26 + 'A'; //if key is over 25 make sure it loops--> ci = (pi + k) % 26
        }
        else if(islower(i)) //if lower case (islower)
        {
            i = i - 'a'; //shift all letters so a= 0
            i = (i + key) % 26 + 'a'; //if key is over 25 make sure it loops--> ci = (pi + k) % 26
        }
    }

    return i;
}
