/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "../../include/navy.h"

void handle_packet(int type, int data)
{
    switch (type) {
        case ConnectionAttempt:
            navy->enemy_pid = data;
            break;
        case AttackAttempt:
        case VictoryResult:
            navy->answer = data;
            break;
        case AttackSuccess:
        case AttackFail:
            navy->answer_status = type;
            navy->answer = data;
            break;
        default:
            break;
    }
}
