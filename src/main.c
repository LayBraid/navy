/*
** EPITECH PROJECT, 2021
** BLANK_PROJECT_C
** File description:
** No file there , just an epitech header example
*/

#include "navy.h"
#include "my.h"

void put_error(char const *message)
{
    write(1, message, my_strlen(message));
}

void print_usage(int size)
{
    char *value = my_itoa(size);

    put_error("./my_radar: bad arguments: ");
    put_error(value);
    put_error(" given but 1 is required\nretry with -h\n");
    free(value);
}

void send_help(void)
{
    my_putstr("USAGE\n     ./navy [first_player_pid] navy_positions\n"
              "DESCRIPTION\n     first_player_pid: only for the 2nd player."
              " pid of the first player.\n     navy_positions: file "
              "representing the positions of the ships.\n");
}

int main(int size, char **args)
{
    if (size == 2 || size == 3) {
        if (size == 2 && my_strcmp(args[1], "-h") == 0) {
            send_help();
            return 0;
        }
        return launch(size, args);
    } else {
        print_usage(size - 1);
        return 84;
    }
}
