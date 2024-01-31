/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-damian.gil
** File description:
** variables
*/

#include <stdio.h>
#include "../includes/my.h"

void setup_variables(palindrome_t *palindrome)
{
    palindrome->number = 0;
    palindrome->pal = 0;
    palindrome->base = 10;
    palindrome->imin = 0;
    palindrome->imax = 100;
    palindrome->str = NULL;
    palindrome->test = false;
    palindrome->l_flag = false;
    palindrome->file_flag = false;
    palindrome->count = 0;
    palindrome->c_flag = false;
    palindrome->r_flag = false;
}
