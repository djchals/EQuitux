#ifndef FOO_DOT_H    /* This is an "include guard" */
#define FOO_DOT_H    /* prevents the file from being included twice. */

#include <stdbool.h> //need for work with bool vars
#include <stdio.h>
#include <stdlib.h> //needed for qsort

//conv_pkr.h
#include <pcre.h>
#include <string.h>
#include <math.h>

#define TOTAL_COMBOS 5175
#define MAX_COMBO_HEX 0xe3e3 
//main.c
void init_vars();
int board[10]={0};

//get_value_combo.h
int get_value_combo(int combo_hex, int local_board[10]);
int is_straight_flush(int hero_all[14]);
int is_pair_to_quads();
int is_flush(int hero_all[14]);
int is_high_card(int hero_all[14]);
//

//conv_pkr.h
void conv_range_pkr_to_hex(char tmp_range[]);
int reverse_hex(int tmp_hex);
int check_combo_ok_vs_board(int ch0,int ch1,int ch2,int ch3);

int arr_let_to_int[85];
int arr_suit_to_int[116];
char arr_int_to_let[15];
char arr_int_to_suit[4];
int *arr_hex_return=NULL;

int long_hex_return=0;//

//boards.c
void calculate_EQ(int *arr_hex_pos0,int long_hex_pos0, int *arr_hex_pos1,int long_hex_pos1);
//

// int FLOP[3];//3 Cards
// int TURN;//1 card
// int RIVER;//1 card
// 
// int HERO[9][2];//9 players 2 cards

//create init vars
void init_vars(){
//     arr_hex_return=malloc(sizeof(int) * 102476);//reserve100 kb
    //init_the_arrays
    arr_let_to_int['2']=2;
    arr_let_to_int['3']=3;
    arr_let_to_int['4']=4;                                
    arr_let_to_int['5']=5;                                
    arr_let_to_int['6']=6;                                
    arr_let_to_int['7']=7;                                
    arr_let_to_int['8']=8;                                
    arr_let_to_int['9']=9;
    arr_let_to_int['T']=0xa;
    arr_let_to_int['J']=0xb;
    arr_let_to_int['Q']=0xc;
    arr_let_to_int['K']=0xd;
    arr_let_to_int['A']=0xe;

    arr_suit_to_int['h']=0;
    arr_suit_to_int['d']=1;
    arr_suit_to_int['s']=2;               
    arr_suit_to_int['c']=3; 

    arr_int_to_let[0]=0;
    arr_int_to_let[1]=0;
    arr_int_to_let[2]='2';
    arr_int_to_let[3]='3';
    arr_int_to_let[4]='4';                                
    arr_int_to_let[5]='5';                                
    arr_int_to_let[6]='6';                                
    arr_int_to_let[7]='7';                                
    arr_int_to_let[8]='8';                                
    arr_int_to_let[9]='9';
    arr_int_to_let[0xa]='T';
    arr_int_to_let[0xb]='J';
    arr_int_to_let[0xc]='Q';
    arr_int_to_let[0xd]='K';
    arr_int_to_let[0xe]='A';

    arr_int_to_suit[0]='h';
    arr_int_to_suit[1]='d';
    arr_int_to_suit[2]='s';               
    arr_int_to_suit[3]='c'; 

}
#endif /* FOO_DOT_H */
