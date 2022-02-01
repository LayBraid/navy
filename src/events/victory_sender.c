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

int conditions_victory(const navy *navy, int i, int j)
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

    for (int row = 0; row < 8; row++)
        for (int column = 0; column < 8; column++)
            result += conditions_victory(navy, row, column);
    if (result > 1000)
        send_request(VictoryResult, 0, navy->enemy_pid);
    else {
        display_maps(navy);
        my_printf("\nEnemy won\n");
        send_request(VictoryResult, 1, navy->enemy_pid);
        navy->bool_game = 1;
        navy->is_winner = FALSE;
    }
}
