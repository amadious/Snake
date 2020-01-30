#include "affichage.h"
#include "plateau.h"
#define WIDTH 700
#define HEIGHT 700

int main(int argc, char const *argv[]){
	int temp = 0;
    char temp_text[50];

    Monde monde = init_monde(3,2);
	MLV_Keyboard_button touche;
    MLV_init_audio( );


	MLV_create_window( "snake", "tp3", WIDTH, HEIGHT );
	do{

    	MLV_clear_window(MLV_COLOR_BLACK);
		afficher_monde(&monde);	
        temp = MLV_get_time();//une fonction qui va recupere le temps depuis le lancement du jeux
        sprintf(temp_text,"Temps écoulés: %ds/120s",temp/1000 );//convertit le temps pour un char
        MLV_draw_adapted_text_box(500 ,100 ,temp_text,20 ,MLV_COLOR_GREEN,MLV_COLOR_BLUE,MLV_COLOR_WHITE,MLV_TEXT_CENTER);//affiche le temps
		MLV_actualise_window();    
		MLV_get_event (&touche, NULL, NULL,NULL, NULL,NULL, NULL, NULL,NULL);
		MLV_wait_milliseconds(50);
    	if( touche == MLV_KEYBOARD_z ){
    		monde.snake.dir.x = 0;
			monde.snake.dir.y = -1;
    	}  
    	if( touche == MLV_KEYBOARD_s ){
    		monde.snake.dir.x = 0;
			monde.snake.dir.y = 1;
    	}
    	if( touche == MLV_KEYBOARD_d ){
    		monde.snake.dir.x = 1;
			monde.snake.dir.y = 0;
    	}
    	if( touche == MLV_KEYBOARD_q ){
    		monde.snake.dir.x = -1;
			monde.snake.dir.y =  0;
    	}
    	while (touche == MLV_KEYBOARD_p){
    		// pour faire la pause 
    		MLV_wait_keyboard(&touche,NULL,NULL );	
    	}
    	touche = MLV_KEYBOARD_m ;
    	manger_pomme_serpent(&monde);
    	deplacer_serpent(&monde);
    }while (!(mort_serpent(&monde)) && temp/1000 < 120);

    

    MLV_free_window();
	return 0;
}

