#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
void CreateWindow2();

void CreateWindow2(){
    SDL_Window *window2 = SDL_CreateWindow("Tic Tac Toe player 2",
                                          700, 100,
                                          WIDTH, HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (window2 == NULL) {
        SDL_Log("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window2, -1,
                                                SDL_RENDERER_ACCELERATED |
                                                SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_DestroyWindow(window2);
        SDL_Log("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Delay(5000);
}

#endif // AFFICHAGE_H_INCLUDED
