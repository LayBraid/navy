/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#ifndef NAVY_STRUCT_H
#define NAVY_STRUCT_H

typedef enum boolean_enum {
    FALSE = 0,
    TRUE
} boolean;

typedef char const *conststr;

typedef struct boat_type {
    int length;
    int *coordinates;
} boat;

typedef struct map_type {
    int boats_count;
    boat **boats;
} map;

typedef struct navy_type {
    map *map;
    char **my_map;
    char **enemy_map;
    int enemy_pid;
    int bool_game;
    boolean is_winner;
} navy;

#endif
