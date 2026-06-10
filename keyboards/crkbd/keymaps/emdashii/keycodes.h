/* Copyright 2022 toinux
  * Copyright 2022 emdashii
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

#pragma once

enum crkbd_layers {
  _QWERTY,
  _NAVIGATION,
  _NUMBER,
  _FUNCTION,
  _ADJUST
};

// NOTE: custom macro keycodes (SURROUND, SELLINE, ...) live in keymap.c, not
// here. This file shares the name "keycodes.h" with QMK's core header, so it
// gets pulled in very early during the include chain (via keymap_us.h) before
// SAFE_RANGE is defined -- anything referencing SAFE_RANGE must stay out.

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Layer access / exits
#define LOSLFUN OSL(_FUNCTION)   // base right-inner thumb: one-shot Function
#define SQWERTY DF(_QWERTY)      // set QWERTY as the default layer
#define LQWERTY TO(_QWERTY)      // jump back to base
#define LADJUST TO(_ADJUST)      // jump to Adjust

// Word delete on the base right-outer thumb (Ctrl+Backspace)
#define WORDDEL LCTL(KC_BSPC)
