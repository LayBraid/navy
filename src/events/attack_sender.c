/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "events.h"
#include "navy.h"
#include "struct.h"
#include "signals.h"
#include "my.h"

boolean is_valid_attack(conststr attack_coordinate)
{
    if (attack_coordinate[0] < 'A' || attack_coordinate[0] > 'H')
        return FALSE;
    if (attack_coordinate[1] < '1' || attack_coordinate[1] > '8')
        return FALSE;
    return TRUE;
}

int attack_to_int(conststr str)
{
    char *result = "";

    if (str[0] < 97)
        result = my_strcat_c(result, (char) (str[0] - 16));
    else
        result = my_strcat_c(result, (char) (str[0] - 48));
    result = my_strcat_c(result, str[1]);
    return my_atoi(result);
}

void result_attack(navy *navy, char *str)
{
    answer = 0;
    while (answer == 0)
        usleep(100);
    if (answer == 1) {
        navy->enemy_map[my_atoi(str) - 1][str[0] - 65] = 'x';
        my_printf("%s: hit\n", str);
    } else if (answer == 2) {
        navy->enemy_map[my_atoi(str) - 1][str[0] - 65] = 'o';
        my_printf("%s: missed\n", str);
    }
}

void attack_sender(navy *navy)
{
    char *line = NULL;
    int is_valid = 0;
    size_t length = 0;

    my_putchar('\n');
    while (!is_valid) {
        my_putstr("attack: ");
        getline(&line, &length, stdin);
        line = my_strncpy(line, line, 2);
        if (is_valid_attack(line))
            is_valid = TRUE;
        else
            my_putstr("wrong position\n");
    }
    is_valid = attack_to_int(line);
    send_request(AttackAttempt, is_valid, navy->enemy_pid);
    result_attack(navy, line);
    free(line);
}
