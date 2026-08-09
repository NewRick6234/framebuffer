#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 320
#define HEIGHT 200

uint32_t framebuffer[WIDTH * HEIGHT];

int main(void) {    
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;

    // Cria a janela de teste
    window = SDL_CreateWindow(
        "SDL FrameBuffer",  
                     // Título da janela
        WIDTH,
        HEIGHT,
        0
    );

    if (!window) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Mantém a janela aberta por 3 segundos (3000 ms)
    SDL_Delay(3000);

    // Destrói a janela e finaliza a SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
