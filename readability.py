from cs50 import get_string


def main():
    text = get_string("Text: ")

    sentences = text.count('.') + text.count('?') + text.count('!')
    words = text.count(' ') + 1
    letters = count_letters(text)

    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = ((0.0588 * L) - (0.296 * S) - 15.8)

    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Below Grade 1")
    else:
        print(f"Grade {round(index)}")


def count_letters(text: str) -> int:
    unwanted = [' ', '!', '?', '.', ',', ';', "'", '"']

    for symbol in unwanted:
        text = text.replace(symbol, '')
    return len(text)


main()
