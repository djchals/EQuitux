#include "header.h"
#include "get_value_combo.h"

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

    get_value_combo(0x030a);
//     is_card_repeated();
}

// int is_card_repeated(){
//     //in this function check there are not repeated cards in board or with hero combo. If is true, returns the odd position in hero_all
//     int hero_all[14],i,j;
//     hero_all[0]=board[0];
//     hero_all[1]=board[1];
//     hero_all[2]=board[2];
//     hero_all[3]=board[3];
//     hero_all[4]=board[4];
//     hero_all[5]=board[5];
//     hero_all[6]=board[6];
//     hero_all[7]=board[7];
//     hero_all[8]=board[8];
//     hero_all[9]=board[9];
//     hero_all[10]=hero_combo[0];
//     hero_all[11]=hero_combo[1];
//     hero_all[12]=hero_combo[2];
//     hero_all[13]=hero_combo[3];
//     for(i=1;i<14;i=i+2){
//         for(j=1;j<14;j=j+2){
//             if(hero_all[i]==hero_all[j] && hero_all[i-1]==hero_all[j-1]){
//                 return i;
//             }
//         }
//     }
//     return 0;
// }
