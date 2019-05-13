/*
** EPITECH PROJECT, 2022
** .
** File description:
** Created by mystogunn,
*/

#include "lemipc.h"

int check_number_player(game_t *game)
{
	int number_player = 0;

	for (int i = 0; i < MAP_SIDE; i++) {
		for (int i2 = 0; i2 < MAP_SIDE; i2++) {
			if (game->data->map[i][i2] != 0)
				number_player++;
		}
	}
	return (number_player);
}

int check_last(game_t *game)
{
	if (check_number_player(game) != 1)
		return (-1);
	inc_sem(game->ipc.sem_id);
	return (0);
}

int check_other(game_t *game)
{
	for (int i = 0; i < MAP_SIDE; i++) {
		for (int i2 = 0; i2 < MAP_SIDE; i2++) {
			if (game->data->map[i][i2] != 0 &&
				game->data->map[i][i2] != game->team_nb)
				return (-1);
		}
	}
	game->data->map[game->pos.x][game->pos.y] = 0;
	inc_sem(game->ipc.sem_id);
	return (0);
}