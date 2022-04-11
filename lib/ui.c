#include <ui.h>
#include <emu.h>
#include <bus.h>
#include <ppu.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

//SDL Objects
SDL_Window *sdlWindow;
SDL_Renderer *sdlRenderer;
SDL_Texture *sdlTexture;
SDL_Surface *screen;

SDL_Window *sdlDebugWindow;
SDL_Renderer *sdlDebugRenderer;
SDL_Texture *sdlDebugTexture;
SDL_Surface *debugScreen;

static int scale = 4; //to allow window scaling

void ui_init() {
    
    SDL_Init(SDL_INIT_VIDEO);
    printf("SDL INIT\n");
    TTF_Init();
    printf("TTF INIT\n");

    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &sdlWindow, &sdlRenderer);

    screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
                                            0x00FF0000,
                                            0x0000FF00,
                                            0x000000FF,
                                            0xFF000000);
    sdlTexture = SDL_CreateTexture(sdlRenderer,
                                                SDL_PIXELFORMAT_ARGB8888,
                                                SDL_TEXTUREACCESS_STREAMING,
                                                SCREEN_WIDTH, SCREEN_HEIGHT);

    //16 tiles by 32 tiles, 8 pixel long, scale factor for resizing
    SDL_CreateWindowAndRenderer(16 * 8 * scale, 32 * 8 * scale, 0, 
        &sdlDebugWindow, &sdlDebugRenderer);

    debugScreen = SDL_CreateRGBSurface(0, (16 * 8 * scale) + (16 * scale), 
                                            (32 * 8 * scale) + (64 * scale), 32,
                                            0x00FF0000,
                                            0x0000FF00,
                                            0x000000FF,
                                            0xFF000000);

    sdlDebugTexture = SDL_CreateTexture(sdlDebugRenderer,
                                            SDL_PIXELFORMAT_ARGB8888,
                                            SDL_TEXTUREACCESS_STREAMING,
                                            (16 * 8 * scale) + (16 * scale), 
                                            (32 * 8 * scale) + (64 * scale));

    //set the position of debug window to right of the main window
    int x, y;
    SDL_GetWindowPosition(sdlWindow, &x, &y);
    SDL_SetWindowPosition(sdlDebugWindow, x + SCREEN_WIDTH + 10, y);
    SDL_SetWindowTitle(sdlWindow, "AkBoy Emu");
    SDL_SetWindowTitle(sdlDebugWindow, "Debug Window");
}

void delay(u32 ms) {
    SDL_Delay(ms);
}

u32 get_ticks() {
    return SDL_GetTicks();
}

static unsigned long tile_colors[4] = {0xFFFFFFFF, 0xFFAAAAAA, 0xFF555555, 0xFF000000}; 

void displayTile(SDL_Surface *surface, u16 startLocation, u16 tileNum, int x, int y) {
    SDL_Rect rc;

    //loop through tiles
    //16 tiles, each tile being 2 bytes
    for (int tileY=0; tileY<16; tileY += 2) {
        u8 b1 = bus_read(startLocation + (tileNum * 16) + tileY);
        u8 b2 = bus_read(startLocation + (tileNum * 16) + tileY + 1);
        //above gives data for one line
        //loop through bits to display it 
        for (int bit=7; bit >= 0; bit--) {
            //2-bit value for the colour of the current pixel
            u8 hi = !!(b1 & (1 << bit)) << 1;
            u8 lo = !!(b2 & (1 << bit));

            u8 color = hi | lo;

            rc.x = x + ((7 - bit) * scale);
            rc.y = y + (tileY / 2 * scale);
            rc.w = scale;
            rc.h = scale;

            SDL_FillRect(surface, &rc, tile_colors[color]);
        }
    }
}

//display all tiles that get loaded eventually to the OAM RAM section
void updateDebugWindow() {
    int xDraw = 0;
    int yDraw = 0;
    int tileNum = 0;

    SDL_Rect rc;
    rc.x = 0;
    rc.y = 0;
    rc.w = debugScreen->w;
    rc.h = debugScreen->h;
    SDL_FillRect(debugScreen, &rc, 0xFF111111); //fill screen as realy dark grey

    u16 addr = 0x8000; //start of tile data according to pandocs
    //384 total tiles, 24 x 16 displaying

    for(int y = 0; y<24; y++) {
        for(int x = 0; x<16; x++) {
            displayTile(debugScreen, addr, tileNum, xDraw + (x * scale), yDraw + (y * scale));
            xDraw += (8 * scale); //update to next location after drawing
            tileNum++; //update tile number
        }
        yDraw += (8 * scale);
        xDraw = 0;
    }

    SDL_UpdateTexture(sdlDebugTexture, NULL, debugScreen->pixels, debugScreen->pitch);
	SDL_RenderClear(sdlDebugRenderer);
	SDL_RenderCopy(sdlDebugRenderer, sdlDebugTexture, NULL, NULL);
	SDL_RenderPresent(sdlDebugRenderer);

}

//public member, to update the debug window
void ui_update() {
    SDL_Rect rc;
    rc.x = rc.y = 0;
    rc.w = rc.h = 2048;

    u32 *video_buffer = ppu_get_context()->video_buffer;

    for (int line_num = 0; line_num < YRES; line_num++) {
        for (int x = 0; x < XRES; x++) {
            rc.x = x * scale;
            rc.y = line_num * scale;
            rc.w = scale;
            rc.h = scale;

            SDL_FillRect(screen, &rc, video_buffer[x + (line_num * XRES)]);
        }
    }

    SDL_UpdateTexture(sdlTexture, NULL, screen->pixels, screen->pitch);
    SDL_RenderClear(sdlRenderer);
    SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
    SDL_RenderPresent(sdlRenderer);
    updateDebugWindow();
}

void ui_handle_events() {
    SDL_Event e;
    while (SDL_PollEvent(&e) > 0)
    {
        //TODO SDL_UpdateWindowSurface(sdlWindow);
        //TODO SDL_UpdateWindowSurface(sdlTraceWindow);
        //TODO SDL_UpdateWindowSurface(sdlDebugWindow);

        if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE) {
            emu_get_context()->die = true;
        }
    }
}

