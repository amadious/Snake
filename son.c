#include "son.h"

void son (MLV_Music* music){
    MLV_play_music( music, 1.0, -1 );
    MLV_wait_seconds(1);
    MLV_stop_music();
    MLV_free_music( music );
    MLV_free_audio();   
}   

