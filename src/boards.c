#include "header.h"
#include "conv_pkr.h"
#include "get_value_combo.h"

//gcc boards.c -lpcre
void main(){
    t_ini = clock();

    init_vars();
    int i=0,i_player=0;
    int j,k;

    board[0]=0;//h
    board[1]=8;//A
    board[2]=2;//s
    board[3]=0xb;//j
    board[4]=2;//s
    board[5]=6;//6
//     board[6]=1;//d
//     board[7]=8;//8
//     board[8]=1;//d
//     board[9]=4;//8

    int *arr_hex_pos=NULL;
    arr_hex_pos=(int *)malloc(sizeof(int));//create the space for save arr_hex_return

    int long_hex_pos[9];
    char range_pkr[9][5000];
    
    strcpy(range_pkr[0],"QQ+, TT-99, 77, 55-22, JdJh, JdJc, JhJc, 8s8c, 6d6h, 6d6c, 6h6c, AQs+, ATs-A9s, A7s, A5s-A2s, KQs, KTs-K9s, K7s, K5s-K2s, QTs-Q9s, Q7s, Q5s-Q2s, T9s, T7s, T5s-T2s, 97s, 95s-94s, 75s-74s, 54s, AdJd, AhJh, AcJc, KdJd, KhJh, KcJc, QdJd, QhJh, QcJc, JdTd, JhTh, JcTc, Jd9d, Jh9h, Jc9c, As8s, Ac8c, Ks8s, Kc8c, Qs8s, Qc8c, Jc8c, Ts8s, Tc8c, 9s8s, 9c8c, Jd7d, Jh7h, Jc7c, 8s7s, 8c7c, Ad6d, Ah6h, Ac6c, Kd6d, Kh6h, Kc6c, Qd6d, Qh6h, Qc6c, Jd6d, Jh6h, Jc6c, Td6d, Th6h, Tc6c, 9d6d, 9h6h, 9c6c, 8c6c, 7d6d, 7h6h, 7c6c, Jd5d, Jh5h, Jc5c, 8s5s, 8c5c, 6d5d, 6h5h, 6c5c, Jd4d, Jh4h, Jc4c, 8s4s, 8c4c, 6d4d, 6h4h, 6c4c, Jd3d, Jh3h, Jc3c, Jd2d, Jh2h, Jc2c, AQo+, ATo-A9o, A7o, A5o-A2o, KQo, KTo-K9o, K7o, K5o-K2o, QTo-Q9o, Q7o, Q5o-Q4o, T9o, T7o, 97o, AdJh, AdJc, AhJd, AhJc, AsJd, AsJh, AsJc, AcJd, AcJh, Ad8s, Ad8c, Ah8s, Ah8c, As8c, Ac8s, Ad6h, Ad6c, Ah6d, Ah6c, As6d, As6h, As6c, Ac6d, Ac6h, KdJh, KdJc, KhJd, KhJc, KsJd, KsJh, KsJc, KcJd, KcJh, Kd8s, Kd8c, Kh8s, Kh8c, Ks8c, Kc8s, Kd6h, Kd6c, Kh6d, Kh6c, Ks6d, Ks6h, Ks6c, Kc6d, Kc6h, QdJh, QdJc, QhJd, QhJc, QsJd, QsJh, QsJc, QcJd, QcJh, Qd8s, Qd8c, Qh8s, Qh8c, Qs8c, Qc8s, Qd6h, Qd6c, Qh6d, Qh6c, Qs6d, Qs6h, Qs6c, Qc6d, Qc6h, JdTh, JdTs, JdTc, JhTd, JhTs, JhTc, JcTd, JcTh, JcTs, Jd9h, Jd9s, Jd9c, Jh9d, Jh9s, Jh9c, Jc9d, Jc9h, Jc9s, Jd8s, Jd8c, Jh8s, Jh8c, Jc8s, Jd7h, Jd7s, Jd7c, Jh7d, Jh7s, Jh7c, Jc7d, Jc7h, Jc7s, Jd6h, Jd6c, Jh6d, Jh6c, Jc6d, Jc6h, Td8s, Td8c, Th8s, Th8c, Ts8c, Tc8s, Td6h, Td6c, Th6d, Th6c, Ts6d, Ts6h, Ts6c, Tc6d, Tc6h, 9d8s, 9d8c, 9h8s, 9h8c, 9s8c, 9c8s, 8s7d, 8s7h, 8s7c, 8c7d, 8c7h, 8c7s, 8s6d, 8s6h, 8s6c, 8c6d, 8c6h, 7d6h, 7d6c, 7h6d, 7h6c, 7s6d, 7s6h, 7s6c, 7c6d, 7c6h");
    strcpy(range_pkr[1],"66");
    

    // i_player to all players
//     i_player=0;
    for(i_player=0;i_player<2;i_player++){
        if(range_pkr[i_player]){
            arr_hex_return=NULL;
            arr_hex_pos=NULL;
            //the result of this function will be saved in arr_hex_return
            conv_range_pkr_to_hex(range_pkr[i_player]);
            long_hex_pos[i_player]=long_hex_return;
            if(long_hex_pos[i_player]>0){
                arr_hex_pos= (int *)realloc(arr_hex_pos,long_hex_pos[i_player]*sizeof(int));
                memcpy((void *)arr_hex_pos,arr_hex_return,sizeof(int)*long_hex_pos[i_player]);
                calculate_EQ(arr_hex_pos,long_hex_pos[i_player],i_player);
            }
        }
    }
    //free the memory.
    arr_hex_pos=NULL;
    arr_hex_return=NULL;
    free(arr_hex_pos);
    free(arr_hex_return);
    //

    printf("long_hex_pos %d",long_hex_pos[0]); 
    
    int last_t_r=0;
    if(board[6]==0 && board[7]==0){
        last_t_r=2704;//turn and river are blank
    }else if(board[8]==0 && board[9]==0){
        last_t_r=52;//river is blank    
    }else{
        last_t_r=1;//all the board is filled
    }

    int tot_combos=0;//total combos analized
    float tot_win_pos[9]={0};//save in each index the result when this position have the highest score
    float tie=0,tot_tie=0;//save here when the hand is tied
    float tot_win_pcent[9];
    int ii=0;   
    for(j=0;j<last_t_r;j++){
        for(i=0;i<long_hex_pos[0];i++){
//             printf("%x%x %x%x %x%x - %x%x - %x%x\n",board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],board[9]);
//                 printf("\tHERO_COMBOS[0] %x\n",HERO_COMBOS[0][j][i]);
            if(HERO_H_VALUES[0][j][i]>0){
                for(ii=0;ii<long_hex_pos[1];ii++){
                    if(HERO_H_VALUES[1][j][ii]>0 && chk_no_repeated_cards(HERO_COMBOS[0][j][i], HERO_COMBOS[1][j][ii])){
//                         printf("\tHERO_COMBOS[1] %x\n",HERO_COMBOS[1][j][ii]);
// 
//                         printf("\t\tHERO_H_VALUES[0] %x\n",HERO_H_VALUES[0][j][i]);
//                         printf("\t\tHERO_H_VALUES[1] %x\n",HERO_H_VALUES[1][j][ii]);

                        if(HERO_H_VALUES[0][j][i]>HERO_H_VALUES[1][j][ii]){
//                             printf("\t\tWIN 0\n");
                            tot_win_pos[0]++;
                        }else if(HERO_H_VALUES[0][j][i]<HERO_H_VALUES[1][j][ii]){
//                             printf("\t\tWIN 1\n");
                            tot_win_pos[1]++;                            
                        }else{
//                             printf("\t\tTIE\n");
                            tie++;
                        }
                    }
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


    printf("tot_combos %d\n",tot_combos);
    printf("vamossss\n\n");



    t_fin = clock();
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    tot_tiempo+=secs * 1000.0;
    printf("%.16g milisegundos\n\n", secs * 1000.0);
}

void calculate_EQ(int *arr_hex_pos0,int long_hex_pos0,int i_player){
    char i,j,k,l;
    int m;
    int local_board[10];
    
    memcpy(local_board, board, 10*sizeof(int));
    int chk_card[4];
    int act_t_r=0;

    if(local_board[1]==0){
        //all the board is empty
    }else if(local_board[6]==0 && local_board[7]==0){//turn is empty
        for(i=0;i<4;i++){
            for(j=2;j<=14;j++){
                for(k=0;k<4;k++){
                    for(l=2;l<=14;l++){
                        if( !(i==k && j==l) &&
                            !(board[0]==i && board[1]==j) &&
                            !(board[2]==i && board[3]==j) &&
                            !(board[4]==i && board[5]==j) &&
                            
                            !(board[0]==k && board[1]==l) &&
                            !(board[2]==k && board[3]==l) &&
                            !(board[4]==k && board[5]==l)
                        ){
                            local_board[6]=i;
                            local_board[7]=j;
                            local_board[8]=k;
                            local_board[9]=l;
                                                
                            act_t_r++;
                            for(m=0;m<long_hex_pos0;m++){
                                chk_card[0]=(*(arr_hex_pos0+m)/0x1000)%0x10;
                                chk_card[1]=(*(arr_hex_pos0+m)/0x100)%0x10;
                                chk_card[2]=(*(arr_hex_pos0+m)/0x10)%0x10;
                                chk_card[3]=*(arr_hex_pos0+m)%0x10;

                                HERO_COMBOS[i_player][act_t_r][m]=(i*0x10000000)+(j*0x1000000)+(k*0x100000)+(l*0x10000)+arr_hex_pos0[m];

                                if(
                                    !(chk_card[0]==local_board[6] && chk_card[1]==local_board[7]) &&
                                    !(chk_card[0]==local_board[8] && chk_card[1]==local_board[9]) &&
                                    !(chk_card[2]==local_board[8] && chk_card[3]==local_board[9]) &&
                                    !(chk_card[2]==local_board[6] && chk_card[3]==local_board[7])
                                ){
                                    HERO_H_VALUES[i_player][act_t_r][m]=get_value_combo(arr_hex_pos0[m],local_board);
                                }else{
                                    HERO_H_VALUES[i_player][act_t_r][m]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(local_board[8]==0 && local_board[9]==0){//river is empty
        for(k=0;k<4;k++){
            for(l=2;l<=14;l++){
                if(
                    !(board[0]==k && board[1]==l) &&
                    !(board[2]==k && board[3]==l) &&
                    !(board[4]==k && board[5]==l) &&
                    !(board[6]==k && board[7]==l)
                ){
                    local_board[8]=k;
                    local_board[9]=l;

                    act_t_r++;
                    for(m=0;m<long_hex_pos0;m++){
                        chk_card[0]=(*(arr_hex_pos0+m)/0x1000)%0x10;
                        chk_card[1]=(*(arr_hex_pos0+m)/0x100)%0x10;
                        chk_card[2]=(*(arr_hex_pos0+m)/0x10)%0x10;
                        chk_card[3]=*(arr_hex_pos0+m)%0x10;

                        HERO_COMBOS[i_player][act_t_r][m]=(k*0x100000)+(l*0x10000)+arr_hex_pos0[m];
                        if(                                
                            !(chk_card[0]==local_board[8] && chk_card[1]==local_board[9]) &&
                            !(chk_card[2]==local_board[8] && chk_card[3]==local_board[9])
                        ){
                            HERO_H_VALUES[i_player][act_t_r][m]=get_value_combo(arr_hex_pos0[m],local_board);
                        }else{
                            HERO_H_VALUES[i_player][act_t_r][m]=0;
                        }
                    }
                }
            }
        }
    }else{//board is all filled
        for(m=0;m<long_hex_pos0;m++){
//             printf("%d %d %x %d\n",m,i_player,arr_hex_pos0[m],long_hex_pos0);
            HERO_H_VALUES[i_player][0][m]=get_value_combo(arr_hex_pos0[m],local_board);
            HERO_COMBOS[i_player][0][m]=arr_hex_pos0[m];
        }
        
    }
    free(arr_hex_pos0);
}

int chk_no_repeated_cards(int num1, int num2){
    int digits[2][4];

    digits[0][0]=(num1/0x1000)%0x10;
    digits[0][1]=(num1/0x100)%0x10;
    digits[0][2]=(num1/0x10)%0x10;
    digits[0][3]=num1%0x10;

    digits[1][0]=(num2/0x1000)%0x10;
    digits[1][1]=(num2/0x100)%0x10;
    digits[1][2]=(num2/0x10)%0x10;
    digits[1][3]=num2%0x10;
    
    if(
        !(digits[0][0]==digits[1][0] && digits[0][1]==digits[1][1]) &&
        !(digits[0][0]==digits[1][2] && digits[0][1]==digits[1][3]) &&
        
        !(digits[0][2]==digits[1][0] && digits[0][3]==digits[1][1]) &&
        !(digits[0][2]==digits[1][2] && digits[0][3]==digits[1][3])
    ){
        return 1;
    }else{
        return 0;
    }
}
