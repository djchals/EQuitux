//init the vars
long double tot_combos=0;//total combos analized
long double tot_win_pos[6]={};//save in each index the result when this position have the highest score
long double tot_tied_pos[6]={};
float tot_win_pcent[6]={};
float tot_tied_pcent[6]={};
long double tie=0;
long double tot_tie=0;//save here when the hand is tied
//

void calculate_all(int num_players,int restart_vars){
    //init the function vars
    if(restart_vars){
        tot_combos=0;
        memset(tot_win_pos,0,sizeof(long double)*6);
        memset(tot_tied_pos,0,sizeof(long double)*6);
        tie=0;
        tot_tie=0;
    }
    int k,j,i,ii,iii,iiii,iiiii,iiiiii;
    int arr_values[6];
    int max=0,i_max=0;
    float flag_tied;
    bool flag_switch_passed=false;
    //
    switch(num_players){
        case 2:
            for(j=0;j<=long_all_boards;j++){
                for(i=0;i<long_hex_pos[0];++i){
                    if(HERO_H_VALUES[0][j][i]==0) continue;
                    for(ii=0;ii<long_hex_pos[1];++ii){
                        if(
                            HERO_H_VALUES[1][j][ii]==0 ||
                            HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][5] ||
                            HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][6] ||
                            HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][5] ||
                            HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][6]
                        ){
                            continue;
                        }     
                        tot_combos++;
                        //the routine when have just 2 players is different than 3 players, because I think that is more simple.
                        if(HERO_H_VALUES[0][j][i]>HERO_H_VALUES[1][j][ii]){
                            ++tot_win_pos[0];
                        }else if(HERO_H_VALUES[1][j][ii]>HERO_H_VALUES[0][j][i]){
                            ++tot_win_pos[1];                            
                        }else{
                            tot_win_pos[0]=tot_win_pos[0]+0.5;
                            tot_win_pos[1]=tot_win_pos[1]+0.5;
                            tot_tied_pos[0]=tot_tied_pos[0]+0.5;
                            tot_tied_pos[1]=tot_tied_pos[1]+0.5;
                        }
                        //
                    }
                }
            }
            flag_switch_passed=true;
            break;
        case 3:
            for(j=0;j<=long_all_boards;j++){
                for(i=0;i<long_hex_pos[0];++i){
                    if(HERO_H_VALUES[0][j][i]==0) continue;
                    arr_values[0]=HERO_H_VALUES[0][j][i];
                    for(ii=0;ii<long_hex_pos[1];++ii){
                        if(
                            HERO_H_VALUES[1][j][ii]==0 ||
                            HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][5] ||
                            HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][6] ||
                            HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][5] ||
                            HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][6]
                        ){
                            continue;
                        }
                        arr_values[1]=HERO_H_VALUES[1][j][ii];
                        for(iii=0;iii<long_hex_pos[2];++iii){
                            if(
                                HERO_H_VALUES[2][j][iii]==0 ||
                                HERO_COMBOS[0][i][5]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[0][i][5]==HERO_COMBOS[2][iii][6] ||
                                HERO_COMBOS[0][i][6]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[0][i][6]==HERO_COMBOS[2][iii][6] ||

                                HERO_COMBOS[1][ii][5]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[1][ii][5]==HERO_COMBOS[2][iii][6] ||
                                HERO_COMBOS[1][ii][6]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[1][ii][6]==HERO_COMBOS[2][iii][6]
                            ){
                                continue;
                            }  
                            arr_values[2]=HERO_H_VALUES[2][j][iii];
                            
                            max=0;
                            i_max=0;
                            flag_tied=1;
                            for(k=0;k<num_players;++k){
                                if(arr_values[k]>max){
                                    max=arr_values[k];
                                    i_max=k;
                                    flag_tied=1;//this is the max value, and for now dont have tied values
                                }else if(arr_values[k]==max){
                                    flag_tied++;
                                }
                            }
                            tot_combos++;
                            if(flag_tied==1){
                                tot_win_pos[i_max]++;
                                continue;//end loop here
                            }
                            //if we are here, we are in the tied case
                            tie++;
                            //tie possibilities
                            for(k=0;k<num_players;++k){
                                if(arr_values[k]==max){
                                    tot_win_pos[k]=tot_win_pos[k]+(1/flag_tied);
                                    tot_tied_pos[k]=tot_tied_pos[k]+(1/flag_tied);
                                }
                            }
                        }
                    }
                }
            }
            flag_switch_passed=true;
            break;
        case 4:
            for(j=0;j<=long_all_boards;j++){
                for(i=0;i<long_hex_pos[0];++i){
                    if(HERO_H_VALUES[0][j][i]==0) continue;
                    arr_values[0]=HERO_H_VALUES[0][j][i];
                    for(ii=0;ii<long_hex_pos[1];++ii){
                        if(
                            HERO_H_VALUES[1][j][ii]==0 ||
                            HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][5] ||
                            HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][6] ||
                            HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][5] ||
                            HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][6]
                        ){
                            continue;
                        }
                        arr_values[1]=HERO_H_VALUES[1][j][ii];
                        for(iii=0;iii<long_hex_pos[2];++iii){
                            if(
                                HERO_H_VALUES[2][j][iii]==0 ||
                                HERO_COMBOS[0][i][5]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[0][i][5]==HERO_COMBOS[2][iii][6] ||
                                HERO_COMBOS[0][i][6]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[0][i][6]==HERO_COMBOS[2][iii][6] ||

                                HERO_COMBOS[1][ii][5]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[1][ii][5]==HERO_COMBOS[2][iii][6] ||
                                HERO_COMBOS[1][ii][6]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[1][ii][6]==HERO_COMBOS[2][iii][6]
                            ){
                                continue;
                            }
                            arr_values[2]=HERO_H_VALUES[2][j][iii];
                            for(iiii=0;iiii<long_hex_pos[3];++iiii){
                                if(
                                    HERO_H_VALUES[3][j][iiii]==0 ||
                                    HERO_COMBOS[0][i][5]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[0][i][5]==HERO_COMBOS[3][iiii][6] ||
                                    HERO_COMBOS[0][i][6]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[0][i][6]==HERO_COMBOS[3][iiii][6] ||

                                    HERO_COMBOS[1][ii][5]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[1][ii][5]==HERO_COMBOS[3][iiii][6] ||
                                    HERO_COMBOS[1][ii][6]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[1][ii][6]==HERO_COMBOS[3][iiii][6] ||
                                    
                                    HERO_COMBOS[2][iii][5]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[2][iii][5]==HERO_COMBOS[3][iiii][6] ||
                                    HERO_COMBOS[2][iii][6]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[2][iii][6]==HERO_COMBOS[3][iiii][6]
                                ){
                                    continue;
                                }
                                arr_values[3]=HERO_H_VALUES[3][j][iiii];

                                max=0;
                                i_max=0;
                                flag_tied=1;
                                for(k=0;k<num_players;++k){
                                    if(arr_values[k]>max){
                                        max=arr_values[k];
                                        i_max=k;
                                        flag_tied=1;//this is the max value, and for now dont have tied values
                                    }else if(arr_values[k]==max){
                                        flag_tied++;
                                    }
                                }
                                tot_combos++;
                                //if is 1, there are not two players with the same max value
                                if(flag_tied==1){
                                    tot_win_pos[i_max]++;
                                    continue;//end loop here
                                }
                                tie++;
                                //tie possibilities
                                for(k=0;k<num_players;++k){
                                    if(arr_values[k]==max){
                                        tot_win_pos[k]=tot_win_pos[k]+(1/flag_tied);
                                        tot_tied_pos[k]=tot_tied_pos[k]+(1/flag_tied);
                                    }
                                }
                            }//end for iiii
                        }//end for iii
                    }//end for ii
                }//end for ii
            }//end for i
            flag_switch_passed=true;
            break;
        case 5:
            for(j=0;j<=long_all_boards;j++){
                for(i=0;i<long_hex_pos[0];++i){
                    if(HERO_H_VALUES[0][j][i]==0) continue;
                    arr_values[0]=HERO_H_VALUES[0][j][i];
                    for(ii=0;ii<long_hex_pos[1];++ii){
                        if(
                            HERO_H_VALUES[1][j][ii]==0 ||
                            HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][5] ||
                            HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][6] ||
                            HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][5] ||
                            HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][6]
                        ){
                            continue;
                        }
                        arr_values[1]=HERO_H_VALUES[1][j][ii];
                        for(iii=0;iii<long_hex_pos[2];++iii){
                            if(
                                HERO_H_VALUES[2][j][iii]==0 ||
                                HERO_COMBOS[0][i][5]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[0][i][5]==HERO_COMBOS[2][iii][6] ||
                                HERO_COMBOS[0][i][6]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[0][i][6]==HERO_COMBOS[2][iii][6] ||

                                HERO_COMBOS[1][ii][5]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[1][ii][5]==HERO_COMBOS[2][iii][6] ||
                                HERO_COMBOS[1][ii][6]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[1][ii][6]==HERO_COMBOS[2][iii][6]
                            ){
                                continue;
                            }
                            arr_values[2]=HERO_H_VALUES[2][j][iii];
                            for(iiii=0;iiii<long_hex_pos[3];++iiii){
                                if(
                                    HERO_H_VALUES[3][j][iiii]==0 ||
                                    HERO_COMBOS[0][i][5]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[0][i][5]==HERO_COMBOS[3][iiii][6] ||
                                    HERO_COMBOS[0][i][6]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[0][i][6]==HERO_COMBOS[3][iiii][6] ||

                                    HERO_COMBOS[1][ii][5]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[1][ii][5]==HERO_COMBOS[3][iiii][6] ||
                                    HERO_COMBOS[1][ii][6]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[1][ii][6]==HERO_COMBOS[3][iiii][6] ||
                                    
                                    HERO_COMBOS[2][iii][5]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[2][iii][5]==HERO_COMBOS[3][iiii][6] ||
                                    HERO_COMBOS[2][iii][6]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[2][iii][6]==HERO_COMBOS[3][iiii][6]
                                ){
                                    continue;
                                }
                                arr_values[3]=HERO_H_VALUES[3][j][iiii];
                                for(iiiii=0;iiiii<long_hex_pos[4];++iiiii){
                                    if(
                                        HERO_H_VALUES[4][j][iiiii]==0 ||
                                        HERO_COMBOS[0][i][5]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[0][i][5]==HERO_COMBOS[4][iiiii][6] ||
                                        HERO_COMBOS[0][i][6]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[0][i][6]==HERO_COMBOS[4][iiiii][6] ||

                                        HERO_COMBOS[1][ii][5]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[1][ii][5]==HERO_COMBOS[4][iiiii][6] ||
                                        HERO_COMBOS[1][ii][6]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[1][ii][6]==HERO_COMBOS[4][iiiii][6] ||
                                        
                                        HERO_COMBOS[2][iii][5]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[2][iii][5]==HERO_COMBOS[4][iiiii][6] ||
                                        HERO_COMBOS[2][iii][6]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[2][iii][6]==HERO_COMBOS[4][iiiii][6] ||
                                        
                                        HERO_COMBOS[3][iiii][5]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[3][iiii][5]==HERO_COMBOS[4][iiiii][6] ||
                                        HERO_COMBOS[3][iiii][6]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[3][iiii][6]==HERO_COMBOS[4][iiiii][6]
                                        
                                    ){
                                        continue;
                                    }
                                    arr_values[4]=HERO_H_VALUES[4][j][iiiii];
                                    max=0;
                                    i_max=0;
                                    flag_tied=1;
                                    for(k=0;k<num_players;++k){
                                        if(arr_values[k]>max){
                                            max=arr_values[k];
                                            i_max=k;
                                            flag_tied=1;//this is the max value, and for now dont have tied values
                                        }else if(arr_values[k]==max){
                                            flag_tied++;
                                        }
                                    }
                                    tot_combos++;
                                    //if is 1, there are not two players with the same max value
                                    if(flag_tied==1){
                                        tot_win_pos[i_max]++;
                                        continue;//end loop here
                                    }
                                    tie++;
                                    //tie possibilities
                                    for(k=0;k<num_players;++k){
                                        if(arr_values[k]==max){
                                            tot_win_pos[k]=tot_win_pos[k]+(1/flag_tied);
                                            tot_tied_pos[k]=tot_tied_pos[k]+(1/flag_tied);
                                        }
                                    }
                                }//end for iiiii
                            }//end for iiii
                        }//end for iii
                    }//end for ii
                }//end for ii
            }//end for i
            flag_switch_passed=true;
            break;
        case 6:
            for(j=0;j<=long_all_boards;j++){
                for(i=0;i<long_hex_pos[0];++i){
                    if(HERO_H_VALUES[0][j][i]==0) continue;
                    arr_values[0]=HERO_H_VALUES[0][j][i];
                    for(ii=0;ii<long_hex_pos[1];++ii){
                        if(
                            HERO_H_VALUES[1][j][ii]==0 ||
                            HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][5] ||
                            HERO_COMBOS[0][i][5]==HERO_COMBOS[1][ii][6] ||
                            HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][5] ||
                            HERO_COMBOS[0][i][6]==HERO_COMBOS[1][ii][6]
                        ){
                            continue;
                        }
                        arr_values[1]=HERO_H_VALUES[1][j][ii];
                        for(iii=0;iii<long_hex_pos[2];++iii){
                            if(
                                HERO_H_VALUES[2][j][iii]==0 ||
                                HERO_COMBOS[0][i][5]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[0][i][5]==HERO_COMBOS[2][iii][6] ||
                                HERO_COMBOS[0][i][6]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[0][i][6]==HERO_COMBOS[2][iii][6] ||

                                HERO_COMBOS[1][ii][5]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[1][ii][5]==HERO_COMBOS[2][iii][6] ||
                                HERO_COMBOS[1][ii][6]==HERO_COMBOS[2][iii][5] ||
                                HERO_COMBOS[1][ii][6]==HERO_COMBOS[2][iii][6]
                            ){
                                continue;
                            }
                            arr_values[2]=HERO_H_VALUES[2][j][iii];
                            for(iiii=0;iiii<long_hex_pos[3];++iiii){
                                if(
                                    HERO_H_VALUES[3][j][iiii]==0 ||
                                    HERO_COMBOS[0][i][5]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[0][i][5]==HERO_COMBOS[3][iiii][6] ||
                                    HERO_COMBOS[0][i][6]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[0][i][6]==HERO_COMBOS[3][iiii][6] ||

                                    HERO_COMBOS[1][ii][5]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[1][ii][5]==HERO_COMBOS[3][iiii][6] ||
                                    HERO_COMBOS[1][ii][6]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[1][ii][6]==HERO_COMBOS[3][iiii][6] ||
                                    
                                    HERO_COMBOS[2][iii][5]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[2][iii][5]==HERO_COMBOS[3][iiii][6] ||
                                    HERO_COMBOS[2][iii][6]==HERO_COMBOS[3][iiii][5] ||
                                    HERO_COMBOS[2][iii][6]==HERO_COMBOS[3][iiii][6]
                                ){
                                    continue;
                                }
                                arr_values[3]=HERO_H_VALUES[3][j][iiii];
                                for(iiiii=0;iiiii<long_hex_pos[4];++iiiii){
                                    if(
                                        HERO_H_VALUES[4][j][iiiii]==0 ||
                                        HERO_COMBOS[0][i][5]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[0][i][5]==HERO_COMBOS[4][iiiii][6] ||
                                        HERO_COMBOS[0][i][6]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[0][i][6]==HERO_COMBOS[4][iiiii][6] ||

                                        HERO_COMBOS[1][ii][5]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[1][ii][5]==HERO_COMBOS[4][iiiii][6] ||
                                        HERO_COMBOS[1][ii][6]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[1][ii][6]==HERO_COMBOS[4][iiiii][6] ||
                                        
                                        HERO_COMBOS[2][iii][5]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[2][iii][5]==HERO_COMBOS[4][iiiii][6] ||
                                        HERO_COMBOS[2][iii][6]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[2][iii][6]==HERO_COMBOS[4][iiiii][6] ||
                                        
                                        HERO_COMBOS[3][iiii][5]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[3][iiii][5]==HERO_COMBOS[4][iiiii][6] ||
                                        HERO_COMBOS[3][iiii][6]==HERO_COMBOS[4][iiiii][5] ||
                                        HERO_COMBOS[3][iiii][6]==HERO_COMBOS[4][iiiii][6]
                                        
                                    ){
                                        continue;
                                    }
                                    arr_values[4]=HERO_H_VALUES[4][j][iiiii];
                                    for(iiiiii=0;iiiiii<long_hex_pos[5];++iiiiii){
                                        if(
                                            HERO_H_VALUES[5][j][iiiiii]==0 ||
                                            HERO_COMBOS[0][i][5]==HERO_COMBOS[5][iiiiii][5] ||
                                            HERO_COMBOS[0][i][5]==HERO_COMBOS[5][iiiiii][6] ||
                                            HERO_COMBOS[0][i][6]==HERO_COMBOS[5][iiiiii][5] ||
                                            HERO_COMBOS[0][i][6]==HERO_COMBOS[5][iiiiii][6] ||

                                            HERO_COMBOS[1][ii][5]==HERO_COMBOS[5][iiiiii][5] ||
                                            HERO_COMBOS[1][ii][5]==HERO_COMBOS[5][iiiiii][6] ||
                                            HERO_COMBOS[1][ii][6]==HERO_COMBOS[5][iiiiii][5] ||
                                            HERO_COMBOS[1][ii][6]==HERO_COMBOS[5][iiiiii][6] ||
                                            
                                            HERO_COMBOS[2][iii][5]==HERO_COMBOS[5][iiiiii][5] ||
                                            HERO_COMBOS[2][iii][5]==HERO_COMBOS[5][iiiiii][6] ||
                                            HERO_COMBOS[2][iii][6]==HERO_COMBOS[5][iiiiii][5] ||
                                            HERO_COMBOS[2][iii][6]==HERO_COMBOS[5][iiiiii][6] ||
                                            
                                            HERO_COMBOS[3][iiii][5]==HERO_COMBOS[5][iiiiii][5] ||
                                            HERO_COMBOS[3][iiii][5]==HERO_COMBOS[5][iiiiii][6] ||
                                            HERO_COMBOS[3][iiii][6]==HERO_COMBOS[5][iiiiii][5] ||
                                            HERO_COMBOS[3][iiii][6]==HERO_COMBOS[5][iiiiii][6] ||

                                            HERO_COMBOS[4][iiiii][5]==HERO_COMBOS[5][iiiiii][5] ||
                                            HERO_COMBOS[4][iiiii][5]==HERO_COMBOS[5][iiiiii][6] ||
                                            HERO_COMBOS[4][iiiii][6]==HERO_COMBOS[5][iiiiii][5] ||
                                            HERO_COMBOS[4][iiiii][6]==HERO_COMBOS[5][iiiiii][6]
                                        ){
                                            continue;
                                        }
                                        arr_values[5]=HERO_H_VALUES[5][j][iiiiii];
                                        max=0;
                                        i_max=0;
                                        flag_tied=1;
                                        for(k=0;k<num_players;++k){
                                            if(arr_values[k]>max){
                                                max=arr_values[k];
                                                i_max=k;
                                                flag_tied=1;//this is the max value, and for now dont have tied values
                                            }else if(arr_values[k]==max){
                                                flag_tied++;
                                            }
                                        }
                                        tot_combos++;
                                        //if is 1, there are not two players with the same max value
                                        if(flag_tied==1){
                                            tot_win_pos[i_max]++;
                                            continue;//end loop here
                                        }
                                        tie++;
                                        //tie possibilities
                                        for(k=0;k<num_players;++k){
                                            if(arr_values[k]==max){
                                                tot_win_pos[k]=tot_win_pos[k]+(1/flag_tied);
                                                tot_tied_pos[k]=tot_tied_pos[k]+(1/flag_tied);
                                            }
                                        }
                                    }//end for iiiiii
                                }//end for iiiii
                        }//end for iiii
                    }//end for iii
                }//end for ii
            }//end for ii
        }//end for i
        flag_switch_passed=true;
        break;
    }//end switch
    if(flag_switch_passed){
        for(k=0;k<num_players;++k){
            tot_win_pcent[k]=(tot_win_pos[k]*100)/tot_combos;
            tot_tied_pcent[k]=(tot_tied_pos[k]*100)/tot_combos;
        }
        tot_tie=(tie*100)/tot_combos;
    }
}//end function
