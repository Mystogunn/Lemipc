/*
** EPITECH PROJECT, 2021
** PSU_lemipc_2017
** File description:
** Created by Yoann Sarkissian,
*/

#include "lemipc.h"

void get_target(game_t *game)
{
	int diff = MAP_SIDE;

	for (int x = 0; x < MAP_SIDE; x++) {
		if (game->data->map[x][game->pos.y] != 0 &&
			game->data->map[x][game->pos.y] != game->team_nb &&
			check_diff(x, game->pos.x) < diff) {
			diff = check_diff(x, game->pos.x);
			game->target_x = x;
		}
	}
	for (int y = 0; y < MAP_SIDE; y++) {
		if (game->data->map[game->pos.x][y] != 0 &&
			game->data->map[game->pos.x][y] != game->team_nb &&
			check_diff(y, game->pos.y) < diff) {
			diff = check_diff(y, game->pos.y);
			game->target_y = y;
		}
	}
}

void move_algo2(game_t *game)
{
	int b_x = game->pos.x;
	int b_y = game->pos.y;
	move_t rand_move;

	if (game->target_x != -1 && game->target_y != -1 &&
		game->target_x < game->target_y &&
		check_move(game, (game->target_x < game->pos.x) ? UP : DOWN))
		move_player(game, (game->target_x < game->pos.x) ? UP : DOWN);
	else if (game->target_x != -1 && game->target_y != -1 &&
		game->target_x > game->target_y &&
		check_move(game, (game->target_y < game->pos.y) ? LEFT : RIGHT))
		move_player(game,
			(game->target_y < game->pos.y) ? LEFT : RIGHT);
	else
		while (game->pos.x == b_x && game->pos.y == b_y) {
			rand_move = (rand() % 4);
			if (check_move(game, rand_move))
				move_player(game, rand_move);
		}
}

void move_algo(game_t *game)
{
	game->target_x = -1;
	game->target_y = -1;
	get_target(game);
	if (!can_move(game))
		return;
	if (game->target_x != -1 && game->target_y == -1 &&
		check_move(game, (game->target_x < game->pos.x) ? UP : DOWN))
		move_player(game, (game->target_x < game->pos.x) ? UP : DOWN);
	else if (game->target_x == -1 && game->target_y != -1 &&
		check_move(game, (game->target_y < game->pos.y) ? LEFT : RIGHT))
		move_player(game,
			(game->target_y < game->pos.y) ? LEFT : RIGHT);
	else
		move_algo2(game);
}