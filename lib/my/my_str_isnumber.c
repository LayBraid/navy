/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

int my_str_isnumber(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
            return 0;
    }
    return 1;
}
