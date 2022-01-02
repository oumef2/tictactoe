#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
typedef struct {
    char nom[20];
    char pass.word[20];
    int score;
}user;

user *DATA;
DATA = (user*)malloc(sizeof (user ));

void Login( SDL_Window window);



#endif // LOGIN_H_INCLUDED
