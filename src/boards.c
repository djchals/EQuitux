#include "header.h"
#include "conv_pkr.h"
#include "get_value_combo.h"
// CONTINUAR AVERIGUANDO PORQUE SALE 8.73 Y DEBERIA SALIR 91.27
//gcc boards.c -lpcre
void main(){
    init_vars();
    int i=0;
    int j;

    board[0]=0;//h
    board[1]=9;//A
    board[2]=2;//s
    board[3]=0xb;//j
    board[4]=2;//s
    board[5]=6;//6
//     board[6]=1;//d
//     board[7]=8;//8
//     board[8]=1;//d
//     board[9]=4;//8

        int *arr_hex_pos1=NULL;
        int *arr_hex_pos0=NULL;

    int long_hex_pos0;
    int long_hex_pos1;
    //  char range_pkr[]={"AsAc, A2s, Kx,A2s-A9s,33-66,99"};
    //  char range_pkr[]={"88"};   
    
//     char *range_pkr1="AJs,A9s-A8s,A6s";
//este no pasa    char range_pkr1[]="KK-33, AQs-A3s, KJs-K3s, QTs-Q3s, J9s-J3s, T8s-T3s, 97s-93s, 86s-83s, 75s-73s, 64s-63s, 53s";
// char range_pkr2[]="AQs-A3s, KJs-K3s, 22-AA";

        /*esta combinacion da bien
         *     board[0]=0;//h
    board[1]=9;//A
    board[2]=2;//s
    board[3]=0xb;//j
    board[4]=2;//s
    board[5]=6;//6
    board[6]=1;//d
    board[7]=8;//8
    board[8]=1;//d
    board[9]=4;//8
        char range_pkr2[]="AA-55,AQs-A2s";
        char range_pkr1[]="AA-22";
        */
        
    /*esta combinacion da MAL, se desvia 0.15
         *     board[0]=0;//h
        AHORA YA CUENTA BIENLOS COMBOS ENLOSDOS SENTIDOS
    board[1]=9;//A
    board[2]=2;//s
    board[3]=0xb;//j
    board[4]=2;//s
    board[5]=6;//6
    board[6]=1;//d
    board[7]=8;//8
    board[8]=1;//d
    board[9]=4;//8
    
YA SALEN EN PARALELO PERO SE DESVIA MÁS

y si las pongo al reves se desvia 0.6
        */
//     char range_pkr1[]="AQs-A2s";
//         char range_pkr1[]="AA,KK,QQ, TT, 77, 55, AQs, ATs, A7s, A5s, A3s-A2s, AdJd, AhJh, AcJc, JdJh, JdJc, JhJc, Ad9d, As9s, Ac9c, 9d9s, 9d9c, 9s9c, Ah8h, As8s, Ac8c, 8h8s, 8h8c, 8s8c, Ad6d, Ah6h, Ac6c, 6d6h, 6d6c, 6h6c, Ah4h, As4s, Ac4c";
//         char range_pkr1[]="AA-55,AQs,AJs,ATs,A9s,A8s,A7s,A6s,A5s,A4s,A3s,A2s";
        
// SIGUE DESVIÁNDOSE, AHORA UN 5%
         char range_pkr1[]="AA-55,AQs,AJs,ATs,A9s,A8s,A7s,A6s,A5s,A4s,A3s,A2s";
        char range_pkr2[]="AA-22,KQs,KJs,KTs,K9s";
//         char range_pkr2[]="AA,KK,QQ,JJ,TT,99,88,77,66,55";
//         char range_pkr1[]="AQs-A3s,K2s-KQs";
//     char range_pkr1[]="A3s,A4s,A5s,A6s,A7s,A8s,A9s,ATs,AJs,AQs,K2s,K3s,K4s,K5s,K6s,K7s,K8s,K9s,KTs,KJs,KQs";
    
//         char *range_pkr1="AJs,A9s-A8s,A6s";
    
//         char *range_pkr1="2h2c";
//     char *range_pkr2="As7s";
//     printf("%s",range_pkr1);
//     int *arr_hex_pos0=NULL;
    if(range_pkr1){
        puts("dentro 1");
        //the result of this function will be saved in arr_hex_return
        conv_range_pkr_to_hex(range_pkr1);
        long_hex_pos0=long_hex_return;
        arr_hex_pos0=(int *)malloc(sizeof(int)*long_hex_pos0);//create the space for save arr_hex_return
        memcpy((void *)arr_hex_pos0,arr_hex_return,sizeof(int)*long_hex_pos0);
    }
    printf("long %d",long_hex_return);
    if(range_pkr2){
        puts("dentro 2");
        //the result of this function will be saved in arr_hex_return
        conv_range_pkr_to_hex(range_pkr2);
        long_hex_pos1=long_hex_return;
        arr_hex_pos1=(int *)malloc(sizeof(int)*long_hex_pos1);//create the space for save arr_hex_return
        memcpy((void *)arr_hex_pos1,arr_hex_return,sizeof(int)*long_hex_pos1);
    }
    
//     for(i=0;i<long_hex_pos0;i++){
//         printf("pasado i1 %d hero combos %x\n",i,arr_hex_pos0[i]);
//     }
//         for(i=0;i<long_hex_pos1;i++){
//             printf("pasado i2 %d hero combos %x\n",i,arr_hex_pos1[i]);
//         } 

    //     
    
//     
//     return;
    calculate_EQ(arr_hex_pos0,long_hex_pos0,arr_hex_pos1,long_hex_pos1);
//     free(arr_hex_pos0);
//     free(arr_hex_pos1);
//         free(range_pkr1);
//         free(range_pkr2);
//     free(arr_hex_return);
}

