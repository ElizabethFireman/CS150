import cs50
import re


def main():
    cc_number = get_cc_number("What is your cc number? ")  # pass in user input

    cc_length = int(len(cc_number))  # length of cc number
    print(cc_length)

    sum_check1 = p1_check_sum(cc_number, cc_length)
    sum_check2 = p2_check_sum(cc_number, cc_length)
    total_sum = sum_check1 + sum_check2

    # print (sum_check1)
    # print (sum_check2)
    # print(total_sum)

    # check Amex
    if (total_sum % 10 == 0) and (cc_length == 15):
        match_amex = re.match('^3[47]', cc_number)

        if match_amex:
            print("AMEX")
        else:
            print("INVALID")

    # check MC or Visa
    elif (total_sum % 10 == 0) and (cc_length == 16):
        match_mc = re.match('^5[12345]', cc_number)
        match_v = re.match('^4', cc_number)

        if match_mc:
            print("MASTERCARD")
        elif match_v:
            print("VISA")
        else:
            print("INVALID")

    # check Visa
    elif (total_sum % 10 == 0) and (cc_length == 13):
        match_v2 = re.match('^4', cc_number)
        if match_v2:
            print("VISA")
        else:
            print("INVALID")
    # print invalid if nothing
    else:
        print("INVALID")


# prompt user for a cc number

def get_cc_number(prompt):
    cc = cs50.get_string(prompt)
    return cc

# calc the part 1 of check sum (sum of every other digit starting with the last)


def p1_check_sum(cc_number, cc_length):
    cc_number = int(cc_number)
    cc_length = cc_length
    p1_sum = 0
    count = 0

    while cc_number > 0:
        digit = cc_number % 10
        cc_number = cc_number//10
        count += 1

        if (count % 2 != 0) and (cc_length % 2 != 0):  # cc number is odd
            p1_sum = p1_sum + digit
        elif (count % 2 != 0) and (cc_length % 2 == 0):  # cc number is even
            p1_sum = p1_sum + digit
    return p1_sum

# calc part 2 of check sum (very other digit starting with the second to last  * 2)


def p2_check_sum(cc_number, cc_length):
    cc_number = int(cc_number)
    cc_length = cc_length
    p2_sum = 0
    count_2 = 0

    while cc_number > 0:
        digit = cc_number % 10
        cc_number = cc_number//10
        count_2 += 1

        if (count_2 % 2 == 0) and (cc_length % 2 != 0):  # cc number is odd
            digit = digit * 2

            if digit > 9:
                digit = digit % 10
                digit = digit + 1
                p2_sum = p2_sum + digit
            else:
                p2_sum = p2_sum + digit

        elif (count_2 % 2 == 0) and (cc_length % 2 == 0):  # cc number is even
            digit = digit * 2

            if digit > 9:
                digit = digit % 10
                digit = digit + 1
                p2_sum = p2_sum + digit
            else:
                p2_sum = p2_sum + digit

    return p2_sum


main()
