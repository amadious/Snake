#include "affichage.h"

void afficher_quadrillage(void){
    int i = 0 ;
    int j = 0 ;
    for (; i < N ; i++){
        for (j = 0; j < M; j++){
                MLV_draw_rectangle((i*10),j*10,10,10,MLV_COLOR_BLUE);
        }
    } 
}

void afficher_pomme(Pomme *pom){
	assert(pom != NULL);

	int i = 0 ;
	int j ;
	int x = pom->pomme.x ;
	int y = pom->pomme.y ;
	
	MLV_Image * image ;
	image =MLV_load_image	("pomme.jpg");	
	MLV_resize_image	(image,10,10);
    for (; i < N ; i++){
        for (j = 0; j < M; j++){
                if (i == x && j == y ){
                	//MLV_draw_filled_circle(i*10 + 5,j*10 + 5,3, MLV_COLOR_GREEN);
        			MLV_draw_image	(image,i*10 ,j*10);	
        		}
        }
    } 
}

void afficher_pomme_poison(Pomme *pom){
	assert(pom != NULL);

	int i = 0 ;
	int j ;
	int x = pom->pomme.x ;
	int y = pom->pomme.y ;
	MLV_Image * image ;
	image =MLV_load_image	("pommeP.jpg");	
	MLV_resize_image	(image,10,10);
    for (; i < N ; i++){
        for (j = 0; j < M; j++){
                if (i == x && j == y ){
                	//MLV_draw_filled_circle(i*10 + 5,j*10 + 5,3, MLV_COLOR_GREEN);
        			MLV_draw_image	(image,i*10 ,j*10);	
        		}
        }
    } 
}

void afficher_serpent(Serpent *ser){
	assert(ser != NULL);

	int i = 2 ;

	MLV_draw_filled_rectangle((ser->tab[0].x)*10,(ser->tab[0].y)*10,10,10, MLV_COLOR_ORANGE); 
	MLV_draw_filled_rectangle((ser->tab[1].x)*10,(ser->tab[1].y)*10,10,10, MLV_COLOR_RED);

	for (; i < ser->taille + 2; ++i){
		MLV_draw_filled_rectangle((ser->tab[i].x)*10,(ser->tab[i].y)*10,10,10, MLV_COLOR_RED); 
	}
}

void afficher_mur(Case c){
	assert(c.x >= 0 && c.y >= 0);

	MLV_draw_filled_rectangle(c.x*10,c.y*10,10,10, MLV_COLOR_RED);
}

void afficher_score(Monde *mon){
	assert(mon != NULL);

	char str[10] = "";
    int nombre = mon->nb_pomme_manger;
    sprintf(str, "%d", nombre); // transforme le score qui est un (int) en une chaine de caractere afin de l'afficher 
    MLV_draw_text(500, 335, "Votre score :", MLV_COLOR_WHITE);
    MLV_draw_text(535, 350, str, MLV_COLOR_WHITE);

}

void afficher_monde(Monde *mon ){
	assert(mon != NULL);
	assert(mon->mur.x >= 0 && mon->mur.y >= 0);
	assert(mon->apple != NULL);
	assert(mon->appleP != NULL);

	afficher_quadrillage();
	afficher_pomme(&(mon->apple[0]));
	afficher_pomme(&(mon->apple[1]));
	afficher_pomme(&(mon->apple[2]));
	afficher_pomme_poison(&(mon->appleP[0]));
	afficher_pomme_poison(&(mon->appleP[1]));	
	afficher_serpent(&(mon->snake));
	afficher_mur(mon->mur);
	afficher_score(mon);
}
