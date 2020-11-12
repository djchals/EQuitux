#ifndef BOARDS_H    /* This is an "include guard" */
#define BOARDS_H    /* prevents the file from being included twice. */
#include "header.h"
#include "conv_pkr.h"
#include "get_value_combo.h"
#include "calculate_all.h"

#include "threadcalculate.h"
#include "mainwindow.h"
//gcc boards.c -lpcre
void calculate_EQ(int i_player){
//    printf("fuego al EQ 0\n");
    int i,j,n;
    int act_t_r=0;
    int local_board[10];
    long int ii;
    memcpy(local_board, board, 10*sizeof(int));
    int board_01=card_hex_to_int[(local_board[0]*0x10)+local_board[1]];
    int board_02=card_hex_to_int[(local_board[2]*0x10)+local_board[3]];
    int board_03=card_hex_to_int[(local_board[4]*0x10)+local_board[5]];
    int board_04=card_hex_to_int[(local_board[6]*0x10)+local_board[7]];
//    int board_05=card_hex_to_int[(local_board[8]*0x10)+local_board[9]];

    if(board[1]==0){
        for(ii=0;ii<NUM_HANDS_PREFLOP;++ii){
            memcpy(local_board,arr_all_boards[ii],10*sizeof(int));
//             printf("%x%x %x%x %x%x - %x%x - %x%x \n",local_board[0],local_board[1],local_board[2],local_board[3],local_board[4],local_board[5],local_board[6],local_board[7],local_board[8],local_board[9]);
            for(n=0;n<long_hex_pos[i_player];++n){
                if(
                    !(HERO_COMBOS[i_player][n][1]==local_board[0] && HERO_COMBOS[i_player][n][2]==local_board[1]) &&
                    !(HERO_COMBOS[i_player][n][1]==local_board[2] && HERO_COMBOS[i_player][n][2]==local_board[3]) &&
                    !(HERO_COMBOS[i_player][n][1]==local_board[4] && HERO_COMBOS[i_player][n][2]==local_board[5]) &&
                    !(HERO_COMBOS[i_player][n][1]==local_board[6] && HERO_COMBOS[i_player][n][2]==local_board[7]) &&
                    !(HERO_COMBOS[i_player][n][1]==local_board[8] && HERO_COMBOS[i_player][n][2]==local_board[9]) &&

                    !(HERO_COMBOS[i_player][n][3]==local_board[0] && HERO_COMBOS[i_player][n][4]==local_board[1]) &&
                    !(HERO_COMBOS[i_player][n][3]==local_board[2] && HERO_COMBOS[i_player][n][4]==local_board[3]) &&
                    !(HERO_COMBOS[i_player][n][3]==local_board[4] && HERO_COMBOS[i_player][n][4]==local_board[5]) &&
                    !(HERO_COMBOS[i_player][n][3]==local_board[6] && HERO_COMBOS[i_player][n][4]==local_board[7]) &&
                    !(HERO_COMBOS[i_player][n][3]==local_board[8] && HERO_COMBOS[i_player][n][4]==local_board[9])
                ){
                    HERO_H_VALUES[i_player][ii][n]=get_value_combo(HERO_COMBOS[i_player][n],local_board);
                }else{
                    HERO_H_VALUES[i_player][ii][n]=0;
                }
            }
        }
        long_all_boards=NUM_HANDS_PREFLOP;
    }else if(local_board[6]==0 && local_board[7]==0){//turn is empty
        for(i=0;i<51;i++){
            local_board[6]=(card_int_to_hex[i]/0x10)%0x10;
            local_board[7]=card_int_to_hex[i]%0x10;
            
            if(board_01==i || board_02==i || board_03==i){
                continue;//skip this iteration
            }
            for(j=i+1;j<52;j++){
                local_board[8]=(card_int_to_hex[j]/0x10)%0x10;
                local_board[9]=card_int_to_hex[j]%0x10;

                if(board_01==j || board_02==j || board_03==j || board_04==j){
                    continue;//skip this iteration
                }
                ++act_t_r;
                for(n=0;n<long_hex_pos[i_player];++n){
                    if( HERO_COMBOS[i_player][n][5]!=i && HERO_COMBOS[i_player][n][5]!=j &&
                        HERO_COMBOS[i_player][n][6]!=i && HERO_COMBOS[i_player][n][6]!=j
                    ){
                        HERO_H_VALUES[i_player][act_t_r][n]=get_value_combo(HERO_COMBOS[i_player][n],local_board);
                    }else{
                        HERO_H_VALUES[i_player][act_t_r][n]=0;
                    }
                }
            }
        }
        long_all_boards=act_t_r;
    }else if(local_board[8]==0 && local_board[9]==0){//river is empty
        for(i=0;i<52;++i){
            if(board_01==i || board_02==i || board_03==i || board_04==i){
                continue;
            }
            local_board[8]=(card_int_to_hex[i]/0x10)%0x10;
            local_board[9]=card_int_to_hex[i]%0x10;

            ++act_t_r;
            for(n=0;n<long_hex_pos[i_player];++n){
                if(                                
                    !(HERO_COMBOS[i_player][n][1]==local_board[8] && HERO_COMBOS[i_player][n][2]==local_board[9]) &&
                    !(HERO_COMBOS[i_player][n][3]==local_board[8] && HERO_COMBOS[i_player][n][4]==local_board[9])
                ){
                    HERO_H_VALUES[i_player][act_t_r][n]=get_value_combo(HERO_COMBOS[i_player][n],local_board);
                }else{
                    HERO_H_VALUES[i_player][act_t_r][n]=0;
                }
            }
        }
        long_all_boards=act_t_r;
    }else{//board is all filled
        for(n=0;n<long_hex_pos[i_player];++n){
//             printf("%d %d %x %d\n",m,i_player,HERO_COMBOS[i_player][m],long_hex_pos[i_player]);
            HERO_H_VALUES[i_player][act_t_r][n]=get_value_combo(HERO_COMBOS[i_player][n],local_board);
        }
        long_all_boards=1;
    }
}

