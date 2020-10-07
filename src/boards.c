#include "header.h"
#include "conv_pkr.h"
#include "get_value_combo.h"
// CONTINUAR AVERIGUANDO PORQUE SALE 8.73 Y DEBERIA SALIR 91.27
//gcc boards.c -lpcre
void main(){
    init_vars();
    int i=0;
    int j;
//     board[0]=0;//h
//     board[1]=9;//A
//     board[2]=0;//s
//     board[3]=0xb;//j
//     board[4]=0;//s
//     board[5]=6;//6
//     board[6]=3;//d
//     board[7]=8;//8
//     board[8]=3;//d
//     board[9]=4;//8
    
        board[0]=0;//h
    board[1]=9;//A
    board[2]=2;//s
    board[3]=0xb;//j
    board[4]=2;//s
    board[5]=6;//6
    board[6]=1;//d
    board[7]=8;//8
    board[8]=1;//d
    board[9]=4;//8
// // h9 sJ s6 - d8 - d4 -
// int combo_hex=0x3e07;
// printf("el valor de la mano es: %x\n",get_value_combo(combo_hex,board));
//     return ;
//     board[0]=0;//h
//     board[1]=0xe;//A
//     board[2]=0;//s
//     board[3]=0xd;//j
//     board[4]=0;//s
//     board[5]=0xc;//6
//     board[6]=0;//d
//     board[7]=0xb;//8
//     board[8]=0;//d
//     board[9]=0xa;//8
    
    int *arr_hex_pos0,*arr_hex_pos1;
    
    int long_hex_pos0=0;
    int long_hex_pos1=0;
    //  char range_pkr[]={"AsAc, A2s, Kx,A2s-A9s,33-66,99"};
    //  char range_pkr[]={"88"};   
    
    char *range_pkr1="AQs-A3s,K2s-KQs";
    char *range_pkr2="AA-55";
    
//         char *range_pkr1="2h2c";
//     char *range_pkr2="As7s";
//     printf("%s",range_pkr1);
    if(range_pkr1){
        //the result of this function will be saved in arr_hex_return
        conv_range_pkr_to_hex(range_pkr1);
        i=0;
        while(*(arr_hex_return+i)){
            i++;
        }
        long_hex_pos0=i;
        arr_hex_pos0=malloc(sizeof(int)*long_hex_pos0);//create the space for save arr_hex_return
        memcpy((void *)arr_hex_pos0,arr_hex_return,sizeof(int)*long_hex_pos0);

    }

    if(range_pkr2){
        //the result of this function will be saved in arr_hex_return
        conv_range_pkr_to_hex(range_pkr2);
        i=0;
        while(*(arr_hex_return+i)){
            i++;
        }
        long_hex_pos1=i;
        arr_hex_pos1=malloc(sizeof(int)*long_hex_pos1);//create the space for save arr_hex_return
        memcpy((void *)arr_hex_pos1,arr_hex_return,sizeof(int)*long_hex_pos1);
    }

    for(i=0;i<long_hex_pos0;i++){
        printf("pasado i1 %d hero combos %x\n",i,arr_hex_pos0[i]);
    }
    for(i=0;i<long_hex_pos1;i++){
        printf("pasado i2 %d hero combos %x\n",i,arr_hex_pos1[i]);
    } 
//     
    
//     
    calculate_EQ(arr_hex_pos0,long_hex_pos0,arr_hex_pos1,long_hex_pos1);
    free(arr_hex_pos0);
    free(arr_hex_pos1);
}

