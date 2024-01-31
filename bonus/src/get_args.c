/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-damian.gil
** File description:
** get_args
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../includes/my.h"

int save_file(palindrome_t *palindrome)
{
    palindrome->file_flag = true;
    char *file_name = malloc(sizeof(char) * 100);
    printf("Name of the file: ");
    scanf("%s", file_name);
    FILE *file = freopen(file_name, "w", stdout);
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 84;
    }
    return 0;
}

int get_last_args(palindrome_t *palindrome, char **av, int *i)
{
    if (strcmp(av[*i], "-r") == 0 || strncmp(av[*i], "--random", 9) == 0) {
        srand(time(NULL));
        palindrome->number = rand() % 5000;
        palindrome->test = true;
        palindrome->r_flag = true;
        return 0;
    } if (strcmp(av[*i], "-o") == 0 || strncmp(av[*i], "--save", 7) == 0) {
        if (save_file(palindrome) == 84)
            return 84;
        return 0;
    }  if (strcmp(av[*i], "-c") == 0 || strncmp(av[*i], "--count", 8) == 0) {
        palindrome->c_flag = true;
        return 0;
    } if (!palindrome->file_flag)
        printf("\033[0;31minvalid argument\n\e[0m");
    else
        printf("invalid argument\n");
    return 84;
}

int get_third_args(palindrome_t *palindrome, int ac, char **av, int *i)
{
    if (strcmp(av[*i], "-imin") == 0) {
        (*i)++;
        if (!(*i < ac)) {
            printf("Missing args for imin\n");
            return 84;
        }
        palindrome->imin = strtol(av[*i], NULL, 10);
        return 0;
    } if (strcmp(av[*i], "-imax") == 0) {
        (*i)++;
        if (!(*i < ac)) {
            printf("Missing args for imax\n");
            return 84;
        }
        palindrome->imax = strtol(av[*i], NULL, 10);
        return 0;
    }
    return get_last_args(palindrome, av, i);
}

int get_second_args(palindrome_t *palindrome, int ac, char **av, int *i)
{
    if (strcmp(av[*i], "-n") == 0) {
        (*i)++;
        if (!(*i < ac)) {
            printf("Missing args for n\n");
            return 84;
        }
        palindrome->number = strtol(av[*i], NULL, 10);
        palindrome->test = true;
        return 0;
    } if (strcmp(av[*i], "-p") == 0) {
        (*i)++;
        if (!(*i < ac)) {
            printf("Missing args for p\n");
            return 84;
        }
        palindrome->pal = strtol(av[*i], NULL, 10);
        palindrome->test = true;
        return 0;
    }
    return get_third_args(palindrome, ac, av, i);
}

int get_args(palindrome_t *palindrome, int ac, char **av, int *i)
{
    if (strcmp(av[*i], "-b") == 0) {
        (*i)++;
        if (!(*i < ac)) {
            printf("Missing args for b\n");
            return 84;
        }
        palindrome->base = strtol(av[*i], NULL, 10);
        return 0;
    } if (strcmp(av[*i], "-l") == 0 || strncmp(av[*i], "--list", 7) == 0) {
        palindrome->l_flag = true;
        return 0;
    }
    return get_second_args(palindrome, ac, av, i);
}
