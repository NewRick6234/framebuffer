#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 320
#define HEIGHT 200

uint32_t framebuffer[WIDTH * HEIGHT];

int main(int argc, char* argv[]) {
    // Inicializa o subsistema de vídeo da SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Cria a janela de teste
    SDL_Window* janela = SDL_CreateWindow(
        "Teste SDL2",                  // Título da janela
        SDL_WINDOWPOS_CENTERED,        // Posição X
        SDL_WINDOWPOS_CENTERED,        // Posição Y
        800,                           // Largura
        600,                           // Altura
        SDL_WINDOW_SHOWN               // Flags
    );

    if (!janela) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Mantém a janela aberta por 3 segundos (3000 ms)
    SDL_Delay(3000);

    // Destrói a janela e finaliza a SDL
    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;
}
