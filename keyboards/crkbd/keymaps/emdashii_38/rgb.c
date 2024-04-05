/* Copyright 2022 @toinux
  * Copyright 2024 @emdashii
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


                                                                        // count:
static const char qwerty_leds[] = {22, 19, 16, 11, 38, 43, 46, 49};     // 8
static const char gaming_leds[] = {17, 11, 19, 16, 13};                 // 5
//static const char sym_leds[] = {22,19,16,11,21,20,15,12};               // 8
static const char nav_leds[] = {35, 38, 43, 46};                        // 4
static const char num_leds[] = {45, 44, 37, 46, 43, 38, 47, 42, 39, 40}; // 10
//static const char fun_leds[] = {45, 44, 37, 46, 43, 38, 47, 42, 39, 50, 49, 48}; // 12
static const char fun_leds[] = {7, 8, 9, 18, 19, 20, 17, 16, 15, 10, 11, 12};    // 12
static const char adjust_leds[] = {22, 19, 16, 21, 20, 15, 11, 12};     // 8
static const char adjust_other_leds[] = {36, 37, 44, 50, 49, 9};        // 6
//static const char mouse_leds[] = {17, 19, 16, 11, 7, 8, 9, 34, 35, 36}; // 10


/*
  _QWERTY = RGB_CORAL   (calm white)
  _NAVIGATION = RGB_PINK
  _GAMING = RGB_SPRINGGREEN
  _NUMBER = RGB_GOLDENROD
  _FUNCTION = RGB_MAGENTA
  _ADJUST = RGB_RED

  // this layer doesn't exist anymore
  _SYMBOL = RGB_ORANGE
*/

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(13, RGB_RED);
    }
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _QWERTY:
            for (uint8_t i = 0; i < 8; i++) {
                rgb_matrix_set_color(qwerty_leds[i], RGB_CORAL);
            }
            rgb_matrix_set_color(40, RGB_GOLDENROD);             // To Numbers
            rgb_matrix_set_color(13, RGB_PINK);             // To Nav
            rgb_matrix_set_color(17, RGB_GOLDENROD);          // To Function keys
            break;
        case _NAVIGATION:
            for (uint8_t i = 0; i < 4; i++) {
                rgb_matrix_set_color(nav_leds[i], RGB_PINK);
            }
            rgb_matrix_set_color(40, RGB_RED);          // To Adjust
            break;
        case _GAMING:
            if (is_keyboard_master()) {
                for (uint8_t i = 0; i < 5; i++) {
                    rgb_matrix_set_color(gaming_leds[i], RGB_SPRINGGREEN);
                }
            }
            rgb_matrix_set_color(48, RGB_RED);              // Escape key
            rgb_matrix_set_color(33, RGB_CORAL);            // To qwerty
            rgb_matrix_set_color(13, RGB_SPRINGGREEN);      // Spacebar
            rgb_matrix_set_color(6, RGB_GOLDENROD);          // To number keys
            break;
        case _NUMBER:
            for (uint8_t i = 0; i < 10; i++) {
                rgb_matrix_set_color(num_leds[i], RGB_GOLDENROD);
            }
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color(fun_leds[i], RGB_PURPLE);
            }
            rgb_matrix_set_color(13, RGB_RED);            // To adjust
            rgb_matrix_set_color(6, RGB_SPRINGGREEN);      // To gaming
            break;
        case _ADJUST:
            rgb_matrix_set_color(23, RGB_GREEN);            // Reset key
            for (uint8_t i = 0; i < 8; i++) {
                rgb_matrix_set_color(adjust_leds[i], RGB_RED);
            }
            for (uint8_t i = 0; i < 6; i++) {
                rgb_matrix_set_color(adjust_other_leds[i], RGB_RED);
            }
            rgb_matrix_set_color(6, RGB_CORAL);            // To qwerty
            rgb_matrix_set_color(33, RGB_SPRINGGREEN);      // To gaming
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

//static const char fun_leds[] = {21, 22, 23, 18, 19, 20, 17, 16, 15, 10, 11, 12}; // 12

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
