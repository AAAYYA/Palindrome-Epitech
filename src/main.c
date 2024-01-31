/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-damian.gil
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/my.h"

void helper(void)
{
    printf("USAGE\n\t./palindrome -n number -p");
    printf(" palindrome [-b base] [-imin i]");
    printf(" [-imax i]\nDESCRIPTION\n\t");
    printf("-n n\tinteger to be transformed (>=0)\n\t");
    printf("-p pal\tpalindromic number to be obtained ");
    printf("(incompatible with the -n\n\t\toption) (>=0)\n");
    printf("\t\tif defined, all fitting values of n will");
    printf(" be output\n\t-b base\tbase in which the");
    printf(" procedure will be executed (1<b=10) [def: 100]\n");
    printf("\t-imin i\tminimum number of iterations,");
    printf(" included (>=0) [def:0]\n\t-imax i\t");
    printf("maximum number of iterations, included");
    printf(" (>=0) [def: 100]\n");
}

int main(int argc, char **argv)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));

    setup_variables(palindrome);
    if (argc < 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        helper();
        return 0;
    }
    for (int i = 1; i < argc; i += 2) {
        if (get_args(palindrome, argc, argv, i) == 84)
            return 84;
    }
    if (second_errors(palindrome) == 84)
        return 84;
    free(palindrome->str);
    return 0;
}
