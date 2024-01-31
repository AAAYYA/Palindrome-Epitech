/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** find_p
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/my.h"

void reverse_string(char* str)
{
    int length = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int is_palindrome(char* str)
{
    int length = strlen(str);
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

char *number_to_base_string(int number, int base)
{
    int num_digits = 1;
    int temp = number;
    while (temp /= base) {
        num_digits++;
    }
    char* result = (char*)malloc((num_digits + 1) * sizeof(char));
    int i = num_digits - 1;
    while (number) {
        int digit = number % base;
        if (digit < 10) {
            result[i] = digit + '0';
        } else {
            result[i] = digit - 10 + 'A';
        }

        number /= base;
        i--;
    }
    result[num_digits] = '\0';
    return result;
}
