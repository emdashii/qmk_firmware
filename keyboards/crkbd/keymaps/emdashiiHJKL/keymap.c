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

// Writing down magic works to make flashing easier in the future:
// Open QMK MSYS
// qmk compile -kb crkbd/rev1 -km emdashii36
// qmk flash -kb crkbd/rev1 -km emdashii36

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// QWERTY
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |   Q    |   W    |  E/nav |   R    |   T    |                    |   Y    |   U    |   I    |   O    |   P    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |  A/GUI | S/ALT  | D/SHIFT| F/CTRL |   G    |                    |   H    | J/CTRL | K/SHIFT| L/ALT  | ;/GUI  |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |   Z    |   X    |   C    |   V    |   B    |                    |   N    |   M    |   ,    |   .    |   /    |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             | Del/num| Tab/nav|Ent/Ctrl|  |ESC/Ctrl| Spc/nav|Bksp/num|
//                             `--------------------------'  `--------------------------'
  [_QWERTY] = LAYOUT_split_3x6_3(
      XXXXXXX,    KC_Q,    KC_W, LTHUMBE,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  XXXXXXX,
      XXXXXXX,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN, XXXXXXX,
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  XXXXXXX,
                                           TDELNUM, TTABNAV, TENTCTL,       TESCCTL, TSPCNAV,  TBKSNUM

  ),

// Navigation/Symbol
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |    !   |   @    |   #    |    $   |   %    |                    |   ^    |   &    |   *    |   _    |   ~    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |  GUI   |  ALT   | [/SHIFT| ]/CTRL |   \    |                    |  Left  |  Down  |   Up   | Right  | Insert |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |   (    |   )    |   {    |   }    |   |    |                    | Pg Up  |  Home  |  End   | Pg Dn  | Escape |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |  Bksp  |  Space | QWERTY |  |Ent/Ctrl|  Tab   |  Del   |
//                             `--------------------------'  `--------------------------'
  [_NAVIGATION] = LAYOUT_split_3x6_3(
     XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_TILD, XXXXXXX,
     XXXXXXX, NAV_PRN, NAV_ABK, NAV_CBR, NAV_BRC, KC_BSLS,                     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_INS, XXXXXXX,
     XXXXXXX, KC_RPRN,S(KC_DOT),KC_RCBR, KC_RBRC, KC_PIPE,                     KC_PGUP, KC_HOME,  KC_END, KC_PGDN,  KC_ESC, XXXXXXX,
                                         KC_BSPC, KC_SPC, LQWERTY,       TENTCTL, KC_TAB, KC_DEL

  ),

// Gaming
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  | Tab    |   Q    |   W    |   E    |   R    |                    |   Y    |   U    |   I    |   O    |   P    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  | Shift  |   A    |   S    |   D    |   F    |                    |   H    |   J    |   K    |   L    |   T    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  | Ctrl   |   1    |   2    |   3    |   4    |                    |   N    |   M    |   G    |   B    | Escape |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |   F3   | Space  | Number |  | QWERTY | Space  | Enter  |
//                             `--------------------------'  `--------------------------'
  [_GAMING] = LAYOUT_split_3x6_3(
      XXXXXXX,  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, XXXXXXX,
      XXXXXXX, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L,  KC_T, XXXXXXX,
      XXXXXXX, KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,                         KC_N,    KC_M,    KC_G,    KC_B, KC_ESC, XXXXXXX,
                                            KC_F3,  KC_SPC, LNUM,         LQWERTY,  KC_SPC,  KC_ENT

  ),

// Number/Function
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |   `    |   F7   |   F8   |   F9   |  F10   |                    |   /    |   7    |   8    |   9    |   -    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |   '    |   F4   |   F5   |   F6   |  F11   |                    |   =    |   4    |   5    |   6    |   +    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |   "    |   F1   |   F2   |   F3   |  F12   |                    |   :    |   1    |   2    |   3    |   *    |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |  Bksp  | Gaming |TOAdjust|  | Enter  |   0    |   .    |
//                             `--------------------------'  `--------------------------'
  [_NUMBER] = LAYOUT_split_3x6_3(
      XXXXXXX,    KC_GRV,  KC_F7,   KC_F8,   KC_F9,  KC_F10,                    KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, XXXXXXX,
      XXXXXXX,   KC_QUOT,  KC_F4,   KC_F5,   KC_F6,  KC_F11,                     KC_EQL,    KC_4,    KC_5,    KC_6, KC_PPLS, XXXXXXX,
      XXXXXXX,S(KC_QUOT),  KC_F1,   KC_F2,   KC_F3,  KC_F12,                      COLON,    KC_1,    KC_2,    KC_3, S(KC_8), XXXXXXX,
                                           KC_BSPC, LGAMING, LADJUST,       KC_ENT,   KC_0,  KC_DOT

  ),

// Adjust
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |  Reset |        |        |        |PrintScr|                    | NumLock|CapsLock|ScrollLock|Bright+| Vol+  |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  | On/Off | Hue ↑  | Sat ↑  | Brght ↑|        |                    |        |        |        | Bright-|  Vol-  |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  | Cycle  | Hue ↓  | Sat ↓  | Brght ↓|        |                    |SetQWERTY|       |        |        |  Mute  |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |        |        | QWERTY |  | Gaming |        |        |
//                             `--------------------------'  `--------------------------'
  [_ADJUST] = LAYOUT_split_3x6_3(
      XXXXXXX,  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                       KC_NUM, KC_CAPS, KC_SCRL, KC_BRIU, KC_VOLU, XXXXXXX,
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_VOLD, XXXXXXX,
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      SQWERTY, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX,
                                          XXXXXXX, XXXXXXX, LQWERTY,      LGAMING, XXXXXXX, XXXXXXX
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
                tap_code(KC_NUM_LOCK);
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
