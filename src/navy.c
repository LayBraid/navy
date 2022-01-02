/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "navy.h"
#include "my.h"
#include "struct.h"
#include "map.h"
#include "events.h"
#include "signals.h"

int answer;

void display_maps(navy_t *navy)
{
    write(1, "\nmy positions:\n", 15);
    display_map(navy->my_map);
    write(1, "\nenemy's positions:\n", 20);
    display_map(navy->enemy_map);
}

void first_player(navy_t *navy)
{
    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    answer = 0;
    while (answer == 0)
        usleep(100);
    navy->enemy_pid = answer;
    my_printf("enemy connected\n");
    while (navy->bool_game != 1) {
        display_maps(navy);
        attack_sender(navy);
        attack_receiver(navy);
        victory_sender(navy);
        victory_receiver(navy);
    }
    free(navy);
}

void second_player(navy_t *navy)
{
    my_printf("my_pid: %d\n", getpid());
    send_request(ConnectionAttempt, getpid(), navy->enemy_pid);
    my_printf("successfully connected\n");
    while (navy->bool_game != 1) {
        display_maps(navy);
        attack_receiver(navy);
        attack_sender(navy);
        victory_receiver(navy);
        victory_sender(navy);
    }
    free(navy);
}

void send_help(void)
{
    my_putstr("USAGE\n     ./navy [first_player_pid] navy_positions\n"
    "DESCRIPTION\n     first_player_pid: only for the 2nd player."
    " pid of the first player.\n     navy_positions: file "
    "representing the positions of the ships.\n");
}

int launch(int size, char **args)
{
    if (size == 2 && my_strcmp(args[1], "-h") == 0) {
        send_help();
    } else {
        navy_t *navy = malloc(sizeof(navy_t));
        navy->bool_game = 0;
        navy->enemy_pid = 0;
        navy->attack = malloc(sizeof(attack_t));
        navy->attack->attack = malloc(sizeof(int) * 2);
        handle_signal(SIGUSR1);
        handle_signal(SIGUSR2);
        fill_map(navy, args[size - 1]);
        if (size == 2) {
            first_player(navy);
        } else {
            navy->enemy_pid = my_atoi(args[1]);
            second_player(navy);
        }
    }
    return 0;
}