void calculate_EQ(int *arr_hex_pos0,int long_hex_pos0, int *arr_hex_pos1,int long_hex_pos1){
    char i,j,k,l,m,n;
    int local_board[10];
    int combo_hex[2][4];

    memcpy(local_board, board, 10*sizeof(int));

    int tot_combos=0;//total combos analized
    float tot_win_pos[9]={0};//save in each index the result when this position have the highest score
    int tie=0;//save here when the hand is tied
    int tmp_val[9]={};//save here the values for compare
    float tot_win_pcent[9];
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
                            
                            for(m=0;m<long_hex_pos0;m++){
                                for(n=0;n<long_hex_pos1;n++){
                                    
                                    combo_hex[0][0]=(*(arr_hex_pos0+m)/0x1000)%0x10;
                                    combo_hex[0][1]=(*(arr_hex_pos0+m)/0x100)%0x10;
                                    combo_hex[0][2]=(*(arr_hex_pos0+m)/0x10)%0x10;
                                    combo_hex[0][3]=*(arr_hex_pos0+m)%0x10;


                                    combo_hex[1][0]=(*(arr_hex_pos1+n)/0x1000)%0x10;
                                    combo_hex[1][1]=(*(arr_hex_pos1+n)/0x100)%0x10;
                                    combo_hex[1][2]=(*(arr_hex_pos1+n)/0x10)%0x10;
                                    combo_hex[1][3]=*(arr_hex_pos1+n)%0x10;

                                    if(
                                        !(combo_hex[0][0]==board[0] && combo_hex[0][1]==board[1]) &&
                                        !(combo_hex[0][2]==board[0] && combo_hex[0][3]==board[1]) &&
                                        !(combo_hex[0][0]==board[2] && combo_hex[0][1]==board[3]) &&
                                        !(combo_hex[0][2]==board[2] && combo_hex[0][3]==board[3]) &&
                                        !(combo_hex[0][0]==board[4] && combo_hex[0][1]==board[5]) &&
                                        !(combo_hex[0][2]==board[4] && combo_hex[0][3]==board[5]) &&
                                        !(combo_hex[0][0]==local_board[6] && combo_hex[0][1]==local_board[7]) &&
                                        !(combo_hex[0][2]==local_board[6] && combo_hex[0][3]==local_board[7]) &&
                                        !(combo_hex[0][0]==local_board[8] && combo_hex[0][1]==local_board[9]) &&
                                        !(combo_hex[0][2]==local_board[8] && combo_hex[0][3]==local_board[9]) &&
                                
                                        !(combo_hex[1][0]==board[0] && combo_hex[1][1]==board[1]) &&
                                        !(combo_hex[1][2]==board[0] && combo_hex[1][3]==board[1]) &&
                                        !(combo_hex[1][0]==board[2] && combo_hex[1][1]==board[3]) &&
                                        !(combo_hex[1][2]==board[2] && combo_hex[1][3]==board[3]) &&
                                        !(combo_hex[1][0]==board[4] && combo_hex[1][1]==board[5]) &&
                                        !(combo_hex[1][2]==board[4] && combo_hex[1][3]==board[5]) &&
                                        !(combo_hex[1][0]==local_board[6] && combo_hex[1][1]==local_board[7]) &&
                                        !(combo_hex[1][2]==local_board[6] && combo_hex[1][3]==local_board[7]) &&
                                        !(combo_hex[1][0]==local_board[8] && combo_hex[1][1]==local_board[9]) &&
                                        !(combo_hex[1][2]==local_board[8] && combo_hex[1][3]==local_board[9]) &&
                                        
                                        !(combo_hex[0][0]==combo_hex[1][0] && combo_hex[0][1]==combo_hex[1][1]) &&
                                        !(combo_hex[0][0]==combo_hex[1][2] && combo_hex[0][3]==combo_hex[1][3]) &&
                                        
                                        !(combo_hex[0][2]==combo_hex[1][0] && combo_hex[0][3]==combo_hex[1][1]) &&
                                        !(combo_hex[0][2]==combo_hex[1][2] && combo_hex[0][3]==combo_hex[1][3]) 

                                    ){
                                        tmp_val[0]=get_value_combo(arr_hex_pos0[m],local_board);
                                        tmp_val[1]=get_value_combo(arr_hex_pos1[n],local_board);

                                        if(tmp_val[0]>tmp_val[1]){
                                            tot_win_pos[0]++;
                                        }else if(tmp_val[0]<tmp_val[1]){
                                            tot_win_pos[1]++;                                        
                                        }else if(tmp_val[0]==tmp_val[1]){
                                            tie++;                                     
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        tot_combos=tot_win_pos[0]+tot_win_pos[1]+tie;
        tot_win_pcent[0]=((tot_win_pos[0]+(tie/2))*100)/tot_combos;
        tot_win_pcent[1]=((tot_win_pos[1]+(tie/2))*100)/tot_combos;

        printf("SIN TURN Y RIVER pos[0] %d\n",(int) tot_win_pos[0]);
        printf("SIN TURN Y RIVER pos[1] %d\n",(int) tot_win_pos[1]);

        printf("tot_win_pcent[0] %.2f\n",tot_win_pcent[0]);
        printf("tot_win_pcent[1] %.2f\n",tot_win_pcent[1]);
        
        printf("tot_combos %d\n",tot_combos);

        
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

                    for(m=0;m<long_hex_pos0;m++){
                        for(n=0;n<long_hex_pos1;n++){
                            combo_hex[0][0]=(*(arr_hex_pos0+m)/0x1000)%0x10;
                            combo_hex[0][1]=(*(arr_hex_pos0+m)/0x100)%0x10;
                            combo_hex[0][2]=(*(arr_hex_pos0+m)/0x10)%0x10;
                            combo_hex[0][3]=*(arr_hex_pos0+m)%0x10;

                            combo_hex[1][0]=(*(arr_hex_pos1+n)/0x1000)%0x10;
                            combo_hex[1][1]=(*(arr_hex_pos1+n)/0x100)%0x10;
                            combo_hex[1][2]=(*(arr_hex_pos1+n)/0x10)%0x10;
                            combo_hex[1][3]=*(arr_hex_pos1+n)%0x10;

                            if(                                
                                !(combo_hex[0][0]==board[0] && combo_hex[0][1]==board[1]) &&
                                !(combo_hex[0][2]==board[0] && combo_hex[0][3]==board[1]) &&
                                !(combo_hex[0][0]==board[2] && combo_hex[0][1]==board[3]) &&
                                !(combo_hex[0][2]==board[2] && combo_hex[0][3]==board[3]) &&
                                !(combo_hex[0][0]==board[4] && combo_hex[0][1]==board[5]) &&
                                !(combo_hex[0][2]==board[4] && combo_hex[0][3]==board[5]) &&
                                !(combo_hex[0][0]==board[6] && combo_hex[0][1]==board[7]) &&
                                !(combo_hex[0][2]==board[6] && combo_hex[0][3]==board[7]) &&
                                !(combo_hex[0][0]==local_board[8] && combo_hex[0][1]==local_board[9]) &&
                                !(combo_hex[0][2]==local_board[8] && combo_hex[0][3]==local_board[9]) &&
                                
                                !(combo_hex[1][0]==board[0] && combo_hex[1][1]==board[1]) &&
                                !(combo_hex[1][2]==board[0] && combo_hex[1][3]==board[1]) &&
                                !(combo_hex[1][0]==board[2] && combo_hex[1][1]==board[3]) &&
                                !(combo_hex[1][2]==board[2] && combo_hex[1][3]==board[3]) &&
                                !(combo_hex[1][0]==board[4] && combo_hex[1][1]==board[5]) &&
                                !(combo_hex[1][2]==board[4] && combo_hex[1][3]==board[5]) &&
                                !(combo_hex[1][0]==board[6] && combo_hex[1][1]==board[7]) &&
                                !(combo_hex[1][2]==board[6] && combo_hex[1][3]==board[7]) &&
                                !(combo_hex[1][0]==local_board[8] && combo_hex[1][1]==local_board[9]) &&
                                !(combo_hex[1][2]==local_board[8] && combo_hex[1][3]==local_board[9]) &&
                                        
                                !(combo_hex[0][0]==combo_hex[1][0] && combo_hex[0][1]==combo_hex[1][1]) &&
                                !(combo_hex[0][0]==combo_hex[1][2] && combo_hex[0][3]==combo_hex[1][3]) &&
                                
                                !(combo_hex[0][2]==combo_hex[1][0] && combo_hex[0][3]==combo_hex[1][1]) &&
                                !(combo_hex[0][2]==combo_hex[1][2] && combo_hex[0][3]==combo_hex[1][3]) 
                            ){
                                tmp_val[0]=get_value_combo(arr_hex_pos0[m],local_board);
                                tmp_val[1]=get_value_combo(arr_hex_pos1[n],local_board);

//                                 printf("pos 0 %x\n",tmp_val[0]);
//                                 printf("pos 1 %x\n",tmp_val[1]);

                                if(tmp_val[0]>tmp_val[1]){
//                                     puts("gana 0");
                                    tot_win_pos[0]++;
                                }else if(tmp_val[0]<tmp_val[1]){
//                                     puts("gana 1");
                                    tot_win_pos[1]++;                                        
                                }else if(tmp_val[0]==tmp_val[1]){
                                    tie++;                                     
                                }
                            }
                        }
                    }
                }
            }
        }
        tot_combos=tot_win_pos[0]+tot_win_pos[1]+tie;
        tot_win_pcent[0]=((tot_win_pos[0]+(tie/2))*100)/tot_combos;
        tot_win_pcent[1]=((tot_win_pos[1]+(tie/2))*100)/tot_combos;

        printf("SIN RIVER pos[0] %d\n",(int) tot_win_pos[0]);
        printf("SIN RIVER pos[1] %d\n",(int) tot_win_pos[1]);

        printf("tot_win_pcent[0] %.2f\n",tot_win_pcent[0]);
        printf("tot_win_pcent[1] %.2f\n",tot_win_pcent[1]);
        
        printf("tot_combos %d\n",tot_combos);

        
    }else{//board is all filled
        for(m=0;m<long_hex_pos0;m++){
            for(n=0;n<long_hex_pos1;n++){
                combo_hex[0][0]=(*(arr_hex_pos0+m)/0x1000)%0x10;
                combo_hex[0][1]=(*(arr_hex_pos0+m)/0x100)%0x10;
                combo_hex[0][2]=(*(arr_hex_pos0+m)/0x10)%0x10;
                combo_hex[0][3]=*(arr_hex_pos0+m)%0x10;

                combo_hex[1][0]=(*(arr_hex_pos1+n)/0x1000)%0x10;
                combo_hex[1][1]=(*(arr_hex_pos1+n)/0x100)%0x10;
                combo_hex[1][2]=(*(arr_hex_pos1+n)/0x10)%0x10;
                combo_hex[1][3]=*(arr_hex_pos1+n)%0x10;
                if(                                
                    !(combo_hex[0][0]==board[0] && combo_hex[0][1]==board[1]) &&
                    !(combo_hex[0][2]==board[0] && combo_hex[0][3]==board[1]) &&
                    !(combo_hex[0][0]==board[2] && combo_hex[0][1]==board[3]) &&
                    !(combo_hex[0][2]==board[2] && combo_hex[0][3]==board[3]) &&
                    !(combo_hex[0][0]==board[4] && combo_hex[0][1]==board[5]) &&
                    !(combo_hex[0][2]==board[4] && combo_hex[0][3]==board[5]) &&
                    !(combo_hex[0][0]==board[6] && combo_hex[0][1]==board[7]) &&
                    !(combo_hex[0][2]==board[6] && combo_hex[0][3]==board[7]) &&
                    !(combo_hex[0][0]==board[8] && combo_hex[0][1]==board[9]) &&
                    !(combo_hex[0][2]==board[8] && combo_hex[0][3]==board[9]) &&
                    
                    !(combo_hex[1][0]==board[0] && combo_hex[1][1]==board[1]) &&
                    !(combo_hex[1][2]==board[0] && combo_hex[1][3]==board[1]) &&
                    !(combo_hex[1][0]==board[2] && combo_hex[1][1]==board[3]) &&
                    !(combo_hex[1][2]==board[2] && combo_hex[1][3]==board[3]) &&
                    !(combo_hex[1][0]==board[4] && combo_hex[1][1]==board[5]) &&
                    !(combo_hex[1][2]==board[4] && combo_hex[1][3]==board[5]) &&
                    !(combo_hex[1][0]==board[6] && combo_hex[1][1]==board[7]) &&
                    !(combo_hex[1][2]==board[6] && combo_hex[1][3]==board[7]) &&
                    !(combo_hex[1][0]==board[8] && combo_hex[1][1]==board[9]) &&
                    !(combo_hex[1][2]==board[8] && combo_hex[1][3]==board[9]) &&
                    
                    !(combo_hex[0][0]==combo_hex[1][0] && combo_hex[0][1]==combo_hex[1][1]) &&
                    !(combo_hex[0][0]==combo_hex[1][2] && combo_hex[0][3]==combo_hex[1][3]) &&
                    
                    !(combo_hex[0][2]==combo_hex[1][0] && combo_hex[0][3]==combo_hex[1][1]) &&
                    !(combo_hex[0][2]==combo_hex[1][2] && combo_hex[0][3]==combo_hex[1][3]) 
                ){
                    tmp_val[0]=get_value_combo(arr_hex_pos0[m],local_board);
//                     printf("%x\n",tmp_val[0]);
                    tmp_val[1]=get_value_combo(arr_hex_pos1[n],local_board);
//                     printf("%x\n",tmp_val[1]);
            //         printf("pos 0 %x\n",tmp_val[0]);
            //         printf("pos 1 %x\n",tmp_val[1]);
                    if(tmp_val[0]>tmp_val[1]){
            //             puts("gana 0");
                        tot_win_pos[0]++;
                    }else if(tmp_val[0]<tmp_val[1]){
            //             puts("gana 1");
                        tot_win_pos[1]++;                                        
                    }else if(tmp_val[0]==tmp_val[1]){
                        tie++;                                     
                    }
//                     tot_combos++;
                }//end if
            }//end for
        }//end for
        tot_combos=tot_win_pos[0]+tot_win_pos[1]+tie;
        tot_win_pcent[0]=((tot_win_pos[0]+(tie/2))*100)/tot_combos;
        tot_win_pcent[1]=((tot_win_pos[1]+(tie/2))*100)/tot_combos;

        printf("SHOWDOWN pos[0] %d\n",(int) tot_win_pos[0]);
        printf("SHOWDOWN pos[1] %d\n",(int) tot_win_pos[1]);

        printf("tot_win_pcent[0] %.2f\n",tot_win_pcent[0]);
        printf("tot_win_pcent[1] %.2f\n",tot_win_pcent[1]);
        
        printf("tot_combos %d\n",tot_combos);
    }
}
