/*
** EPITECH PROJECT, 2019
** make_board.c
** File description:
** functions to set the game_board
*/

#include "my.h"

char **set_first_and_last(char **game_board, int linelen, int linenum)
{
    int i = 0;

    while (i < linelen) {
        game_board[0][i] = '*';
        game_board[linenum + 1][i] = '*';
        ++i;
    }
    game_board[0][i] = '\0';
    game_board[linenum + 1][i] = '\0';
}

char **fill_game_board(char **game_board, int linelen, int linenum)
{
    int i = 0;
    int j = 1;
    int matchnum = 0;

    set_first_and_last(game_board, linelen, linenum);
    i = 1;
    while (i < linenum + 1) {
        game_board[i][0] = '*';
        while (j < linelen - 1) {
            game_board[i][j] = ' ';
            if (j >= linelen / 2 - matchnum && j <= linelen / 2 + matchnum)
                game_board[i][j] = '|';
            ++j;
            }
        game_board[i][j] = '*';
        game_board[i][j + 1] = '\0';
        j = 1;
        ++i;
        ++matchnum;
    }
}

char **make_game_board(int linenum)
{
    int linelen = (2 * linenum) + 1;
    int matchmax = (2 * linenum) - 1;
    char **game_board = malloc(sizeof(char *) * linenum + 2);
    int i = 0;
    int j = 0;

    while (i < linenum + 2) {
        game_board[i] = malloc(sizeof(char) * linelen + 1);
        ++i;
    }
    fill_game_board(game_board, linelen, linenum);
    return (game_board);
}
