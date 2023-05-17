#include <stdio.h>

//definicion de las estructuras
typedef int arr_asalto[12][2]; //arreglo que almacena las puntuaciones de cada ronda
typedef int arr_puntuacion[2]; //arreglo que almacena la puntuacion total de cada jugador
typedef struct{
    arr_asalto rondas;
    arr_puntuacion total;
    arr_asalto vict; //este arreglo tendra un 1 por cada victoria y un 0 por cada derrota
    arr_puntuacion v_total; //este arreglo guardara la cantidad de victorias por cada jugador
}tarjeta; //este struct guardara los arreglos

typedef tarjeta arr_tarjetas[3]; //esta va a ser la estructura principal, un arreglo de structs que tienen arreglos como campo

//declaracion de los prototipos
int valopcion(int var, int opcion1, int opcion2); //funcion que valida una de dos opciones
void combate(arr_asalto tarjeta, arr_asalto victoria); //aqui se llenara las puntuaciones de cada ronda para una tarjeta dada
void puntuaciontotal(arr_asalto tarjeta, arr_puntuacion punt); //este va a calcular la puntuacion total y lo almacenara en el arreglo correspondiente 
void imprimirtotal(arr_puntuacion punt); //este mostrara por pantalla la puntuacion final de cada jugador
void mayor(arr_tarjetas punt); //este mostrara por pantalla la tarjeta con mayor puntuacion
void menor(arr_tarjetas punt); //igual pero con la menor puntuacion
char tipovictoria(arr_tarjetas v, char g); //este determinara el tipo de victoria
void recompensa(arr_tarjetas v, char g); //este muestra por pantalla el tipo de victoria y la recompensa que obtendra cada jugador

//variables globales
arr_tarjetas t;
char ganador;
//principal
int main(){
  printf("PELEA DE:\nFLOYD MAYWEATHER JR. VS SAUL CANELO ALVAREZ\n\nPelea Auspiciada por:\nDAZN\n\nSISTEMA DE PUNTUACIONES\n\n");

  for(int i=0; i<3; i++){
	  printf("==========TARJETA #%d==========\n\n", i+1);
	  combate(t[i].rondas, t[i].vict);
	  puntuaciontotal(t[i].rondas, t[i].total);
	  puntuaciontotal(t[i].vict, t[i].v_total);
  }

  for(int i=0; i<3; i++){
	  printf("\nPuntuaciones finales para la tarjeta #%d\n\n", i+1);
	  imprimirtotal(t[i].total);
	  printf("\nCantidad de victorias para la tarjeta #%d\n\n", i+1);
	  imprimirtotal(t[i].v_total);
  }
    mayor(t);
    menor(t);

    recompensa(t, ganador);
    return 0;
}

//definicion de los prototipos
int valopcion(int var, int opcion1, int opcion2){
  do {
    scanf("%d", &var);
	  fflush(stdin);
	  if(var != opcion1 && var != opcion2) printf("Ingrese una opcion valida (o %d o %d): ", opcion1, opcion2);
  } while(var != opcion1 && var != opcion2);
  return var;
}

void combate(arr_asalto tarjeta, arr_asalto victoria){

  int ganador;
  int caida;

  for(int i = 0 ; i<12 ; i++){
	  printf("ROUND %d\n", i+1);

	  printf("Quien gano?\n\n1 - Floyd\n2 - Canelo\n\nInserte una opcion: ");
	  ganador = valopcion(ganador, 1, 2);

	  if(ganador == 1){
	    victoria[i][0] = 1;
	    victoria[i][1] = 0;

	    printf("Cayo Canelo?\n\n0 - No\n1 - Si\n\nIngrese una opcion: ");
	    caida = valopcion(caida, 1, 0);
	    if(caida == 0){
		    tarjeta[i][0] = 10;
		    tarjeta[i][1] = 9;
		    
	    } else {		
		    tarjeta[i][0] = 10;
		    tarjeta[i][1] = 8;
	    }	
	  }
	  else{ 
	    victoria[i][0] = 0;
	    victoria[i][1] = 1;
	    
	    printf("Cayo Floyd?\n\n0 - No\n1 - Si\n\nIngrese una opcion: ");
	    caida = valopcion(caida, 1, 0);

	    if(caida == 0) {
		    tarjeta[i][0] = 9;
		    tarjeta[i][1] = 10;
	    } else { 
	    	tarjeta[i][0] = 8;
    		tarjeta[i][1] = 10;
	    }
	  }
  }
}

