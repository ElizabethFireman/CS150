import cs50


def main():
    changeowed = get_change("How much change do we owe you? ")
    changeowed = changeowed * 100

    # determine number of quarters
    num_quarter = quarter_count(changeowed)
    # print(f"quarters, {num_quarter}")

    # recalc change owed
    changeowed = changeowed - (num_quarter * 25)
    # print(f"change outstanding, {changeowed}")

    # determine number of dimes
    num_dime = dimes_count(changeowed)
    # print(f"dimes, {num_dime}")

    # recalc change owed
    changeowed = changeowed - (num_dime * 10)
    # print(f"change outstanding, {changeowed}")

    # determine number of nickels
    num_nickel = nickels_count(changeowed)
    # print(f"nickels, {num_nickel}")

    # recalc change owed
    changeowed = changeowed - (num_nickel * 5)
    # print(f"change outstanding, {changeowed}")

    # determine number of pennies
    num_penny = pennies_count(changeowed)
    # print(f"pennies, {num_penny}")

    # check to see if accurate
    changeowed = changeowed - (num_penny * 1)
    # print(f"change outstanding, {changeowed}")

    # sum coins
    coins = num_quarter + num_dime + num_nickel + num_penny

    # print number coind
    print(coins)


# ask user how much change they are owed using get_float
def get_change(prompt):
    while True:
        change = cs50.get_float(prompt)
        if change > 0:  # check to see if change is postive - if not ask again
            break
        else:
            print("Please enter a number greater than 0 ")
    return change


# calculate the number of quarters needed
def quarter_count(changeowed):
    quarters = 0
    while changeowed >= 25:
        quarters = quarters + 1
        changeowed = changeowed - 25
    return quarters

# calculate the number of dimes needed


def dimes_count(changeowed):
    dimes = 0
    while changeowed >= 10:
        dimes = dimes + 1
        changeowed = changeowed - 10
    return dimes

# calculate the number of nickels needed


def nickels_count(changeowed):
    nickels = 0
    while changeowed >= 5:
        nickels = nickels + 1
        changeowed = changeowed - 5
    return nickels

# calculate the number of pennies needed


def pennies_count(changeowed):
    pennies = 0
    while changeowed >= 1:
        pennies = pennies + 1
        changeowed = changeowed - 1
    return pennies

# call main


main()
