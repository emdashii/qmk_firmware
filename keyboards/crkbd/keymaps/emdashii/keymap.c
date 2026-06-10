/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 Elliott Claus <@emdashii>

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
#include "keycodes.h"

// Custom keycodes for productivity macros (combo-triggered on the base layer).
// Defined here rather than in keycodes.h to avoid the early-include name clash
// with QMK's core keycodes.h (see note there).
enum custom_keycodes {
  SURROUND = SAFE_RANGE,  // wrap the word at the cursor in double quotes
  SURROUND_SQ,            // wrap the word at the cursor in single quotes
  SELLINE,                // select the whole line
  COPY_LINE,              // copy the whole line
  DUPLINE,                // duplicate the whole line
  DELEND,                 // delete from the cursor to the end of the line
  LOREMIPSUM,             // type a lorem ipsum block
  EMDASH                  // insert an em dash
};


#ifdef OLED_ENABLE
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Base (QWERTY)
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |   Tab  |   Q    |   W    |   E    |   R    |   T    |                    |   Y    |   U    |   I    |   O    |   P    | Bksp   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | CapsWd |  A/GUI | S/ALT  | D/SHIFT| F/CTRL |   G    |                    |   H    | J/CTRL | K/SHIFT| L/ALT  | ;/GUI  |   '    |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | MO Num |   Z    |   X    |   C    |   V    |   B    |                    |   N    |   M    |   ,    |   .    |   /    | Escape |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |   Del  | MO Nav | Enter  |  | OSL Fn |  Space | C-Bksp |
//                                      `--------------------------'  `--------------------------'
  [_QWERTY] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,  KC_BSPC,
      CW_TOGG,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN,  KC_QUOT,
   MO(_NUMBER),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH,   KC_ESC,
                                  KC_DEL, MO(_NAVIGATION), KC_ENT,    LOSLFUN, KC_SPC, WORDDEL
  ),

// Navigation + Symbol
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |   !    |   @    |   #    |   $    |   %    |                    |   ^    |   &    |   *    |   (    |   )    | Bksp   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |  WIN   |  ALT   | SHIFT  |  CTRL  |   |    |                    |  Left  |  Down  |   Up   | Right  |        | Delete |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |   [    |   ]    |   {    |   }    |   \    |                    |  Home  | PgDn   | PgUp   |  End   |        | Escape |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      | Adjust |  Nav   | Enter  |  | LLock  |  Space |        |
//                                      `--------------------------'  `--------------------------'
  [_NAVIGATION] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_PIPE,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,  KC_DEL,
      XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,  KC_ESC,
                                         LADJUST, _______,  KC_ENT,     QK_LLCK,  KC_SPC, _______
  ),

// Number (numpad mirrored on both hands)
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |   +    |   7    |   8    |   9    |   /    |        |                    |   +    |   7    |   8    |   9    |   /    | Bksp   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |   -    |   4    |   5    |   6    |   0    |   =    |                    |   -    |   4    |   5    |   6    |   0    |   =    |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | MO Num |   1    |   2    |   3    |   .    |   *    |                    |   *    |   1    |   2    |   3    |   .    | Escape |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      | Adjust |  Nav   | Enter  |  | LLock  |  Space |        |
//                                      `--------------------------'  `--------------------------'
  [_NUMBER] = LAYOUT_split_3x6_3(
      KC_PLUS,    KC_7,    KC_8,    KC_9, KC_SLSH, XXXXXXX,                      KC_PLUS,    KC_7,    KC_8,    KC_9, KC_SLSH, KC_BSPC,
      KC_MINS,    KC_4,    KC_5,    KC_6,   KC_0,  KC_EQL,                       KC_MINS,    KC_4,    KC_5,    KC_6,   KC_0,   KC_EQL,
      _______,    KC_1,    KC_2,    KC_3,  KC_DOT, KC_ASTR,                      KC_ASTR,    KC_1,    KC_2,    KC_3,  KC_DOT,  KC_ESC,
                                         LADJUST, _______,  KC_ENT,     QK_LLCK,  KC_SPC, _______
  ),

