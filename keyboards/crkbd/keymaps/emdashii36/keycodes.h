/* Copyright 2022 toinux
  * Copyright 2023 emdashii
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
  _MINECRAFT,
  _NUMBER,
  _FUNCTION,
  _ADJUST
};


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

// Left-hand thumb keys
#define TDELFUN LT(_FUNCTION, KC_DEL)
#define TTABNAV LT(_NAVIGATION, KC_TAB)
#define TENTNUM LT(_NUMBER, KC_ENT)

// Right-hand thumb keys
#define TNAVNUM LT(_NUMBER, TO(_NAVIGATION))
#define TSPCNAV LT(_NAVIGATION, KC_SPC)
#define TBKSFUN LT(_FUNCTION, KC_BSPC)

// Special layer navigation keys
#define SQWERTY DF(_QWERTY) // sets qwerty as base layer
#define LQWERTY TO(_QWERTY)
#define LNAV    TO(_NAVIGATION)
#define LADJUST TO(_ADJUST)
#define LNUM    TO(_NUMBER)
#define LFUN    TO(_FUNCTION)
#define LMINECR TO(_MINECRAFT)

// Misc combined keys
#define CTRLSPC LCTL_T(KC_SPC)
#define CTRLSFT C(KC_LSFT)
#define COLON S(KC_SCLN)
#define TABLGUI LGUI_T(KC_TAB)
#define LCAPSFT LSFT_T(KC_CAPS)

// Tab movement
#define TABFWRD C(KC_TAB)
#define TABBKWD C(S(KC_TAB))

//OSM(MOD_LSFT) One Shot Modifer Shift Key
