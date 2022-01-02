/*
** EPITECH PROJECT, 2022
** navy
** File description:
** No file there , just an epitech header example
*/

#include "map.h"
#include "my.h"

void display_next(char **map, int i, int j)
{
    if (j != 7)
        my_printf("%c ", map[i][j]);
    else
        my_printf("%c", map[i][j]);
}

void display_map(char **map)
{
    write(1, " |A B C D E F G H\n", 18);
    write(1, "-+---------------\n", 18);
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++)
            display_next(map, i, j);
        write(1, "\n", 1);
    }
}
