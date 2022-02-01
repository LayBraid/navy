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

void display_maps(navy *navy)
{
    write(1, "\nmy positions:\n", 15);
    display_map(navy->my_map);
    write(1, "\nenemy's positions:\n", 20);
    display_map(navy->enemy_map);
}

void first_player(navy *navy)
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

void second_player(navy *navy)
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

int launch(int size, char **args)
{
    navy *game = malloc(sizeof(navy));
    game->bool_game = 0;
    game->enemy_pid = 0;
    handle_signal(SIGUSR1);
    handle_signal(SIGUSR2);
    if (!load_boats(game, args[size - 1])) {
        //TODO free game
        return 84;
    }
    fill_map(game);
    if (size == 2) {
        first_player(game);
    } else {
        game->enemy_pid = my_atoi(args[1]);
        second_player(game);
    }
    return 0;
}
