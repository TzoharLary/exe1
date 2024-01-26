#include <stdio.h>
#include "NumClass.h"

// Function to calculate the power of a number
int powerloop(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// Function to count the number of digits in a number
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        ++count;
    }
    return count;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int originalNum = num;
    int n = countDigits(num);
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += powerloop(digit, n);
        num /= 10;
    }

    return (sum == originalNum);
}

// Function to check if an integer is a palindrome
int isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;

    // Reverse the integer
    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    // Check if the reversed integer is equal to the original
    return (originalNum == reversedNum) ? 1 : 0;
}