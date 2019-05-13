/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "lemipc.h"

void print_help()
{
	printf("USAGE\n"
		"./lemipc PATH TEAM_NUMBER\n\n"
		"DESCRIPTION\n"
		"PATH\tpath you’ll give to ftok\n"
		"TEAM_NUMBER\t"
		"team number of the current champion (greater than 0)\n");
}

bool is_num(char *str)
{
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	game_t game;

	if (ac == 2 && strcmp("--help", av[1]) == 0)
		print_help();
	else if (ac == 3 && is_num(av[2])) {
		game.key_path = strdup(av[1]);
		game.team_nb = atoi(av[2]);
		game.key = ftok(game.key_path, 0);
		game.key_end = ftok(game.key_path, 1);
		if (game.team_nb <= 0 || game.key == -1 ||
			game.key_end == -1)
			return (84);
		init_ipc(&game);
	}
	return (0);
}