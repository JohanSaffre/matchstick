/*
** EPITECH PROJECT, 2019
** game_two.c
** File description:
** second file for game functions
*/

#include "my.h"

int get_line(int linenum)
{
    int line = 0;
    size_t size = 4;
    char *buffer = malloc(sizeof(int) * size + 1);

    while (line <= 0 || line > linenum) {
        my_putstr("Line: ");
        if (getline(&buffer, &size, stdin) == -1)
            return (-1);
        line = (my_get_nbr(buffer) / 10);
        if (line <= 0)
            my_putstr("Error: invalid input (positive number expected)\n");
        if (line > linenum)
            my_putstr("Error: this line is out of range\n");
    }
    free(buffer);
    return (line);
}

int get_matches(int matchesmax)
{
    int matches = 0;
    size_t size = 4;
    char *buffer = malloc(sizeof(int) * size);

    while (matches <= 0 || matches == -1564) {
        my_putstr("Matches: ");
        if (getline(&buffer, &size, stdin) == -1)
            return (-1);
        matches = (my_get_nbr(buffer) / 10);
        if (matches > matchesmax) {
            my_putstr("Error: you cannot remove more than ");
            my_put_nbr(matchesmax);
            my_putstr(" matches per turn\n");
            return (-2);
        } else if (matches == 0) {
            my_putstr("Error: you have to remove at least one match\n");
            return (0);
        }
    }
    free(buffer);
    return (matches);
}
