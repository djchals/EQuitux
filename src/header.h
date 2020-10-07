#ifndef FOO_DOT_H    /* This is an "include guard" */
#define FOO_DOT_H    /* prevents the file from being included twice. */

#include <stdbool.h> //need for work with bool vars
#include <stdio.h>
// #include <stdlib.h> //needed for qsort


#define TOTAL_COMBOS 5175
#define MAX_COMBO_HEX 0xe3e3 
//main.c
void init_vars();
int board[10]={0};


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
int get_value_combo(int combo_hex, int local_board[10]);
int is_straight_flush(int hero_all[14]);
int is_pair_to_quads();
int is_flush(int hero_all[14]);
int is_high_card(int hero_all[14]);
int comparator (const void * a, const void * b);
//

//conv_pkr.h
int arr_let_to_int[85];
int arr_suit_to_int[116];
char arr_int_to_let[15];
char arr_int_to_suit[4];
int reverse_hex(int tmp_hex);
int *arr_hex_return;
int arr_deck[52];
//

//boards.c
void calculate_EQ(int *arr_hex_pos0,int long_hex_pos0, int *arr_hex_pos1,int long_hex_pos1);
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
    arr_int_to_let[0xd]='Q';
    arr_int_to_let[0xc]='K';
    arr_int_to_let[0xe]='A';

    arr_int_to_suit[0]='h';
    arr_int_to_suit[1]='d';
    arr_int_to_suit[2]='s';               
    arr_int_to_suit[3]='c'; 
//     int i='0';
//     arr_deck[i]=0x20;i++;
//     arr_deck[i]=0x30;i++;
//     arr_deck[i]=0x40;i++;
//     arr_deck[i]=0x50;i++;
//     arr_deck[i]=0x60;i++;
//     arr_deck[i]=0x70;i++;
//     arr_deck[i]=0x80;i++;
//     arr_deck[i]=0x90;i++;
//     arr_deck[i]=0xa0;i++;
//     arr_deck[i]=0xb0;i++;
//     arr_deck[i]=0xc0;i++;
//     arr_deck[i]=0xd0;i++;
//     arr_deck[i]=0xe0;i++;
// 
//     arr_deck[i]=0x21;i++;
//     arr_deck[i]=0x31;i++;
//     arr_deck[i]=0x41;i++;
//     arr_deck[i]=0x51;i++;
//     arr_deck[i]=0x61;i++;
//     arr_deck[i]=0x71;i++;
//     arr_deck[i]=0x81;i++;
//     arr_deck[i]=0x91;i++;
//     arr_deck[i]=0xa1;i++;
//     arr_deck[i]=0xb1;i++;
//     arr_deck[i]=0xc1;i++;
//     arr_deck[i]=0xd1;i++;
//     arr_deck[i]=0xe1;i++;
// 
//     arr_deck[i]=0x22;i++;
//     arr_deck[i]=0x32;i++;
//     arr_deck[i]=0x42;i++;
//     arr_deck[i]=0x52;i++;
//     arr_deck[i]=0x62;i++;
//     arr_deck[i]=0x72;i++;
//     arr_deck[i]=0x82;i++;
//     arr_deck[i]=0x92;i++;
//     arr_deck[i]=0xa2;i++;
//     arr_deck[i]=0xb2;i++;
//     arr_deck[i]=0xc2;i++;
//     arr_deck[i]=0xd2;i++;
//     arr_deck[i]=0xe2;i++;
// 
//     arr_deck[i]=0x23;i++;
//     arr_deck[i]=0x33;i++;
//     arr_deck[i]=0x43;i++;
//     arr_deck[i]=0x53;i++;
//     arr_deck[i]=0x63;i++;
//     arr_deck[i]=0x73;i++;
//     arr_deck[i]=0x83;i++;
//     arr_deck[i]=0x93;i++;
//     arr_deck[i]=0xa3;i++;
//     arr_deck[i]=0xb3;i++;
//     arr_deck[i]=0xc3;i++;
//     arr_deck[i]=0xd3;i++;
//     arr_deck[i]=0xe3;i++;
    
//     i=0;
//     arr_cards[i]=0x02;i++;
//     arr_cards[i]=0x03;i++;
//     arr_cards[i]=0x04;i++;
//     arr_cards[i]=0x05;i++;
//     arr_cards[i]=0x06;i++;
//     arr_cards[i]=0x07;i++;
//     arr_cards[i]=0x08;i++;
//     arr_cards[i]=0x09;i++;
//     arr_cards[i]=0x0a;i++;
//     arr_cards[i]=0x0b;i++;
//     arr_cards[i]=0x0c;i++;
//     arr_cards[i]=0x0d;i++;
//     arr_cards[i]=0x0e;i++;
    

}
#endif /* FOO_DOT_H */
