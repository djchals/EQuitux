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

#include <time.h>


double tot_tiempo=0;

clock_t t_ini, t_fin;
double secs;

//main.c
void init_vars();
int board[10]={0};
int card_int_to_hex[52];
int card_hex_to_int[0x3f]={0};
    
// [i_player][turn_and_river][hero_combo]
int long_hex_pos[9];
// int HERO_COMBOS[9][1326][7];
// HERO_COMBOS[x][x][0]=0x1234
// HERO_COMBOS[x][x][1]=0x1
// HERO_COMBOS[x][x][2]=0x2
// HERO_COMBOS[x][x][3]=0x3
// HERO_COMBOS[x][x][4]=0x4
// HERO_COMBOS[x][x][5]=0x12
// HERO_COMBOS[x][x][6]=0x34


int HERO_COMBOS[9][1326];



int HERO_H_VALUES[9][1326][1326];
int arr_all_boards[6497400][10];
int long_all_boards=0;

//get_value_combo.h
int get_value_combo(int combo_hex, int local_board[10]);
int is_straight_flush(int hero_all[14]);
int is_pair_to_quads();
int is_flush(int hero_all[14]);
int is_high_card(int hero_all[14]);
//

//conv_pkr.h
void conv_range_pkr_to_hex(char tmp_range[],int i_player);
int reverse_hex(int tmp_hex);
int check_combo_ok_vs_board(int ch0,int ch1,int ch2,int ch3);

int arr_let_to_int[85];
int arr_suit_to_int[116];
char arr_int_to_let[15];
char arr_int_to_suit[4];

//boards.c
void calculate_EQ(int i_player);
int chk_no_repeated_cards(int num1, int num2);
//
                                                                                                                                                                                                                                                                //create init vars

void init_vars(){
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

    card_int_to_hex[0]=0x2;
    card_int_to_hex[1]=0x3;
    card_int_to_hex[2]=0x4;
    card_int_to_hex[3]=0x5;
    card_int_to_hex[4]=0x6;
    card_int_to_hex[5]=0x7;
    card_int_to_hex[6]=0x8;
    card_int_to_hex[7]=0x9;
    card_int_to_hex[8]=0xa;
    card_int_to_hex[9]=0xb;
    card_int_to_hex[10]=0xc;
    card_int_to_hex[11]=0xd;
    card_int_to_hex[12]=0xe;
    card_int_to_hex[13]=0x12;
    card_int_to_hex[14]=0x13;
    card_int_to_hex[15]=0x14;
    card_int_to_hex[16]=0x15;
    card_int_to_hex[17]=0x16;
    card_int_to_hex[18]=0x17;
    card_int_to_hex[19]=0x18;
    card_int_to_hex[20]=0x19;
    card_int_to_hex[21]=0x1a;
    card_int_to_hex[22]=0x1b;
    card_int_to_hex[23]=0x1c;
    card_int_to_hex[24]=0x1d;
    card_int_to_hex[25]=0x1e;
    card_int_to_hex[26]=0x22;
    card_int_to_hex[27]=0x23;
    card_int_to_hex[28]=0x24;
    card_int_to_hex[29]=0x25;
    card_int_to_hex[30]=0x26;
    card_int_to_hex[31]=0x27;
    card_int_to_hex[32]=0x28;
    card_int_to_hex[33]=0x29;
    card_int_to_hex[34]=0x2a;
    card_int_to_hex[35]=0x2b;
    card_int_to_hex[36]=0x2c;
    card_int_to_hex[37]=0x2d;
    card_int_to_hex[38]=0x2e;
    card_int_to_hex[39]=0x32;
    card_int_to_hex[40]=0x33;
    card_int_to_hex[41]=0x34;
    card_int_to_hex[42]=0x35;
    card_int_to_hex[43]=0x36;
    card_int_to_hex[44]=0x37;
    card_int_to_hex[45]=0x38;
    card_int_to_hex[46]=0x39;
    card_int_to_hex[47]=0x3a;
    card_int_to_hex[48]=0x3b;
    card_int_to_hex[49]=0x3c;
    card_int_to_hex[50]=0x3d;
    card_int_to_hex[51]=0x3e;
    
    card_hex_to_int[0x2]=0;
    card_hex_to_int[0x3]=1;
    card_hex_to_int[0x4]=2;
    card_hex_to_int[0x5]=3;
    card_hex_to_int[0x6]=4;
    card_hex_to_int[0x7]=5;
    card_hex_to_int[0x8]=6;
    card_hex_to_int[0x9]=7;
    card_hex_to_int[0xa]=8;
    card_hex_to_int[0xb]=9;
    card_hex_to_int[0xc]=10;
    card_hex_to_int[0xd]=11;
    card_hex_to_int[0xe]=12;
    card_hex_to_int[0x12]=13;
    card_hex_to_int[0x13]=14;
    card_hex_to_int[0x14]=15;
    card_hex_to_int[0x15]=16;
    card_hex_to_int[0x16]=17;
    card_hex_to_int[0x17]=18;
    card_hex_to_int[0x18]=19;
    card_hex_to_int[0x19]=20;
    card_hex_to_int[0x1a]=21;
    card_hex_to_int[0x1b]=22;
    card_hex_to_int[0x1c]=23;
    card_hex_to_int[0x1d]=24;
    card_hex_to_int[0x1e]=25;
    card_hex_to_int[0x22]=26;
    card_hex_to_int[0x23]=27;
    card_hex_to_int[0x24]=28;
    card_hex_to_int[0x25]=29;
    card_hex_to_int[0x26]=30;
    card_hex_to_int[0x27]=31;
    card_hex_to_int[0x28]=32;
    card_hex_to_int[0x29]=33;
    card_hex_to_int[0x2a]=34;
    card_hex_to_int[0x2b]=35;
    card_hex_to_int[0x2c]=36;
    card_hex_to_int[0x2d]=37;
    card_hex_to_int[0x2e]=38;
    card_hex_to_int[0x32]=39;
    card_hex_to_int[0x33]=40;
    card_hex_to_int[0x34]=41;
    card_hex_to_int[0x35]=42;
    card_hex_to_int[0x36]=43;
    card_hex_to_int[0x37]=44;
    card_hex_to_int[0x38]=45;
    card_hex_to_int[0x39]=46;
    card_hex_to_int[0x3a]=47;
    card_hex_to_int[0x3b]=48;
    card_hex_to_int[0x3c]=49;
    card_hex_to_int[0x3d]=50;
    card_hex_to_int[0x3e]=51;
}


#endif /* FOO_DOT_H */
