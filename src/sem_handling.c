/*
** EPITECH PROJECT, 2021
** PSU_lemipc_2017
** File description:
** Created by Yoann Sarkissian,
*/

#include "lemipc.h"

void inc_sem(int sem_id)
{
	struct sembuf sops;

	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = 1;
	semop(sem_id, &sops, 1);
}

void dec_sem(int sem_id)
{
	struct sembuf sops;

	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = -1;
	semop(sem_id, &sops, 1);
}