/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#ifndef NAVY_SIGNALS_H
    #define NAVY_SIGNALS_H

    #include <signal.h>
    #include <stdlib.h>
    #include <unistd.h>

enum Packets {
    ConnectionAttempt,
    AttackAttempt,
    AttackSuccess,
    AttackFail,
    VictoryResult
};

void handle_signal(int signal_id);

void send_request(int type, int data, int pid);

//== binary_parser.c ==

int signal_to_binary(int signal_id);

int from_binary(int const *binary_value);

int *to_binary(int number);

//== packet_handler.c ==
void handle_packet(int type, int data);

#endif
