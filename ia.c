/*
** EPITECH PROJECT, 2019
** ia.c
** File description:
** AI file
*/

#include "my.h"

int ia(char **board, int linenum, int matchesmax)
{
    int i = 0;
    int line = 0;

    my_putstr("\nAI's turn...\n");
    while (!line) {
        line = count_matches_line(board[i + 1]);
        ++i;
    }
    my_putstr("AI removed 1 match(es) from line ");
    my_put_nbr(i);
    my_putchar('\n');
    board = update_game_board(i, 1, board);
}
