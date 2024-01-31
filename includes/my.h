/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdbool.h>

    typedef struct palindrome_s {
        char *str;
        int imin;
        int imax;
        int base;
        char *strsearch;
        int number;
        int pal;
        bool test;
        int ret;
    } palindrome_t;

void reverse_string(char *str);

int is_palindrome(char *str);

char* number_to_base_string(int number, int base);

int main_loop(palindrome_t *palindrome, int iterations);

int perform_iteration(palindrome_t *palindrome);

int get_args(palindrome_t *palindrome, int ac, char **av, int i);

void second_loop(palindrome_t *palindrome);

int error_handling(palindrome_t *palindrome);

int main_condition(palindrome_t *palindrome);

int second_errors(palindrome_t *palindrome);

void setup_variables(palindrome_t *palindrome);

void get_second_args(palindrome_t *palindrome, int converted, char **av, int i);

#endif /* !MY_H_ */
