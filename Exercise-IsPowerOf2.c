/********************************************
*                                           *
*    Console Exercise - IsPowerOf2          *
*    Author Petar Nikolov                   *
*                                           *
*********************************************/

#include <stdio.h>

int main()
{
    int oldNumber = 0;
    int suma = 0;
    int number, i, number_bezEdno;
    //char number_char[20] =          { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
    char *number_char = NULL;
    //char number_char_bezEdno[20] =  { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
    char *number_char_bezEdno = NULL;
    int NumberOfBitsNeeded = 1;

    printf("Enter some number to check: ");
    scanf_s("%d", &number);
    printf("\n");

    /* First we have to determine how many bits are needed to store the user input and allocate memory for the arrays */
    /* The constarains of this cycle is 64 because this is the maximum size of INT in 64bit mashine */

    oldNumber = number;
    for (i = 0; i < 64; i++)
    {
        oldNumber /= 2;
        if (oldNumber) NumberOfBitsNeeded++;
    }

    /* Allocate memory */
    number_char = (char *)calloc(NumberOfBitsNeeded, sizeof(char));
    number_char_bezEdno = (char *)calloc(NumberOfBitsNeeded, sizeof(char));
    if (number_char == NULL || number_char_bezEdno == NULL)
    {
        printf("Cannot allocate memory. The program will now close\n");
        _getch();
        return 0;
    }

    oldNumber = number;
    for (i = 0; i < NumberOfBitsNeeded; i++)
    {
        if (number % 2 == 1)
            number_char[i] = '1';
        else if (number % 2 == 0)
            number_char[i] = '0';
        number /= 2;
        if (number == 0) break;
    }

    number_bezEdno = oldNumber - 1;
    for (i = 0; i < NumberOfBitsNeeded; i++)
    {
        if (number_bezEdno % 2 == 1)
            number_char_bezEdno[i] = '1';
        else if (number_bezEdno % 2 == 0)
            number_char_bezEdno[i] = '0';
        number_bezEdno /= 2;
        if (number_bezEdno == 0) break;
    }

    for (i = 0; i < NumberOfBitsNeeded; i++)
    {
        printf("%c ", number_char[i]);
    }

    printf("\n");
    for (i = 0; i < NumberOfBitsNeeded; i++)
    {
        printf("%c ", number_char_bezEdno[i]);
    }
    for (i = 0; i < NumberOfBitsNeeded; i++)
    {
        if ((number_char_bezEdno[i] - 48) & (number_char[i] - 48)) suma++;
    }
    if (!suma)
        printf("\nsum: %d,  The number is a power of 2\n", suma);
    else
        printf("\nsum: %d,  The number is not a power of 2\n", suma);
    _getch();
    return 0;
}
