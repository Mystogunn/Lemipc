/*
** EPITECH PROJECT, 2021
** PSU_lemipc_2017
** File description:
** Created by Yoann Sarkissian,
*/

#include "lemipc.h"

void init_shm(game_t *game)
{
	game->ipc.shm_id = shmget(game->key, sizeof(data_t), SHM_R | SHM_W);
	if (game->ipc.shm_id == -1) {
		game->ipc.shm_id = shmget(
			game->key, sizeof(data_t), IPC_CREAT | SHM_R | SHM_W);
		game->data = (data_t *)shmat(
			game->ipc.shm_id, NULL, SHM_R | SHM_W);
		game->first_player = true;
		init_map(game);
	} else {
		printf("Using shm segment %d\n", game->ipc.shm_id);
		game->data = (data_t *)shmat(game->ipc.shm_id,
			NULL, SHM_R | SHM_W);
	}
}

void init_sem(game_t *game)
{
	game->ipc.sem_id = semget(game->key, 1, SHM_R | SHM_W);
	if (game->ipc.sem_id == -1)
	{
		game->ipc.sem_id = semget(game->key, 1,
			IPC_CREAT | SHM_R | SHM_W);
		semctl(game->ipc.sem_id, 0, SETVAL, 1);
	} else {
		printf("Using sem %d\n", game->ipc.sem_id);
	}
}

void init_sem_end(game_t *game)
{
	game->ipc.sem_id_end = semget(game->key_end, 1, SHM_R | SHM_W);
	if (game->ipc.sem_id_end == -1)
	{
		game->ipc.sem_id_end = semget(game->key_end, 1,
			IPC_CREAT | SHM_R | SHM_W);
		semctl(game->ipc.sem_id_end, 0, SETVAL, 0);
	} else {
		printf("Using sem %d\n", game->ipc.sem_id_end);
	}
}

void init_msg(game_t *game)
{
	game->ipc.msg_id = msgget(game->key, SHM_R | SHM_W);
	if (game->ipc.msg_id == -1)
		game->ipc.msg_id = msgget(game->key, IPC_CREAT | SHM_R | SHM_W);
	else
		printf("Using msg %d\n", game->ipc.msg_id);
}

void init_ipc(game_t *game)
{
	srand(time(NULL));
	game->first_player = false;
	game->last_player = false;
	init_shm(game);
	init_sem(game);
	init_sem_end(game);
	init_msg(game);
	dec_sem(game->ipc.sem_id);
	rand_pos(game);
	inc_sem(game->ipc.sem_id);
	block_for_wait(game);
	printf("AFTER MSG\n");
	play_game(game);
}