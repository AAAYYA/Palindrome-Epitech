/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-damian.gil
** File description:
** main_loop
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/my.h"

int main_loop(palindrome_t *palindrome, int iterations)
{
    char* reverseStr = strdup(palindrome->str);
    reverse_string(palindrome->str);
    long long num = strtoll(palindrome->str, NULL, palindrome->base);
    long long reverseNum = strtoll(reverseStr, NULL, palindrome->base);
    long long sum = num + reverseNum;
    free(reverseStr);
    free(palindrome->str);
    palindrome->str = number_to_base_string(sum, palindrome->base);
    iterations++;
    return iterations;
}

int condition_next(palindrome_t *palindrome)
{
    palindrome->str = number_to_base_string
    (palindrome->pal, palindrome->base);
    if (is_palindrome(palindrome->str) == 0) {
        printf("invalid argument\n");
        return 84;
    }
    second_loop(palindrome);
    if (palindrome->test == false)
        printf("no solution\n");
    return 0;
}

int main_condition(palindrome_t *palindrome)
{
    if (palindrome->number != 0) {
        palindrome->str = number_to_base_string
        (palindrome->number, palindrome->base);
        int iterations = perform_iteration(palindrome);
        if (iterations == -1)
            printf("no solution\n");
        else
            printf("%d leads to %s in %d iteration(s) in base %d\n",
            palindrome->number, palindrome->str, iterations, palindrome->base);
    } else {
        if (condition_next(palindrome) == 84)
            return 84;
    }
    return 0;
}

void setup_variables(palindrome_t *palindrome)
{
    palindrome->number = 0;
    palindrome->pal = 0;
    palindrome->base = 10;
    palindrome->imin = 0;
    palindrome->imax = 100;
    palindrome->str = NULL;
    palindrome->test = false;
    palindrome->strsearch = NULL;
}
