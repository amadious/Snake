#ifndef __plateau__
#define __plateau__
#include "pomme.h"

typedef struct monde{
	Serpent snake ;
	Pomme apple[N * M];
	Pomme appleP[N * M];
	Case mur ;
	int nb_pommes;
	int nb_pommes_poisons;
	char nb_pomme_manger ;
}Monde;

/* prend une case et un monde en argument et verifie si 
   les coordonnées de la case corespondent a cellle d'une
   case occupée par une pomme, renvoie  1 si c'est le cas et 0 sinon. */
int est_case_pomme(Monde* monde_pomme, Case c);

/* prend une case et un monde en argument et verifie si 
   les coordonnées de la case corespondent a cellle d'une
   case occupée par le serpent, renvoie  1 si c'est le cas et 0 sinon. */
int est_case_serpent(Monde* monde_pomme, Case c);

/* prend une case et un monde en argument et verifie si 
   les coordonnées de la case corespondent a cellle d'une
   case occupée par une pomme empoisonnées, renvoie  1 si c'est le cas et 0 sinon. */
int est_case_pomme_poison(Monde* monde_pomme_poison, Case c);

/* ajoute une pomme generer aleatoirement par pomme_gen_alea dans un monde donné en argument */ 
void ajouter_pomme_monde(Monde *mon);

/* ajoute une pomme empoisonnées generer aleatoirement par pomme_gen_alea dans un monde donné en argument */ 
void ajouter_pomme_poison_monde(Monde *mon);

/* prend une case et un monde en argument et verifie si 
   les coordonnées de la case corespondent a cellle d'une
   case occupée par une pomme empoisonnées, si c'est le cas
   genere une nouvelle pomme et incremente le score (nb_pomme_manger) */
void supp_pomme(Monde* mon, Case c);

/* prend en argument un nombre de pomme et de pomme empoisonnées et 
   renvoie un monde dans sa position initiale avec le serpent initialisé
   grace init_serpent et le bon nombre de pommes données en arguments */
Monde init_monde(int nb_pommes, int nb_pommes_poisons);

/* prend un monde en argument et si la case suivante correspondante a la direction du serpent
   est une pomme, effectue la suppression de la pomme et se regeneraion ailleur
   assure aussi le deplacement suivant du serpent et l'augmentation de sa taille
   renvoie 1 si la case suivante est bien une pomme et 0 sinon */ 
int manger_pomme_serpent(Monde *mon);

/* prend un monde en argument et si la case suivante correspondante a la direction du serpent
   n'est pas une case occupée par quoi que ce soit, effectue le deplacement suivant du serpent
   et l'augmentation de sa taille renvoie 1 si la case suivante est bien libre et 0 sinon */ 
int deplacer_serpent(Monde *mon);

/* prend un monde en argument et si la case suivante correspondante a la direction du serpent
   est soit une partie du serpent, soit une case en dehors du quadrillage ou soit une pomme empoisonnées
   renvoie 1 et 0 sinon */ 
int mort_serpent(Monde *mon);

/* ajoute un mur generer aleatoirement par mur_gen_alea dans un monde donné en argument */ 
void ajouter_mur_monde(Monde *mon);

/* prend une case et un monde en argument et verifie si 
   les coordonnées de la case corespondent a cellle d'une
   case occupée par une pomme empoisonnées,serpent ,pomme
    renvoie  1 si c'est le cas et 0 sinon. */
int est_case_mur(Monde* mon,Case c);

/* prend une case et un monde en argument et une case et verifie si 
   les coordonnées de la case corespondent a cellle d'une
   case occupée par un mur , renvoie  1 si c'est le cas et 0 sinon. */
int mur_present(Monde *mon ,Case c);

#endif
