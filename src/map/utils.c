/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "map.h"

boolean is_part(int row, int column, const int *coord)
{
    if (row >= coord[0] && row <= coord[2])
        if (column >= coord[1] && column <= coord[3])
            return TRUE;
    return FALSE;
}

void update_boat(const navy *navy, const boat *boat, const int *coord)
{
    for (int row = 0; row < 8; row++) {
        for (int column = 0; column < 8; column++) {
            if (is_part(row, column, coord))
                navy->my_map[row][column] = (char) ('0' + boat->length);
        }
    }
}

void update_map(const navy *navy)
{
    int boats_count = navy->map->boats_count;
    for (int index = 0; index < boats_count; index++) {
        const boat *boat = navy->map->boats[index];
        const int *coords = boat->coordinates;

        update_boat(navy, boat, coords);
    }
}
