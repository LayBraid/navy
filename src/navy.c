/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "../include/navy.h"

void simulation_enemy_connection(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    lineSize = getline(&line, &len, stdin);
    my_printf("enemy connected\n");
    free(line);
}

int navy(int ac, char **av)
{
    if (ac == 2 || ac == 3) {
        navy_t *navy = malloc(sizeof(navy_t));
        fill_map(navy, av[1]);
        if (ac == 2) {
            my_printf("my_pid: %d\n", getpid());
            my_printf("waiting for enemy connection...\n\n");
            simulation_enemy_connection();
            display_maps(navy);
        } else {

        }
    } else
        return 84;
    return (0);
}
