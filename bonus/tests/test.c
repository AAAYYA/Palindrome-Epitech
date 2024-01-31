/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-damian.gil
** File description:
** test
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/my.h"

int my_squareroot_synthesis(int nb);
int my_factrec_synthesis(int nb);

Test(errors, second_errors_test)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));
    setup_variables(palindrome);

    int result = second_errors(palindrome);

    cr_assert_eq(result, 0);

    free(palindrome);
}

Test(errors, error_handling_test)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));
    setup_variables(palindrome);

    int result = error_handling(palindrome);

    cr_assert_eq(result, 0);

    free(palindrome);
}

Test(find_p, is_palindrome_test)
{
    char str[] = "12321";

    int result = is_palindrome(str);

    cr_assert_eq(result, 1);
}

Test(find_p, number_to_base_string_test)
{
    int number = 4782;
    int base = 10;

    char* result = number_to_base_string(number, base);

    cr_assert_str_eq(result, "4782");

    free(result);
}

Test(main, main_condition_test)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));
    setup_variables(palindrome);

    palindrome->number = 4782;
    palindrome->base = 10;

    int result = main_condition(palindrome);

    cr_assert_eq(result, 0);

    free(palindrome->str);
    free(palindrome);
}

Test(my_squareroot_synthesis, negative_number)
{
    int result =my_squareroot_synthesis(-9);
    cr_assert_eq(result, -1);
}

Test(my_squareroot_synthesis, zero)
{
    int result =my_squareroot_synthesis(0);
    cr_assert_eq(result, 0);
}

Test(my_squareroot_synthesis, perfect_square)
{
    int result =my_squareroot_synthesis(16);
    cr_assert_eq(result, 4);
}

Test(my_squareroot_synthesis, non_perfect_square)
{
    int result = my_squareroot_synthesis(10);
    cr_assert_eq(result, -1);
}

Test(my_squareroot_synthesis, large_number)
{
    int result = my_squareroot_synthesis(123456789);
    cr_assert_eq(result, -1);
}

Test(my_factrec_synthesis, factorial_of_zero)
{
    int result = my_factrec_synthesis(0);
    cr_assert_eq(result, 1, "Expected factorial of 0 to be 1");
}

Test(my_factrec_synthesis, factorial_of_positive_number)
{
    int result = my_factrec_synthesis(5);
    cr_assert_eq(result, 120, "Expected factorial of 5 to be 120");
}

Test(my_factrec_synthesis, factorial_of_negative_number)
{
    int result = my_factrec_synthesis(-2);
    cr_assert_eq(result, 0, "Expected factorial of a negative number to be 0");
}

Test(my_factrec_synthesis, factorial_of_large_number)
{
    int result = my_factrec_synthesis(13);
    cr_assert_eq(result, 0, "Expected factorial of a large number to be 0");
}
