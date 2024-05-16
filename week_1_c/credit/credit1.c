#include <cs50.h>
#include <stdio.h>

long long get_creditcard(void);

int main(void)
{
    // what is the cc number
    long long cc = get_creditcard();
    int num_digit = 0; // number of digits in the number
    long long i; // first digits to add for luhmns check
    long long j; // second digits to add for luhmns check
    int first_sum = 0, sec_sum = 0;
    int count_first = 0, count_sec = 0;

    //count total number of digits
    long long a = cc;
    while (a!=0)
    {
        a = a/10;
        num_digit++;
    }

    //calc sum of first digit

    i = cc;

    while (i > 0)
    {
        int digit = (i % 10);
        i = i/10;
        count_first++;

        if ((count_first % 2 != 0) && (num_digit % 2!= 0)) //num digit is odd
        {
            first_sum = first_sum + digit;
        }
        else if ((count_first % 2 != 0) && (num_digit % 2 == 0)) //num digit is even
        {
            first_sum = first_sum + digit;
        }
    }

    printf("First Sum: %i\n", first_sum);


   //calc sum of second digits * 2
    j = cc;

    while (j > 0)
    {
        int digit = (j % 10);
        j = j/10;
        count_sec++;

        if  ((num_digit % 2 != 0) && (count_sec % 2 == 0)) //num digit is odd
        {
            digit = digit * 2;

            if (digit > 9)
            {
                digit = digit % 10;
                digit = digit + 1;
                sec_sum = sec_sum + digit;
            }
            else
            {
                sec_sum = sec_sum + digit;
            }
        }

        else if ((count_sec % 2 == 0) && (num_digit % 2 == 0)) //num digit is even
        {
            digit = digit * 2;
            if (digit > 9)
            {
                digit = digit % 10;
                digit = digit + 1;
                sec_sum = sec_sum + digit;
            }
            else
            {
                sec_sum = sec_sum + digit;
            }
        }
    }

    printf("Second Sum: %i\n", sec_sum);

    // add fist and second sum
    int total_sum = first_sum + sec_sum;
    printf("Total Sum: %i\n", total_sum);
    printf("Num Digit: %i\n", num_digit);

    // // Determine which cc it is
    // if ((total_sum % 10 == 0) && (num_digit == 15)) // Amex check
    // {
    //     //check first two digits

    // }
    // else if ((total_sum % 10 == 0) && (num_digit == 16)) // Master Card Check or Visa
    // {
    //     //check first two digits
    //     //check first digit for visa
    // }
    // else if ((total_sum % 10 == 0) && (num_digit == 13)) // Visa check
    // {
    //     //check first digit for visa
    // }
    // else
    // {
    //     printf("INVALID\n");
    // }

}

// ask user for credit card number
long long get_creditcard(void)
{
    long long cc = get_long("What is your credit card number? ");
    return cc;
}

// first number in CC
// int get_first_num(cc)
// second number in CC
