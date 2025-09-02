#include "ft_get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *lineMaker(char *string)
{
    int i;
    char *line;

    if (!string)
        return (NULL);
    i = f_strchr(string, '\n');
    if (i == -1)
        i = f_strlen(string);
    else
        i++;
    line = f_ssubstr(string, 0, i);
    return (line);
}

char *updateLeftover(char *string)
{
    int start;
    char *editedLeftover;

    if (!string)
        return (NULL);
    start = f_strchr(string, '\n') + 1;
    if (start == 0)
    {
        free(string);
        return (NULL);
    }
    editedLeftover = f_ssubstr(string, start, f_strlen(string) - start);
    free(string);
    if (editedLeftover && !editedLeftover[0])
    {
        free(editedLeftover);
        return (NULL);
    }
    return (editedLeftover);
}

static char *readloop(int fd, char *leftover)
{
    char buffer[BUFFER_SIZE + 1];
    int bytes;

    bytes = read(fd, buffer, BUFFER_SIZE);
    while (bytes > 0)
    {
        buffer[bytes] = '\0';
        if (!leftover)
            leftover = f_dup(buffer);
        else
            leftover = f_join(leftover, buffer);
        if (f_strchr(leftover, '\n') != -1)
            break;
        bytes = read(fd, buffer, BUFFER_SIZE);
    }
    if (bytes < 0)
        return (NULL);
    return (leftover);
}

char *get_next_line(int fd)
{
    static char *leftover;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (leftover && f_strchr(leftover, '\n') != -1)
    {
        line = lineMaker(leftover);
        leftover = updateLeftover(leftover);
        return (line);
    }
    leftover = readloop(fd, leftover);
    if (!leftover)
        return (NULL);
    if (f_strchr(leftover, '\n') != -1)
    {
        line = lineMaker(leftover);
        leftover = updateLeftover(leftover);
        return (line);
    }
    line = leftover;
    leftover = NULL;
    return (line);
}

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    for (int i = 0; i < 21; i++)
    {
        char *line = get_next_line(fd);
        printf("the %d line is ==> %s\n", i + 1, line);
        free(line);
    }
}
