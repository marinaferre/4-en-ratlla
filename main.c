// gcc main.c lojoc4r.c lominimax.c mainminimax.c -o q

// l'ordenador sempre és les O
// la persona sempre és les X

#include <stdio.h>
#include <stdlib.h>

#include "lojoc4r.h"


int main(){

  Tauler t;
  int guanyarr=0;

  int torn_persona;
  torn_persona=inicialitzacio(&t);
  for(int i=0; i<N*N; i++){
    jugades(&t, torn_persona);

    guanyarr=guanyar(t.taula,"XXXX" ,"OOOO" );
    if(guanyarr==1){
      printf("\n\n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
      printf("\n\n MOLTES FELICITATS M'HAS GUANYAT!!!\n\n");
      printf("\n\n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
      break;
    }
    if(guanyarr==2){
      printf("\n\n !!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
      printf("\n\n HA HA HA, T'HE GUANYAT!!!\n\n");
      printf("\n\n !!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
      break;
    }
  }

  if(guanyarr==0){
    printf("\n\n !!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
    printf("\n\n           EMPAT!! \n\n");
    printf("\n\n !!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
  }

  return 0;
}
