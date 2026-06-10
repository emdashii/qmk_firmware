/* Copyright 2022 @toinux
  * Copyright 2022 @emdashii
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */


#include QMK_KEYBOARD_H
#include "keycodes.h"

// LED index reference (from the template at the bottom of this file).
// Base home-row keys: A S D F (L) / J K L ; (R).
static const char home_leds[] = {22, 19, 16, 11, 38, 43, 46, 49};

// Navigation: only the four arrow keys. Kept minimal because the per-key
// indicators (rgb_matrix_set_color) bypass RGB_MATRIX_MAXIMUM_BRIGHTNESS, and
// lighting many keys at full brightness browned out the TRRS-powered right half.
static const char nav_leds[] = {
    35, 38, 43, 46           // right home row: arrows (Left Down Up Right)
};

// Number: the mirrored numpad block on both hands.
// Number: only the 0-9 digit keys on both hands (same current concern as nav).
static const char num_leds[] = {
    23, 18, 17,              // left:  7 8 9
    22, 19, 16, 11,          // left:  4 5 6 0
    21, 20, 15,              // left:  1 2 3
    37, 44, 45,              // right: 7 8 9
    38, 43, 46, 49,          // right: 4 5 6 0
    39, 42, 47               // right: 1 2 3
};

// Function: F1-F12, plus Caps Lock on the left home pinky.
static const char fun_leds[] = {
    23, 18, 17, 10,  9,      // left top row: F1-F5
    25,                      // left home pinky: Caps Lock
    36, 37, 44, 45, 50,      // right top row: F6-F10
    35,                      // right home pinky: F11
    34                       // right bottom pinky: F12
};

// Adjust: the RGB control block on the left hand.
static const char adjust_leds[] = {
    25, 22, 19, 16, 11,      // left home row: RGB toggle / hue / sat / val / spd up
    26, 21, 20, 15, 12       // left bottom row: RGB mode / hue / sat / val / spd down
};

// Dimmed indicator colors (~1/4 of the full RGB_* macros) for the layers that
// light keys on both hands, to keep current low on the TRRS-powered right half.
#define NAV_DIM_PINK       60, 30, 45   // dim pink
#define NUM_DIM_GOLDENROD  55, 42, 8    // dim goldenrod


/*
  _QWERTY     = RGB_CORAL  home row, with access keys in their own colors
  _NAVIGATION = RGB_PINK
  _NUMBER     = RGB_GOLDENROD
  _FUNCTION   = RGB_MAGENTA
  _ADJUST     = RGB_RED
*/

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(25, RGB_RED);              // Caps Word / Caps Lock spot
    }
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:
            for (uint8_t i = 0; i < sizeof(home_leds); i++) {
                rgb_matrix_set_color(home_leds[i], RGB_CORAL);
            }
            rgb_matrix_set_color(25, RGB_WHITE);        // Caps Word
            rgb_matrix_set_color(13, RGB_PINK);         // MO Navigation (left middle thumb)
            rgb_matrix_set_color(26, RGB_GOLDENROD);    // MO Number (lower-left pinky)
            rgb_matrix_set_color(33, RGB_MAGENTA);      // OSL Function (right inner thumb)
            break;
        case _NAVIGATION:                               // held layer, no jump hints
            for (uint8_t i = 0; i < sizeof(nav_leds); i++) {
                rgb_matrix_set_color(nav_leds[i], NAV_DIM_PINK);
            }
            break;
        case _NUMBER:                                   // held layer, no jump hints
            for (uint8_t i = 0; i < sizeof(num_leds); i++) {
                rgb_matrix_set_color(num_leds[i], NUM_DIM_GOLDENROD);
            }
            break;
        case _FUNCTION:                                 // one-shot, no jump hints
            for (uint8_t i = 0; i < sizeof(fun_leds); i++) {
                rgb_matrix_set_color(fun_leds[i], RGB_MAGENTA);
            }
            break;
        case _ADJUST:                                   // toggle layer, keeps jump hints
            rgb_matrix_set_color(24, RGB_GREEN);        // Boot
            for (uint8_t i = 0; i < sizeof(adjust_leds); i++) {
                rgb_matrix_set_color(adjust_leds[i], RGB_RED);
            }
            rgb_matrix_set_color(36, RGB_RED);          // Num Lock
            rgb_matrix_set_color(44, RGB_RED);          // Scroll Lock
            rgb_matrix_set_color(35, RGB_CORAL);        // DF(QWERTY)
            rgb_matrix_set_color(34, RGB_CORAL);        // TO(QWERTY)
            break;
    }
    return false;
}

// CRKBD LED TEMPLATE (learned through much thought (and trial and error))
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |   24   |   23   |   18   |   17   |   10   |    9   |                    |   36   |   37   |   44   |   45   |   50   |   51   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |   25   |   22   |   19   |   16   |   11   |    8   |                    |   35   |   38   |   43   |   46   |   49   |   52   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |   26   |   21   |   20   |   15   |   12   |    7   |                    |   34   |   39   |   42   |   47   |   48   |   53   |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |   14   |   13   |   6    |  |   33   |   40   |   41   |
//                                      `--------------------------'  `--------------------------'

/*
Colors (Not using HSV for some reason? idk)

RGB	                HSV
RGB_AZURE	        HSV_AZURE
RGB_BLACK/RGB_OFF	HSV_BLACK/HSV_OFF
RGB_BLUE	        HSV_BLUE
RGB_CHARTREUSE	    HSV_CHARTREUSE
RGB_CORAL	        HSV_CORAL
RGB_CYAN	        HSV_CYAN
RGB_GOLD	        HSV_GOLD
RGB_GOLDENROD	    HSV_GOLDENROD
RGB_GREEN	        HSV_GREEN
RGB_MAGENTA	        HSV_MAGENTA
RGB_ORANGE	        HSV_ORANGE
RGB_PINK	        HSV_PINK
RGB_PURPLE	        HSV_PURPLE
RGB_RED	            HSV_RED
RGB_SPRINGGREEN	    HSV_SPRINGGREEN
RGB_TEAL	        HSV_TEAL
RGB_TURQUOISE	    HSV_TURQUOISE
RGB_WHITE	        HSV_WHITE
RGB_YELLOW	        HSV_YELLOW

*/
