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

int main(int size, char **args)
{
    if (size == 2 || size == 3) {
        return launch(size, args);
    } else {
        print_usage(size - 1);
        return 84;
    }
}
