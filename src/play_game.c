/*
** EPITECH PROJECT, 2022
** .
** File description:
** Created by mystogunn,
*/

#include "lemipc.h"

int loop_game(game_t *game)
{
	while (42) {
		dec_sem(game->ipc.sem_id);
		if (game->first_player == true)
			print_map(game);
		if (check_last(game) == 0)
			return (1);
		if (check_other(game) == 0)
			return (0);
		if (check_death(game) == 0)
			return (0);
		move_algo(game);
		if (check_death(game) == 0)
			return (0);
		usleep(300000);
		inc_sem(game->ipc.sem_id);
	}
}

void play_game(game_t *game)
{
	int i;

	i = loop_game(game);
	if (i == 0)
		end_no_delete(game);
	else if (i == 1)
		end_delete(game);
}

void block_for_wait(game_t *game)
{
	t_msg my_msg;

	if (check_number_player(game) == PLAYERS_NB) {
		bzero(&my_msg, sizeof(my_msg));
		my_msg.mtype = 42;
		sprintf(my_msg.str, "hello world !");
		for (int i = PLAYERS_NB; i > 0; i--)
			msgsnd(game->ipc.msg_id, &my_msg, sizeof(my_msg), 0);
	} else {
		msgrcv(game->ipc.msg_id, &my_msg, sizeof(my_msg), 42, 0);
	}
}