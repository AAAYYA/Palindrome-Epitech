/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-damian.gil
** File description:
** test
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/my.h"

int my_squareroot_synthesis(int nb);
int my_factrec_synthesis(int nb);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(find_p_else, number_to_base_string_test, .init = redirect_all_std)
{
    int number = 10;
    int base = 11;

    char* result = number_to_base_string(number, base);

    cr_assert_str_eq(result, "A");

    free(result);
}

Test(errors, second_errors_test, .init = redirect_all_std)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));
    setup_variables(palindrome);

    int result = second_errors(palindrome);

    cr_assert_eq(result, 84);

    free(palindrome);
}

Test(errors, third_errors_test, .init = redirect_all_std)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));
    setup_variables(palindrome);

    palindrome->pal = 10;
    palindrome->test = true;
    int result = second_errors(palindrome);

    cr_assert_eq(result, 84);

    free(palindrome);
}

Test(errors, fourth_errors_test, .init = redirect_all_std)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));
    setup_variables(palindrome);

    palindrome->pal = 1;
    palindrome->test = true;
    int result = second_errors(palindrome);

    cr_assert_eq(result, 0);

    free(palindrome);
}

Test(errors, error_handling_test, .init = redirect_all_std)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));
    setup_variables(palindrome);

    int result = error_handling(palindrome);

    cr_assert_eq(result, 84);

    free(palindrome);
}

Test(find_p, is_palindrome_test, .init = redirect_all_std)
{
    char str[] = "12321";

    int result = is_palindrome(str);

    cr_assert_eq(result, 1);
}

Test(find_p, number_to_base_string_test, .init = redirect_all_std)
{
    int number = 4782;
    int base = 10;

    char* result = number_to_base_string(number, base);

    cr_assert_str_eq(result, "4782");

    free(result);
}

Test(main, main_condition_test, .init = redirect_all_std)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));
    setup_variables(palindrome);

    palindrome->number = 4782;
    palindrome->base = 10;

    int result = main_condition(palindrome);

    cr_assert_eq(result, 0);

    free(palindrome);
}

Test(main, main_condition_test_second, .init = redirect_all_std)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));
    setup_variables(palindrome);

    palindrome->number = 47;
    palindrome->base = 10;
    palindrome->imax = 0;

    int result = main_condition(palindrome);

    cr_assert_eq(result, 0);

    free(palindrome);
}

Test(main, main_condition_test_third, .init = redirect_all_std)
{
    palindrome_t *palindrome = malloc(sizeof(palindrome_t));
    setup_variables(palindrome);

    palindrome->pal = 363;
    palindrome->base = 10;
    palindrome->imin = 7;

    int result = main_condition(palindrome);

    cr_assert_eq(result, 0);

    free(palindrome);
}

Test(get_second_args, test_arguments, .init = redirect_all_std)
{
    palindrome_t palindrome;
    palindrome.number = 0;
    palindrome.pal = 0;
    palindrome.base = 0;
    palindrome.imin = 0;
    palindrome.imax = 0;
    palindrome.test = false;

    char *arguments[] = { "-n", "-p", "-b", "-imin", "-imax" };
    int converted = 10;

    for (int i = 0; i < sizeof(arguments) / sizeof(arguments[0]); i++) {
        get_second_args(&palindrome, converted, arguments, i);
    }

    cr_assert_eq(palindrome.number, converted);
    cr_assert_eq(palindrome.pal, converted);
    cr_assert_eq(palindrome.base, converted);
    cr_assert_eq(palindrome.imin, converted);
    cr_assert_eq(palindrome.imax, converted);
    cr_assert(palindrome.test);
}

Test(get_args, valid_arguments, .init = redirect_all_std)
{
    palindrome_t palindrome;
    char *argument = "-n"; 

    int result = get_args(&palindrome, 2, &argument, 3);
    cr_assert_eq(result, 84);
}

