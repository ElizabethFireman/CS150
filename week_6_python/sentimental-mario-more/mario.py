# import moduels
from cs50 import get_int


def main():
    pyramid = get_height()
    # create a for loop to print out space, blocks, gap, blocks
    # print_row(height-(i+1), i+1, 2*height+2-2*height);
    for i in range(pyramid):
        print_row(pyramid - (i + 1), i + 1, 2*pyramid+2-2*pyramid)


def get_height():
    # get user to input a height (number between 1 and 8 inclusive)
    while True:
        height = get_int("Pick a height between 1 and 8 ")
        if height >= 1 and height <= 8:  # check to make sure user input in between 1 & 8
            break
    return height


def print_spaces(spaces):
    for i in range(spaces):
        print(" ", end="")


def print_bricks(bricks):
    for i in range(bricks):
        print("#", end="")


def print_gap(gap):
    for i in range(gap):
        print(" ", end="")


def print_row(spaces, bricks, gap):
    print_spaces(spaces)
    print_bricks(bricks)
    print_gap(gap)
    print_bricks(bricks)
    print()


main()
