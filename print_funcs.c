/*
** EPITECH PROJECT, 2018
** printt_funcs
** File description:
** file for printing functions
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

int my_put_nbr(int nb)
{
    int nbr;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        nbr = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(nbr + 48);
    } else
        my_putchar(nb + 48);
    return (0);
}

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return (length);
}
