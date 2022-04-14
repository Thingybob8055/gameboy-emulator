#include <emu.h>
#include <nfd.h>
#include <string.h>

int main() {
    NFD_Init();

    nfdchar_t *outPath;
    nfdfilteritem_t filterItem[1] = { { "Gameboy ROM", "gb" }};
    nfdresult_t result = NFD_OpenDialog(&outPath, filterItem, 1, NULL);
    if (result == NFD_OKAY) {
        puts("Success!");
        puts(outPath);
    }
    else if (result == NFD_CANCEL) {
        puts("User pressed cancel.");
        exit(-1);
    }
    else {
        printf("Error: %s\n", NFD_GetError());
        exit(-1);
    }

    NFD_Quit();
    return emu_run((char*)outPath);
}