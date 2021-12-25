/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#ifndef NAVY_MAP_H
    #define NAVY_MAP_H

    #include "navy.h"
    #include "my.h"

    #include <sys/stat.h>
    #include <sys/fcntl.h>

int input_map(navy_t *navy, char *path);

void fill_map(navy_t *navy, char *path);

void display_map(char **map);

void browse_vectors(navy_t *navy);

#endif