void create_preflop(int num_hands){
    int i,j,k,l, m;
    if(board[1]==0){
        int act_t_r=0;
        while(act_t_r<num_hands){
            i=rand()%52;
            do{
                j=rand()%52;
            }while( i==j);
            do{
                k=rand()%52;
            }while(k==i || k==j);
            do{
                l=rand()%52;
            }while(l==i || l==j || l==k);
            do{
                m=rand()%52;
            }while(m==i || m==j || m==k || m==l);
            
            arr_all_boards[act_t_r][0]=(card_int_to_hex[i]/0x10)%0x10;
            arr_all_boards[act_t_r][1]=card_int_to_hex[i]%0x10;

            arr_all_boards[act_t_r][2]=(card_int_to_hex[j]/0x10)%0x10;
            arr_all_boards[act_t_r][3]=card_int_to_hex[j]%0x10;

            arr_all_boards[act_t_r][4]=(card_int_to_hex[k]/0x10)%0x10;
            arr_all_boards[act_t_r][5]=card_int_to_hex[k]%0x10;

            arr_all_boards[act_t_r][6]=(card_int_to_hex[l]/0x10)%0x10;
            arr_all_boards[act_t_r][7]=card_int_to_hex[l]%0x10;

            arr_all_boards[act_t_r][8]=(card_int_to_hex[m]/0x10)%0x10;
            arr_all_boards[act_t_r][9]=card_int_to_hex[m]%0x10;

//            printf("%x%x %x%x %x%x - %x%x - %x%x | act_t_r %d\n",arr_all_boards[act_t_r][0],arr_all_boards[act_t_r][1],arr_all_boards[act_t_r][2],arr_all_boards[act_t_r][3],arr_all_boards[act_t_r][4],arr_all_boards[act_t_r][5],arr_all_boards[act_t_r][6],arr_all_boards[act_t_r][7],arr_all_boards[act_t_r][8],arr_all_boards[act_t_r][9],act_t_r );

            ++act_t_r;
        }
    }
}
#endif // END BOARDS_H
