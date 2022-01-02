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

int correct_attack(char *str)
{
    if (my_str_contains_c(str[0], LETTERS_ATTACK) &&
    my_str_contains_c(str[1], NUMBERS_ATTACK))
        return 1;
    return 0;
}

int attack_to_int(char *str)
{
    char *result = "";

    if (str[0] < 97)
        result = my_strcat_c(result, (char) (str[0] - 16));
    else
        result = my_strcat_c(result, (char) (str[0] - 48));
    result = my_strcat_c(result, str[1]);
    return my_atoi(result);
}

void result_attack(navy_t *navy, char *str)
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

void attack_sender(navy_t *navy)
{
    char *line = NULL;
    int bool = 0;
    size_t len = 0;
    ssize_t lineSize = 0;
    my_printf("\n");
    while (bool == 0) {
        my_printf("attack: ");
        lineSize = getline(&line, &len, stdin);
        line = my_strncpy(line, line, 2);
        if (correct_attack(line) == 1)
            bool = 1;
        else
            my_printf("wrong position\n");
    }
    bool = attack_to_int(line);
    send_request(AttackAttempt, bool, navy->enemy_pid);
    result_attack(navy, line);
    free(line);
}
