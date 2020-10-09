int get_value_combo(int combo_hex, int local_board[10]){
   
//     printf("hero_combo %x%x%x%x\n",hero_combo[0],hero_combo[1],hero_combo[2],hero_combo[3]);
//     printf("board %x%x%x%x%x%x%x%x%x%x\n",board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],board[9]);
//     
    
//     MIRAR A VER SI CONVIENE TRAERSE EL ARRAY ORDENADO DE LA OTRA FUNCIÓN O NO
    int hero_all[14];
    hero_all[0]=local_board[0];
    hero_all[1]=local_board[1];
    hero_all[2]=local_board[2];
    hero_all[3]=local_board[3];
    hero_all[4]=local_board[4];
    hero_all[5]=local_board[5];
    hero_all[6]=local_board[6];
    hero_all[7]=local_board[7];
    hero_all[8]=local_board[8];
    hero_all[9]=local_board[9];
    hero_all[10]=(combo_hex/0x1000)%0x10;
    hero_all[11]=(combo_hex/0x100)%0x10;
    hero_all[12]=(combo_hex/0x10)%0x10;
    hero_all[13]=combo_hex%0x10;

//             printf("hero_all %x%x%x%x%x%x%x%x%x%x%x%x%x%x\n",hero_all[0],hero_all[1],hero_all[2],hero_all[3],hero_all[4],hero_all[5],hero_all[6],hero_all[7],hero_all[8],hero_all[9],hero_all[10],hero_all[11],hero_all[12],hero_all[13]);
//         printf("%c%c %c%c %c%c - %c%c - %c%c - %c%c %c%c == \n",
//                arr_int_to_suit[hero_all[0]],
//                arr_int_to_let[hero_all[1]],
//                arr_int_to_suit[hero_all[2]],
//                arr_int_to_let[hero_all[3]],
//                arr_int_to_suit[hero_all[4]],
//                arr_int_to_let[hero_all[5]],
//                arr_int_to_suit[hero_all[6]],
//                arr_int_to_let[hero_all[7]],
//                arr_int_to_suit[hero_all[8]],
//                arr_int_to_let[hero_all[9]],
//                arr_int_to_suit[hero_all[10]],
//                arr_int_to_let[hero_all[11]],
//                arr_int_to_suit[hero_all[12]],
//                arr_int_to_let[hero_all[13]] );
    
    
    //now we order hero_all respecting the suits. We order the cards in this point because is faster than order in each function after.
    char i,j,temp0,temp1;
    for(i=1;i<(14-1);i=i+2){ 
        for(j=i+2;j<14;j=j+2){ 
            if(hero_all[j]<hero_all[i]){ 
                temp1=hero_all[j]; 
                temp0=hero_all[j-1]; 
                hero_all[j]=hero_all[i];
                hero_all[j-1]=hero_all[i-1];
                hero_all[i]=temp1; 
                hero_all[i-1]=temp0; 
            } 
        } 
    }
    

    int hand_value[3];
    hand_value[0]=is_straight_flush(hero_all);
    if(hand_value[0]>0x80000){
        return hand_value[0];//dont waste time if is an straight flush
    }
    hand_value[1]=is_flush(hero_all);
    hand_value[2]=is_pair_to_quads(hero_all);
    if(hand_value[0]==0 && hand_value[1]==0 && hand_value[2]==0){
        return is_high_card(hero_all);//dont waste time is high card
    }

    int max_hand_value=0;
    for(int i=0;i<3;i++){
        if(hand_value[i]>max_hand_value){
            max_hand_value=hand_value[i];
        }
    }
    return max_hand_value;//return the highest hand value
}
int is_high_card(int hero_all[14]){
    return hero_all[13]*0x10000+hero_all[11]*0x1000+hero_all[9]*0x100+hero_all[7]*0x10+hero_all[5];
}
int is_straight_flush(int hero_all[14]){
    char cont=1,i,j;
    int value_combo=0,hero_straight[15]={0};//0x0e is the ace
    //make hero_straight running over hero_all
    for(i=0;i<14;i=i+2){
        hero_straight[hero_all[i+1]]++;
        if(hero_all[i+1]==0x0e){//if there is A sum 1, as 1 and as 14 (0x0e)
            hero_straight[1]++;            
        }
    }
    //check if there are 5 in a row
    for(i=0x0e;i>=1;i--){
        if(hero_straight[i-1]>0 && hero_straight[i]>0){
            cont++;
            if(cont==5){
                value_combo=i+3;
                break;
            }
        }else{
            cont=1;
        }
    }
    if(value_combo!=0){//is an straight!
        //check if is an straight flush
        char hero_suits_in_a_row[4]={0};
        int flag_straight_flush=0;
        //run over 7 cards with their suits
        for(j=0;j<14;j=j+2){
            if( hero_all[j+1]==value_combo || 
                (hero_all[j+1]==(value_combo-1)) || 
                (hero_all[j+1]==(value_combo-2)) || 
                (hero_all[j+1]==(value_combo-3)) || 
                (hero_all[j+1]==(value_combo-4)) || 
                /*this case is down straight with Ace*/
                ((value_combo-4)==1 && hero_all[j+1]==0x0e)){
                
                hero_suits_in_a_row[hero_all[j]]++;
                //yes! there is an straight flush!
                if(hero_suits_in_a_row[hero_all[j]]==5){
                    flag_straight_flush=0x400000;
                    break;
                }
            }
        }
        return flag_straight_flush+0x400000+value_combo;//In the straight case doesnt have kicker
    }
    return 0;
}
int is_pair_to_quads(int hero_all[14]){
    //the cards are sorted
    if(!(hero_all[1]==hero_all[3] || 
        hero_all[3]==hero_all[5] || 
        hero_all[5]==hero_all[7] || 
        hero_all[7]==hero_all[9] || 
        hero_all[9]==hero_all[11] || 
        hero_all[11]==hero_all[13])
    ){
        return 0;//if dont have repeated cards, return now
    }else{

        char j, i;
        char max_1=0,max_2=0,max_0=0,card_1=0,card_2=0;
            
        //fill the array with zeros
        int hero_repeated_cards[15]={0};
        
        //for upside down for count the better cards first
        for(i=13;i>=0;i=i-2){
            hero_repeated_cards[hero_all[i]]++;
        }
        

        for(i=2;i<15;i++){
            if(max_1<=hero_repeated_cards[i] && hero_repeated_cards[i]>=2){

                if(max_1>max_2 || max_1==2 && max_2==2 || max_1==3 && max_2==3){
                    max_2=max_1;
                    card_2=card_1;
                }
                max_1=hero_repeated_cards[i];
                card_1=i;
            }
        }
        char value_kicker[3];
        
        //now fill the value_hand
        if(max_1==2 && max_2==0){
            j=0;
            //pair
            for(i=13;i>=0;i=i-2){
                if(hero_all[i]!=card_1){
                    value_kicker[j]=hero_all[i];
                    j++;
                    if(j==3){
                        break;//2+3=the 5 better cards
                    }
                }
            }        
            return 0x100000+(card_1*0x10000)+(value_kicker[0]*0x1000)+(value_kicker[1]*0x100)+(value_kicker[2]*0x10); 
        }else if(max_1==2 && max_2==2){
            //2pair
            for(i=13;i>=0;i=i-2){
                if(hero_all[i]!=card_1 && hero_all[i]!=card_2){
                    value_kicker[0]=hero_all[i];
                    break;
                }
            }        
            return 0x200000+(card_1*0x100)+(card_2*0x10)+value_kicker[0];
        }else if(max_1==3 && max_2==0){
            //set
            j=0;
            for(i=13;i>=0;i=i-2){
                if(hero_all[i]!=card_1){
                    value_kicker[j]=hero_all[i];
                    j++;
                    if(j==2){
                        break;//3+2=the 5 better cards
                    }
                }
            }        
            return 0x300000+(card_1*0x10000)+(value_kicker[0]*0x1000)+(value_kicker[1]*0x100);//no kicker here
        }else if(max_1==3 && (max_2==2 || max_2==3)){
            //full house
            return 0x600000+(card_1*0x100)+(card_2*0x10);//no kicker here
        }else if(max_1==4){
            //quads
            for(i=13;i>=0;i=i-2){
                if(hero_all[i]!=card_1){
                    value_kicker[0]=hero_all[i];
                    break;
                }
            }
            return 0x700000+(card_1*0x100)+value_kicker[0];
        }
        return 0;   
    }
}

int is_flush(int hero_all[14]){
    char i,j,value_combo[5],act_suit=5,hero_suits[4]={0};
    for(i=0;i<14;i=i+2){
        hero_suits[hero_all[i]]++;
    }
    for(i=0;i<4;i++){
        if(hero_suits[i]>=5){//if this suit>=5 we want know what is the highest card
            for(j=13;j>=0;j=j-2){
                if(hero_all[j-1]==i && act_suit>-1){
                    act_suit--;
                    value_combo[act_suit]=hero_all[j];
                }
            }
            return 0x500000+(value_combo[4]*0x10000)+(value_combo[3]*0x1000)+(value_combo[2]*0x100)+(value_combo[1]*0x10)+value_combo[0];
        }
    }
    return 0;
}
