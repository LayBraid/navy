/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "navy.h"
#include "signals.h"

void handle_packet(int type, int data)
{
    switch (type) {
        case AttackAttempt:
        case VictoryResult:
        case ConnectionAttempt:
        case AttackSuccess:
        case AttackFail:
            answer = data;
            break;
        default:
            break;
    }
}
