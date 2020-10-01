#ifndef FOO_DOT_H    /* This is an "include guard" */
#define FOO_DOT_H    /* prevents the file from being included twice. */

#include <stdbool.h> //need for work with bool vars
#include <stdlib.h> //needed for qsort
//main.c
int get_value_combo(int combo_hex);
int board[10];

int is_straight_flush(int hero_all[14]);
int is_repeated_cards();
int is_flush(int hero_all[14]);
int is_high_card(int hero_all[14]);
/*
int is_board_paired();
int is_pocket_pair(int hero_combo[4]);
int get_kicker(int hero_combo[4],int except);*/
int comparator (const void * a, const void * b);
//
#endif /* FOO_DOT_H */
