#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // saves the KEY Length in a variable.

    int keylen = strlen(argv[1]);

    //checks if the key is 26 characters

    if (keylen != 26)
    {
        printf("Length of the Key Must Be 26\n");
        return 1;
    }
    for (int i = 0; i < keylen; i++)
    {
        // checks if there is anything but letters from a to z and A to Z.
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
        for (int j = 0; j < i; j++)
        {
            // checks for repeated characters.
            if ((argv[1][i] == argv[1][j]) || (argv[1][i] == tolower(argv[1][j])) || (argv[1][i] == toupper(argv[1][j])))
            {
                printf("Key must not containt repeated charachters.\n");
                return 1;
            }
        }
    }
    // get's plain text from user
    string plain = get_string("plaintext: ");

    // create the cryptic message
    int plen = strlen(plain);

    for (int i = 0; i < plen; i++)
    {
        if (islower(plain[i]))
        {
            plain[i] = tolower(argv[1][plain[i] - 'a']);
        }
        else if (isupper(plain[i]))
        {
            plain[i] = toupper(argv[1][plain[i] - 'A']);
        }
        else
        {
            continue;
        }
    }
    printf("ciphertext: %s\n", plain);
}