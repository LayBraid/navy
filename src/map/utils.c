/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "map.h"
#include "my.h"

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

void display_next(char **map, int row, int column)
{
    my_putchar(map[row][column]);
    if (column != 7)
        my_putchar(' ');
}

void display_map(char **map)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int row = 0; row < 8; row++) {
        my_printf("%d|", row + 1);
        for (int column = 0; column < 8; column++)
            display_next(map, row, column);
        my_putchar('\n');
    }
}
