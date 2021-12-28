/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "../include/navy.h"

int simulation_enemy_connection(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    lineSize = getline(&line, &len, stdin);
    my_printf("enemy connected\n");
    free(line);
    return 1111;
}

void first_player(navy_t *navy)
{
    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    navy->enemy_pid = simulation_enemy_connection();
    while (navy->bool_game != 1) {
        display_maps(navy);
        attack_sender(navy);
        attack_sender(navy);
    }
}

void second_player(navy_t *navy)
{
    my_printf("my_pid: %d\n", getpid());
    my_printf("successfully connected\n\n");
    display_maps(navy);

}

int navy(int ac, char **av)
{
    if (ac == 2 || ac == 3) {
        navy_t *navy = malloc(sizeof(navy_t));
        navy->bool_game = 0;
        navy->attack = malloc(sizeof(attack_t));
        navy->attack->attack = malloc(sizeof(int) * 2);
        if (ac == 2) {
            fill_map(navy, av[1]);
            first_player(navy);
        } else {
            fill_map(navy, av[2]);
            navy->enemy_pid = my_atoi(av[1]);
            second_player(navy);
        }
    } else
        return 84;
    return (0);
}
