/*
** EPITECH PROJECT, 2019
** player.c
** File description:
** player file
*/

#include "my.h"

int not_enough(void)
{
    my_putstr("Error: not enough matches on this line\n");
    return (0);
}

int player(char **board, int num, int mmax)
{
    int li = 0;
    int mat = 0;
    int linem = 0;
    int i = 0;

    my_putstr("\nYour turn:\n");
    while (i == 0) {
        while (mat == 0) {
            if (((li = get_line(num)) == -1 || (mat = get_matches(mmax)) == -1))
                return (-1);
            if (mat <= mmax &&
                mat <= (linem = count_matches_line(board[li]))
                && mat != -2 && mat != 0) {
                board = update_game_board(li, mat, board);
                print_message(mat, li);
                i = 1;
            }
            if (mat > linem && mat != -2)
                mat = not_enough();
        }
    }
    return (0);
}
