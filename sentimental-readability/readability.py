# TODO
# Function to count number of letters by incrementing
# everytime alphabet is detected
def count_letters(input):
    nu = 0
    for i in range(len(input)):
        if input[i].isalpha():
            nu = nu + 1
    return nu


# Function to count number of words by incrementing
# everytime space is detected
def count_words(input):
    num = 1
    for i in range(len(input)):
        if input[i].isspace():
            num = num + 1
    return num


# Function to count number of sentences by incrementing everytime
# period exclamation or question mark is detected
def count_sentences(input):
    numb = 0
    for i in range(len(input)):
        if input[i] == "." or input[i] == "?" or input[i] == "!":
            numb = numb + 1
    return numb


# Requesting input from the user
input = input("Text: ")

# Coleman-Liau index to calculate readability of a text.
L = float(count_letters(input) / count_words(input) * 100)
S = float(count_sentences(input) / count_words(input) * 100)
index = 0.0588 * L - 0.296 * S - 15.8


# Using round to approximate index to the nearest int.
number = round(index)

# Conditions depending on the value of the rounded index.
if number < 1:
    print("Before Grade 1")
elif number > 16 or number == 16:
    print("Grade 16+")
else:
    print(f"Grade {number}")