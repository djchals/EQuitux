#include <stdio.h>
#include "header.h"
/*
 * 
cada carta puede ser un número hexadecimal de dos cifras donde la primera índique el palo y la segunda indique el número, ejemplo:
0 corazón
1 diamante
2 pica
3 trébol
23456789ABCDE
23456789TJQKA

x34 -> esto sería el 4 de trébol
x1a -> esto seria la J de diamante. 

Un combo simplemente puede ser un número hex de 4 cifras, podria ser un array pero pienso que para transportar un array de hexadecimales de 4 cifras va a ser menos costoso.

x0c 2c -> esto seria KK de corazón y pica

un board seria un número hexadecimal de 10 cifras o un array de 10?:

x20 29 34 1c 28 -> As9s4cKds8 -> aquí habria un color completado
*/

void main(){
    get_value_combo(0x030a);
}

int get_value_combo(int combo_hex){
    int n_combo=combo_hex;
    int hero_combo[4];
    int value_combo, value_return;
    int hero_all_cards[7];
    
    //convert combo_hex to an array[4]. Ex: Ac2h -> 30 02 ->
    for(int i=3;i>=0;i--){
        hero_combo[i]=n_combo%0x10;
        n_combo=n_combo/0x10;
    }
    
    //the board is always an int array[10];    
    board[0]=0x01;//h
    board[1]=0x0e;//8
    board[2]=0x01;//h
    board[3]=0x02;//2
    board[4]=0x03;//h
    board[5]=0x08;//4
    board[6]=0x01;//h
    board[7]=0x04;//7
    board[8]=0x01;//s
    board[9]=0x0e;//A

    printf("hero_combo %x%x%x%x\n",hero_combo[0],hero_combo[1],hero_combo[2],hero_combo[3]);
    printf("board %x%x%x%x%x%x%x%x%x%x\n",board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],board[9]);
    
    int hero_all[14];
    hero_all[0]=board[0];
    hero_all[1]=board[1];
    hero_all[2]=board[2];
    hero_all[3]=board[3];
    hero_all[4]=board[4];
    hero_all[5]=board[5];
    hero_all[6]=board[6];
    hero_all[7]=board[7];
    hero_all[8]=board[8];
    hero_all[9]=board[9];
    hero_all[10]=hero_combo[0];
    hero_all[11]=hero_combo[1];
    hero_all[12]=hero_combo[2];
    hero_all[13]=hero_combo[3];

    int hand_value[4];
    hand_value[0]=is_flush(hero_all);
    hand_value[1]=is_straight_flush(hero_all);
    hand_value[2]=is_repeated_cards(hero_all);
    hand_value[3]=is_high_card(hero_all);

    qsort (hand_value,4,sizeof(int),comparator);
    
    printf("el valor de la mano es %x\n",hand_value[3]);

}
int is_high_card(int hero_all[14]){
    int i,value_combo=0,value_kicker=0;
    for(i=0;i<14;i=i+2){
        if(hero_all[i+1]>value_combo){
            if(value_combo>value_kicker){
                value_kicker=value_combo;
            }
            value_combo=hero_all[i+1];
        }else if(hero_all[i+1]>value_kicker){
            value_kicker=hero_all[i+1];            
        }
    }
    return (0x10*value_combo)+value_kicker;
}
int is_straight_flush(int hero_all[14]){
    int value_combo=0, cont=1,i,j;
    int hero_straight[15]={0};//0x0e is the ace
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
        int hero_suits_in_a_row[4]={0};
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
                    flag_straight_flush=0x4000;
                    break;
                }
            }
        }
        return ((flag_straight_flush+0x4000)+(value_combo*0x10));//In the straight case doesnt have kicker
    }
    return 0;
}
int is_repeated_cards(int hero_all[14]){
    int hero_all_cards[7];
    hero_all_cards[0]=hero_all[1];
    hero_all_cards[1]=hero_all[3];
    hero_all_cards[2]=hero_all[5];
    hero_all_cards[3]=hero_all[7];
    hero_all_cards[4]=hero_all[9];
    hero_all_cards[5]=hero_all[11];
    hero_all_cards[6]=hero_all[13];

    qsort(hero_all_cards,7,sizeof(int),comparator);

    int value_return=0,value_kicker=0;
    int max_1=0,max_2=0,card_1=0,card_2=0,i;
    int value_hand=0;
        
    //fill the array with zeros
    int hero_repeated_cards[15]={0};
    //for upside down for count the better cards first
    for(i=6;i>=0;i--){
        hero_repeated_cards[hero_all_cards[i]]++;
    }
    for(i=0;i<15;i++){
        if(max_1<=hero_repeated_cards[i] && hero_repeated_cards[i]>=2){
            if(max_1>max_2){
                max_2=max_1;
                card_2=card_1;
            }
            max_1=hero_repeated_cards[i];
            card_1=i;
        }
    }
    
    //now fill the value_hand
    if(max_1==4){
        //quads
        for(i=6;i>=0;i--){
            if(hero_all_cards[i]!=card_1){
                value_kicker=hero_all_cards[i];
                break;
            }
        }
        value_return=0x7000+card_1*0x100+value_kicker;
    }else if(max_1==3 && (max_2==2 || max_2==3)){
        //full house
        value_return=0x6000+card_1*0x100+card_2*0x10;//no kicker here
    }else if(max_1==3 && max_2==0){
        //set
        for(i=6;i>=0;i--){
            if(hero_all_cards[i]!=card_1){
                value_kicker=hero_all_cards[i];
                break;
            }
        }        
        value_return=0x3000+(card_1*0x100)+value_kicker;//no kicker here
    }else if(max_1==2 && max_2==2){
        //2pair
        for(i=6;i>=0;i--){
            if(hero_all_cards[i]!=card_1 && hero_all_cards[i]!=card_2){
                value_kicker=hero_all_cards[i];
                break;
            }
        }        
        value_return=0x2000+card_1*0x100+card_2*0x10+value_kicker;
    }else if(max_1==2 && max_2==0){
        //pair
        for(i=6;i>=0;i--){
            if(hero_all_cards[i]!=card_1 && hero_all_cards[i]!=card_2){
                value_kicker=hero_all_cards[i];
                break;
            }
        }        
        value_return=0x1000+card_1*0x100+value_kicker; 
    }
    return value_return;    
}

int is_flush(int hero_all[14]){
    int i,j,value_combo=0, hero_suits[4]={0};
    for(i=0;i<14;i=i+2){
        hero_suits[hero_all[i]]++;
    }
    for(i=0;i<4;i++){
        if(hero_suits[i]>=5){//if this suit>=5 we want know what is the highest card
            for(j=1;j<14;j=j+2){
                if(hero_all[j-1]==i && value_combo<hero_all[j]){
                    value_combo=hero_all[i];
                }
            }
            return (0x5000+(value_combo*0x10));//In the flush case doesnt have kicker
        }
    }
    return 0;
}
int comparator(const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}
