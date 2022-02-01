from cs50 import get_int


# Prompt user for card number
def getCardNum():
    cardNum = get_int("Number: ")
    while (cardNum > 0):
        return cardNum


# Find card number length
def getCardLength(cardNum):
    cardLength = len(str(cardNum))
    return cardLength


# Get every other digit from end, multiply each by 2, and then add products' digits
def sumDigitsOdd(cardNum):
    index = 0
    sum = 0
    while cardNum > 0:
        if index % 2 == 1:
            digit = cardNum % 10
            digitMult = digit * 2
            if digitMult <= 9:
                sum = digitMult + sum
            else:
                sum = (digitMult % 10) + sum
                sum = int(digitMult / 10) + sum
        cardNum = int(cardNum / 10)
        index += 1
        oddSum = int(sum)
    return oddSum


# Get sum of remaining digits
def sumDigitsEven(cardNum):
    index = 0
    sum = 0
    while cardNum > 0:
        if index % 2 == 0:
            digit = cardNum % 10
            sum = digit + sum
        cardNum = int(cardNum / 10)
        index += 1
        evenSum = int(sum)
    return evenSum


# Get first two digits of card number
def firstDigits(cardNum, n):
    while cardNum >= n:
        cardNum = int(cardNum / 10)
    return int(cardNum)


def main():
    # Call function to get card number
    cardNum = getCardNum()

    # Calculate checksum with Luhn's algorithm
    totalSumDigits = sumDigitsOdd(cardNum) + sumDigitsEven(cardNum)

    # If the total's last digit is 0, number is valid
    if totalSumDigits % 10 != 0:
        print("INVALID")
        return 0

    # Call function to get card number length
    cardLength = getCardLength(cardNum)

    # First two digits of card number
    startingTwo = firstDigits(cardNum, 100)
    startingOne = firstDigits(cardNum, 10)

    # Check if American Express
    if cardLength == 15 and startingTwo == 34 or startingTwo == 37:
        print("AMEX")
        return 0

    # Check if Mastercard
    if cardLength == 16 and startingTwo >= 51 and startingTwo <= 55:
        print("MASTERCARD")
        return 0

    # Check if Visa
    if cardLength == 13 or cardLength == 16 and startingOne == 4:
        print("VISA")
        return 0
    # Otherwise card is invalid
    print("INVALID")

    return 0


main()