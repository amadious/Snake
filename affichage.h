#ifndef __affichage__
#define __affichage__
#include "plateau.h"
#include <MLV/MLV_all.h>

/* affiche le quadrillage N*M */
void afficher_quadrillage();

/* affiche le quadrillage N*M */
void afficher_pomme(Pomme *pom);

/* la meme chose avec une pomme (bleu) poison  */
void afficher_pomme_poison(Pomme *pom);

/* prend un serpent en argument et l'affiche sur le quadrillage */
void afficher_serpent(Serpent *ser);

/* prend un monde en argument et recupere nb_pomme_manger afin d'afficher le score */
void afficher_score(Monde *mon);

/* prend un monde en argument et affiche tout ce qu'il contient (quadrillage, pomme, score, sepent, mur, score)*/
void afficher_monde(Monde *mon);

/* affiche un mur sur une case données */
void afficher_mur(Case c);
#endif
