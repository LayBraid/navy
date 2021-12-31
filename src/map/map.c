/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "map.h"
#include "navy.h"

void malloc_map()
{
    navy->my_map = malloc(sizeof(char *) * 9);
    for (int i = 0; i < 9; i++)
        navy->my_map[i] = malloc(sizeof(char) * 9);
    navy->enemy_map = malloc(sizeof(char *) * 9);
    for (int i = 0; i < 9; i++)
        navy->enemy_map[i] = malloc(sizeof(char) * 9);
}

char value_map(int i, int j)
{
    if (i == 8 || j == 8)
        return '\0';
    else
        return '.';
}

void init_map(char **map)
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            map[i][j] = value_map(i, j);
}

void fill_map(char *path)
{
    input_map(path);
    malloc_map();
    init_map(navy->my_map);
    init_map(navy->enemy_map);
    browse_vectors(navy);
}
