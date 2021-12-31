/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "events.h"
#include "navy.h"

char *int_to_attack(int nb)
{
    char *result = "";

    result = my_strcat_c(result, (char) ((nb / 10) + 64));
    result = my_strcat(result, my_itoa(nb % 10));
    return result;
}

void result_receiver(char *str)
{
    if (navy->my_map[my_atoi(str) - 1][str[0] - 65] != '.' &&
        navy->my_map[my_atoi(str) - 1][str[0] - 65] != 'o') {
        my_printf("%s: hit\n", str);
        send_request(AttackSuccess, 1, navy->enemy_pid);
        navy->my_map[my_atoi(str) - 1][str[0] - 65] = 'x';
    } else {
        my_printf("%s: missed\n", str);
        send_request(AttackFail, 2, navy->enemy_pid);
        navy->my_map[my_atoi(str) - 1][str[0] - 65] = 'o';
    }
}

void attack_receiver()
{
    char *result;

    navy->answer = 0;
    my_printf("\nwaiting for enemy's attack...\n");
    while (navy->answer == 0)
        usleep(100);
    result = int_to_attack(navy->answer);
    result_receiver(result);
}
