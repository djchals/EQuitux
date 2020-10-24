#ifndef BOARDS_H    /* This is an "include guard" */
#define BOARDS_H    /* prevents the file from being included twice. */
#include "header.h"
#include "conv_pkr.h"
#include "get_value_combo.h"
#include "calculate_all.h"

//gcc boards.c -lpcre
//void create_game(int num_players){

//    t_ini = clock();
//    int i=0,i_player=0;
//    int j,k;

    
//if(board[1]!=0){
//    for(i_player=0;i_player<num_players;++i_player){
//        if(range_pkr[i_player]){
//            //the result of this function will be saved in arr_hex_return
//            conv_range_pkr_to_hex(range_pkr[i_player],i_player);
//            if(long_hex_pos[i_player]>0){
//                calculate_EQ(i_player);
//            }
//        }
//    }
//    calculate_all(num_players,1);
////        for(j=0;j<num_players;j++){
////            printf("long_hex_pos[%d] %d\n",j,long_hex_pos[j]);
////        }
////        for(j=0;j<num_players;j++){
////            printf("pos[%d] %d\n",j,(int) tot_win_pos[j]);
////        }
//        for(j=0;j<num_players;j++){
//            printf("tot_win_pcent[%d] %.3f\n",j,tot_win_pcent[j]);
//        }
//        for(j=0;j<num_players;j++){
//            printf("tot_tied_pcent[%d] %.3f\n",j,tot_tied_pcent[j]);
//        }
//}else{
    
////    printf("long_all_boards %d\n",long_all_boards);
//    for(i=0;i<10000;i++){
////        printf("Creando preflop %d...\n",i);
//        create_preflop(NUM_HANDS_PREFLOP);
////        printf("Creado %d\n",i);
//        for(i_player=0;i_player<num_players;++i_player){
//            if(range_pkr[i_player]){
//                //the result of this function will be saved in arr_hex_return
//                conv_range_pkr_to_hex(range_pkr[i_player],i_player);
//                if(long_hex_pos[i_player]>0){
//                    calculate_EQ(i_player);
//                }
//            }
//        }
//        calculate_all(num_players,0);
        
////        for(j=0;j<num_players;j++){
////            printf("long_hex_pos[%d] %d\n",j,long_hex_pos[j]);
////        }
////        for(j=0;j<num_players;j++){
////            printf("pos[%d] %d\n",j,(int) tot_win_pos[j]);
////        }
//        for(j=0;j<num_players;j++){
////            emit(MainWindow::show_win_pcent(j,tot_win_pcent[j]));
////            MainWindow::show_win_pcent(j,tot_win_pcent[j]);
////            printf("tot_win_pcent[%d] %.3f\n",j,tot_win_pcent[j]);
//        }
//        for(j=0;j<num_players;j++){
////            MainWindow::show_win_pcent(j,tot_tied_pcent[j]);
////            emit(MainWindow::show_tied_pcent(j,tot_tied_pcent[j]));
////            printf("tot_tied_pcent[%d] %.3f\n",j,tot_tied_pcent[j]);
//        }
//    }
//}
    
////    printf("TIE %Lf\n",tie);
////    printf("tot_tie %.3Lf\n",tot_tie);

////    printf("tot_combos %Lf\n",tot_combos);
////    printf("vamossss\n\n");

//    t_fin = clock();
//    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
//    tot_tiempo+=secs * 1000.0;
//    printf("%.16g milisegundos\n\n", secs * 1000);
//}

void calculate_EQ(int i_player){
    int i,j,k,l,m,n,act_t_r=0;
    char local_board[10];
    long int ii;
    memcpy(local_board, board, 10*sizeof(char));
    int board_01=card_hex_to_int[(local_board[0]*0x10)+local_board[1]];
    int board_02=card_hex_to_int[(local_board[2]*0x10)+local_board[3]];
    int board_03=card_hex_to_int[(local_board[4]*0x10)+local_board[5]];
    int board_04=card_hex_to_int[(local_board[6]*0x10)+local_board[7]];
    int board_05=card_hex_to_int[(local_board[8]*0x10)+local_board[9]];

    if(board[1]==0){
        for(ii=0;ii<NUM_HANDS_PREFLOP;++ii){
            memcpy(local_board,arr_all_boards[ii],10*sizeof(char));
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
//                     printf("valor %x i_player %x\n",HERO_H_VALUES[i_player][ii][n],i_player);
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
        printf("fin bucle %d\n\n",i_player);
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
    char i,j,k,l, m;
    char local_board[10];
    int act_t_r=0;
    if(board[1]==0){
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
            
            local_board[0]=(card_int_to_hex[i]/0x10)%0x10;
            local_board[1]=card_int_to_hex[i]%0x10;
            
            local_board[2]=(card_int_to_hex[j]/0x10)%0x10;
            local_board[3]=card_int_to_hex[j]%0x10;
            
            local_board[4]=(card_int_to_hex[k]/0x10)%0x10;
            local_board[5]=card_int_to_hex[k]%0x10;
            
            local_board[6]=(card_int_to_hex[l]/0x10)%0x10;
            local_board[7]=card_int_to_hex[l]%0x10;
            
            local_board[8]=(card_int_to_hex[m]/0x10)%0x10;
            local_board[9]=card_int_to_hex[m]%0x10;
//             printf("%x%x %x%x %x%x - %x%x - %x%x \n",local_board[0],local_board[1],local_board[2],local_board[3],local_board[4],local_board[5],local_board[6],local_board[7],local_board[8],local_board[9]);
            memcpy(arr_all_boards[act_t_r],local_board,sizeof(char)*10);
            ++act_t_r;
        }
    }
}
#endif // END BOARDS_H
