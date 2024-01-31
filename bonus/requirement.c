/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** requirement
*/

#include <stdlib.h>

int my_factrec_synthesis_helper(int nb, int fact)
{
    if (nb == 1)
        return fact;
    if (fact > 2147483647 / nb)
        return 0;
    else
        return my_factrec_synthesis_helper(nb - 1, fact * nb);
}

int my_factrec_synthesis(int nb)
{
    if (nb < 0)
        return 0;
    else if (nb == 0)
        return 1;
    else
        return my_factrec_synthesis_helper(nb, 1);
}

int my_squareroot_synthesis(int nb)
{
    int root = 0;
    int square = 0;

    if (nb < 0)
        return -1;
    while (square <= nb) {
        if (square == nb)
            return root;
        root++;
        square = root * root;
    }
    return -1;
}
