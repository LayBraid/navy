/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "../include/utils.h"

void display_maps(navy_t *navy)
{
    write(1, "my positions:\n", 14);
    display_map(navy->my_map);
    write(1, "\nenemy's positions:\n", 20);
    display_map(navy->enemy_map);
}
