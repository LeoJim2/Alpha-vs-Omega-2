#include <allegro.h>
#include <allegro5/allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
int main()

{


    // inicializacion del allegro
	allegro_init();
	install_keyboard();
	install_mouse();
    al_install_audio();
    al_init_acodec_addon();

	//sonido
     //if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       //allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       //return 1;

    //}
    //set_volume(230, 200);
    //SAMPLE *sonido1 = load_wav("notify.wav");
    //play_sample(sonido1,200,150,1000,0);

    ALLEGRO_SAMPLE *nub = NULL;

    al_reserve_samples(30);
    nub = al_load_sample ("intro.ogg");
    al_play_sample(nub,1,0,1.2,ALLEGRO_PLAYMODE_ONCE,0);

    set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 530, 0, 0);

	//define variables utilizadas en el programa
	BITMAP *buffer = create_bitmap(800, 530);
	BITMAP *fondo1;
	BITMAP *fondo2;
	BITMAP *fondo3;
	BITMAP *cursor;
	BITMAP *omar;
	BITMAP *omar1;

	// inicializa las variables
	clear_to_color(buffer, 0x333333);
	fondo1 = load_bitmap("FONDO1.bmp",NULL);
	fondo2 = load_bitmap("FONDO2.bmp",NULL);
	fondo3 = load_bitmap("FONDO3.bmp",NULL);
	cursor = load_bitmap("cursor.bmp",NULL);


    bool salida = false;

    // primer menu simple
	while ( !salida )
	{
         // posicion del boton
         if ( mouse_x > 210 && mouse_x < 569 &&
              mouse_y > 319 && mouse_y < 387)
         {
            blit(fondo2, buffer, 0, 0, 0, 0, 800, 530);

            // se ha pulsado el boton del raton
            if ( mouse_b & 1 )
            {
                  salida = true;}}
            else if (mouse_x > 218 && mouse_x < 403 &&
                      mouse_y > 409 && mouse_y < 472)
                      {
                          blit(fondo3, buffer, 0, 0, 0, 0, 800, 530);
                          if ( mouse_b & 1 ){
                                salida = true;}}

         else{
            blit(fondo1, buffer, 0, 0, 0, 0, 800, 530);
         }

         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla
	     blit(buffer, screen, 0, 0, 0, 0, 800, 530);

          if ( key[KEY_ESC] )
          {
               salida = true;
          }

    }

    //declarar nuevas variables nuevo menu
    salida = false;
    destroy_bitmap(fondo1);
	destroy_bitmap(fondo2);
	destroy_bitmap(fondo3);
	fondo1 = load_bitmap ("omar.bmp", NULL);
	fondo2 = load_bitmap ("omar1.bmp", NULL);

    //segundo menu
    while(!salida){

        if (mouse_x > 240 && mouse_x < 530 &&
            mouse_y > 453 && mouse_x < 514 )
        {
            blit (fondo2 , buffer , 0 , 0 , 0 , 0, 800 , 530);
            if (mouse_b & 1)
            {
                salida = true;
            }
            }else {
                blit (fondo1 , buffer, 0 , 0 ,0 ,0 , 800, 530);
            }

        masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

	     blit(buffer, screen, 0, 0, 0, 0, 800, 530);


    if ( key [KEY_ENTER])
    {
        salida = true;
    }
    }

//escenario
    //declarar nuevas variables
    salida = false;
    destroy_bitmap(fondo1);
	destroy_bitmap(fondo2);
	al_destroy_sample(nub);

	fondo1 = load_bitmap ("omar2.bmp", NULL);

	ALLEGRO_SAMPLE *nub1 = NULL;

    al_reserve_samples(30);
    nub1 = al_load_sample ("Play.ogg");
    al_play_sample(nub1,2,0,1,ALLEGRO_PLAYMODE_ONCE,0);

while(!salida){

    blit (fondo1 , buffer, 0 , 0 ,0 ,0 , 800, 530);


blit(buffer, screen, 0, 0, 0, 0, 800, 530);


    if ( key[KEY_ESC])
          {
               salida = true;
          }


}

 // libera memoria quitando las imagenes
    destroy_bitmap(buffer);
	destroy_bitmap(fondo1);
    al_destroy_sample(nub1);
	destroy_bitmap(cursor);



	return 0;
}
END_OF_MAIN();
