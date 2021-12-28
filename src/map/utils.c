/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "../../include/map.h"

void exe_vector(const int *vector, char **map)
{
    for (int i = 0; i < vector[4] + 1; i++) {
        map[vector[1] - 1][vector[0] + i] = (char) (vector[6] + '0');
        for (int j = 0; j < vector[5] + 1; j++)
            map[vector[1] + j - 1][vector[0] + i] = (char) (vector[6] + '0');
    }
    for (int j = 0; j < vector[5]; j++)
        map[vector[1]][vector[0]] = (char) (vector[6] + '0');
}

void browse_vectors()
{
    for (int i = 0; i < navy->map->buffer_lines; i++) {
        exe_vector(navy->map->vectors[i], navy->my_map);
    }
}

void display_map(char **map)
{
    write(1, " |A B C D E F G H\n", 18);
    write(1, "-+---------------\n", 18);
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            if (j != 7)
                my_printf("%c ", map[i][j]);
            else
                my_printf("%c", map[i][j]);
        }
        write(1, "\n", 1);
    }
}
