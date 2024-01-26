#include <stdio.h>
#include "NumClass.h"


// Function to calculate the power of a number
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    else{
    return base * power(base, exponent - 1);
}
}

// Function to calculate the number of digits in an integer
int countDigits(int num) {
    if (num == 0) {
        return 0;
    } else{
    return 1 + countDigits(num / 10);
    }
}

// Function to check if a number is an Armstrong number recursively
int isArmstrongRecursive(int num, int originalNum, int n) {
    if (num == 0) {
        return 0;
    } else {
        return power(num % 10, n) + isArmstrongRecursive(num / 10, originalNum, n);
    }
}

// Function to check if a number is an Armstrong number recursively
int isArmstrong(int num) {
    // Find the number of digits in the given number
    int n = countDigits(num);

    // Calculate the sum of nth powers of digits recursively
    int sum = isArmstrongRecursive(num, num, n);

    // Check if the sum is equal to the original number
    return sum == num;
}



// Function to check if an integer is a palindrome recursively
int isPalindrome(int num) {
    if (num < 0) {
        // Negative numbers are not palindromic
        return 0;
    }

    int digits = countDigits(num);

    if (digits <= 1) {
        // Single-digit numbers are palindromic
        return 1;
    }

    int divisor = 1;
    for (int i = 1; i < digits; ++i) {
        divisor *= 10;
    }

    int firstDigit = num / divisor;
    int lastDigit = num % 10;

    if (firstDigit != lastDigit) {
        // If the first and last digits are not equal, it's not a palindrome
        return 0;
    }

    // Recursively check the palindrome status of the remaining sub-number
    int remainingNum = (num % divisor) / 10;
    return isPalindrome(remainingNum);
}
