/*
** EPITECH PROJECT, 2019
** my_get_nbr.c
** File description:
** getnbr
*/

int my_get_nbr(char *str)
{
    int i = 0;
    int nb_minus = 0;
    int dest = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            dest = dest + str[i] - '0';
        else if (str[i] == '-')
            nb_minus++;
        if (str[i + 1] != '\0')
            dest = dest * 10;
        i++;
    }
    if (nb_minus % 2 != 0 && nb_minus > 0)
        dest = dest * -1;
    return (dest);
}
