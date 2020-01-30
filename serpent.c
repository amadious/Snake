#include "serpent.h"

Serpent init_serpent(void){
	Serpent snake ;
	snake.tab[0] = (Case) {N/2, M/2};
	snake.tab[1] = (Case) {N/2 - 1, M/2};
	snake.dir.x = 1 ;
	snake.dir.y = 0 ;

	snake.taille = 2;
	int i = 2 ;
	for (; i <= snake.taille + 2; ++i){
			snake.tab[i] = (Case) {N/2 - i, M/2};		
	}
	return snake ;
}