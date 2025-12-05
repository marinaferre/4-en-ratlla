// codi de lo joc en si

#include "lojoc4r.h"
#include "lominimax.h"

void imprimir(Tauler *t){
  for(int i=0; i<N; i++){
    printf(" " );
    for(int j=0; j<N; j++){
      printf(" %c ",t->taula[i][j] );
    }
    printf("\n" );
  }
  printf(" " );
  for(int i=1; i<N+1;i++){
    printf(" %d ",i );
  }
  printf("\n");
}

int inicialitzacio(Tauler *t){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      t->taula[i][j]='.';
    }
  }

  for(int i=0; i<N+1; i++){
    t->taula[i][N]='\0';
    t->taula[N][i]='\0'; // això ho poso perquè així puc fer una cadena de caràcters
  }

  printf("\n\n BENVINGUDA AL JOC DEL QUATRE EN RATLLA EXTREM \n\n");
  imprimir(t);
  printf("\n\n QUI VOLS QUE COMENCI? \n\n 1=Tu (la persona), 2=Jo (l'ordinador)  \n\n" );
  int torn_persona;
  printf(" ");
  scanf("%d", &torn_persona);
  t->qui_jugara=1;
  return torn_persona;
}

void preguntem(Tauler *t, int torn_persona){
  if(torn_persona==1){
    if(t->qui_juga==1){
      printf("\n jugadora 1 (X) en quina columna vols tirar? ");

      scanf("%d", &t->columna); // Llegim un enter de la terminal
      t->columna--;
      if( (t->columna) < 0 || (t->columna) > N){
        printf("\n  Aquesta columna no és vàlida !!!!!\n");
        preguntem(t,torn_persona);
      }

      //mirem quina és la fila lliure de la columna
      for(t->fila=N-1; t->fila>-1; t->fila--){
        if(t->taula[t->fila][t->columna]=='.'){
          break;
        }
      }

      if(t->fila==-1){
        printf("\n  Aquesta columna està plena, tria'n una altra !!!!!\n");
        preguntem(t,torn_persona);
      }
    }
    if(t->qui_juga==2){
      t->columna=mainminimax(t);
      printf("\n Jo, l'ordinador, trio tirar en la columna %d\n", t->columna+1);

      //mirem quina és la fila lliure de la columna
      for(t->fila=N-1; t->fila>-1; t->fila--){
        if(t->taula[t->fila][t->columna]=='.'){
          break;
        }
      }
    }
  }

  if(torn_persona==2){
    if(t->qui_juga==2){
      printf("\n jugadora 2 (X) en quina columna vols tirar? ");

      scanf("%d", &t->columna); // Llegim un enter de la terminal
      t->columna--;
      if( (t->columna) < 0 || (t->columna) > N){
        printf("\n  Aquesta columna no és vàlida !!!!!\n");
        preguntem(t,torn_persona);
      }

      //mirem quina és la fila lliure de la columna
      for(t->fila=N-1; t->fila>-1; t->fila--){
        if(t->taula[t->fila][t->columna]=='.'){
          break;
        }
      }

      if(t->fila==-1){
        printf("\n  Aquesta columna està plena, tria'n una altra !!!!!\n");
        preguntem(t,torn_persona);
      }
    }
    if(t->qui_juga==1){
      t->columna=mainminimax(t);
      printf("\n Jo, l'ordinador, trio tirar en la columna %d\n", t->columna+1);

      //mirem quina és la fila lliure de la columna
      for(t->fila=N-1; t->fila>-1; t->fila--){
        if(t->taula[t->fila][t->columna]=='.'){
          break;
        }
      }
    }

  }


}

void apuntem(Tauler *t, int torn_persona){
  if(torn_persona==1){
    if(t->qui_juga==1){
      t->taula[t->fila][t->columna] = 'X';
      t->qui_jugara=2;
    }
    if(t->qui_juga==2){
      t->taula[t->fila][t->columna] = 'O';
      t->qui_jugara=1;
    }
  }
  if(torn_persona==2){
    if(t->qui_juga==1){
      t->taula[t->fila][t->columna] = 'O';
      t->qui_jugara=2;
    }
    if(t->qui_juga==2){
      t->taula[t->fila][t->columna] = 'X';
      t->qui_jugara=1;
    }
  }
}

void jugades(Tauler *t,int torn_persona){
  t->qui_juga = t->qui_jugara;

  preguntem(t,torn_persona);
  apuntem(t,torn_persona);
  imprimir(t);

}

