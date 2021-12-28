/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "../include/utils.h"

void display_maps()
{
    write(1, "\nmy positions:\n", 15);
    display_map(navy->my_map);
    write(1, "\nenemy's positions:\n", 20);
    display_map(navy->enemy_map);
}
