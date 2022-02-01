from cs50 import get_string


# Function to count letters
def countLetters(text):
    count = 0
    textLength = len(text)
    for i in range(textLength):
        if text[i].isalpha():
            count += 1
    return count


# Function to count words
def countWords(text):
    count = 1
    textLength = len(text)
    for i in range(textLength):
        if text[i] == " ":
            count += 1
    return count


# Function to count sentences
def countSentences(text):
    count = 0
    textLength = len(text)
    for i in range(textLength):
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            count += 1
    return count


def main():
    # Prompt the user for a string of text
    text = get_string("Text: ")

    # Number of letters in text
    letterCount = countLetters(text)

    # Number of words in text
    wordCount = countWords(text)

    # Number of sentences in text
    sentenceCount = countSentences(text)

    # Plug values into Coleman-Liau index
    L = (letterCount / wordCount) * 100
    S = (sentenceCount / wordCount) * 100
    indexFloat = 0.0588 * L - 0.296 * S - 15.8
    index = round(indexFloat)

    # Print grade level
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


main()
