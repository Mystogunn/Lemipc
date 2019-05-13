/*
** EPITECH PROJECT, 2021
** PSU_lemipc_2017
** File description:
** Created by Yoann Sarkissian,
*/

#include "lemipc.h"

int check_diff(int n, int a)
{
	if (n < a)
		return (a - n);
	return (n - a);
}

bool check_move(game_t *game, move_t move)
{
	int tmp_pos_x = game->pos.x;
	int tmp_pos_y = game->pos.y;

	(move == UP && game->pos.x > 0) ? (tmp_pos_x--) : 0;
	(move == DOWN && game->pos.x < MAP_SIDE - 1) ? (tmp_pos_x++) : 0;
	(move == LEFT && game->pos.y > 0) ? (tmp_pos_y--) : 0;
	(move == RIGHT && game->pos.y < MAP_SIDE - 1) ? (tmp_pos_y++) : 0;
	if (game->data->map[tmp_pos_x][tmp_pos_y] == 0)
		return (true);
	return (false);
}

bool can_move(game_t *game)
{
	if (check_move(game, UP) || check_move(game, DOWN) ||
		check_move(game, LEFT) || check_move(game, RIGHT))
		return (true);
	return (false);
}

void move_player(game_t *game, move_t move)
{
	game->data->map[game->pos.x][game->pos.y] = 0;
	(move == UP && game->pos.x > 0) ? (game->pos.x--) : 0;
	(move == DOWN && game->pos.x < MAP_SIDE - 1) ? (game->pos.x++) : 0;
	(move == LEFT && game->pos.y > 0) ? (game->pos.y--) : 0;
	(move == RIGHT && game->pos.y < MAP_SIDE - 1) ? (game->pos.y++) : 0;
	game->data->map[game->pos.x][game->pos.y] = game->team_nb;
}