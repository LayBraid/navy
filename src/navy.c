/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "navy.h"

void first_player()
{
    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    while (navy->enemy_pid == 0)
        usleep(100);
    my_printf("enemy connected\n");
    while (navy->bool_game != 1) {
        display_maps(navy);
        attack_sender(navy);
        attack_receiver(navy);
        victory_sender();
        victory_receiver();
    }
}

void second_player()
{
    my_printf("my_pid: %d\n", getpid());
    send_request(ConnectionAttempt, getpid(), navy->enemy_pid);
    my_printf("successfully connected\n");
    while (navy->bool_game != 1) {
        display_maps(navy);
        attack_receiver(navy);
        attack_sender(navy);
        victory_receiver();
        victory_sender();
    }
}

int help_message()
{
    my_putstr("USAGE\n     ./navy [first_player_pid] navy_positions\n"
              "DESCRIPTION\n     first_player_pid: only for the 2nd player."
              " pid of the first player.\n     navy_positions: file "
              "representing the positions of the ships.\n");
    return 1;
}

int launch(int size, char **args)
{
    if (size == 2 && my_strcmp(args[1], "-h") == 0)
        return help_message();
    if (size == 2 || size == 3) {
        navy = malloc(sizeof(navy_t));
        navy->bool_game = 0;
        navy->enemy_pid = 0;
        navy->attack = malloc(sizeof(attack_t));
        navy->attack->attack = malloc(sizeof(int) * 2);
        handle_signal(SIGUSR1);
        handle_signal(SIGUSR2);
        fill_map(args[size - 1]);
        if (size == 2) {
            first_player();
        } else {
            navy->enemy_pid = my_atoi(args[1]);
            second_player();
        }
        return 0;
    }
    return 84;
}
