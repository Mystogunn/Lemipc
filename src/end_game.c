/*
** EPITECH PROJECT, 2022
** .
** File description:
** Created by mystogunn,
*/

#include "lemipc.h"

void end_no_delete(game_t *game)
{
	dec_sem(game->ipc.sem_id_end);
}

void end_delete(game_t *game)
{
	while (semctl(game->ipc.sem_id_end, 0, GETVAL) != 1) {
		inc_sem(game->ipc.sem_id_end);
	}
	printf("TEAM NUMBER : %d WIN\n", game->team_nb);
	semctl(game->ipc.sem_id, 0, IPC_RMID);
	semctl(game->ipc.sem_id_end, 0, IPC_RMID);
	msgctl(game->ipc.msg_id, IPC_RMID, NULL);
	shmctl(game->ipc.shm_id, IPC_RMID, NULL);
}