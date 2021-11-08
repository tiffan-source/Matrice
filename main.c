#include <stdio.h>
#include "matrice.h"
#include <SDL/SDL.h>

// void pause()
// {
//     int continuer = 1;
//     SDL_Event event;
 
//     while (continuer)
//     {
//         SDL_WaitEvent(&event);
//         switch(event.type)
//         {
//             case SDL_QUIT:
//                 continuer = 0;
//         }
//     }
// }

int main(){

    // SDL_Surface *screen = NULL;
    // SDL_Surface *rectangle = NULL;

    // SDL_Rect position;

    // position->x = 0;
    // position->y = 50;
    // Uint32 mycolor;

    // if(SDL_Init(SDL_INIT_VIDEO)==-1){
    //     printf("Erreur d'initialisation : %s\n", SDL_GetError());
    //     exit(EXIT_FAILURE);
    // }

    // screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    // if(screen==NULL){
    //     printf("Mode video non chargé : %s \n", SDL_GetError());
    //     exit(EXIT_FAILURE);
    // }

    // SDL_WM_SetCaption("Matrice calculator", NULL);
    
    // mycolor = SDL_MapRGB(screen->format, 255, 255, 255);
    // SDL_FillRect(screen, NULL, mycolor);

    // rectangle= SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 100, 32, 0, 0, 0, 0);
    // SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->type, 255, 0, 0));

    // SDL_BlitSurface(rectangle, NULL, screen, &position);

    // SDL_Flip(screen);
    // pause();

    // SDL_FreeSurface(rectangle);
    // SDL_Quit();

    Matrice *myTrix = createMatrice(4, 4);

    printf("%f\n", determinant(myTrix));

    return 0;
}