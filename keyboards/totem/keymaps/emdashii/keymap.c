/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀
                                                           ▀  ▀  ▀  E M D A S H I I

▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

// Writing down magic works to make flashing easier in the future:
// Open QMK MSYS
// qmk compile -kb totem -km emdashii
// qmk flash -kb totem -km emdashii

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "totem.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘

enum totem_layers {
    _QWERTY,
  _NAVIGATION,
  _GAMING,
  _NUMBER,
  _ADJUST
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    LOWER,
    RAISE,
    ADJUST,
    OS_SWAP,
    MAKE_H,
    SNAP,
    SURROUND,
    LOREMIPSUM
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS QWERTY ├──────────────────┐
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// RIGHT HAND HOME ROW MODS QWERTY ├─────────────────┐
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Misc combined keys
#define COLON S(KC_SCLN)
#define NAV_RBR LSFT_T(KC_LBRC)
#define NAV_LBR LCTL_T(KC_RBRC)

// Left-hand thumb keys
#define TDELADJ LT(_ADJUST, KC_DEL)
#define TTABNAV LT(_NAVIGATION, KC_TAB)

// Right-hand thumb keys
#define TESCNUM LT(_NUMBER, KC_ESC)
#define TSPCNAV LT(_NAVIGATION, KC_SPC)

// Special layer navigation keys
#define SQWERTY DF(_QWERTY) // sets qwerty as base layer
#define LQWERTY TO(_QWERTY)
#define LNUM    TO(_NUMBER)
#define LGAMING TO(_GAMING)
// #define NUM_TOG LT(_NUMBER, CW_TOGG) this doesn't work


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ┌─────────────────────────────────────────────────┐
   │ q w e r t y                                     │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡    Q    │    W    │    E    │    R    │    T    ││    Y    │    U    │    I    │    O    │    P    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │    A    │    S    │    D    │    F    │    G    ││    H    │    J    │    K    │    L    │    ;    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │ NUM/ESC │    Z    │    X    │    C    │    V    │    B    ││    N    │    M    │    ,    │    .    │    /    │ CAPSWORD│
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │   DEL   │   TAB   │  ENTER  ││  REPEAT │  SPACE  │  BSPC   │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/

   [_QWERTY] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
                KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
              HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN,
    TESCNUM,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  CW_TOGG,
                                           TDELADJ, TTABNAV, KC_ENT,       QK_REPEAT_KEY, TSPCNAV,  KC_BSPC
 ),