// Function (one-shot from base right-inner thumb)
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |   F1   |   F2   |   F3   |   F4   |   F5   |                    |   F6   |   F7   |   F8   |   F9   |   F10  |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | CapsLk |        |        |        |        |        |                    |  F11   |  Prev  |  Play  |  Next  | Vol +  |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |  F12   |  Mute  |  Menu  |PrntScr | Vol -  |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  | LLock  |        |        |
//                                      `--------------------------'  `--------------------------'
  [_FUNCTION] = LAYOUT_split_3x6_3(
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
      KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F11, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F12, KC_MUTE,  KC_APP, KC_PSCR, KC_VOLD, XXXXXXX,
                                         _______, _______, _______,     QK_LLCK, _______, _______
  ),

// Adjust (toggle access from Nav / Number)
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |  Boot  | EE Clr |        |        |        |PrntScr |                    | NumLck |        | ScrlLk |        | Bright+|        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | RGB Tg | Hue +  | Sat +  | Val +  | Spd +  |        |                    | QWERTY |        |        |        | Bright-|        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | RGB Md | Hue -  | Sat -  | Val -  | Spd -  |        |                    | QWERTY |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  | LLock  |        |        |
//                                      `--------------------------'  `--------------------------'
  [_ADJUST] = LAYOUT_split_3x6_3(
      QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                       KC_NUM, XXXXXXX, KC_SCRL, XXXXXXX, KC_BRIU, XXXXXXX,
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX,                      SQWERTY, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, XXXXXXX,
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, XXXXXXX,                      LQWERTY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                         _______, _______, _______,     QK_LLCK, _______, _______
  )
};

// Combos (base layer) ---------------------------------------------------------
const uint16_t PROGMEM combo_equal[]  = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM combo_plus[]   = {HOME_K, HOME_L, COMBO_END};
const uint16_t PROGMEM combo_minus[]  = {HOME_L, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM combo_tilde[]  = {HOME_J, HOME_L, COMBO_END};
const uint16_t PROGMEM combo_emdash[] = {HOME_K, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM combo_dquote[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_squote[] = {KC_I, KC_P, COMBO_END};
const uint16_t PROGMEM combo_selline[]= {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_copyln[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_dupln[]  = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_lorem[]  = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_delend[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_equal,  KC_EQL),
    COMBO(combo_plus,   KC_PLUS),
    COMBO(combo_minus,  KC_MINS),
    COMBO(combo_tilde,  KC_TILD),
    COMBO(combo_emdash, EMDASH),
    COMBO(combo_dquote, SURROUND),
    COMBO(combo_squote, SURROUND_SQ),
    COMBO(combo_selline,SELLINE),
    COMBO(combo_copyln, COPY_LINE),
    COMBO(combo_dupln,  DUPLINE),
    COMBO(combo_lorem,  LOREMIPSUM),
    COMBO(combo_delend, DELEND),
};

void set_keylog(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif // OLED_ENABLE

    if (record->event.pressed) {
        switch (keycode) {
            case SURROUND:
                // Select the word at the cursor and wrap it in double quotes.
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) "\"" SS_LCTL(SS_TAP(X_RIGHT)) "\"");
                return false;
            case SURROUND_SQ:
                // Same, but single quotes.
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) "'" SS_LCTL(SS_TAP(X_RIGHT)) "'");
                return false;
            case SELLINE:
                // Home, Shift+End -> selects the whole line.
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
                return false;
            case COPY_LINE:
                // SELLINE + Ctrl+C.
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)) SS_LCTL("c"));
                return false;
            case DUPLINE:
                // COPY_LINE + End, Enter, Ctrl+V.
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)) SS_LCTL("c")
                            SS_TAP(X_END) SS_TAP(X_ENTER) SS_LCTL("v"));
                return false;
            case DELEND:
                // Shift+End, Delete -> trims from cursor to end of line.
                SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DELETE));
                return false;
            case LOREMIPSUM:
                SEND_STRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                            "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
                return false;
            case EMDASH:
                // Windows Alt+0151 numpad code for an em dash.
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_1)
                            SS_TAP(X_KP_5) SS_TAP(X_KP_1) SS_UP(X_LALT));
                return false;
        }
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
