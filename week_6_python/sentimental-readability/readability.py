from  cs50 import get_string

def main():
    text = get_passage("Enter Text: ")


    num_letters = count_letters(text)
    num_words = count_words(text)
    num_sens = count_sens(text)
    reading_index = calc_index(num_letters, num_words, num_sens)

    # determine reading level
    if reading_index < 1:
        print("Before Grade 1")
    elif reading_index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {reading_index}")

# get a passage from user
def get_passage(prompt):
    passage = get_string(prompt)
    return passage

# count number of letters
def count_letters(text):
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters

# count number of words (counting spaces)
def count_words(text):
    words = text.split()
    return len(words)


# count number of sentences (counting punctuation)
def count_sens(text):
    sentences = text.count('.') + text.count('!') + text.count('?')
    return sentences

# calc CL Index
# index formula = 0.0588 * L - 0.296 * S - 15.8
def calc_index(num_letters, num_words, num_sens):
    s = (num_sens/num_words) * 100
    l = (num_letters/num_words) * 100
    index = (0.0588 * l) - (0.296 * s) - 15.8
    index = round(index)
    return(index)

main()
