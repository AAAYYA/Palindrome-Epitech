/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** palindrome
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "../includes/my.h"

int perform_iteration(palindrome_t *palindrome)
{
    int iterations = 0;
    int start = strtol(palindrome->str, NULL, palindrome->base);
    while (((!is_palindrome(palindrome->str) &&
    palindrome->strsearch == NULL ) ||
    (palindrome->strsearch != NULL &&
    strcmp(palindrome->str, palindrome->strsearch) != 0))
    || iterations < palindrome->imin ) {
        if (iterations == palindrome->imax ||
        (palindrome->strsearch != NULL &&
        strtol(palindrome->str, NULL, palindrome->base)
        > strtol(palindrome->strsearch, NULL, palindrome->base)) ||
        strtol(palindrome->str, NULL, palindrome->base) < start)
            return -1;
        iterations = main_loop(palindrome, iterations);
        display_l_args(palindrome, iterations);
    }
    sprintf(palindrome->str, "%ld",
    strtol(palindrome->str, NULL, palindrome->base));
    return iterations;
}

void third_loop(palindrome_t *palindrome)
{
    for (int i = 0; i <= palindrome->pal; i++) {
        palindrome->str = number_to_base_string(i, palindrome->base);
        palindrome->strsearch = number_to_base_string
        (palindrome->pal, palindrome->base);
        int iterations = perform_iteration(palindrome);
        if (iterations != -1) {
            palindrome->test = true;
            palindrome->list[i] = true;
        }
    }
}

void print_output(palindrome_t *palindrome, int i, int iterations)
{
    if (!palindrome->file_flag) {
        printf("\033[0;33m%d\033[0m leads to \033[0;33m%s\033[0m "
        "in \033[0;33m%d\033[0m iteration(s) in base \033[0;33m%d\033[0m\n",
        i, palindrome->str, iterations, palindrome->base);
        if (palindrome->c_flag && palindrome->r_flag)
            printf("The number of steps is: "
            "\033[0;32m%d\n\033[0m", palindrome->count);
    } else {
        printf("%d leads to %s in %d iteration(s) in base %d\n",
        i, palindrome->str, iterations, palindrome->base);
        if (palindrome->c_flag && palindrome->r_flag)
            printf("The number of steps is: %d\n", palindrome->count);
    }
}

void second_loop(palindrome_t *palindrome)
{
    palindrome->list = (bool *)malloc(sizeof(bool) * (palindrome->pal + 1));
    for (int i = 0; i <= palindrome->pal; i++)
        palindrome->list[i] = false;
    third_loop(palindrome);
    for (int i = 0; i <= palindrome->pal; i++) {
        if (palindrome->list[i] == true) {
            palindrome->number = i;
            palindrome->str = number_to_base_string(i, palindrome->base);
            int iterations = perform_iteration(palindrome);
            print_output(palindrome, i, iterations);
        }
    }
    free(palindrome->list);
}
