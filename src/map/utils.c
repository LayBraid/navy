/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "map.h"
#include "my.h"

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

void browse_vectors(navy_t *navy)
{
    for (int i = 0; i < navy->map->buffer_lines; i++)
        exe_vector(navy->map->vectors[i], navy->my_map);
}

int line_in_buffer(char *buffer)
{
    int nb = 1;

    for (int i = 0; i < my_strlen(buffer); i++)
        if (buffer[i] == '\n')
            nb++;
    return nb;
}

int char_in_line(char *buffer)
{
    for (int i = 0; i < my_strlen(buffer); i++)
        if (buffer[i] == '\n')
            return i;
    return 0;
}
