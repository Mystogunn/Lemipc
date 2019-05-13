/*
** EPITECH PROJECT, 2021
** PSU_lemipc_2017
** File description:
** Created by Yoann Sarkissian,
*/

#ifndef PSU_LEMIPC_2017_DATA_H
#define PSU_LEMIPC_2017_DATA_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <time.h>

#define MAP_SIDE 5
#define PLAYERS_NB 3

typedef struct data {
	int map[MAP_SIDE][MAP_SIDE];
} data_t;

typedef struct ipc_id {
	int shm_id;
	int sem_id;
	int msg_id;
	int sem_id_end;
} ipc_id_t;

typedef struct pos_player {
	int x;
	int y;
} pos_player_t;

typedef enum move {
	UP,
	DOWN,
	LEFT,
	RIGHT,
} move_t;

typedef struct game {
	char *key_path;
	int team_nb;
	key_t key;
	key_t key_end;
	data_t *data;
	ipc_id_t ipc;
	pos_player_t pos;
	int target_x;
	int target_y;
	bool first_player;
	bool last_player;
} game_t;

typedef struct s_msg
{
	long mtype;
	char str[32];
} t_msg;

void init_ipc(game_t *game);
void init_map(game_t *game);
void print_map(game_t *game);
void rand_pos(game_t *game);
void inc_sem(int sem_id);
void dec_sem(int sem_id);
int loop_game(game_t *game);
int check_last(game_t *game);
int check_death(game_t *game);
int check_other(game_t *game);
int check_number_player(game_t *game);
void end_delete(game_t *game);
void end_no_delete(game_t *game);
void block_for_wait(game_t *game);
void play_game(game_t *game);
bool check_move(game_t *game, move_t move);
void move_player(game_t *game, move_t move);
bool can_move(game_t *game);
int check_diff(int n, int a);
void move_algo(game_t *game);

#endif //PSU_LEMIPC_2017_DATA_H
