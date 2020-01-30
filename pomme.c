#include "pomme.h"

Pomme pomme_gen_alea(int n, int m){
	assert (n > 0);
	assert (m > 0);
	Pomme p ;

	p.pomme.x = MLV_get_random_integer (0,n) ;
	p.pomme.y = MLV_get_random_integer (0,m) ;		
	
	return p ;
}

Case mur_gen_alea(int n, int m){
	assert (n > 0);
	assert (m > 0);
	Case c ;

	c.x = MLV_get_random_integer (0,n) ;
	c.y = MLV_get_random_integer (0,m) ;		
	
	return c ;

}