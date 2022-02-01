from cs50 import get_int


# Prompt the user with get_int for height
# Re-prompt until user provides an integer between 1 and 9
def get_height():
    while True:
        size = get_int("Height: ")
        if size in range(1, 9):
            break
    return size


# Print the desired height of pyramid
def main():
    height = get_height()
    for i in range(height):
        for j in range(height - i - 1):
            print(" ", end="")
        for j in range(i + 1):
            print("#", end="")
        print("")


main()
