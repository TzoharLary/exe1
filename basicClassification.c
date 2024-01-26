#include <stdio.h>
#include "NumClass.h"


// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to check if a number is a strong number
int isStrong(int num) {
    int originalNum = num;
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }

    return (sum == originalNum);
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;  // 0 and 1 are not prime numbers
    }

    // Check for factors from 2 to the square root of num
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;  // num has a factor other than 1 and itself
        }
    }

    return 1;  // num is a prime number
}
