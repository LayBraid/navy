/*
** EPITECH PROJECT, 2022
** navy
** File description:
** No file there , just an epitech header example
*/

#include "struct.h"
#include "my.h"

boolean is_valid(conststr line)
{
    if (my_strlen(line) != 7)
        return FALSE;
    if (line[0] < '2' || line[0] > '5')
        return FALSE;
    if (line[1] != ':' || line[4] != ':')
        return FALSE;
    if (line[2] < 'A' || line[2] > 'H')
        return FALSE;
    if (line[3] < '0' || line[3] > '8')
        return FALSE;
    if (line[5] < 'A' || line[5] > 'H')
        return FALSE;
    if (line[6] < '0' || line[6] > '8')
        return FALSE;
    if (line[2] != line[5] && line[3] != line[6])
        return FALSE;
    return TRUE;
}

boat *load_boat(conststr line)
{
    if (!is_valid(line))
        return NULL;
    boat *loaded_boat = malloc(sizeof(boat));
    int *coordinates = malloc(sizeof(int) * 4);

    coordinates[0] = line[2] - 'A';
    coordinates[1] = line[3] - '0';
    coordinates[2] = line[5] - 'A';
    coordinates[3] = line[6] - '0';
    loaded_boat->length = line[0] - '0';
    loaded_boat->coordinates = coordinates;
    return loaded_boat;
}

