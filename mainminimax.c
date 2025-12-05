#include "lojoc4r.h"
#include "lominimax.h"

// nivell imparell és O    (p->nivell%2)
// nivell parell és X    (p->nivell%2==0)

int mainminimax(Tauler *t){
  // ara tenim un tauler t, per manipular-lo el copiem en un node
  // creo el node
  Node *arrel= malloc(sizeof(Node));
  // i el copio
  copiaTauler(arrel->taula,t->taula);
  // i l'inicialitzo amb tot zeros
  inicialitzacionode(arrel);
  // creo tots els fills
  crearArbreRec(arrel, 1);
  // l'arrel està a nivell 0

  int valorfinal= assignovalors(arrel, 0);

  // arrel,0  -> significa que començo maximitzant
  // és a dir que volem que guanyen les O i perdin les X

  int col=buscoquinacolumnaes(arrel, valorfinal );

  alliberarEspai(arrel);

  return col;


}
