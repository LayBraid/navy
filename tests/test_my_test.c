/*
** EPITECH PROJECT, 2021
** BLANK_PROJECT_C
** File description:
** No file there , just an epitech header example
*/

#include "criterion/criterion.h"

int my_test(int i);

Test(my_test, my_test_zero)
{
    cr_assert_eq(my_test(0), 0);
}

Test(my_test, my_test_one)
{
    cr_assert_eq(my_test(1), 1);
}