/*

   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ n a v i g a t i o n / s y m b o l               │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡    !    │    @    │    #    │    $    │    %    ││    ^    │    &    │    *    │    _    │    `    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │   GUI   │   ALT   │    [    │    ]    │    \    ││    ←    │    ↓    │    ↑    │    →    │    '    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │    (    │    )    │    {    │    }    │    |    ││   HOME  │   PGDN  │   PGUP  │   END   │    "    │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         ││         │         │         │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/

   [_NAVIGATION] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
            KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_GRV,
            KC_LGUI, KC_LALT, NAV_RBR, NAV_LBR, KC_BSLS,                     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_QUOT,
     KC_TRNS, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PIPE,                     KC_HOME, KC_PGDN, KC_PGUP,  KC_END, S(KC_QUOT), KC_TRNS,
                                         KC_TRNS , KC_TRNS, KC_TRNS,       KC_TRNS, MO(_ADJUST), KC_TRNS
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ g a m i n g                                     │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡   TAB   │    Q    │    W    │    E    │    R    ││    Y    │    U    │    I    │    O    │    P    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │  SHIFT  │    A    │    S    │    D    │    F    ││    H    │    J    │    K    │    L    │    T    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   ESC   │   CTRL  │    1    │    2    │    3    │    4    ││    N    │    M    │    G    │    B    │    Z    │   ENT   │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │   DEL   │   TAB   │  ENTER  ││  REPEAT │  SPACE  │  BSPC   │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/

   [_GAMING] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
              KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L,   KC_T,
      KC_ESC, KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,                         KC_N,    KC_M,    KC_G,    KC_B,   KC_Z, KC_ENT,
                                            KC_F3,  KC_SPC, LNUM,         LQWERTY,  KC_SPC,  KC_BSPC
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ n u m b e r / f u n c t i o n                   │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡   INS   │   F7    │   F8    │   F9    │   F12   ││    *    │    7    │    8    │    9    │    0    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │ CAPSLOCK│   F4    │   F5    │   F6    │   F11   ││    =    │    4    │    5    │    6    │    .    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │ PRINTSCR│   F1    │   F2    │   F3    │   F10   ││    :    │    1    │    2    │    3    │    /    │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    ▼    │    ▼    │    ▼    ││    .    │    0    │         │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_NUMBER] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
                  KC_INS,  KC_F7,   KC_F8,   KC_F9,  KC_F10,                    S(KC_8),    KC_7,    KC_8,    KC_9, KC_0,
                 KC_CAPS,  KC_F4,   KC_F5,   KC_F6,  KC_F11,                     KC_EQL,    KC_4,    KC_5,    KC_6, KC_DOT,
      KC_TRNS,   KC_PSCR,  KC_F1,   KC_F2,   KC_F3,  KC_F12,                      COLON,    KC_1,    KC_2,    KC_3, KC_SLSH, KC_TRNS,
                                           KC_DEL, MO(_ADJUST), LGAMING,          KC_DOT,   KC_0,  KC_BSPC
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ a d j u s t                                     │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡   ALT   │  HOME   │    ↑    │   END   │   PG↑   ││ NUMLOCK │ SCRLLOCK│         │         │ VOL UP  │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │  SHIFT  │    ←    │    ↓    │    →    │   PG↓   ││  PREV   │ BRI DN  │ BRI UP  │  NEXT   │ VOL DN  │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │  CTRL   │   GUI   │   APP   │   INS   │         │  RESET  ││         │         │         │  PLAY   |   MUTE  │    ▼    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    ▼    │    ▼    │    ▼    ││    ▼    │ ADJUST  │    0    │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_ADJUST] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_LALT, KC_HOME,   KC_UP,  KC_END, KC_PGUP,                       KC_NUM, KC_SCRL, XXXXXXX, XXXXXXX, KC_VOLU,
               KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                     KC_MPRV, KC_BRID, KC_BRIU, KC_MNXT, KC_VOLD,
      KC_LCTL, KC_LGUI,  KC_APP,  KC_INS, XXXXXXX, QK_BOOT,                      SQWERTY, XXXXXXX, XXXXXXX, KC_MPLY, KC_MUTE, XXXXXXX,
                                          XXXXXXX, XXXXXXX, LQWERTY,      LGAMING, XXXXXXX, XXXXXXX
 )
/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ t e m p l a t e                                 │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡         │         │         │         │         ││         │         │         │         │         │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │         │         │         │         │         ││         │         │         │         │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ││         │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         ││         │         │         │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘

   [_TEMPLATE] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______,
              _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______,
    _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______, _______,
                                  _______,  _______,   _______,  _______,  _______,  _______,
 ),
*/
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ C O M B O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_equal[] = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM combo_plus[] = {HOME_K, HOME_L, COMBO_END};
const uint16_t PROGMEM combo_minus[] = {HOME_L, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM combo_tilde[] = {HOME_J, HOME_L, COMBO_END};
const uint16_t PROGMEM combo_backspace3[] = {HOME_K, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_surround[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_loremipsum[] = {KC_T, KC_Y, COMBO_END};

const uint16_t PROGMEM combo_equal2[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo_plus2[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM combo_minus2[] = {KC_6, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_tilde2[] = {KC_4, KC_6, COMBO_END};
const uint16_t PROGMEM combo_backspace2[] = {KC_5, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_equal, KC_EQUAL),
    COMBO(combo_plus, KC_PPLS),
    COMBO(combo_minus, KC_MINS),
    COMBO(combo_tilde, LSFT(KC_GRV)),
    COMBO(combo_backspace3, LCTL(KC_BACKSPACE)),
    COMBO(combo_backspace, LCTL(KC_BACKSPACE)),
    COMBO(combo_surround, SURROUND),
    COMBO(combo_loremipsum, LOREMIPSUM),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_equal2, KC_EQUAL),
    COMBO(combo_plus2, KC_PPLS),
    COMBO(combo_minus2, KC_MINS),
    COMBO(combo_tilde2, LSFT(KC_GRV)),
    COMBO(combo_backspace2, LCTL(KC_BACKSPACE)),
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                }
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys
            return false;
          }

// ┌─────────────────────────────────────────────────┐
// │ s u r r o u n d                                 │
// └─────────────────────────────────────────────────┘

        case SURROUND:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL) SS_DELAY(30));
                SEND_STRING(SS_LSFT("'"));
                SEND_STRING(SS_DELAY(30) SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTL) SS_DELAY(30));
                // tap_code(KC_LEFT);
                SEND_STRING(SS_DELAY(30) SS_LSFT("'"));
            }
            break;

// ┌─────────────────────────────────────────────────┐
// │ l o r e m   i p s u m                           │
// └─────────────────────────────────────────────────┘

        case LOREMIPSUM:
            if (record->event.pressed) {
                SEND_STRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. " SS_DELAY(50));
                SEND_STRING("Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. " SS_DELAY(50));
                SEND_STRING("Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. " SS_DELAY(50));
                SEND_STRING("Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
            }
            break;

// ┌─────────────────────────────────────────────────┐
// │ q m k                                           │
// └─────────────────────────────────────────────────┘

        case MAKE_H:
          if (record->event.pressed) {
            SEND_STRING("qmk compile -kb totem -km default");
            tap_code(KC_ENTER);
          }
          break;

// ┌─────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                         │
// └─────────────────────────────────────────────────┘

      case SNAP:
          if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
              SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4"))));  //MAC
            } else {
              SEND_STRING(SS_LSFT(SS_LWIN("S")));           //WIN
            }
          }
          break;
    }
    return true;
}
/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


                                                          ██████
                                                            ██  ▄▄▄▄
                                                            ██ ██▀▀██
                                                            ▀▀ ██▄▄██
                                                        ██████  ▀▀▀▀
                                                          ██ ▄▄▄▄▄▄
                                                          ██ ██▀▀▀▀
                                                          ██ ██████
                                                             ██▄▄▄▄
                                                             ▀▀▀▀▀▀
                                                           ████████
                                                           ██ ██ ██
                                                           ██ ██ ██
                                                           ▀▀ ▀▀ ▀▀
                                                          ████████

*/



