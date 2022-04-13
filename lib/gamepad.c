#include <gamepad.h>
#include <string.h>

typedef struct {
    bool button_sel;
    bool dir_sel; //let us know what we are selecting
    gamepad_state controller; //call the controller
}gamepad_context;

static gamepad_context ctx = {0}; //initialising

bool gamepad_button_sel() {
    return ctx.button_sel; //returns the selected button
}

//from the bus write
bool gamepad_dir_sel() {
    return ctx.dir_sel; //returns selected direction
}

void gamepad_set_sel(u8 value) {
    ctx.button_sel = value & 0x20; //checks if it is a button sel of dir sel
    ctx.dir_sel = value & 0x10;   //based on what bit is set (bit 5 and bit 4) 
}

gamepad_state *gamepad_get_state() {
    return &ctx.controller;
}

u8 gamepad_get_output() {
    u8 output = 0xCF; //starts with this output value
    //starts as everything set, and then set set based on what is selected.

    if (!gamepad_button_sel()) {
        if (gamepad_get_state()->start) {
            output &= ~(1 << 3);
        } 
        if (gamepad_get_state()->select) {
            output &= ~(1 << 2);
        } 
        if (gamepad_get_state()->a) {
            output &= ~(1 << 0);
        } 
        if (gamepad_get_state()->b) {
            output &= ~(1 << 1);
        }
    }

    if (!gamepad_dir_sel()) {
        if (gamepad_get_state()->left) {
            output &= ~(1 << 1);
        } 
        if (gamepad_get_state()->right) {
            output &= ~(1 << 0);
        } 
        if (gamepad_get_state()->up) {
            output &= ~(1 << 2);
        } 
        if (gamepad_get_state()->down) {
            output &= ~(1 << 3);
        }
    }

    return output;
}