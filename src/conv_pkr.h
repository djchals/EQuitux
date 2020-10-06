#include <stdio.h>
#include <pcre.h>
#include <string.h>
#include <math.h>
#include "header.h"

//gcc poker.c -lpcre
int conv_range_pkr_to_hex(char *tmp_range);

// 0 corazón
// 1 diamante
// 2 pica
// 3 trébol
// 23456789ABCDE
// 23456789TJQKA

int conv_range_pkr_to_hex(char *tmp_range){
    
// int *arr_let_to_int;
// arr_let_to_int=malloc(sizeof(int)*82);
// memset(arr_let_to_int,0,82);

    //Format the string extracting the spaces
    int j=0,i,tmp_long=strlen(tmp_range);
    char range_pkr[tmp_long];
    
    for(i=0;i<tmp_long;i++){
        if(tmp_range[i]!=32){
            range_pkr[j]=tmp_range[i];
//             printf("range_pkr[j] %x\n",range_pkr[j]);
            j++;
        }
    }
    range_pkr[j]=0;//end the string
    //
    //These are the regex for make the hexadecimal combos 
    char *regex[7];
    regex[0]="^([23456789TJQKA]){1}([schd]){1}([23456789TJQKA]){1}([schd]){1}$";// -> 8d9c, KsJs...
    regex[1]="^(22|33|44|55|66|77|88|99|TT|JJ|QQ|KK|AA){1}-(?!\\1)(22|33|44|55|66|77|88|99|TT|JJ|QQ|KK|AA){1}$";//AA-99
    regex[2]="^([23456789TJQKA]{1})((?!\\1)[23456789TJQKA]{1})(s|)?-\\1((?!\\2)[23456789TJQKA]{1})\\3$";//A2s-A8s,T9-TJ,85-89    
    regex[3]="^([23456789TJQKA]{1})((?!\\1)[23456789TJQKA]{1})(s|)?$";//A2s, T8,..
    regex[4]="^([23456789TJQKA]{1})(s|)x$";//7x, Kxs ...
    regex[5]="^(22|33|44|55|66|77|88|99|TT|JJ|QQ|KK|AA){1}$";//AA,KK,88...
    regex[6]="^(?:\\b|-)([1-9]{1,2}[0]?|100)\\b%{1}$";//1-100%
    

    /* for pcre_compile */
    pcre *re;
    const char *error;
    int erroffset;

    /* for pcre_exec */
    int rc;
    int ovector[30];

    /* to get substrings from regex */
    int rc2;
    char *substring;

    //now start processing regex1
    char *token=strtok(range_pkr, ",");
    bool flag_exit_loop;
//     int *array_combo_hex[];
    char ch_pkr[7];
    int tmp_hex,k,l,ch_cmp0,ch_cmp1,ch_cmp2;
    int array_combos_marked_hex[MAX_COMBO_HEX]={};//now we fill this array with the combos, for not repeat combos
    bool flag_suited=false;
    int cont=0,i_in,i_fin;
    while(token!=NULL){//loop through the string to extract all other tokens
        flag_exit_loop=false;
        for(i=0;i<7;i++){
//             printf("regex para analizar: %s\n",regex[i]);
            re=pcre_compile(regex[i], 0, &error, &erroffset, NULL);
            rc=pcre_exec(re, NULL, token, strlen(token), 0, 0, ovector, 30);          

            if(rc == PCRE_ERROR_NOMATCH){
//                 fprintf(stderr,"no match\n");
            }else if(rc < -1) {
//                 fprintf(stderr,"error %d from regex\n",rc);
            }else{
//                 
//             if(rc!=PCRE_ERROR_NOMATCH && rc>=0){
//                 printf("token: =%s=\n",token);
                // loop through matches and return them
                rc2 = pcre_get_substring(token, ovector, rc, 0, (const char**) &substring);
                strcpy(ch_pkr,substring);
                switch(i){
                    case 0://8d9c, KsJs...
                        ch_cmp0=arr_let_to_int[ch_pkr[0]];
                        ch_cmp1=arr_let_to_int[ch_pkr[2]];
                        
                        //if the cards and suits are not equal we sum the combo
                        if(!(ch_cmp0==ch_cmp1 && arr_suit_to_int[ch_pkr[1]]==arr_suit_to_int[ch_pkr[3]])){//
// tmp_hex=ch_cmp0*0x1000+arr_suit_to_int[ch_pkr[1]]*0x100+ch_cmp1*0x10+arr_suit_to_int[ch_pkr[3]];
tmp_hex=(arr_suit_to_int[ch_pkr[1]]*0x1000)+(ch_cmp0*0x100)+(arr_suit_to_int[ch_pkr[3]]*0x10)+ch_cmp1;
                            
                            
                            
                            
                            if(!array_combos_marked_hex[reverse_hex(tmp_hex)]){
                                array_combos_marked_hex[tmp_hex]=1;
                                cont++;
                            }
                        }
                        // 0 corazón
                        // 1 diamante
                        // 2 pica
                        // 3 trébol
                        // 23456789ABCDE
                        // 23456789TJQKA
                        flag_exit_loop=true;
                        break;
                    case 1://AA-99
                        ch_cmp1=arr_let_to_int[ch_pkr[0]];
                        ch_cmp2=arr_let_to_int[ch_pkr[3]];
                        
                        if(ch_cmp1<ch_cmp2){
                            i_in=ch_cmp1;
                            i_fin=ch_cmp2;
                        }else{
                            i_in=ch_cmp2;
                            i_fin=ch_cmp1;
                        }
                        for(j=i_in;j<=i_fin;j++){
                            for(k=0;k<4;k++){
                                for(l=0;l<4;l++){
                                    if(k!=l){//is a pocket pair
//tmp_hex=(j*0x1000)+(k*0x100)+(j*0x10)+l;
tmp_hex=(k*0x1000)+(j*0x100)+(l*0x10)+j;

                                        if(!array_combos_marked_hex[reverse_hex(tmp_hex)]){
                                            array_combos_marked_hex[tmp_hex]=1;
                                            cont++;
                                        }
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        break;
                    case 2://A2s-A8s,T9-TJ,85-89 
                        ch_cmp0=arr_let_to_int[ch_pkr[0]];
                        ch_cmp1=arr_let_to_int[ch_pkr[1]];
                        
                        if(ch_pkr[2]=='s' && ch_pkr[3]=='-' && ch_pkr[6]=='s'){
                            flag_suited=true;
                            ch_cmp2=arr_let_to_int[ch_pkr[5]];
                        }else if(ch_pkr[2]=='-'){//no suited
                            flag_suited=false;
                            ch_cmp2=arr_let_to_int[ch_pkr[4]];
                        }
                        if(ch_cmp1<ch_cmp2){
                            i_in=ch_cmp1;
                            i_fin=ch_cmp2;
                        }else{
                            i_in=ch_cmp2;
                            i_fin=ch_cmp1;
                        }
                        for(j=i_in;j<=i_fin;j++){
                            for(k=0;k<4;k++){
                                for(l=0;l<4;l++){
                                    if((!flag_suited || (flag_suited && l==k)) && (ch_cmp0!=j && l==k)){
// tmp_hex=(ch_cmp0*0x1000)+(k*0x100)+(j*0x10)+l;
tmp_hex=(k*0x1000)+(ch_cmp0*0x100)+(l*0x10)+j;
                                        if(!array_combos_marked_hex[reverse_hex(tmp_hex)]){
                                            array_combos_marked_hex[tmp_hex]=1;
                                            cont++;
                                        }
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        flag_suited=false;                     
                        break;
                    case 3://A2s, T8,..
                        flag_suited=(ch_pkr[2]=='s');//if true is suited, if false not
                        for(k=0;k<4;k++){
                            for(l=0;l<4;l++){
                                if(!flag_suited || (flag_suited && l==k)){
// tmp_hex=(arr_let_to_int[ch_pkr[0]]*0x1000)+(k*0x100)+(arr_let_to_int[ch_pkr[1]]*0x10)+l;
tmp_hex=(k*0x1000)+(arr_let_to_int[ch_pkr[0]]*0x100)+(l*0x10)+arr_let_to_int[ch_pkr[1]];
                                    if(!array_combos_marked_hex[reverse_hex(tmp_hex)]){
                                        array_combos_marked_hex[tmp_hex]=1;
                                        cont++;
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        break;
                    case 4://7x, Ksx ...
                        ch_cmp1=arr_let_to_int[ch_pkr[0]];
                        flag_suited=(ch_pkr[1]=='s');//if true is suited, if false not
                        for(j=2;j<=0x0e;j++){
                            for(k=0;k<4;k++){
                                for(l=0;l<4;l++){
                                    if((!flag_suited || (flag_suited && l==k)) && (ch_cmp1!=j && l==k)){
// tmp_hex=(arr_let_to_int[ch_pkr[0]]*0x1000)+(k*0x100)+(j*0x10)+l;
tmp_hex=(k*0x1000)+(arr_let_to_int[ch_pkr[0]]*0x100)+(l*0x10)+j;
                                        if(!array_combos_marked_hex[reverse_hex(tmp_hex)]){
                                            array_combos_marked_hex[tmp_hex]=1;
                                            cont++;
                                        }
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        flag_exit_loop=true;
                        break;
                    case 5://AA,KK,88..
                            for(k=0;k<4;k++){
                            for(l=0;l<4;l++){
                                if(l!=k){//is a pocket pair
// tmp_hex=(arr_let_to_int[ch_pkr[0]]*0x1000)+(k*0x100)+(arr_let_to_int[ch_pkr[1]]*0x10)+l;
tmp_hex=(k*0x1000)+(arr_let_to_int[ch_pkr[0]]*0x100)+(l*0x10)+arr_let_to_int[ch_pkr[1]];
                                    if(!array_combos_marked_hex[reverse_hex(tmp_hex)]){
                                        array_combos_marked_hex[tmp_hex]=1;
                                        cont++;
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        break;
                    case 6://1-100%
                        //THIS PART IS PENDING
//                         printf("i %d %s\n",i,substring);
                        flag_exit_loop=true;
                        break;
                    
                }
            } 
            if(flag_exit_loop){
                break;
            }

        }//end for
        token=strtok(NULL,",");
    }//end while
    pcre_free(re);
    
    int arr_local_return[cont];//now we make the array with only the combos marked.
    j=0;

    for(i=0;i<MAX_COMBO_HEX;i++){
        if(array_combos_marked_hex[i]!=0){
//             printf("i %x j %d\n",i,j);
            arr_local_return[j]=(int) i;
            j++;
        }
    }
    arr_local_return[j]=(int) 0x0000;//mark the last for know where is the end

//     for(i=0;i<j;i++){
//         printf("dentro %x\n",arr_local_return[i]);
//     }
//     
    arr_hex_return=arr_local_return;
}
int reverse_hex(int tmp_hex){
    //check if the combo is already inserted
    int first_card=ceil(tmp_hex/0x100);
    int second_card=tmp_hex-first_card*0x100;
    return (second_card*0x100)+first_card;
}
