/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 Elliott Claus <@emdashii>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
// #include <stdio.h>
#include "keycodes.h"


#ifdef OLED_ENABLE
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// QWERTY
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |   Q    |   W    |   E    |   R    |   T    |                    |   Y    |   U    |   I    |   O    |   P    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |  A/GUI | S/ALT  | D/SHIFT| F/CTRL | G/Num  |                    | H/Num  | J/CTRL | K/SHIFT| L/ALT  | ;/GUI  |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |   Z    |   X    |   C    |   V    |  B/Fn  |                    |  N/Fn  |   M    |   ,    |   .    |   /    |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |   Del  | Shift  |  Bksp  |  |   Nav  |Spc/Meh | Enter  |
//                             `--------------------------'  `--------------------------'
  [_QWERTY] = LAYOUT_split_3x6_3(
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  XXXXXXX,
      XXXXXXX,  HOME_A,  HOME_S,  HOME_D,  HOME_F,   NUM_G,                        NUM_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN, XXXXXXX,
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,   FUN_B,                        FUN_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  XXXXXXX,
                                           KC_DEL, SFT_SFT, KC_BSPC,       LNAV, MEH_SPC,  KC_ENT

  ),

//  Navigation
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |        |  Home  |   Up   |  End   | Pg Up  |                    |   ^    |   &    |   *    |   ~    |  Esc   |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  | Tab    |  Left  |  Down  | Right  | Pg Dn  |                    |        |        |        |        |   '    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  | Insert |Tab Back|        |Tab Fwd |        |                    |        |   _    |   +    |   \    |   `~   |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |   Alt  | Shfit  | QWERTY |  | Number |Spc/Ctrl|  LGui  |
//                             `--------------------------'  `--------------------------'
  [_NAVIGATION] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX,  KC_HOME,  KC_UP,  KC_END, KC_PGUP,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_TILD, KC_ESC,  XXXXXXX,
      XXXXXXX,  KC_TAB,  KC_LEFT,KC_DOWN, KC_RGHT, KC_PGDN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, XXXXXXX,
      XXXXXXX,  KC_INS, TABBKWD, XXXXXXX, TABFWRD, KC_BTN2,                      XXXXXXX, KC_UNDS, KC_PPLS, KC_BSLS,  KC_GRV, XXXXXXX,
                                          KC_LALT, SFT_SFT, LQWERTY,       LNUM, CTRLSPC, KC_LGUI

  ),

// Minecraft
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  | Tab    |   Q    |   W    |   E    |   R    |                    |   Y    |   U    |   I    |   O    |   P    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  | Shift  |   A    |   S    |   D    |   F    |                    |   H    |   J    |   K    |   L    | Escape |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  | Ctrl   |   1    |   2    |   3    |   4    |                    |   N    |   M    |   G    |   B    |   T    |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |   F3   | Space  | QWERTY |  | Number |  Fun   | Enter  |
//                             `--------------------------'  `--------------------------'
  [_MINECRAFT] = LAYOUT_split_3x6_3(
      XXXXXXX,  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, XXXXXXX,
      XXXXXXX, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, KC_ESC, XXXXXXX,
      XXXXXXX, KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,                         KC_N,    KC_M,    KC_G,    KC_B,   KC_T, XXXXXXX,
                                            KC_F3,  KC_SPC, LQWERTY,         LNUM,  LFUN,  KC_ENT

  ),

// Number/Symbol
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |    !   |   @    |   #    |   $    |   %    |                    |   *    |   7    |   8    |   9    |   +    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |   (    |   <    |   {    |   [    |        |                    |   =    |   4    |   5    |   6    |   -    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |   )    |   >    |   }    |   ]    |   |    |                    |   :    |   1    |   2    |   3    |   /    |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |   Del  |Spc/Ctrl| QWERTY |  | Fuction|   0    |   .    |
//                             `--------------------------'  `--------------------------'
  [_NUMBER] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_ASTR,    KC_7,    KC_8,    KC_9, KC_PPLS, XXXXXXX,
      XXXXXXX, KC_LPRN,S(KC_COMM),KC_LCBR,KC_LBRC, XXXXXXX,                       KC_EQL,    KC_4,    KC_5,    KC_6, KC_MINS, XXXXXXX,
      XXXXXXX, KC_RPRN,S(KC_DOT),KC_RCBR, KC_RBRC, KC_PIPE,                        COLON,    KC_1,    KC_2,    KC_3, KC_SLSH, XXXXXXX,
                                           KC_DEL, CTRLSPC,  LQWERTY,       LFUN,   KC_0,  KC_DOT

  ),

// Fuction/Mouse
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |  Acl0  | Wh up  | Ms up  | Wh dn  |        |                    |Mid Clic|   F7   |   F8   |   F9   |   F10  |        
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |  Acl1  | Ms lft | Ms dn  | Ms rgt |        |                    |Rt Click|   F4   |   F5   |   F6   |   F11  |        
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |  Acl2  | Wh lft |        | Wh rgt |        |                    |LeftClic|   F1   |   F2   |   F3   |   F12  |        
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |        |  Num   | QWERTY |  | Adjsut |  Nav   | Minecraft |
//                             `--------------------------'  `--------------------------'
  [_FUNCTION] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_ACL0, KC_WH_U, KC_MS_U, KC_WH_D, XXXXXXX,                        KC_BTN3,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
      XXXXXXX, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                        KC_BTN1,   KC_F4,   KC_F5,   KC_F6,  KC_F11, XXXXXXX,
      XXXXXXX, KC_ACL2, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX,                        KC_BTN2,   KC_F1,   KC_F2,   KC_F3,  KC_F12, XXXXXXX,
                                          XXXXXXX,    LNUM, LQWERTY,        LADJUST,  LNAV, LMINECR

  ),

// Adjust
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |  Reset |        |        |        |PrintScr|                    | NumLock|CapsLock|ScrollLock|Bright+| Vol+  |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  | On/Off | Hue ↑  | Sat ↑  | Brght ↑|        |                    |        |        |        | Bright-|  Vol-  |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  | Cycle  | Hue ↓  | Sat ↓  | Brght ↓|        |                    |SetQWERTY|       |        |        |  Mute  |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |        |        | QWERTY |  | Gaming |  Nav   |        |
//                             `--------------------------'  `--------------------------'
  [_ADJUST] = LAYOUT_split_3x6_3(
      XXXXXXX,   RESET, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                       KC_NUM, KC_CAPS, KC_SCRL, KC_BRIU, KC_VOLU, XXXXXXX,
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_VOLD, XXXXXXX,
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      SQWERTY, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX,
                                          XXXXXXX, XXXXXXX, LQWERTY,      LMINECR,  LNAV, XXXXXXX
  )
};

void set_keylog(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif // OLED_ENABLE

    switch (keycode) {
        case LADJUST:
            if  (!host_keyboard_led_state().num_lock) {
                tap_code(KC_NUMLOCK);
            }
        return true;
        break;
    }
    return true;
}

void keyboard_post_init_user(void) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
#endif
}


// Template from @toinux

// TEMPLATE
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'

// Template from @emdashii

// TEMPLATE
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |        |        |        |        |        |                    |        |        |        |        |        |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |        |        |        |        |        |                    |        |        |        |        |        |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |        |        |        |        |        |                    |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
