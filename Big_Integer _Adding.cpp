#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 100

using namespace std;

int main (int argc, char *argv [])
{
    char firstNumber [N];
    char secondNumber [N];
    int result [N + 10];

    // initialize the array with '0'
    memset(firstNumber, '0', sizeof firstNumber);
    memset(secondNumber, '0', sizeof secondNumber);

    scanf ("%s %s", firstNumber, secondNumber);

    int firstNumberLength = strlen (firstNumber);
    int secondNumberLength = strlen (secondNumber);
    int maximumLength = max (firstNumberLength, secondNumberLength);

    reverse(firstNumber, firstNumber + strlen(firstNumber));
    reverse(secondNumber, secondNumber + strlen(secondNumber));

    // normalize the last end of string character
    firstNumber [firstNumberLength] = '0';
    secondNumber [secondNumberLength] = '0';

    int carry = 0;
    int resultLength = 0;

    for ( int i = 0; i < maximumLength; i++ ) {
        carry = (firstNumber [i] - '0') + (secondNumber [i] - '0') + carry;
        result [resultLength++] = carry % 10;
        carry /= 10;
    }

    while ( carry ) {
        result [resultLength++] = carry % 10;
        carry /= 10;
    }

    reverse(result, result + resultLength);

    for ( int i = 0; i < resultLength; i++ )
        printf ("%d", result [i]);

    printf ("\n");

    return 0;
}
