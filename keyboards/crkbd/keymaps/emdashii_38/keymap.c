/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2024 Elliott Claus <@emdashii>

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
// qmk compile -kb crkbd/rev1 -km emdashii_38
// qmk flash -kb crkbd/rev1 -km emdashii_38

// this keymap is a demo for the TOTEM keyboard

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// QWERTY
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |   Q    |   W    |  E/adj |   R    |   T    |                    |   Y    |   U    |   I    |   O    |   P    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |  A/GUI | S/ALT  | D/SHIFT| F/CTRL |   G    |                    |   H    | J/CTRL | K/SHIFT| L/ALT  | ;/GUI  |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//ESC|  Z    |   X    |   C    |   V    |   B    |                    |   N    |   M    |   ,    |   .    |   /    |CAPS WORD
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |Del/Adj |  TAB   |  ENT   |  | REPEAT | Spc/NUM|  Bksp  |
//                             `--------------------------'  `--------------------------'
  [_QWERTY] = LAYOUT_split_3x6_3(
      XXXXXXX,    KC_Q,    KC_W, LTHUMBE,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  XXXXXXX,
      XXXXXXX,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN, XXXXXXX,
      TESCNUM,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  CW_TOGG,
                                           TDELADJ, TTABNUM, KC_ENT,       QK_REPEAT_KEY, TSPCNAV,  KC_BSPC

  ),

// Navigation/Symbol
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  |    !   |   @    |   #    |    $   |   %    |                    |   ^    |   &    |   *    |   _    |   `    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |  GUI   |  ALT   | [/SHIFT| ]/CTRL |   \    |                    |  Left  |  Down  |   Up   | Right  |   '    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |   (    |   )    |   {    |   }    |   |    |                    |  Home  | Pg Dn  | Pg Up  |  End   |   "    |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |        |        |        |  |        | ADJUST |        |
//                             `--------------------------'  `--------------------------'
  [_NAVIGATION] = LAYOUT_split_3x6_3(
     XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_GRV, XXXXXXX,
     XXXXXXX, KC_LGUI, KC_LALT, NAV_RBR, NAV_LBR, KC_BSLS,                     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_QUOT, XXXXXXX,
     KC_TRNS, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PIPE,                     KC_HOME, KC_PGDN, KC_PGUP,  KC_END, S(KC_QUOT), KC_TRNS,
                                         KC_TRNS , KC_TRNS, KC_TRNS,       KC_TRNS, MO(_ADJUST), KC_TRNS

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
      KC_ESC, KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,                         KC_N,    KC_M,    KC_G,    KC_B, KC_Z, KC_ENT,
                                            KC_F3,  KC_SPC, LNUM,         LQWERTY,  KC_SPC,  KC_BSPC

  ),

// Number/Function
//  ,--------------------------------------------.                    ,--------------------------------------------.
//  | Insert |   F7   |   F8   |   F9   |  F10   |                    |   *    |   7    |   8    |   9    |   +    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |  CAPS  |   F4   |   F5   |   F6   |  F11   |                    |   =    |   4    |   5    |   6    |   -    |
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//  |PrintScr|   F1   |   F2   |   F3   |  F12   |                    |   :    |   1    |   2    |   3    |   /    | 0
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |   DEL  | ADJUST |ToGaming|  |   .    |   0    |  BKSP  |
//                             `--------------------------'  `--------------------------'
  [_NUMBER] = LAYOUT_split_3x6_3(
      XXXXXXX,    KC_INS,  KC_F7,   KC_F8,   KC_F9,  KC_F10,                    S(KC_8),    KC_7,    KC_8,    KC_9, KC_PPLS, XXXXXXX,
      XXXXXXX,   KC_CAPS,  KC_F4,   KC_F5,   KC_F6,  KC_F11,                     KC_EQL,    KC_4,    KC_5,    KC_6, KC_MINS, XXXXXXX,
      KC_TRNS,   KC_PSCR,  KC_F1,   KC_F2,   KC_F3,  KC_F12,                      COLON,    KC_1,    KC_2,    KC_3, KC_SLSH, KC_0,
                                           KC_DEL, MO(_ADJUST), LGAMING,          KC_DOT,   KC_0,  KC_BSPC

  ),

// Adjust
//  ,--------------------------------------------.                    ,--------------------------------------------.
//Hue↑|Alt   | Home   |   Up   |  End   | Pg Up  |                    | NumLock|ScrollLock|Brght ↓|Brght ↑| Vol+   | Sat ↑
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//Hue↓| Shift|  Left  |  Down  | Right  | Pg Dn  |                    |PrevTrack|Bright-|Bright+|NextTrack|  Vol-  | Sat ↓
//  |--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
//CTRL| Meta |  App   |   Ins  |        |  RESET |                    |SetQWERTY| On/Off| Cycle  |Play/Pause| Mute |
//  `--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------'
//                             |        | Reset  | QWERTY |  | Gaming |        |        |
//                             `--------------------------'  `--------------------------'
  [_ADJUST] = LAYOUT_split_3x6_3(
      RGB_HUI, KC_LALT, KC_HOME,   KC_UP,  KC_END, KC_PGUP,                       KC_NUM, KC_SCRL, RGB_VAD, RGB_VAI, KC_VOLU, RGB_SAI,
      RGB_HUD, KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,              KC_MPRV, KC_BRID, KC_BRIU, KC_MNXT, KC_VOLD, RGB_SAD,
      KC_LCTL, KC_LGUI,  KC_APP, KC_INS, XXXXXXX, QK_BOOT,                      SQWERTY, RGB_TOG, RGB_MOD, KC_MPLY, KC_MUTE, XXXXXXX,
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
