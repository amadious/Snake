#include "son.c"
#include "plateau.h"

int est_case_pomme(Monde* monde_pomme, Case c){
	assert(monde_pomme >= 0);
	
	int i = 0;
	for (i = 0; i < monde_pomme->nb_pommes; i++){
		if ((c.x == monde_pomme->apple[i].pomme.x ) && ((c.y) == monde_pomme->apple[i].pomme.y))
			return 1;
	}
	return 0;
}

int est_case_serpent(Monde* monde_serpent, Case c){
	assert(monde_serpent != NULL);

	int i = 0;
	for (i = 0; i < monde_serpent->snake.taille; i++){
		if ((c.x == monde_serpent->snake.tab[i].x ) && ((c.y) == monde_serpent->snake.tab[i].y))
			return 1;
	}return 0;
}

int est_case_pomme_poison(Monde* monde_pomme_poison, Case c){
	assert(monde_pomme_poison != NULL);
	
	int i = 0;
	for (i = 0; i < monde_pomme_poison->nb_pommes_poisons ; i++){
		if ((c.x == monde_pomme_poison->appleP[i].pomme.x ) && ((c.y) == monde_pomme_poison->appleP[i].pomme.y))
			return 1;
	}
	return 0;	
}

int est_case_mur(Monde* mon,Case c){
	assert(mon != NULL);

	Case cx1 = {c.x+1,c.y} ;
	Case cx2 = {c.x-1,c.y};
	Case cy1 = {c.x,c.y+1};
	Case cy2 = {c.x,c.y-1};
	
	if (est_case_pomme(mon, c) || est_case_serpent(mon, c) || est_case_pomme_poison(mon,c)
		|| est_case_serpent(mon,cy2) || est_case_serpent(mon,cy1) || est_case_serpent(mon,cx1)
		|| est_case_serpent(mon,cx2)){
		 return 1;
	}
	return 0;
}
 
void ajouter_pomme_monde(Monde *mon){
    assert(mon != NULL);

	Pomme p;
	do {
		p = pomme_gen_alea (N,M);
	// regenerer une nouvelle pomme tant que la case de la pomme est occupée
	}while ((est_case_pomme(mon, p.pomme)) || (est_case_serpent(mon, p.pomme)));
	
	mon->apple[mon->nb_pommes] = p;
	mon->nb_pommes++;
}

int mur_present(Monde *mon ,Case c){
	if (mon->mur.x == c.x && c.y == mon->mur.y)
		return 1;
	
	return 0 ;
}

void ajouter_pomme_poison_monde(Monde *mon){
    assert(mon != NULL);
	Pomme p;
	do {
		p = pomme_gen_alea (N,M);
	// regenerer une nouvelle pomme tant que la case de la pomme est occupée
	}while ((est_case_pomme(mon, p.pomme)) || (est_case_serpent(mon, p.pomme)) || (est_case_pomme_poison(mon,p.pomme)));
	
	mon->appleP[mon->nb_pommes_poisons] = p;
	mon->nb_pommes_poisons++;
}

void ajouter_mur_monde(Monde *mon){
	assert(mon != NULL);
	
	Case p;
	do {
		p = mur_gen_alea(N,M);
	// regenerer une nouveau mur tant que la case du mur est occupée
	}while (est_case_mur(mon,p));
	mon->mur = p ;
}

void supp_pomme(Monde* mon, Case c){
	assert(mon != NULL);


	int i = 0; 
	for (i =0; i < mon->nb_pommes; i++){
		if ((c.x == mon->apple[i].pomme.x) && (c.y == mon->apple[i].pomme.y)){
			mon->apple[i].pomme.x = MLV_get_random_integer (0,N) ;
			mon->apple[i].pomme.y = MLV_get_random_integer (0,M) ;
			mon->nb_pomme_manger += 1 ;	 
		}
	} 
}

