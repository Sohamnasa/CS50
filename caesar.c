#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string p = get_string("Plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, a = strlen(p); i < a; i++)
    {
        if (isupper(p[i]))
        {
            printf("%c", (p[i] - 65 + key) % 26 + 65);
        }

        else if (islower(p[i]))
        {
            printf("%c", (p[i] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c\n", p[i]);
        }
    }
    printf("\n");
}