/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header file for matchstick
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
char **update_game_board(int line, int nb_matches, char **game_board);
void print_game_board(int linenum, char **game_board);
int check_end(char **board, int linenum);
char **set_first_and_last(char **game_board, int linelen, int linenum);
char **fill_game_board(char **game_board, int linelen, int linenum);
char **make_game_board(int linenum);
int game(char **board, int linenum, int matchesmax);
int get_line(int linenum);
int get_matches(int matchesmax);
int my_get_nbr(char const *str);
int player(char **board, int linenum, int matchesmax);
int count_matches_line(char *line);
void print_message(int matches, int line);
int ia(char **board, int linenum, int matchesmax);

#endif
