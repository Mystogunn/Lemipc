/*
** EPITECH PROJECT, 2021
** PSU_lemipc_2017
** File description:
** Created by Yoann Sarkissian,
*/

#include "lemipc.h"

void print_map(game_t *game)
{
	for (int i = 0; i < MAP_SIDE; i++) {
		for (int i2 = 0; i2 < MAP_SIDE; i2++) {
			printf(" %d |", game->data->map[i][i2]);
		}
		printf("\n");
	}
	printf("\nx : %d  y : %d\n", game->pos.x, game->pos.y);
}

bool check_line(game_t *game)
{
	for (int i = 0; i < MAP_SIDE; i++) {
		if (game->data->map[game->pos.x][i] == 0)
			return (true);
	}
	return (false);
}

void rand_pos(game_t *game)
{
	game->pos.x = rand() % (MAP_SIDE);
	while (!check_line(game)) {
		game->pos.x = rand() % (MAP_SIDE);
	}
	game->pos.y = rand() % (MAP_SIDE);
	while (game->data->map[game->pos.x][game->pos.y] != 0)
		game->pos.y = rand() % (MAP_SIDE);
	game->data->map[game->pos.x][game->pos.y] = game->team_nb;
}

void init_map(game_t *game)
{
	for (int i = 0; i < MAP_SIDE; i++) {
		for (int i2 = 0; i2 < MAP_SIDE; i2++)
			game->data->map[i][i2] = 0;
	}
}