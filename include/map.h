/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#ifndef NAVY_MAP_H
    #define NAVY_MAP_H
    #include <sys/stat.h>
    #include <sys/fcntl.h>
    #include "struct.h"

void display_map(char **map);

// == utils.c ==

void update_map(const navy *navy);

// == navy.c ==

boolean load_boats(navy *navy, conststr path);

void fill_map(navy *navy);

// == parser.c ==

boolean is_valid(conststr line);

boat *load_boat(conststr line);

// == reader.c ==

char *load_raw_map(conststr path);

int count_lines(conststr input);

char **split_lines(conststr input);

#endif
