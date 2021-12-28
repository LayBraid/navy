/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "signals.h"

int signal_to_binary(int signal_id)
{
    switch (signal_id) {
        case SIGUSR1:
            return 0;
        case SIGUSR2:
            return 1;
        default:
            return -1;
    }
}

int from_binary(int const *binary_value)
{
    static int numbers[16] = {32768, 16384, 8192, 4096, 2048, 1024, 512, 256,
                              128, 64, 32, 16, 8, 4, 2, 1};
    int value = 0;

    for (int index = 0; index < 16; index++)
        if (binary_value[index] == 1)
            value += numbers[index];
    return value;
}

int *to_binary(int number)
{
    static int numbers[16] = {32768, 16384, 8192, 4096, 2048, 1024, 512, 256,
                              128, 64, 32, 16, 8, 4, 2, 1};
    int *array = malloc(sizeof(int) * 16);

    if (number < 0 || number > (2 * numbers[0] - 1) || array == NULL) {
        free(array);
        return NULL;
    }
    for (int index = 0; index < 16; index++) {
        if (numbers[index] <= number) {
            number -= numbers[index];
            array[index] = 1;
        } else {
            array[index] = 0;
        }
    }
    return array;
}

