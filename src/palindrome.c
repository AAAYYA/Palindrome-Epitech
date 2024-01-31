/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** palindrome
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    }
    sprintf(palindrome->str, "%ld",
    strtol(palindrome->str, NULL, palindrome->base));
    return iterations;
}

void get_second_args(palindrome_t *palindrome, int converted, char **av, int i)
{
    if (strcmp(av[i], "-n") == 0) {
        palindrome->number = converted;
        palindrome->test = true;
    } if (strcmp(av[i], "-p") == 0) {
        palindrome->pal = converted;
        palindrome->test = true;
    } if (strcmp(av[i], "-b") == 0) {
        palindrome->base = converted;
    } if (strcmp(av[i], "-imin") == 0) {
        palindrome->imin = converted;
    } if (strcmp(av[i], "-imax") == 0) {
        palindrome->imax = converted;
    }
}

int get_args(palindrome_t *palindrome, int ac, char **av, int i)
{
    char *endptr = NULL;
    if (i + 1 >= ac) {
        printf("invalid argument\n");
        return 84;
    }
    if (strlen(av[i + 1]) > 10 || strlen(av[i + 1]) == 0) {
        printf("invalid argument\n");
        return 84;
    }
    long long converted = strtoll(av[i + 1], &endptr, 10);
    if (converted < 0 || converted > 2147483647) {
        printf("invalid argument68789\n");
        return 84;
    }
    if (*endptr != '\0')
        return 84;
    get_second_args(palindrome, converted, av, i);
    return 0;
}

void second_loop(palindrome_t *palindrome)
{
    for (int i = 0; i <= palindrome->pal; i++) {
        palindrome->str = number_to_base_string(i, palindrome->base);
        palindrome->strsearch = number_to_base_string
        (palindrome->pal, palindrome->base);
        int iterations = perform_iteration(palindrome);
        if (iterations != -1) {
            printf("%d leads to %s in %d iteration(s) in base %d\n",
            i, palindrome->str, iterations, palindrome->base);
            palindrome->test = true;
        }
    }
}