void puntuaciontotal(arr_asalto tarjeta, arr_puntuacion punt){
  int acum;
  for(int c=0; c<2; c++){
	  acum=0;
	  for(int f=0; f<12; f++){
	    acum += tarjeta[f][c];
	  }
	  punt[c] = acum;
  }
}

void imprimirtotal(arr_puntuacion punt){
  for(int i=0; i<2; i++){
	  switch (i){
	    case 0:
		    printf("Puntuacion para Floyd: %d\n", punt[i]);
		    break;
	    case 1:
		    printf("Puntuacion para Canelo: %d\n", punt[i]);
		    break;
	  }
  }  
}

void menor(arr_tarjetas punt){
    int i=0, j=0, cont=i, aux;
    aux = punt[i].total[j];
    for(i; i<3; i++){
	    for(j; j<2; j++){
	      if(aux > punt[i].total[j]){
		      aux = punt[i].total[j];
		      cont = i;
	      }
	    }
    }
  printf("La tarjeta con menor puntuacion es la #%d con %d puntos\n", cont+1, aux);
}

void mayor(arr_tarjetas punt){
  int i=0, j=0, cont=i, aux;
  aux = punt[i].total[j];
  
  for(i; i<3; i++){
	  for(j; j<2; j++){
	    if(aux < punt[i].total[j]){
	    	aux = punt[i].total[j];
		    cont = i;
	    }
	  }
  }
  printf("La tarjeta con mayor puntuacion es la #%d con %d puntos\n", cont+1, aux);
}

char tipovictoria(arr_tarjetas v, char g){
  //ganar por decision unanime
  if( ((v[0].v_total[0] > v[0].v_total[1])&&(v[1].v_total[0] > v[1].v_total[1])&&(v[2].v_total[0] > v[2].v_total[1])) ){
    g = 'f'; //floyd u
  }
  if ((v[0].v_total[1] > v[0].v_total[0])&&(v[1].v_total[1] > v[1].v_total[0])&&(v[2].v_total[1] > v[2].v_total[0])) {
    g = 'g'; //canelo u
  }

  //ganar por decision no unanime
  if ( ((v[0].v_total[0] > v[0].v_total[1]) && (v[1].v_total[0] > v[1].v_total[1]) && (v[2].v_total[0] < v[2].v_total[1])) ) {
    g = 'h'; //floyd s1
  }

  if ( ((v[0].v_total[0] > v[0].v_total[1]) && (v[1].v_total[0] < v[1].v_total[1]) && (v[2].v_total[0] > v[2].v_total[1])) ) {
    g = 'i'; //floyd s2
  }

  if ( ((v[0].v_total[0] < v[0].v_total[1]) && (v[1].v_total[0] > v[1].v_total[1]) && (v[2].v_total[0] > v[2].v_total[1])) ) {
    g = 'j'; //floyd s3
  }

  if ( ((v[0].v_total[0] < v[0].v_total[1]) && (v[1].v_total[0] < v[1].v_total[1]) && (v[2].v_total[0] > v[2].v_total[1])) ) {
    g = 'k'; //canelo s1
  }

  if ( ((v[0].v_total[0] < v[0].v_total[1]) && (v[1].v_total[0] > v[1].v_total[1]) && (v[2].v_total[0] < v[2].v_total[1])) ) {
    g = 'l'; //canelo s2
  }

  if ( ((v[0].v_total[0] > v[0].v_total[1]) && (v[1].v_total[0] < v[1].v_total[1]) && (v[2].v_total[0] < v[2].v_total[1])) ) {
    g = 'm'; //canelo s3
  }

  //ganar por mayoria
  if ( ((v[0].v_total[0] > v[0].v_total[1]) && (v[1].v_total[0] > v[1].v_total[1]) && (v[2].v_total[0] == v[2].v_total[1])) ) {
    g = 'n'; //floyd m1
  }

  if ( ((v[0].v_total[0] > v[0].v_total[1]) && (v[1].v_total[0] == v[1].v_total[1]) && (v[2].v_total[0] > v[2].v_total[1])) ) {
    g = 'o'; //floyd m2
  }

  if ( ((v[0].v_total[0] == v[0].v_total[1]) && (v[1].v_total[0] > v[1].v_total[1]) && (v[2].v_total[0] > v[2].v_total[1])) ) {
    g = 'p'; //floyd m3
  }

  if ( ((v[0].v_total[0] < v[0].v_total[1]) && (v[1].v_total[0] < v[1].v_total[1]) && (v[2].v_total[0] == v[2].v_total[1])) ) {
    g = 'q'; //canelo m1
  }

  if ( ((v[0].v_total[0] < v[0].v_total[1]) && (v[1].v_total[0] == v[1].v_total[1]) && (v[2].v_total[0] < v[2].v_total[1])) ) {
    g = 'r'; //canelo m2
  }

  if ( ((v[0].v_total[0] == v[0].v_total[1]) && (v[1].v_total[0] < v[1].v_total[1]) && (v[2].v_total[0] < v[2].v_total[1])) ) {
    g = 's'; //canelo m3
  }

  return g;
}

