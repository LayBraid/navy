/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#ifndef NAVY_STRUCT_H
    #define NAVY_STRUCT_H

typedef struct map_struct {
    int **vectors;
    char *buffer;
    char **lines;
    int buffer_lines;
    int length_line;
} map_t;

typedef struct navy_game {
    map_t *map;
    char **my_map;
    char **enemy_map;
} navy_t;

#endif
