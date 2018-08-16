#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 100

using namespace std;

int main (int argc, char *argv [])
{
    char firstNumber [N];
    int secondNumber;
    int result [N + 10];

    scanf ("%s %d", firstNumber, &secondNumber);

    int firstNumberLength = strlen (firstNumber);

    reverse(firstNumber, firstNumber + strlen(firstNumber));

    int carry = 0;
    int resultLength = 0;

    for ( int i = 0; i < firstNumberLength; i++ ) {
        carry = ((firstNumber [i] - '0') * secondNumber) + carry;
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