void recompensa(arr_tarjetas v, char g){
  const float rec = 100000; //la bolsa inicial
  int acumv=0; //va a acumular la cantidad de rondas ganadas del ganador y se va a multiplicar por el porcentaje segun el tipo de victoria para obtener una ganancia final
  g = tipovictoria(v, g);

  //recompensas si la victoria es por decision unanime
  if(g == 'f'){
    for(int i=0; i<3; i++){
      acumv += t[i].v_total[0];
    }
    printf("Ganador: Floyd (decision unanime)\nRecompensa: %g\n\nPerdedor: Canelo\nRecompensa: %g", rec + (rec * (0.1 * acumv)), (rec + (rec * -0.4)));
  }
  if(g == 'g'){
    for(int i=0; i<3; i++){
      acumv += t[i].v_total[1];
    }
    printf("Ganador: Canelo (decision unanime)\nRecompensa: %g\n\nPerdedor: Floyd\nRecompensa: %g", rec + (rec * (0.1 * acumv)), (rec + (rec * -0.4)));
  }

  //recompensas si la victoria es por decision no unanime
  if((g == 'h') || (g == 'i') || (g == 'j')){
    for(int i=0; i<3; i++){
      acumv += t[i].v_total[0];
    }
    printf("Ganador: Floyd (decision no unanime)\nRecompensa: %g\n\nPerdedor: Canelo\nRecompensa: %g", rec + (rec * (0.05 * acumv)), (rec + (rec * -0.4)));
  }
  if((g == 'k') || (g == 'l') || (g == 'm')){
    for(int i=0; i<3; i++){
      acumv += t[i].v_total[1];
    }
    printf("Ganador: Canelo (decision no unanime)\nRecompensa: %g\n\nPerdedor: Floyd\nRecompensa: %g", rec + (rec * (0.05 * acumv)), (rec + (rec * -0.4)));
  }

  //recompensas si la victoria es por decision mayoritaria

  if((g == 'n') || (g == 'o') || (g == 'p')){
    for(int i=0; i<3; i++){
      acumv += t[i].v_total[0];
    }
    printf("Ganador: Floyd (decision por mayoria)\nRecompensa: %g\n\nPerdedor: Canelo\nRecompensa: %g", rec + (rec * (0.15 * acumv)), (rec + (rec * -0.4)));
  }
  if((g == 'q') || (g == 'r') || (g == 's')){
    for(int i=0; i<3; i++){
      acumv += t[i].v_total[1];
    }
    printf("Ganador: Canelo (decision por mayoria)\nRecompensa: %g\n\nPerdedor: Floyd\nRecompensa: %g", rec + (rec * (0.15 * acumv)), (rec + (rec * -0.4)));
  }
}