Test(get_args, invalid_argument_case1, .init = redirect_all_std)
{
    palindrome_t palindrome;
    int ac = 2;
    char* av[] = {"program_name", "invalid"};
    int i = 0;
    
    int result = get_args(&palindrome, ac, av, i);
    
    cr_assert_eq(result, 84);
}

Test(get_args, invalid_argument_case2, .init = redirect_all_std)
{
    palindrome_t palindrome;
    int ac = 2;
    char* av[] = {"program_name", ""};
    int i = 0;
    
    int result = get_args(&palindrome, ac, av, i);
    
    cr_assert_eq(result, 84);
}

Test(get_args, invalid_argument_case3, .init = redirect_all_std)
{
    palindrome_t palindrome;
    int ac = 2;
    char* av[] = {"program_name", "9876543210"};
    int i = 0;
    
    int result = get_args(&palindrome, ac, av, i);
    
    cr_assert_eq(result, 84);
}

Test(get_args, valid_argument_case, .init = redirect_all_std)
{
    palindrome_t palindrome;
    int ac = 2;
    char* av[] = {"program_name", "123"};
    int i = 0;
    
    int result = get_args(&palindrome, ac, av, i);
    
    cr_assert_eq(result, 0);
}

Test(error_handling, valid_arguments)
{
    palindrome_t palindrome;
    palindrome.number = 12321;
    palindrome.base = 10;
    palindrome.imin = 0;
    palindrome.imax = 5;
    palindrome.pal = 0;
    palindrome.test = true;

    int result = error_handling(&palindrome);

    cr_assert_eq(result, 0);

    cr_assert_eq(palindrome.test, false);
}

Test(error_handling, invalid_arguments, .init = redirect_all_std)
{
    palindrome_t palindrome;

    // Test 1: number and palindrome are both 0
    palindrome.number = 0;
    palindrome.base = 5;
    palindrome.imin = 0;
    palindrome.imax = 5;
    palindrome.pal = 0;
    palindrome.test = true;
    int result = error_handling(&palindrome);
    cr_assert_eq(result, 0);

    // Test 2: base is less than or equal to 1
    palindrome.number = 12321;
    palindrome.base = 1;
    palindrome.imin = 0;
    palindrome.imax = 5;
    palindrome.pal = 0;
    palindrome.test = true;
    result = error_handling(&palindrome);
    cr_assert_eq(result, 84);

    // Test 3: base > 10
    palindrome.base = 11;
    result = error_handling(&palindrome);
    cr_assert_eq(result, 84);

    // Test 4: imin is negative
    palindrome.base = 5;
    palindrome.imin = -1;
    result = error_handling(&palindrome);
    cr_assert_eq(result, 84);

    // Test 5: imax is negative
    palindrome.imin = 0;
    palindrome.imax = -1;
    result = error_handling(&palindrome);
    cr_assert_eq(result, 84);

    // Test 6: number is not 0 and pal is not 0
    palindrome.imax = 5;
    palindrome.number = 12321;
    palindrome.pal = 1;
    result = error_handling(&palindrome);
    cr_assert_eq(result, 84);

    // Test 7: base is 0
    palindrome.pal = 0;
    palindrome.base = 0;
    result = error_handling(&palindrome);
    cr_assert_eq(result, 84);

    // Test 8: test is false
    palindrome.base = 5;
    palindrome.test = false;
    result = error_handling(&palindrome);
    cr_assert_eq(result, 84);

    // Test 9: imin > imax
    palindrome.test = true;
    palindrome.imin = 10;
    palindrome.imax = 5;
    result = error_handling(&palindrome);
    cr_assert_eq(result, 84);

    // Test 10: negative
    palindrome.imin = 0;
    palindrome.imax = 5;
    palindrome.number = -12321;
    result = error_handling(&palindrome);
    cr_assert_eq(result, 84);

    palindrome.base = 0;
    palindrome.test = false;
    result = error_handling(&palindrome);
    cr_assert_eq(result, 84);
}

