#include "header.h"
#include "conv_pkr.h"
#include "get_value_combo.h"

//gcc boards.c -lpcre
void main(){
    srand (time(NULL));
//     srand (getpid());
    t_ini = clock();
    init_vars();
    int i=0,i_player=0;
    int j,k;

//     board[0]=0;//h
//     board[1]=8;//A
//     board[2]=2;//s
//     board[3]=0xb;//j
//     board[4]=2;//s
//     board[5]=6;//6
//     board[6]=1;//d
//     board[7]=8;//8
//     board[8]=1;//d
//     board[9]=4;//8

//     int *arr_hex_pos=NULL;
//     arr_hex_pos=(int *)malloc(sizeof(int));//create the space for save arr_hex_return

    char range_pkr[9][5000];
//EN ESTE TARDA 22 SEGUNDOS    
            //ahora falla aqui al faltar solo en river 0.13%
    strcpy(range_pkr[0],"8s8c, 6d6h, 6d6c, 6h6c, AQs+, ATs-A9s, A7s, A5s-A2s, KQs, KTs-K9s, K7s, K5s-K2s, QTs-Q9s, Q7s, Q5s-Q2s, T9s, T7s, T5s-T2s, 97s, 95s-94s, 75s-74s, 54s, AdJd, AhJh, AcJc, KdJd, KhJh, KcJc, QdJd, QhJh, QcJc, JdTd, JhTh, JcTc, Jd9d, Jh9h, Jc9c, As8s, Ac8c, Ks8s, Kc8c, Qs8s, Qc8c, Jc8c, Ts8s, Tc8c, 9s8s, 9c8c, Jd7d, Jh7h, Jc7c, 8s7s, 8c7c, Ad6d, Ah6h, Ac6c, Kd6d, Kh6h, Kc6c, Qd6d, Qh6h, Qc6c, Jd6d, Jh6h, Jc6c, Td6d, Th6h, Tc6c, 9d6d, 9h6h, 9c6c, 8c6c, 7d6d, 7h6h, 7c6c, Jd5d, Jh5h, Jc5c, 8s5s, 8c5c, 6d5d, 6h5h, 6c5c, Jd4d, Jh4h, Jc4c, 8s4s, 8c4c, 6d4d, 6h4h, 6c4c, Jd3d, Jh3h, Jc3c, Jd2d, Jh2h, Jc2c, AQo+, ATo-A9o, A7o, A5o-A2o, KQo, KTo-K9o, K7o, K5o-K2o, QTo-Q9o, Q7o, Q5o-Q4o, T9o, T7o, 97o, AdJh, AdJc, AhJd, AhJc, AsJd, AsJh, AsJc, AcJd, AcJh, Ad8s, Ad8c, Ah8s, Ah8c, As8c, Ac8s, Ad6h, Ad6c, Ah6d, Ah6c, As6d, As6h, As6c, Ac6d, Ac6h, KdJh, KdJc, KhJd, KhJc, KsJd, KsJh, KsJc, KcJd, KcJh, Kd8s, Kd8c, Kh8s, Kh8c, Ks8c, Kc8s, Kd6h, Kd6c, Kh6d, Kh6c, Ks6d, Ks6h, Ks6c, Kc6d, Kc6h, QdJh, QdJc, QhJd, QhJc, QsJd, QsJh, QsJc, QcJd, QcJh, Qd8s, Qd8c, Qh8s, Qh8c, Qs8c, Qc8s, Qd6h, Qd6c, Qh6d, Qh6c, Qs6d, Qs6h, Qs6c, Qc6d, Qc6h, JdTh, JdTs, JdTc, JhTd, JhTs, JhTc, JcTd, JcTh, JcTs, Jd9h, Jd9s, Jd9c, Jh9d, Jh9s, Jh9c, Jc9d, Jc9h, Jc9s, Jd8s, Jd8c, Jh8s, Jh8c, Jc8s, Jd7h, Jd7s, Jd7c, Jh7d, Jh7s, Jh7c, Jc7d, Jc7h, Jc7s, Jd6h, Jd6c, Jh6d, Jh6c, Jc6d, Jc6h, Td8s, Td8c, Th8s, Th8c, Ts8c, Tc8s, Td6h, Td6c, Th6d, Th6c, Ts6d, Ts6h, Ts6c, Tc6d, Tc6h, 9d8s, 9d8c, 9h8s, 9h8c, 9s8c, 9c8s, 8s7d, 8s7h, 8s7c, 8c7d, 8c7h, 8c7s, 8s6d, 8s6h, 8s6c, 8c6d, 8c6h, 7d6h, 7d6c, 7h6d, 7h6c, 7s6d, 7s6h, 7s6c, 7c6d, 7c6h");
    strcpy(range_pkr[1],"77-22, A9s-A2s, K9s-K2s, QTs-Q2s, J2s+, T2s+, 93s+, 84s+, 74s+, 63s+, 53s+, ATo-A2o, K2o+, Q3o+, J5o+, T6o+, 96o+, 86o+, 76o");
//con este se desvia 0.7
/*    strcpy(range_pkr[0],"AQs+");
    strcpy(range_pkr[1],"22")*/;

    //     strcpy(range_pkr[0],"8s8c,6d6h,6d6c");
//     strcpy(range_pkr[1],"77-22,A9s-A2s");

    // i_player to all players
//     i_player=0;
    for(i_player=0;i_player<2;++i_player){
        if(range_pkr[i_player]){
            //the result of this function will be saved in arr_hex_return
            conv_range_pkr_to_hex(range_pkr[i_player],i_player);
            if(long_hex_pos[i_player]>0){
                calculate_EQ(i_player);
            }
        }
    }
    printf("long_hex_pos[0] %d\n",long_hex_pos[0]); 
    printf("long_hex_pos[1] %d\n",long_hex_pos[1]); 
    printf("long_all_boards %d\n",long_all_boards);

    long int tot_combos=0;//total combos analized
    double tot_win_pos[9]={0};//save in each index the result when this position have the highest score
    double tie=0;
    float tot_tie=0;//save here when the hand is tied
    float tot_win_pcent[9];
    long int tot_t_r=0;
    int ii=0;

    for(j=long_all_boards-1;j>=0;--j){
        for(i=(long_hex_pos[0]-1);i>=0;--i){
            if(HERO_H_VALUES[0][j][i]==0) continue;
            for(ii=(long_hex_pos[1]-1);ii>=0;--ii){
                if(
                    HERO_H_VALUES[1][j][ii]==0 ||
                    HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][5] ||
                    HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][6] ||
                    HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][5] ||
                    HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][6]
                    ) {
                    continue;
                }

                if(HERO_H_VALUES[0][j][i]>HERO_H_VALUES[1][j][ii]){
                    ++tot_win_pos[0];
                }else if(HERO_H_VALUES[0][j][i]<HERO_H_VALUES[1][j][ii]){
                    ++tot_win_pos[1];                            
                }else{
                    ++tie;
                }
            }
        }
    }
    
    tot_combos=tot_win_pos[0]+tot_win_pos[1]+tie;
    tot_win_pcent[0]=((tot_win_pos[0]+(tie/2))*100)/tot_combos;
    tot_win_pcent[1]=((tot_win_pos[1]+(tie/2))*100)/tot_combos;
    tot_tie=(tie*100)/tot_combos;

    printf("pos[0] %d\n",(int) tot_win_pos[0]);
    printf("pos[1] %d\n",(int) tot_win_pos[1]);
    printf("TIE %f\n",tie);

    printf("tot_win_pcent[0] %.3f\n",tot_win_pcent[0]);
    printf("tot_win_pcent[1] %.3f\n",tot_win_pcent[1]);
    printf("tot_tie %.3f\n",tot_tie);


    printf("tot_combos %ld\n",tot_combos);
    printf("vamossss\n\n");

    t_fin = clock();
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    tot_tiempo+=secs * 1000.0;
    printf("%.16g milisegundos\n\n", secs * 1000.0);
}

