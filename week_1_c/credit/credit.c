#include <cs50.h>
#include <math.h>
#include <stdio.h>

long long get_creditcard(void);
int get_num_digit(long long cc);
int get_first_sum(long long cc, int num_digit);
int get_second_sum(long long cc, int num_digit);
int get_first_digit(long long cc, int num_digit);
int get_first_two_digits(long long cc);

int main(void)
{
    long long cc = get_creditcard();              // what is the cc number
    int num_digit = get_num_digit(cc);            // number of digits in the number
    int first_sum = get_first_sum(cc, num_digit); // part 1 sumcheck add every other number starting with the last
    int sec_sum =
        get_second_sum(cc, num_digit); // part 2 sumcheck add every other number starting with the second to last and double
    int first_digit = get_first_digit(cc, num_digit); // get first digit of cc #
    int first_two_digits = get_first_two_digits(cc);  // get first 2 digits of cc #

    // add fist and second sum
    int total_sum = first_sum + sec_sum;

    // Card Type check

    if ((total_sum % 10 == 0) && (num_digit == 15)) // Amex check
    {
        if ((first_two_digits == 34) || (first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if ((total_sum % 10 == 0) && (num_digit == 16)) // Master Card Check & Visa Check 1
    {
        if ((first_two_digits == 51) || (first_two_digits == 52) || (first_two_digits == 53) || (first_two_digits == 54) ||
            (first_two_digits == 55))
        {
            printf("MASTERCARD\n");
        }
        else if (first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else if ((total_sum % 10 == 0) && (num_digit == 13)) // Other Visa check
    {
        if (first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    // printf("num digit: %i\n", num_digit);
    // printf("first_digit: %i\n", first_digit);
    // printf("total_sum: %i\n", total_sum);
}

// ask user for credit card number
long long get_creditcard(void)
{
    long long cc = get_long("What is your credit card number? ");
    return cc;
}

// count number of digits in the credit card
int get_num_digit(long long cc)
{
    int num_digit = 0;
    while (cc != 0)
    {
        cc = cc / 10;
        num_digit++;
    }
    return num_digit;
}

// calc sum of every other digit starting with the last- luhmns equation
int get_first_sum(long long cc, int num_digit)
{
    int first_sum = 0, count_first = 0;

    while (cc > 0)
    {
        int digit = (cc % 10);
        cc = cc / 10;
        count_first++;

        if ((count_first % 2 != 0) && (num_digit % 2 != 0)) // num digit is odd
        {
            first_sum = first_sum + digit;
        }
        else if ((count_first % 2 != 0) && (num_digit % 2 == 0)) // num digit is even
        {
            first_sum = first_sum + digit;
        }
    }
    return first_sum;
}

// calc sum of every other digit starting with the second to last  * 2 -  luhmns check
int get_second_sum(long long cc, int num_digit)
{
    int sec_sum = 0, count_sec = 0;

    while (cc > 0)
    {
        int digit = (cc % 10);
        cc = cc / 10;
        count_sec++;

        if ((num_digit % 2 != 0) && (count_sec % 2 == 0)) // num digit is odd
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

        else if ((count_sec % 2 == 0) && (num_digit % 2 == 0)) // num digit is even
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
    return sec_sum;
}

// first number in CC
int get_first_digit(long long cc, int num_digit)
{
    int digit = num_digit - 1;
    int first_digit = cc / pow(10, digit);
    return first_digit;
}

// first two numbers in CC
int get_first_two_digits(long long cc)
{
    long long two_digits = cc;
    while (two_digits >= 99)
    {
        two_digits = two_digits / 10;
    }

    int first_two_digits = two_digits;

    return first_two_digits;
}
