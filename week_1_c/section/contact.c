#include <cs50.h>
#include <stdio.h>
int main(void)
{
    string name = get_string("Whats your name?" );
    int age = get_int("How old are you?" );
    string phone = get_string("What is your phone number?" );
    printf("Contact, %s:, %i, %s\n", name, age, phone);
}
