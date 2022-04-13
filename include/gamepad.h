#pragma once

#include <common.h>

typedef struct {
    bool start;
    bool select;
    bool a;
    bool b;
    bool up;
    bool down;
    bool left;
    bool right;
} gamepad_state; //different button states. 0 =  pressed, 1 = not pressed

void gamepad_init();
bool gamepad_button_sel(); //A, B buttons //bools let us know what we are selecting
bool gamepad_dir_sel(); //directional pad //
void gamepad_set_sel(u8 value);

gamepad_state *gamepad_get_state(); //let us use it else where, such as ui
u8 gamepad_get_output(); //value reading from the bus