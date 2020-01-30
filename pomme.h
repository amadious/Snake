#ifndef __pomme__
#define __pomme__
#include <assert.h>
#include <MLV/MLV_all.h>
#include "serpent.h"
typedef struct  pomme {
	Case pomme ;
}Pomme;

/* prend en argument 2 int correspondant respectivement a la largeur 
   et a la hauteur du quadrillage affecte ensuite des coordonnées 
   aleatoire comprises entre les 2 int a une pomme puis la renvoie */
Pomme pomme_gen_alea(int n, int m);

/* prend en argument 2 int correspondant respectivement a la largeur 
   et a la hauteur du quadrillage affecte ensuite des coordonnées 
   aleatoire comprises entre les 2 int a une case puis la renvoie */
Case mur_gen_alea(int n, int m);

#endif