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

int input_map(char *path);

void fill_map(char *path);

void display_map(char **map);

void browse_vectors();

#endif
