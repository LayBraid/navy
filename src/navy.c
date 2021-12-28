/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "../include/navy.h"

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
        attack_sender(navy);
    }
}

void second_player()
{
    my_printf("my_pid: %d\n", getpid());
    send_request(ConnectionAttempt, getpid(), navy->enemy_pid);
    my_printf("successfully connected\n\n");
    display_maps(navy);
}

int launch(int ac, char **av)
{
    //TODO -h
    if (ac == 2 || ac == 3) {
        navy = malloc(sizeof(navy_t));
        navy->bool_game = 0;
        navy->attack = malloc(sizeof(attack_t));
        navy->attack->attack = malloc(sizeof(int) * 2);
        handle_signal(SIGUSR1);
        handle_signal(SIGUSR2);
        fill_map(av[ac - 1]);
        if (ac == 2) {
            first_player();
        } else {
            navy->enemy_pid = my_atoi(av[1]);
            second_player();
        }
        return 0;
    }
    return 84;
}
