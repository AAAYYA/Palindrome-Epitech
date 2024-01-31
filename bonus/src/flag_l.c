/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-damian.gil
** File description:
** flag_l
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../includes/my.h"

void display_args_shorten(palindrome_t *palindrome, int iterations)
{
    if (palindrome->file_flag) {
        printf("%d leads to %s in %d iteration(s) in base %d\n",
        palindrome->number, palindrome->str, iterations, palindrome->base);
        palindrome->count++;
    } else {
        printf("\033[0;33m\t%d\033[0m leads to \033[0;33m%s\033[0m in "
        "\033[0;33m%d\033[0m iteration(s) in base \033[0;33m%d\033[0m\n",
        palindrome->number, palindrome->str, iterations,
        palindrome->base);
        palindrome->count++;
    }
}

void display_l_args(palindrome_t *palindrome, int iterations)
{
    if (palindrome->l_flag && iterations == 1 && palindrome->number != 0) {
        if (!palindrome->file_flag)
            printf("\033[0;34mThe list for the steps is: \n\033[0m");
        else
            printf("The list for the steps is: \n");
    }
    if (palindrome->l_flag && palindrome->number != 0)
        display_args_shorten(palindrome, iterations);
}
