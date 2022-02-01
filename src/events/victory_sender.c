/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "events.h"
#include "navy.h"
#include "struct.h"
#include "signals.h"
#include "my.h"

int conditions_victory(navy *navy, int i, int j)
{
    if (navy->my_map[i][j] != '.' &&
        navy->my_map[i][j] != 'x' &&
        navy->my_map[i][j] != 'o')
        return 1111;
    return 0;
}

void victory_sender(navy *navy)
{
    int result = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            result += conditions_victory(navy, i, j);
    if (result > 1000)
        send_request(VictoryResult, 0, navy->enemy_pid);
    else {
        display_maps(navy);
        my_printf("\nEnemy won\n");
        send_request(VictoryResult, 1, navy->enemy_pid);
        navy->bool_game = 1;
    }
}
