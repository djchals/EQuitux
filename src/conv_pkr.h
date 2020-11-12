void conv_range_pkr_to_hex(char tmp_range[],int i_player){
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
    const int NUM_REGEX=10;
    char regex[NUM_REGEX][100];
    strcpy(regex[0],"^([23456789TJQKA]){1}([schd]){1}([23456789TJQKA]){1}([schd]){1}$");// -> 8d9c, KsJs...
    strcpy(regex[1],"^(22|33|44|55|66|77|88|99|TT|JJ|QQ|KK|AA){1}-(?!\\1)(22|33|44|55|66|77|88|99|TT|JJ|QQ|KK|AA){1}$");//AA-99
    strcpy(regex[2],"^([23456789TJQKA]{1})((?!\\1)[23456789TJQKA]{1})(s|o)?-\\1((?!\\2)[23456789TJQKA]{1})\\3$");//A2s-A8s,T9o-TJo
    strcpy(regex[3],"^([23456789TJQKA]{1})((?!\\1)[23456789TJQKA]{1})-(\\1)((?!\\2)[23456789TJQKA]{1})$");//A2-A8,T9-TJ,85-89    

    strcpy(regex[4],"^([23456789TJQKA]{1})((?!\\1)[23456789TJQKA]{1})(s|o|)?\\+$");//A2s+, T8+, T8o+,..
    strcpy(regex[5],"^([23456789TJQKA]{1})((?!\\1)[23456789TJQKA]{1})(s|o|)?$");//A2s, T8,..
    strcpy(regex[6],"^(22|33|44|55|66|77|88|99|TT|JJ|QQ|KK){1}\\+$");//22+ until KK+
    strcpy(regex[7],"^([23456789TJQKA]{1})x$");//7x, Kx...
    strcpy(regex[8],"^(22|33|44|55|66|77|88|99|TT|JJ|QQ|KK|AA){1}$");//AA,KK,88...
    strcpy(regex[9],"^(?:\\b|-)([1-9]{1,2}[0]?|100)\\b%{1}$");//1-100%

    /* for pcre_compile */
    pcre *re=NULL;

    const char *error=NULL;

    error=(char *)malloc(3);//dont do nothing with the regex errors

    int erroffset;

    /* for pcre_exec */
    int rc;

    int ovector[1024];//with this we count the maximum "," in range_pkr

    /* to get substrings from regex */
    int rc2;

    char *substring=NULL;
    substring=(char *)malloc(sizeof(char)*7);

    bool flag_exit_loop;

    char ch_pkr[7],k,l,ch_cmp0,ch_cmp1,ch_cmp2;

    int tmp_hex;
    int array_combos_marked_hex[MAX_COMBO_HEX]={};//now we fill this array with the combos, for not repeat combos

    char flag_suited=0;
    int cont=0,i_in,i_fin;

    //now start processing regex1
    char *searching_here=NULL;

    searching_here=(char*) malloc(sizeof(char)*3700);

    strcpy(searching_here,strtok(range_pkr, ","));

    while(searching_here!=NULL){//loop through the string to extract all other searching_heres
        flag_exit_loop=false;
        for(i=0;i<NUM_REGEX;i++){
//             printf("regex para analizar: %s\n",regex[i]);
            re=pcre_compile(regex[i], 0, &error, &erroffset, NULL);
//                 printf("i %d antes searching_here: =%s=\n",i,searching_here);
            rc=pcre_exec(re, NULL, searching_here, strlen(searching_here), 0, 0, ovector, 60000);//60000 is the maximum matches          
            if(rc!=PCRE_ERROR_NOMATCH && rc>=0){
//                 printf("i %d despues searching_here: =%s=\n",i,searching_here);
//                 printf("rc: =%d=\n",rc);
                // printf("ovector: =%n=\n",ovector);
                // loop through matches and return them
                rc2 = pcre_get_substring(searching_here, ovector, rc, 0, (const char**) &substring);
//                 printf("rc2: =%d=\n",rc2);
//                 printf("substring: =%s=\n",substring);
                strcpy(ch_pkr,substring);
                switch(i){
                    case 0://8d9c, KsJs...
                        ch_cmp0=arr_let_to_int[ch_pkr[0]];
                        ch_cmp1=arr_let_to_int[ch_pkr[2]];
                        if(ch_cmp1>ch_cmp0){
                            i_in=ch_cmp1;
                            i_fin=ch_cmp0;
                        }else{
                            i_in=ch_cmp0;
                            i_fin=ch_cmp1;
                        }
                        //if the cards and suits are not equal we sum the combo
                        if(!(i_in==i_fin && arr_suit_to_int[ch_pkr[1]]==arr_suit_to_int[ch_pkr[3]])){//
                            // tmp_hex=ch_cmp0*0x1000+arr_suit_to_int[ch_pkr[1]]*0x100+ch_cmp1*0x10+arr_suit_to_int[ch_pkr[3]];
                            tmp_hex=(arr_suit_to_int[ch_pkr[1]]*0x1000)+(i_in*0x100)+(arr_suit_to_int[ch_pkr[3]]*0x10)+i_fin;
                            
                            if(!array_combos_marked_hex[reverse_hex(tmp_hex)] && check_combo_ok_vs_board(arr_suit_to_int[ch_pkr[1]],i_in,arr_suit_to_int[ch_pkr[3]],i_fin)){
                                array_combos_marked_hex[tmp_hex]=1;
                                cont++;
                            }
                        }
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
                                        tmp_hex=(k*0x1000)+(j*0x100)+(l*0x10)+j;

                                        if(!array_combos_marked_hex[reverse_hex(tmp_hex)] && check_combo_ok_vs_board(k,j,l,j)){
                                            array_combos_marked_hex[tmp_hex]=1;
                                            cont++;
                                        }
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        break;
                    case 2://A2s-A8s,T9o-TJo 
                    case 3://85-89
                        ch_cmp0=arr_let_to_int[ch_pkr[0]];
                        ch_cmp1=arr_let_to_int[ch_pkr[1]];
                        if(ch_pkr[2]=='s' && ch_pkr[3]=='-' && ch_pkr[6]=='s'){
                            flag_suited=1;//suited
                            ch_cmp2=arr_let_to_int[ch_pkr[5]];
                        }else if(ch_pkr[2]=='o' && ch_pkr[3]=='-' && ch_pkr[6]=='o'){
                            flag_suited=2;//offsuited
                            ch_cmp2=arr_let_to_int[ch_pkr[5]];
                        }else if(ch_pkr[2]=='-'){//suited && offsuited
                            flag_suited=0;
                            ch_cmp2=arr_let_to_int[ch_pkr[4]];
                        }
                        if(ch_cmp1<ch_cmp2){
                            i_in=ch_cmp1;
                            i_fin=ch_cmp2;
                        }else {
                            i_in=ch_cmp2;
                            i_fin=ch_cmp1;
                        }
                        for(j=i_in;j<=i_fin;j++){
                            for(k=0;k<4;k++){
                                for(l=0;l<4;l++){
                                    if( 
                                        !(ch_cmp0==j && l==k) 
                                        &&
                                        (   flag_suited==0 ||
                                            (flag_suited==1 && l==k) || 
                                            (flag_suited==2 && l!=k)
                                        )
                                    ){
                                        tmp_hex=(k*0x1000)+(ch_cmp0*0x100)+(l*0x10)+j;
                                        if(!array_combos_marked_hex[reverse_hex(tmp_hex)] && check_combo_ok_vs_board(k,ch_cmp0,l,j)!=0){
                                            array_combos_marked_hex[tmp_hex]=1;
                                            cont++;
                                        }
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        break;
                    case 4://A2s+, T8+, T8o+,..
                        ch_cmp0=arr_let_to_int[ch_pkr[0]];
                        ch_cmp1=arr_let_to_int[ch_pkr[1]];    
                        switch(ch_pkr[2]){
                            case 's':
                                flag_suited=1;//suited
                                break;
                            case 'o':
                                flag_suited=2;//offsuited
                                break;
                            default:
                                flag_suited=0;//suited & offsuited
                                break;
                        }
                        if(ch_cmp0>ch_cmp1){
                            i_in=ch_cmp1;
                            i_fin=ch_cmp0;
                        }else if(ch_cmp0<ch_cmp1){
                            i_in=ch_cmp0;
                            i_fin=ch_cmp1;                            
                        }
                        for(j=i_in;j<i_fin;j++){
                            for(k=0;k<4;k++){
                                for(l=0;l<4;l++){
                                    if( 
                                        !(i_fin==j && l==k) 
                                        &&
                                        (
                                            flag_suited==0 ||
                                            (flag_suited==1 && l==k) || 
                                            (flag_suited==2 && l!=k)
                                        )
                                    ){
                                        tmp_hex=(k*0x1000)+(i_fin*0x100)+(l*0x10)+j;    
                                        if(!array_combos_marked_hex[reverse_hex(tmp_hex)] && check_combo_ok_vs_board(k,i_fin,l,j)!=0){
                                            array_combos_marked_hex[tmp_hex]=1;
                                            cont++;
                                        }
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        break;
                    case 5://A2s, T8,..
                        ch_cmp0=arr_let_to_int[ch_pkr[0]];
                        ch_cmp1=arr_let_to_int[ch_pkr[1]];
                        if(ch_cmp0>ch_cmp1){
                            i_in=ch_cmp0;
                            i_fin=ch_cmp1;
                        }else{
                            i_in=ch_cmp1;
                            i_fin=ch_cmp2;
                        }
                        switch(ch_pkr[2]){
                            case 's':
                                flag_suited=1;//suited
                                break;
                            case 'o':
                                flag_suited=2;//offsuited
                                break;
                            default:
                                flag_suited=0;//suited & offsuited
                                break;
                        }
                        for(k=0;k<4;k++){
                            for(l=0;l<4;l++){
                                if( 
                                    flag_suited==0 ||
                                    (flag_suited==1 && l==k) || 
                                    (flag_suited==2 && l!=k)
                                ){
                                    tmp_hex=(k*0x1000)+(i_in*0x100)+(l*0x10)+i_fin;
                                    if(!array_combos_marked_hex[reverse_hex(tmp_hex)] && check_combo_ok_vs_board(k,i_in,l,i_fin)!=0){
                                        array_combos_marked_hex[tmp_hex]=1;
                                        cont++;
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        break;
                    case 6://22+ until KK+
                        i_in=arr_let_to_int[ch_pkr[0]];
                        for(j=i_in;j<=0x0e;j++){
                            for(k=0;k<4;k++){
                                for(l=0;l<4;l++){
                                    if(l!=k){//is a pocket pair
                                        tmp_hex=(k*0x1000)+(j*0x100)+(l*0x10)+j;
                                        if(!array_combos_marked_hex[reverse_hex(tmp_hex)] && check_combo_ok_vs_board(k,j,l,j)){
                                            array_combos_marked_hex[tmp_hex]=1;
                                            cont++;
                                        }
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        break;
                    case 7://7x, Kx...
                        ch_cmp0=arr_let_to_int[ch_pkr[0]];

                        for(j=2;j<ch_cmp0;j++){//stop before arrive to pocket pair 
                            for(k=0;k<4;k++){
                                for(l=0;l<4;l++){
                                    if(!(ch_cmp0==j && l==k)){
                                        tmp_hex=(k*0x1000)+(ch_cmp0*0x100)+(l*0x10)+j;
                                        if(!array_combos_marked_hex[reverse_hex(tmp_hex)] && check_combo_ok_vs_board(k,ch_cmp0,l,j)){
                                            array_combos_marked_hex[tmp_hex]=1;
                                            cont++;
                                        }
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        break;
                    case 8://AA,KK,88..
                        ch_cmp0=arr_let_to_int[ch_pkr[0]];
                        ch_cmp1=arr_let_to_int[ch_pkr[1]];
                        for(k=0;k<4;k++){
                            for(l=0;l<4;l++){
                                if(l!=k){//is a pocket pair
                                    tmp_hex=(k*0x1000)+(ch_cmp0*0x100)+(l*0x10)+ch_cmp1;
                                    if(!array_combos_marked_hex[reverse_hex(tmp_hex)] && check_combo_ok_vs_board(k,ch_cmp0,l,ch_cmp1)){
                                        array_combos_marked_hex[tmp_hex]=1;
                                        cont++;
                                    }
                                }
                            }
                        }
                        flag_exit_loop=true;
                        break;
                    case 9://1-100%
                        //THIS PART IS PENDING
                        flag_exit_loop=true;
                        break;
                    
                    }
                    flag_suited=0;//for if the flies
                    
            }//end if
//             printf("end if\n");
            re=NULL;
            if(flag_exit_loop){
                break;
            }

        }//end for
        searching_here=strtok(NULL,",");
    }//end while
    pcre_free(re);
    pcre_free_substring(substring);

    free(searching_here);

//     int arr_local_return[cont];//now we make the array with only the combos marked.
    j=0;

    for(i=0;i<MAX_COMBO_HEX;i++){
        if(array_combos_marked_hex[i]==0) continue; 

        HERO_COMBOS[i_player][j][0]=i;
        // printf("%x\n",HERO_COMBOS[i_player][j][0]);
        HERO_COMBOS[i_player][j][1]=(i/0x1000)%0x10;
        HERO_COMBOS[i_player][j][2]=(i/0x100)%0x10;
        HERO_COMBOS[i_player][j][3]=(i/0x10)%0x10;
        HERO_COMBOS[i_player][j][4]=i%0x10;

        HERO_COMBOS[i_player][j][5]=card_hex_to_int[(i/0x100)];
        HERO_COMBOS[i_player][j][6]=card_hex_to_int[i%0x100];
        j++;
    }
//     arr_local_return[j]=(int) 0x0000;//mark the last for know where is the end

//     for(i=0;i<j;i++){
//         printf("dentro %x\n",arr_local_return[i]);
//     }
// arr_hex_return=arr_local_return;
    long_hex_pos[i_player]=j;
//     arr_hex_return=(int *) malloc(sizeof(arr_local_return));
//     memcpy(arr_hex_return,arr_local_return,sizeof(arr_local_return));
//     printf("esto es arr_local_return: %d\n",sizeof(arr_local_return));
//         printf("esto es arr_hex_return: %d\n",sizeof(arr_hex_return));
//     printf("esto es j: %d\n",j);
//     printf("esto es cont: %d\n",cont);
//     printf("j*sizeof: %d\n",sizeof(int) * j);

//     arr_hex_return=malloc(sizeof(int) * j);
//     memcpy(arr_hex_return,arr_local_return,j);
//     free(tmp_range);
//     free(regex);

}
int reverse_hex(int tmp_hex){
    //check if the combo is already inserted
    int hex[4];
    hex[0]=(tmp_hex/0x1000)%0x10;
    hex[1]=(tmp_hex/0x100)%0x10;
    hex[2]=(tmp_hex/0x10)%0x10;
    hex[3]=tmp_hex%0x10;
    return (hex[2]*0x1000)+(hex[3]*0x100)+(hex[0]*0x10)+hex[1];
}
int check_combo_ok_vs_board(int ch0,int ch1,int ch2,int ch3){
    if( /*!(ch0==ch2 && ch1==ch3) && is not needed because we check above*/
//     printf("ch: %x%x%x%x board: %x%x %x%x %x%x - %x%x - %x%x\n",ch0,ch1,ch2,ch3,board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],board[9]);
        board[1]==0 //we are in preflop mode 
        || 
        (
            !(ch0==board[0] && ch1==board[1]) &&
            !(ch0==board[2] && ch1==board[3]) &&
            !(ch0==board[4] && ch1==board[5]) &&
            !(ch0==board[6] && ch1==board[7]) &&
            !(ch0==board[8] && ch1==board[9]) &&
            
            !(ch2==board[0] && ch3==board[1]) &&
            !(ch2==board[2] && ch3==board[3]) &&
            !(ch2==board[4] && ch3==board[5]) &&
            !(ch2==board[6] && ch3==board[7]) &&
            !(ch2==board[8] && ch3==board[9])
        )
    ){
       return 1;//combo is ok
    }else{
        return 0;//combo is ko
    }
}
