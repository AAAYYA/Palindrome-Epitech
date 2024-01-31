/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-damian.gil
** File description:
** main_loop
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

void prints(palindrome_t *palindrome, int iterations)
{
    if (palindrome->file_flag) {
        printf("%d leads to %s in %d iteration(s) in base %d\n",
        palindrome->number, palindrome->str, iterations, palindrome->base);
        if (palindrome->r_flag && palindrome->c_flag)
            printf("The number of steps is: %d\n", palindrome->count);
    } else {
        printf("\033[0;33m%d\033[0m leads to \033[0;33m%s\033[0m "
        "in \033[0;33m%d\033[0m iteration(s) in base \033[0;33m%d\033[0m\n",
        palindrome->number, palindrome->str, iterations, palindrome->base);
        if (palindrome->r_flag && palindrome->c_flag)
            printf("The number of steps is: "
            "\033[0;32m%d\n\033[0m", palindrome->count);
    }
}

void print_solution(palindrome_t *palindrome)
{
    if (!palindrome->test && !palindrome->file_flag)
        printf("\033[0;36mno solution!!!\e[0m\n");
    else if (!palindrome->test && palindrome->file_flag)
        printf("no solution\n");
}

int condition(palindrome_t *palindrome)
{
    palindrome->str = number_to_base_string
    (palindrome->pal, palindrome->base);
    if (is_palindrome(palindrome->str) == 0)
        return 84;
    second_loop(palindrome);
    print_solution(palindrome);
    return 0;
}

int main_condition(palindrome_t *palindrome)
{
    if (palindrome->number != 0) {
        palindrome->str = number_to_base_string
        (palindrome->number, palindrome->base);
        int iterations = perform_iteration(palindrome);
        if (iterations == -1 && !palindrome->file_flag) {
            printf("\033[0;36mno solution\e[0m\n");
            return 0;
        }
        if (iterations == -1 && palindrome->file_flag) {
            printf("no solution\n");
            return 0;
        } else
            prints(palindrome, iterations);
    } else {
        if (condition(palindrome) == 84)
            return 84;
    }
    return 0;
}
