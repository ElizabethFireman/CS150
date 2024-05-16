#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_bricks(int bricks);
void print_spaces(int spaces);
void print_gaps(int gaps);
void print_row(int spaces, int bricks, int gaps);


int main(void)
{
    //declare height variable
    int height = get_height();

    //for loop to print pyramid with spaces and bricks and a gap
    for(int i=0; i< height; i++)
        {
            print_row(height-(i+1), i+1, 2*height+2-2*height);
        }
}

//get pyramid height from user- limit height b/w 1 & 8
int get_height(void)
{
    int height;
    do
        {
            height = get_int("Height: ");
        }
    while(height>8 || height<1);
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

//print gaps
void print_gaps(int gaps)
{
    for(int i=0; i<gaps; i++)
        {
            printf(" ");
        }
}

//print row- print spaces + print bricks
void print_row(int spaces, int bricks, int gaps)
{
    print_spaces(spaces);
    print_bricks(bricks);
    print_gaps(gaps);
    print_bricks(bricks);
    printf("\n");
}
