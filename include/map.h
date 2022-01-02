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

int input_map(navy_t *navy, char *path);

void fill_map(navy_t *navy, char *path);

void display_map(char **map);

void browse_vectors(navy_t *navy);

int line_in_buffer(char *buffer);

int char_in_line(char *buffer);

#endif
