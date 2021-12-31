/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "signals.h"

int send_signal(int signal, int pid)
{
    if (kill(pid, signal) == -1)
        return 0;
    usleep(10000);
    return 1;
}

void send_corresponding_signal(int value, int pid)
{
    if (value == 0)
        send_signal(SIGUSR1, pid);
    else if (value == 1)
        send_signal(SIGUSR2, pid);
}

void send_request(int type, int data, int pid)
{
    int *type_bin = to_binary(type);
    int *data_bin = to_binary(data);

    usleep(8000);
    for (int index = 0; index < 16; index++)
        send_corresponding_signal(type_bin[index], pid);
    usleep(8000);
    for (int index = 0; index < 16; index++)
        send_corresponding_signal(data_bin[index], pid);
    free(type_bin);
    free(data_bin);
}

void receive_signal(int signal_id)
{
    static int *type = NULL;
    static int *data = NULL;
    static int position = 0;

    if (type == NULL || data == NULL) {
        type = malloc(sizeof(int) * 16);
        data = malloc(sizeof(int) * 16);
    }
    if (position < 16)
        type[position] = signal_to_binary(signal_id);
    else
        data[position - 16] = signal_to_binary(signal_id);
    position++;
    if (position == 32)
        handle_packet(from_binary(type), from_binary(data));
    if (position >= 32) {
        type = NULL;
        data = NULL;
        position = 0;
    }
}

void handle_signal(int signal_id)
{
    struct sigaction action;

    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
    action.sa_handler = receive_signal;
    sigaction(signal_id, &action, NULL);
}
