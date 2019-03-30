/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main fil e for matchstick
*/

#include "my.h"

void print_game_board(int linenum, char **game_board)
{
    int j = 0;

    while (j <= linenum + 1) {
        my_putstr(game_board[j]);
        my_putchar('\n');
        ++j;
    }
}

int check_end(char **board, int linenum)
{
    int i = 0;
    int j = 0;

    while (i < linenum) {
        while (board[i][j] != '\0') {
            if (board[i][j] == '|')
                return (1);
            ++j;
        }
        ++i;
        j = 0;
    }
    return (0);
}

int main(int ac, char **av)
{
    int linenum = 0;
    int matchesmax = 0;
    char **board = 0;
    int ret = 0;

    if (ac != 3)
        return (84);
    linenum = my_get_nbr(av[1]);
    matchesmax = my_get_nbr(av[2]);
    board = make_game_board(linenum);
    print_game_board(linenum, board);
    ret = game(board, linenum, matchesmax);
    if (ret == 2)
        return (2);
    else if (ret == 1)
        return (1);
    if (ret == 0)
        return (0);
        return ret;
    return (0);
}