Monde init_monde(int nb_pommes,int nb_pommes_poisons){
	assert(nb_pommes >= 0 );
	assert(nb_pommes_poisons >= 0);


	Monde world ;
 	world.snake = init_serpent();
 	world.nb_pommes = 0;
 	world.nb_pomme_manger = 0 ;	
	int i = 0 ;
	int ii = 0 ;

	while (i < nb_pommes){
		ajouter_pomme_monde(&world);
		i++ ;
	}
	while (ii < nb_pommes_poisons){
		ajouter_pomme_poison_monde(&world);
		ii++ ;
	}
	ajouter_mur_monde(&world);
	return world ;
}

int manger_pomme_serpent(Monde *mon){
	assert(mon != NULL);

	int i;
	Serpent* serpent = &mon->snake;
	Direction dir = serpent->dir;
	
	Case courante = serpent->tab[0];
	Case prochaine = {courante.x + dir.x, courante.y + dir.y};

	// verifier que la prochaine case est bien dans le quadrillage 
	if (prochaine.x < 0 || prochaine.y < 0 || prochaine.y > M+1 || prochaine.x > N+1)
		return 0;
	// verifier que le serpent n'est pas deja sur la case "prochaine"
	if (est_case_serpent(mon, prochaine))
		return 0;	
	// verifier que la case suivante est bien une pomme	
	if (est_case_pomme(mon, prochaine)){
		MLV_init_audio();
		MLV_Music* manger = MLV_load_music( "manger.mp3" );	
		son(manger);
		supp_pomme(mon, prochaine);
		ajouter_mur_monde(mon);
		serpent->taille = serpent->taille + 1 ;
		for (i = serpent->taille - 1; i > 0; i--) 
			serpent->tab[i] = serpent->tab[i-1];
		serpent->tab[0] = prochaine;
	}
	return 1;
}

int deplacer_serpent(Monde *mon){
	assert(mon != NULL);
		
	int i;
	Serpent* serpent = &mon->snake;
	Direction dir = serpent->dir;
	
	Case courante = serpent->tab[0];// a verifier 
	Case prochaine = {courante.x + dir.x, courante.y + dir.y};
	// verifier que la prochaine case est bien dans le quadrillage 
	if (prochaine.x < -1 || prochaine.y < -1 || prochaine.y > M || prochaine.x > N)
		return 0;
	// verifier qu'aucune pomme empoisonée n'est sur la case "prochaine"	
	if (est_case_pomme_poison(mon, prochaine))
		return 0 ; 
	// verifier que le serpent ou mur n'est pas deja sur la case "prochaine"
	if (est_case_serpent(mon, prochaine) || mur_present(mon,prochaine))
		return 0;	
	// avancer la tete du sepent vers la direction souhaiter grace a case suivante et faire suivre le corp
	for (i = serpent->taille + 1; i > 0; i--){
		serpent->tab[i].x = serpent->tab[i-1].x;
		serpent->tab[i].y = serpent->tab[i-1].y;
	}
	serpent->tab[0] = prochaine;
	return 1;
}

int mort_serpent(Monde *mon){
	assert(mon != NULL);

	Serpent* serpent = &mon->snake;
	Direction dir = serpent->dir;
	MLV_init_audio();
	MLV_Music* mort = MLV_load_music( "mort.mp3" );	

	Case courante = serpent->tab[0];
	Case prochaine = {courante.x + dir.x, courante.y + dir.y};
	// verifier que la prochaine case est bien dans le quadrillage 
	if (prochaine.x <-1 || prochaine.y <-1 || prochaine.y > M || prochaine.x > N){
		son(mort);
		return 1;
	}
	// verifier que le serpent n'est pas deja sur la case "prochaine"
	if (est_case_serpent(mon, prochaine)){
		son(mort);
		return 1;
	}
	// verifier qu'aucune pomme poison n'est sur la case "prochaine" ou un mur
	if (est_case_pomme_poison(mon, prochaine) ){
		son(mort);
		return 1;
	}
	if (mur_present(mon,prochaine)){
		son(mort);
		return 1;
	}
	else 
		return 0;
}