/*
** EPITECH PROJECT, 2021
** BLANK_PROJECT_C
** File description:
** No file there , just an epitech header example
*/

#include "criterion/criterion.h"
#include "../include/my.h"

Test(my_strlen, my_strlen)
{
    cr_assert_eq(my_strlen("test"), 4);
}