void calculate_EQ(int i_player){
    int i,j,k,l;
    int m,n;
    int local_board[10];
    
    memcpy(local_board, board, 10*sizeof(int));
    int board_01=card_hex_to_int[(local_board[0]*0x10)+local_board[1]];
    int board_02=card_hex_to_int[(local_board[2]*0x10)+local_board[3]];
    int board_03=card_hex_to_int[(local_board[4]*0x10)+local_board[5]];
    int board_04=card_hex_to_int[(local_board[6]*0x10)+local_board[7]];
    int board_05=card_hex_to_int[(local_board[8]*0x10)+local_board[9]];

    
    int local_COMBOS[1326][7];
    memcpy(local_COMBOS, HERO_COMBOS[i_player], 1326*7*sizeof(int));
    int chk_card[4];
    int act_t_r=0;
    int act_long=long_hex_pos[i_player];
    if(local_board[1]==0){
        puts("empiezo el bucle");
            for(i=1;i<48;++i){
                for(j=i+1;j<49;++j){
                    for(k=j+1;k<50;++k){
                        for(l=k+1;l<51;++l){
                            for(m=l+1;m<52;++m){
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
/*                              printf("%x%x %x%x %x%x - %x%x - %x%x / %d %d\n",local_board[0],local_board[1],local_board[2],local_board[3],local_board[4],local_board[5],local_board[6],local_board[7],local_board[8],local_board[9],chk_card[0],chk_card[1]);*/  
                                act_t_r++;
                                
                                for(n=0;n<act_long;++n){
                                    
                                    if(!(local_COMBOS[n][5]!=i && local_COMBOS[n][6]!=i && 
                                        local_COMBOS[n][5]!=j && local_COMBOS[n][6]!=j && 
                                        local_COMBOS[n][5]!=k && local_COMBOS[n][6]!=k && 
                                        local_COMBOS[n][5]!=l && local_COMBOS[n][6]!=l && 
                                        local_COMBOS[n][5]!=m && local_COMBOS[n][6]!=m)) {
                                            continue;
                                    }
                                    if(
                                        
//                 if(
//                     !(local_COMBOS[n][1]==local_board[0] && local_COMBOS[n][2]==local_board[1]) &&
//                     !(local_COMBOS[n][1]==local_board[2] && local_COMBOS[n][2]==local_board[3]) &&
//                     !(local_COMBOS[n][1]==local_board[4] && local_COMBOS[n][2]==local_board[5]) &&
//                     !(local_COMBOS[n][1]==local_board[6] && local_COMBOS[n][2]==local_board[7]) &&
//                     !(local_COMBOS[n][1]==local_board[8] && local_COMBOS[n][2]==local_board[9]) &&
//                     
//                     !(local_COMBOS[n][3]==local_board[0] && local_COMBOS[n][4]==local_board[1]) &&
//                     !(local_COMBOS[n][3]==local_board[2] && local_COMBOS[n][4]==local_board[3]) &&
//                     !(local_COMBOS[n][3]==local_board[4] && local_COMBOS[n][4]==local_board[5]) &&
//                     !(local_COMBOS[n][3]==local_board[8] && local_COMBOS[n][4]==local_board[9]) &&
//                     !(local_COMBOS[n][3]==local_board[6] && local_COMBOS[n][4]==local_board[7])
//                                         
                                        !(local_COMBOS[n][5]==i) && !(local_COMBOS[n][6]==i) &&
                                        !(local_COMBOS[n][5]==j) && !(local_COMBOS[n][6]==j) &&
                                        !(local_COMBOS[n][5]==k) && !(local_COMBOS[n][6]==k) &&
                                        !(local_COMBOS[n][5]==l) && !(local_COMBOS[n][6]==l) &&
                                        !(local_COMBOS[n][5]==m) && !(local_COMBOS[n][6]==m)
                                    ){
                        HERO_H_VALUES[i_player][act_t_r][n]=get_value_combo(local_COMBOS[n],local_board);
                                    }
                                }
                            }
                        }
                    }
                }
            }

        puts("he acabado el bucle");
    }else if(local_board[6]==0 && local_board[7]==0){//turn is empty

        for(i=0;i<51;++i){
            local_board[6]=(card_int_to_hex[i]/0x10)%0x10;
            local_board[7]=card_int_to_hex[i]%0x10;
            if(board_01==i || board_02==i || board_03==i){
                continue;//skip this iteration
            }
            for(j=i+1;j<52;++j){
                local_board[8]=(card_int_to_hex[j]/0x10)%0x10;
                local_board[9]=card_int_to_hex[j]%0x10;

                if(board_01==j || board_02==j || board_03==j){
                    continue;//skip this iteration
                }
                ++act_t_r;
                for(n=0;n<long_hex_pos[i_player];++n){
                    if( local_COMBOS[n][5]!=i && local_COMBOS[n][5]!=j &&
                        local_COMBOS[n][6]!=i && local_COMBOS[n][6]!=j
                    ){
                        HERO_H_VALUES[i_player][act_t_r][n]=get_value_combo(local_COMBOS[n],local_board);
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
                    !(local_COMBOS[n][1]==local_board[8] && local_COMBOS[n][2]==local_board[9]) &&
                    !(local_COMBOS[n][3]==local_board[8] && local_COMBOS[n][4]==local_board[9])
                ){
                HERO_H_VALUES[i_player][act_t_r][n]=get_value_combo(local_COMBOS[n],local_board);
                                        printf("i_player %d score %x\n",i_player,HERO_H_VALUES[i_player][act_t_r][n]);

                }
            }
        }
        long_all_boards=act_t_r;
    }else{//board is all filled
        for(n=0;n<long_hex_pos[i_player];++n){
//             printf("%d %d %x %d\n",m,i_player,HERO_COMBOS[i_player][m],long_hex_pos[i_player]);
            HERO_H_VALUES[i_player][act_t_r][n]=get_value_combo(local_COMBOS[n],local_board);
        }
        long_all_boards=1;
    }
}
