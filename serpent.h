#ifndef __serpent__
#define __serpent__
#include <stdlib.h>
#include <stdio.h>
#define M 64
#define N 32

typedef struct Case{
	int x ;
	int y ;
}Case;

typedef struct {
	int x ;
	int y ;
}Direction ;

typedef struct serpent {
	Case tab[N*M] ;
	Direction dir ;
	int taille ;	
}Serpent;

/* renvoie un serpent dans sa position initiale 
   avec 1 tete et une partie pour le corp sa direction
   est a l'EST et sa taille est donc 2 */
Serpent init_serpent(void);

#endif