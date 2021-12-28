/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "navy.h"

void handle_packet(int type, int data)
{
    switch (type) {
        case ConnectionAttempt:
            navy->enemy_pid = data;
            break;
        case AttackAttempt:
            break;
        case AttackSuccess:
            break;
        case AttackFail:
            break;
        case TurnFinished:
            break;
        case GameFinished:
            break;
    }
}