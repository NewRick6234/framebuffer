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
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    // Cria a janela de teste
    window = SDL_CreateWindow(
        "SDL FrameBuffer", 
        WIDTH *4,
        HEIGHT *4,
        0
    );
    renderer = SDL_CreateRenderer(
        window,
        "software"
    );

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_XRGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WIDTH,
        HEIGHT
    );

    SDL_SetTextureScaleMode(texture,SDL_SCALEMODE_NEAREST);
    
    uint8_t is_running = 1;
    while (is_running)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_EVENT_QUIT){
                is_running = 0;
            }
            
        }

        framebuffer[16500]=0xFF0000;
        SDL_UpdateTexture(
            texture,
            NULL,
            framebuffer,
            WIDTH  * sizeof(uint32_t)

        );
        
        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer,texture,NULL,NULL);
        SDL_RenderPresent(renderer);
        /* code */
    }
    
     
    // Destrói a janela e finaliza a SDL
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