Test(perform_iteration, strtol_comparison, .init = redirect_all_std)
{
    palindrome_t palindrome = {"123", 10, 0, 0, 0};
    int result = perform_iteration(&palindrome);
    cr_assert_eq(result, -1, "Expected perform_iteration to return -1");
}

Test(get_args, invalid_argument_index_out_of_range, .init = redirect_all_std)
{
    palindrome_t palindrome;
    char* av[] = {"program", "arg1"};
    int ac = sizeof(av) / sizeof(av[0]);
    int result = get_args(&palindrome, ac, av, 1);
    cr_assert_eq(result, 84, "Expected get_args to return 84");
}

Test(get_args, invalid_argument_length_exceeded, .init = redirect_all_std)
{
    palindrome_t palindrome;
    char* av[] = {"program", "this_argument_is_too_long"};
    int ac = sizeof(av) / sizeof(av[0]);
    int result = get_args(&palindrome, ac, av, 1);
    cr_assert_eq(result, 84, "Expected get_args to return 84");
}

Test(get_args, invalid_argument_not_a_number, .init = redirect_all_std)
{
    palindrome_t palindrome;
    char* av[] = {"program", "not_a_number"};
    int ac = sizeof(av) / sizeof(av[0]);
    int result = get_args(&palindrome, ac, av, 1);
    cr_assert_eq(result, 84, "Expected get_args to return 84");
}

Test(get_args, invalid_argument_out_of_range, .init = redirect_all_std)
{
    palindrome_t palindrome;
    char* av[] = {"program", "2147483648"};
    int ac = sizeof(av) / sizeof(av[0]);
    int result = get_args(&palindrome, ac, av, 1);
    cr_assert_eq(result, 84, "Expected get_args to return 84");
}

Test(get_args, valid_arguments_second, .init = redirect_all_std)
{
    palindrome_t palindrome;
    char* av[] = {"program", "123"};
    int ac = sizeof(av) / sizeof(av[0]);
    int result = get_args(&palindrome, ac, av, 1);
    cr_assert_eq(result, 84, "Expected get_args to return 0");
}

Test(my_squareroot_synthesis, negative_number, .init = redirect_all_std)
{
    int result =my_squareroot_synthesis(-9);
    cr_assert_eq(result, -1);
}

Test(my_squareroot_synthesis, zero, .init = redirect_all_std)
{
    int result =my_squareroot_synthesis(0);
    cr_assert_eq(result, 0);
}

Test(my_squareroot_synthesis, perfect_square, .init = redirect_all_std)
{
    int result =my_squareroot_synthesis(16);
    cr_assert_eq(result, 4);
}

Test(my_squareroot_synthesis, non_perfect_square, .init = redirect_all_std)
{
    int result = my_squareroot_synthesis(10);
    cr_assert_eq(result, -1);
}

Test(my_squareroot_synthesis, large_number, .init = redirect_all_std)
{
    int result = my_squareroot_synthesis(123456789);
    cr_assert_eq(result, -1);
}

Test(my_factrec_synthesis, factorial_of_zero, .init = redirect_all_std)
{
    int result = my_factrec_synthesis(0);
    cr_assert_eq(result, 1, "Expected factorial of 0 to be 1");
}

Test(my_factrec_synthesis, factorial_of_positive_number, .init = redirect_all_std)
{
    int result = my_factrec_synthesis(5);
    cr_assert_eq(result, 120, "Expected factorial of 5 to be 120");
}

Test(my_factrec_synthesis, factorial_of_negative_number, .init = redirect_all_std)
{
    int result = my_factrec_synthesis(-2);
    cr_assert_eq(result, 0, "Expected factorial of a negative number to be 0");
}

Test(my_factrec_synthesis, factorial_of_large_number, .init = redirect_all_std)
{
    int result = my_factrec_synthesis(13);
    cr_assert_eq(result, 0, "Expected factorial of a large number to be 0");
}
