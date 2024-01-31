/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-damian.gil
** File description:
** errors
*/

#include <stdio.h>
#include "../includes/my.h"

int second_errors(palindrome_t *palindrome)
{
    if (error_handling(palindrome) == 84)
        return 84;
    if (main_condition(palindrome) == 84)
        return 84;
    return 0;
}

int error_handling(palindrome_t *palindrome)
{
    if ((palindrome->number == 0 && palindrome == 0)
    || palindrome->base <= 1 || palindrome->base > 10
    || palindrome->imin < 0 || palindrome->imax < 0
    || (palindrome->number != 0 && palindrome->pal != 0)
    || palindrome->base == 0 || palindrome->test == false
    || palindrome->imin > palindrome->imax
    || palindrome->number < 0) {
        printf("invalid argument\n");
        return 84;
    }
    palindrome->test = false;
    return 0;
}
