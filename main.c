#include <stdio.h>

#include "NumClass.h"


int main() {
    int a, b, i;

   scanf("%d%d",&a,&b);

    //  int number;

    // // Get the input from the user or assign a value to 'number'
    // printf("Enter an integer: ");
    // scanf("%d", &number);

    // // Call the isArmstrong function
    // if (isArmstrong(number)) {
    //     printf("%d is an Armstrong number.\n", number);
    // } else {
    //     printf("%d is not an Armstrong number.\n", number);
    // }







    printf("The Armstrong numbers are:");
    for (i = a; i <= b; ++i)
    {
        if (isArmstrong(i))
            printf(" %d", i);
    }

    printf("\nThe Palindromes are:");
    for (i = a; i <= b; ++i)
    {
        if (isPalindrome(i))
            printf(" %d", i);
    }

    printf("\nThe Prime numbers are:");
    for (i = a; i <= b; ++i)
    {
        if (isPrime(i))
            printf(" %d", i);
    }

    printf("\nThe Strong numbers are:");
    for (i = a; i <= b; ++i)
    {
        if (isStrong(i))
             printf(" %d", i);
    }

    printf("\n");

    return 0;
}