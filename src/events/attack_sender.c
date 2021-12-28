/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "../../include/events.h"

int correct_attack(char *str)
{
    if (my_str_contains_c(str[0], LETTERS_ATTACK) &&
    my_str_contains_c(str[1], NUMBERS_ATTACK))
        return 1;
    return 0;
}

int attack_sender(navy_t *navy)
{
    char *line = NULL;
    int bool = 0;
    size_t len = 0;
    ssize_t lineSize = 0;
    my_printf("\n");
    while (bool == 0) {
        my_printf("attack: ");
        lineSize = getline(&line, &len, stdin);
        line = my_strncpy(line, line, 2);
        if (correct_attack(line) == 1)
            bool = 1;
        else
            my_printf("wrong position\n");
    }
    my_printf("success");
    free(line);
    return (0);
}
