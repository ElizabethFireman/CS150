#include <cs50.h>
#include <stdio.h>

int get_change(void);
int number_quarters(int change);
int number_dimes(int change);
int number_nickels(int change);
int number_pennies(int change);


int main(void)
{
    //declare change variable
    int change = get_change();


    // Determine the number of quarters
    int quarters = number_quarters(change);
    // Subtract quarters from total change
    change = change - (quarters * 25);
    //printf("%i\n", change);

    // Determine the number of dimes
    int dimes = number_dimes(change);
    // Subtract dimes from change
    change = change - (dimes * 10);
    //printf("%i\n", change);

    // Determine the number of nickels
    int nickels = number_nickels(change);
    // Subtract nickels from change
    change = change - (nickels * 5);
    //printf("%i\n", change);

    // Determine the number of pennies
    int pennies = number_pennies(change);
    // Subtract pennies from change
    change = change - (pennies * 1);
    //printf("%i\n", change);

    // Number of coins
    int coins = (quarters + dimes + nickels + pennies);
    // Print number of coins
    printf("%i\n", coins);
}

//Ask user for amount of change greater than 0
int get_change(void)
{
    int change;
    do
    {
        change = get_int("Change Amount? ");
    }
    while (change < 0);
    return change;
}

// Number of Quarters
int number_quarters(int change)
{
    int quarters = 0;
    while (change >=25)
    {
        quarters++;
        change = change - 25;
    }
    return quarters;
}

// Number of Dimes
int number_dimes(int change)
{
    int dimes = 0;
    while (change >=10)
    {
        dimes++;
        change = change - 10;
    }
    return dimes;
}
// Number of Nickels
int number_nickels(int change)
{
    int nickels = 0;
    while (change >=5)
    {
        nickels++;
        change = change - 5;
    }
    return nickels;
}
// Number of Pennies
int number_pennies(int change)
{
    int pennies = 0;
    while (change >=1)
    {
        pennies++;
        change = change - 1;
    }
    return pennies;
}
