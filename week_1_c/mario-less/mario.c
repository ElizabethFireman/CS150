#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_bricks(int bricks);
void print_spaces(int spaces);
void print_row(int spaces, int bricks);


int main(void)
{
    //declare height variable
    int height = get_height();

    //for loop to print pyramid with spaces and bricks
    for(int i=0; i< height; i++)
        {
            print_row(height-(i+1), i+1);
        }
}

//get pyramid height from user
int get_height(void)
{
    int height;
    do
        {
            height = get_int("Height: ");
        }
    while(height<1);
    return height;
}

//print number of spaces
void print_spaces(int spaces)
{
    for(int i=0; i<spaces; i++)
        {
            printf(" ");
        }
}

//print number of bricks
void print_bricks(int bricks)
{
    for(int i=0; i<bricks; i++)
        {
            printf("#");
        }
}

//print row- print spaces + print bricks
void print_row(int spaces, int bricks)
{
    print_spaces(spaces);
    print_bricks(bricks);
    printf("\n");
}
