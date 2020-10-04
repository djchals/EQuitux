#ifndef FOO_DOT_H    /* This is an "include guard" */
#define FOO_DOT_H    /* prevents the file from being included twice. */

#include <stdbool.h> //need for work with bool vars
#include <stdio.h>
#include <stdlib.h> //needed for qsort

#define TOTAL_COMBOS 5175
#define MAX_COMBO_HEX 0xe3e3 
//main.c
int board[10];


//     board[0]=0x01;//h
//     board[1]=0x0e;//8
//     board[2]=0x01;//h
//     board[3]=0x02;//2
//     board[4]=0x03;//h
//     board[5]=0x08;//4
//     board[6]=0x01;//h
//     board[7]=0x04;//7
//     board[8]=0x01;//s
//     board[9]=0x0e;//A
// 
int convert_combo_to_array(int n_combo);

//get_value_combo.h
int get_value_combo(int combo_hex);
int is_straight_flush(int hero_all[14]);
int is_pair_to_quads();
int is_flush(int hero_all[14]);
int is_high_card(int hero_all[14]);
int comparator (const void * a, const void * b);
//

//
int arr_let_to_int[82];
int arr_suit_to_int[116];
int reverse_hex(int tmp_hex);

//
#endif /* FOO_DOT_H */
