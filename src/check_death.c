/*
** EPITECH PROJECT, 2022
** PSU_lemipc_2017
** File description:
** Created by mystogunn,
*/

#include "lemipc.h"

int get_position(int x, int y, game_t *game)
{
	if (x < 0 || x > MAP_SIDE - 1 || y < 0 || y > MAP_SIDE - 1)
		return (0);
	return (game->data->map[x][y]);
}

void fill_position(game_t *game, int **position)
{
	(*position)[0] = get_position(game->pos.x - 1, game->pos.y - 1, game);
	(*position)[1] = get_position(game->pos.x - 1, game->pos.y, game);
	(*position)[2] = get_position(game->pos.x - 1, game->pos.y + 1, game);
	(*position)[3] = get_position(game->pos.x, game->pos.y - 1, game);
	(*position)[4] = get_position(game->pos.x, game->pos.y + 1, game);
	(*position)[5] = get_position(game->pos.x + 1, game->pos.y - 1, game);
	(*position)[6] = get_position(game->pos.x + 1, game->pos.y, game);
	(*position)[7] = get_position(game->pos.x + 1, game->pos.y + 1, game);
}

int check_death(game_t *game)
{
	int i;
	int *position = malloc(sizeof(int) * 8);

	fill_position(game, &position);
	while (i < 8) {
		if (position[i] != 0 && i != 7 && position[i] != game->team_nb)
			for (int i2 = 0; i2 < 8; ++i2) {
				if (position[i2] == position[i] && i2 != i) {
					game->data->map[game->pos.x]
					[game->pos.y] = 0;
					inc_sem(game->ipc.sem_id);
					free(position);
					return (0);
				}
			}
		i++;
	}
	free(position);
	return (-1);
}