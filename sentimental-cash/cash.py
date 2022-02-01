from cs50 import get_float


def main():
    # Prompt user for amount of change owed
    change = get_change()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(change)
    change = change - quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(change)
    change = change - dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(change)
    change = change - nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(change)
    change = change - pennies

    # Sum coins
    sum = quarters + dimes + nickels + pennies
    coins = int(sum)

    # Print total number of coins to give the customer
    print(f"{coins}")


def get_change():
    while True:
        change = get_float("Change owed: ")
        if change > 0:
            change = change * 100
            return change


def calculate_quarters(change):
    counter = 0
    while change >= 25:
        change = change - 25
        counter += 1
    return counter


def calculate_dimes(change):
    counter = 0
    while change >= 10:
        change = change - 10
        counter += 1
    return counter


def calculate_nickels(change):
    counter = 0
    while change >= 5:
        change = change - 5
        counter += 1
    return counter


def calculate_pennies(change):
    return change


main()