void calculate_EQ(int *arr_hex_pos0,int long_hex_pos0, int *arr_hex_pos1,int long_hex_pos1){
    char i,j,k,l,m,n;
    int local_board[10];
    int combo_hex[2][4];

    memcpy(local_board, board, 10*sizeof(int));

    int tot_combos=0;//total combos analized
    float tot_win_pos[9]={0};//save in each index the result when this position have the highest score
    float tie=0,tot_tie=0;//save here when the hand is tied
    int tmp_val[9]={};//save here the values for compare
    float tot_win_pcent[9];
    
    long int cont_1=0;
    long int cont_2=0;
    int cont_3=0;
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
                                        !(combo_hex[0][0]==local_board[6] && combo_hex[0][1]==local_board[7]) &&
                                        !(combo_hex[0][0]==local_board[8] && combo_hex[0][1]==local_board[9]) &&
                                        !(combo_hex[0][2]==local_board[8] && combo_hex[0][3]==local_board[9]) &&
                                        !(combo_hex[0][2]==local_board[6] && combo_hex[0][3]==local_board[7]) &&

                                        !(combo_hex[1][0]==local_board[6] && combo_hex[1][1]==local_board[7]) &&
                                        !(combo_hex[1][0]==local_board[8] && combo_hex[1][1]==local_board[9]) &&
                                        !(combo_hex[1][2]==local_board[8] && combo_hex[1][3]==local_board[9]) &&
                                        !(combo_hex[1][2]==local_board[6] && combo_hex[1][3]==local_board[7]) &&
                                        
                                        !(combo_hex[0][0]==combo_hex[1][0] && combo_hex[0][1]==combo_hex[1][1]) &&
                                        !(combo_hex[0][0]==combo_hex[1][2] && combo_hex[0][1]==combo_hex[1][3]) &&
                                        
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
                                !(combo_hex[0][0]==local_board[8] && combo_hex[0][1]==local_board[9]) &&
                                !(combo_hex[0][2]==local_board[8] && combo_hex[0][3]==local_board[9]) &&
                                
                                !(combo_hex[1][0]==local_board[8] && combo_hex[1][1]==local_board[9]) &&
                                !(combo_hex[1][2]==local_board[8] && combo_hex[1][3]==local_board[9]) &&
                                        
                                !(combo_hex[0][0]==combo_hex[1][0] && combo_hex[0][1]==combo_hex[1][1]) &&
                                !(combo_hex[0][0]==combo_hex[1][2] && combo_hex[0][1]==combo_hex[1][3]) &&
                                
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
        tot_tie=(tie*100)/tot_combos;
        
        printf("SIN RIVER pos[0] %d\n",(int) tot_win_pos[0]);
        printf("SIN RIVER pos[1] %d\n",(int) tot_win_pos[1]);
        printf("TIE %f\n",tie);

        printf("tot_win_pcent[0] %.3f\n",tot_win_pcent[0]);
        printf("tot_win_pcent[1] %.3f\n",tot_win_pcent[1]);
        printf("tot_tie %.3f\n",tot_tie);

        
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
                    !(combo_hex[0][0]==combo_hex[1][0] && combo_hex[0][1]==combo_hex[1][1]) &&
                    !(combo_hex[0][0]==combo_hex[1][2] && combo_hex[0][1]==combo_hex[1][3]) &&
                    
                    !(combo_hex[0][2]==combo_hex[1][0] && combo_hex[0][3]==combo_hex[1][1]) &&
                    !(combo_hex[0][2]==combo_hex[1][2] && combo_hex[0][3]==combo_hex[1][3]) 
                ){
//                 printf("%x%x%x%x %x%x%x%x\n",combo_hex[0][0],combo_hex[0][1],combo_hex[0][2],combo_hex[0][3],combo_hex[1][0],combo_hex[1][1],combo_hex[1][2],combo_hex[1][3]);
                    tmp_val[0]=get_value_combo(arr_hex_pos0[m],local_board);
                    tmp_val[1]=get_value_combo(arr_hex_pos1[n],local_board);
//                 printf("valor 0 %x\n",tmp_val[0]);
//                 printf("valor 1 %x\n",tmp_val[1]);
                    if(tmp_val[0]>tmp_val[1]){
//                         puts("gana 0");
                        tot_win_pos[0]++;
                        cont_1+=tot_win_pos[0];
                    }else if(tmp_val[0]<tmp_val[1]){
//                         puts("gana 1");
                        tot_win_pos[1]++;                                        
                        cont_2+=tot_win_pos[1];

                        
                    }else if(tmp_val[0]==tmp_val[1]){
//                         puts("empate");
                        
                        tie++;                                     
                    }
//                 printf("\n");
                    tot_combos++;
                    cont_3++;
                }//end if
                else{
//                     printf("NO: %x%x%x%x %x%x%x%x\n",combo_hex[0][0],combo_hex[0][1],combo_hex[0][2],combo_hex[0][3],combo_hex[1][0],combo_hex[1][1],combo_hex[1][2],combo_hex[1][3]);
                }
            }//end for
//             printf("m: %d n: %d\n",m,n);
        }//end for
        tot_combos=tot_win_pos[0]+tot_win_pos[1]+tie;
        tot_win_pcent[0]=((tot_win_pos[0]+(tie/2))*100)/tot_combos;
        tot_win_pcent[1]=((tot_win_pos[1]+(tie/2))*100)/tot_combos;
        tot_tie=(tie*100)/tot_combos;

        printf("SHOWDOWN pos[0] %d\n",(int) tot_win_pos[0]);
        printf("SHOWDOWN pos[1] %d\n",(int) tot_win_pos[1]);

        printf("TIE %f\n",tie);

        printf("tot_win_pcent[0] %.2f\n",tot_win_pcent[0]);
        printf("tot_win_pcent[1] %.2f\n",tot_win_pcent[1]);
        
        printf("tot_combos %d\n",tot_combos);
        printf("tot_tie %.3f\n",tot_tie);
 
        printf("cont_1 %ld\n",cont_1);
        printf("cont_2 %ld\n",cont_2);

        printf("veces que he pasado por el if %d\n",cont_3);      
    }
    free(arr_hex_pos0);
    free(arr_hex_pos1);
}
