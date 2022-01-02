
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#define WIDTH 500
#define HEIGHT 500

#include "affichage.h"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Could not initialize sdl2: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window1 = SDL_CreateWindow("Tic Tac Toe GAME",100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window1 == NULL) {
        SDL_Log("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window1, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_DestroyWindow(window1);
        SDL_Log("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Rect rect ={0,0,500,500};
    SDL_Surface* picture = SDL_LoadBMP("intro5.BMP");
    if(!picture)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Texture* intro = SDL_CreateTextureFromSurface(renderer ,picture );
    SDL_FreeSurface(picture );
    if( intro == NULL ){
        SDL_Log("ERROR > % \n", SDL_GetError());
        return EXIT_FAILURE;
    }

    if(SDL_QueryTexture(intro, NULL, NULL, WIDTH, HEIGHT) != 0){
        SDL_Log("ERROR > % \n", SDL_GetError());
        return EXIT_FAILURE;
    }

    if(SDL_RenderCopy(renderer, intro, NULL ,&rect)!= 0){
        SDL_Log("ERROR > % \n", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_RenderPresent(renderer);

    SDL_Delay(5000);


    //Login(window1);
    //CreateWindow2();
    /*game_t game = {
        .board = { EMPTY, EMPTY, EMPTY,
                   EMPTY, EMPTY, EMPTY,
                   EMPTY, EMPTY, EMPTY },
        .player = PLAYER_X,
        .state = RUNNING_STATE
    };

    SDL_Event e;
    while (game.state != QUIT_STATE) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                game.state = QUIT_STATE;
                break;

            case SDL_MOUSEBUTTONDOWN:
                click_on_cell(&game,
                              e.button.y / CELL_HEIGHT,
                              e.button.x / CELL_WIDTH);
                break;

            default: {}
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        render_game(renderer, &game);
        SDL_RenderPresent(renderer);
    }
*/
    SDL_RenderClear(renderer);
    SDL_DestroyWindow(window1);
    SDL_Quit();

    return EXIT_SUCCESS;
}
