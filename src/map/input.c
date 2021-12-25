/*
** EPITECH PROJECT, 2021
** navy
** File description:
** No file there , just an epitech header example
*/

#include "../../include/map.h"

void get_in_buffer(navy_t *navy, char *path)
{
    int fd;
    struct stat buf;

    stat(path, &buf);
    navy->map->buffer = malloc(sizeof(char) * (buf.st_size + 1));
    fd = open(path, O_RDONLY);
    if (fd == -1)
        navy->map->buffer = "error";
    read(fd, navy->map->buffer, buf.st_size);
    navy->map->buffer[buf.st_size] = '\0';
    close(fd);
}

int line_in_buffer(char *buffer) //TODO Mettre dans la lib
{
    int nb = 1;

    for (int i = 0; i < my_strlen(buffer); i++)
        if (buffer[i] == '\n')
            nb++;
    return nb;
}

int char_in_line(char *buffer) //TODO Mettre dans la lib
{
    for (int i = 0; i < my_strlen(buffer); i++)
        if (buffer[i] == '\n')
            return i;
    return 0;
}

void line_by_line(navy_t *navy)
{
    navy->map->buffer_lines = line_in_buffer(navy->map->buffer);
    navy->map->length_line = char_in_line(navy->map->buffer);
    navy->map->lines = malloc(sizeof(char *) * (navy->map->buffer_lines + 1));

    for (int i = 0; i < navy->map->buffer_lines; i++)
        navy->map->lines[i] = malloc(sizeof(char) * (navy->map->
        length_line + 1));
    for (int i = 0; i < navy->map->buffer_lines; i++) {
        for (int j = 0; j < navy->map->length_line; j++)
            navy->map->lines[i] = my_strcat_c(navy->map->lines[i],
            navy->map->buffer[j + navy->map->length_line * i + i * 1]);
        navy->map->lines[i][navy->map->length_line] = '\0';
    }
    navy->map->lines[navy->map->buffer_lines] = "\0";
}

void init_vectors(navy_t *navy)
{
    navy->map->vectors = malloc(sizeof(int *) * navy->map->buffer_lines);
    for (int i = 0; i < navy->map->buffer_lines; i++) {
        navy->map->vectors[i] = malloc(sizeof(int) * 7);
        navy->map->vectors[i][0] = (int) navy->map->lines[i][2] - 'A';
        navy->map->vectors[i][1] = (int) navy->map->lines[i][3] - '0';
        navy->map->vectors[i][2] = (int) navy->map->lines[i][5] - 'A';
        navy->map->vectors[i][3] = (int) navy->map->lines[i][6] - '0';
        navy->map->vectors[i][4] = navy->map->vectors[i][2] - navy->map->
        vectors[i][0];
        navy->map->vectors[i][5] = navy->map->vectors[i][3] - navy->map->
        vectors[i][1];
        navy->map->vectors[i][6] = (int) navy->map->lines[i][0] - '0';
    }
}

int input_map(navy_t *navy, char *path)
{
    navy->map = malloc(sizeof(map_t));
    get_in_buffer(navy, path);
    line_by_line(navy);
    init_vectors(navy);
    return (0);
}
