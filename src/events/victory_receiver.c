/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "events.h"
#include "navy.h"
#include "struct.h"
#include "my.h"

void victory_receiver(navy_t *navy)
{
    answer = 3;
    while (answer == 3)
        usleep(100);
    if (answer == 1) {
        display_maps(navy);
        my_printf("\nI won\n");
        navy->bool_game = 1;
    }
}
