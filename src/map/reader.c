/*
** EPITECH PROJECT, 2022
** navy
** File description:
** No file there , just an epitech header example
*/

#include <fcntl.h>
#include <unistd.h>
#include "struct.h"
#include "my.h"

int file_length(conststr path)
{
    int file_descriptor = open(path, O_RDONLY);
    int length = 0;
    char buffer;

    if (file_descriptor == -1)
        return -1;
    while (read(file_descriptor, &buffer, 1) > 0)
        length++;
    close(file_descriptor);
    return length;
}

char *load_raw_map(conststr path)
{
    int file_descriptor = open(path, O_RDONLY);
    int length = file_length(path);

    if (file_descriptor != -1 && length > 0) {
        char *buffer = malloc(sizeof(char) * (length + 1));

        buffer[length] = '\0';
        read(file_descriptor, buffer, length);
        close(file_descriptor);
        return buffer;
    }
    return NULL;
}

int count_lines(conststr input)
{
    int counter = 0;
    for (int index = 0; input[index] != '\0'; index++) {
        if (input[index] == '\n')
            counter++;
    }
    return counter;
}

char **split_lines(conststr input)
{
    if (my_strlen(input) % 8 != 0)
        return NULL;
    int lines_count = count_lines(input);
    char **lines = malloc(sizeof(char *) * (lines_count + 1));
    for (int line = 0; line < lines_count; line++) {
        lines[line] = malloc(sizeof(char) * 8);
        for (int index = 0; index < 7; index++)
            lines[line][index] = input[(line * 8) + index];
        lines[line][7] = '\0';
    }
    lines[lines_count] = NULL;
    return lines;
}
