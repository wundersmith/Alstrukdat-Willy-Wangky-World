#include "player.h"
#include <stdio.h>
#include <string.h>

boolean EndKata;
Kata CKata;
JAM JamBuka;
JAM JamTutup;

void CreatePlayer(player *P){
    CopyKata(CKata, &(P->Name));
    
    (*P).position.X = 1;
    (*P).position.Y = 1;
    MapNum(*P) = 1;
    Money(*P) = 1000;
    CJam(*P) = MakeJAM(21,0,0);
    Day(*P) = 1;
}

void TulisPlayer(player P){
    printf("Player Name: ");
    for (int i = 0; i < (P.Name).Length; i++){
        printf("%c", P.Name.TabKata[i]);
    }
    printf("\n");
    printf("Money: %d\n", Money(P));
}

void movePeta(player *P){

}
