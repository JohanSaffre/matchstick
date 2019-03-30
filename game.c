/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** file with game functions
*/

#include "my.h"

int count_matches(char *line)
{
    int i = 0;
    int matchnum = 0;

    while (line[i]) {
        if (line[i] == '|')
            ++matchnum;
        ++i;
    }
    return (matchnum);
}

char **update_game_board(int line, int nb_matches, char **game_board)
{
    char *to_update = game_board[line];
    int len = my_strlen(to_update);
    int matchnum = count_matches(to_update);
    int tmp = matchnum - nb_matches;
    int i = len;

    while (matchnum > tmp) {
        if (to_update[i] == '|') {
            to_update[i] = ' ';
            --matchnum;
        }
        --i;
    }
    game_board[line] = to_update;
    return (game_board);
}

void print_message(int matches, int line)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int count_matches_line(char *line)
{
    int i = 0;
    int count = 0;

    while (line[i] != '\0') {
        if (line[i] == '|')
            ++count;
        ++i;
    }
    return (count);
}

int game(char **board, int linenum, int matchesmax)
{
    int turn = 1;

    while (check_end(board, linenum + 2)) {
        if (turn == 1) {
            if (player(board, linenum, matchesmax) == -1)
                return (-1);
            turn = 2;
        } else if (turn == 2) {
            ia(board, linenum, matchesmax);
            turn = 1;
        }
        print_game_board(linenum, board);
    }
    if (turn == 2) {
        my_putstr("You lost, too bad...\n");
        return (2);
    } else if (turn == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}