int guanyar(char taula[N+1][N+1], char trobarX[], char trobarO[]){
//HORITZONTALMENT

for(int k=N-1; k>-1; k--){ //mirem totes les files
  for(int i=0; i<N-3; i++){
    int jX=0;
    int jO=0;
    while(trobarX[jX]!='\0' && taula[k][i + jX] == trobarX[jX]){
      jX++;
    }
    if (trobarX[jX] == '\0') { // hem arribat al final de trobarX -> tenim 4enratlla
      return 1; // ha guanyat la jugadora 1
    }
    while(trobarO[jO]!='\0' && taula[k][i + jO] == trobarO[jO]){
      jO++;
    }
    if (trobarO[jO] == '\0') { // hem arribat al final de trobarO -> tenim 4enratlla
      return 2; // ha guanyat la jugadora 2
    }
  }
}

//VERTICALMENT

for(int k=0; k<N; k++){ //mirem totes les columnes
  for(int i=0; i<N-3; i++){
    int jX=0;
    int jO=0;
    while(trobarX[jX]!='\0' && taula[i + jX][k] == trobarX[jX]){
      jX++;
    }
    if (trobarX[jX] == '\0') { // hem arribat al final de trobarX -> tenim 4enratlla
      return 1; // ha guanyat la jugadora 1
    }
    while(trobarO[jO]!='\0' && taula[i + jO][k] == trobarO[jO]){
      jO++;
    }
    if (trobarO[jO] == '\0') { // hem arribat al final de trobarO -> tenim 4enratlla
      return 2; // ha guanyat la jugadora 2
    }
  }
}

//EN DIAGONAL AMB PENDENT NEGATIVA \

for (int k = 0; k < N - 3; k++) {
    int sumar = 0;
    int l = 0;
    int m = k;

    int jX = 0;
    int jO = 0;

    while ((l + sumar) < N && (m + sumar) < N) {
        jX = 0;
        while (taula[m + sumar + jX][l + sumar + jX] == trobarX[jX] && trobarX[jX] != '\0') {
            jX++;
        }
        if (trobarX[jX] == '\0') {
          return 1; // ha guanyat la jugadora 1
        }

        jO = 0;
        while (taula[m + sumar + jO][l + sumar + jO] == trobarO[jO] && trobarO[jO] != '\0') {
            jO++;
        }
        if (trobarO[jO] == '\0') {
          return 2; // ha guanyat la jugadora 2
        }
        sumar++;
    }

    if (k > 0) {
        sumar = 0;
        while ((l + sumar) < N && (m + sumar) < N) {
            jX = 0;
            while (taula[l + sumar + jX][m + sumar + jX] == trobarX[jX] && trobarX[jX] != '\0') {
                jX++;
            }
            if (trobarX[jX] == '\0') {
                 return 1; // ha guanyat la jugadora 1
            }

            jO = 0;
            while (taula[l + sumar + jO][m + sumar + jO] == trobarO[jO] && trobarO[jO] != '\0') {
                jO++;
            }
            if (trobarO[jO] == '\0') {
                 return 2; // ha guanyat la jugadora 2
            }
            sumar++;
        }
    }
}

//EN DIAGONAL AMB PENDENT POSITIVA /

for(int k=0; k<N-3;k++){
  int sumar=0;
  int l=N-1;
  int m=k;
  int jX = 0;
  int jO = 0;
  while((m+sumar)<N && (l-sumar)>-1 ){
    jX = 0;
    while ((m + sumar + jX) < N && (l - sumar - jX) > -1 &&
      taula[m + sumar + jX][l - sumar - jX] == trobarX[jX] && trobarX[jX] != '\0') {
      jX++;
    }
    if (trobarX[jX] == '\0') {
      return 1; // ha guanyat la jugadora 1
    }

    jO = 0;
    while ((m + sumar + jO)<N && (l - sumar - jO)>-1 &&
      taula[m + sumar + jO][l - sumar - jO] == trobarO[jO] && trobarO[jO] != '\0') {
      jO++;
    }
    if (trobarO[jO] == '\0') {
      return 2; // ha guanyat la jugadora 2
    }
    sumar++;
  }

  if(k>0){
    sumar=0;
    while(sumar<N && (l-sumar-m)>-1 ){
      jX = 0;
      while ((sumar + jX)<N && (l-sumar-m- jX)>-1 &&
        taula[sumar + jX][l-sumar-m- jX] == trobarX[jX] && trobarX[jX] != '\0') {
          jX++;
      }
      if (trobarX[jX] == '\0') {
        return 1; // ha guanyat la jugadora 1
      }

      jO = 0;
      while ((sumar + jO)<N && (l-sumar-m- jO)>-1 &&
        taula[sumar + jO][l-sumar-m- jO] == trobarO[jO] && trobarO[jO] != '\0') {
          jO++;
      }
      if (trobarO[jO] == '\0') {
        return 2; // ha guanyat la jugadora 2
      }
      sumar++;
    }
  }
}

  return 0;
}
