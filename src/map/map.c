/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "map.h"
#include "navy.h"
#include "my.h"

void malloc_maps(navy *navy)
{
    navy->my_map = malloc(sizeof(char *) * 9);
    for (int index = 0; index < 9; index++) {
        navy->my_map[index] = malloc(sizeof(char) * 9);
        navy->my_map[index][8] = '\0';
    }
    navy->my_map[8] = NULL;
    navy->enemy_map = malloc(sizeof(char *) * 9);
    for (int index = 0; index < 9; index++) {
        navy->enemy_map[index] = malloc(sizeof(char) * 9);
        navy->enemy_map[index][8] = '\0';
    }
    navy->enemy_map[8] = NULL;
}

void initialize_maps(const navy *navy)
{
    for (int row = 0; row < 8; row++) {
        for (int line = 0; line < 8; line++) {
            navy->my_map[row][line] = '.';
            navy->enemy_map[row][line] = '.';
        }
    }
}

boolean load_boats(navy *navy, conststr path)
{
    conststr raw_map = load_raw_map(path);
    char **raw_boats = split_lines(raw_map);
    int boats_count = count_lines(raw_map);

    navy->map = malloc(sizeof(map));
    navy->map->boats_count = boats_count;
    navy->map->boats = malloc(sizeof(boat *) * (boats_count + 1));
    navy->map->boats[boats_count] = NULL;
    for (int index = 0; index < boats_count; index++) {
        if (is_valid(raw_boats[index]))
            navy->map->boats[index] = load_boat(raw_boats[index]);
        else
            return FALSE;
    }
    return TRUE;
}

void fill_map(navy *navy)
{
    malloc_maps(navy);
    initialize_maps(navy);
    update_map(navy);
}
