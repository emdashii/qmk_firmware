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
  _GAMING,
  _NUMBER,
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

// Nav home row mods KC_LPRN,S(KC_COMM),KC_LCBR,KC_LBRC,
#define NAV_PRN LGUI_T(KC_LPRN)
#define NAV_ABK LALT_T(KC_LABK)
#define NAV_CBR LSFT_T(KC_LCBR)
#define NAV_BRC LCTL_T(KC_LBRC)

// Left-hand thumb keys
#define TDELNUM LT(_NUMBER, KC_DEL)
#define TTABNAV LT(_NAVIGATION, KC_TAB)
#define TENTCTL LCTL_T(KC_ENT)

// Right-hand thumb keys
#define TESCCTL LCTL_T(KC_ESC)
#define TSPCNAV LT(_NAVIGATION, KC_SPC)
#define TBKSNUM LT(_NUMBER, KC_BSPC)

// Special layer navigation keys
#define SQWERTY DF(_QWERTY) // sets qwerty as base layer
#define LQWERTY TO(_QWERTY)
#define LNAV    TO(_NAVIGATION)
#define LADJUST TO(_ADJUST)
#define LNUM    TO(_NUMBER)
#define LGAMING TO(_GAMING)
#define LTHUMBE LT(_NAVIGATION, KC_E)

// Misc combined keys
#define CTRLSPC LCTL_T(KC_SPC)
#define CTRLSFT C(KC_LSFT)
#define COLON S(KC_SCLN)
#define TABLGUI LGUI_T(KC_TAB)
#define LCAPSFT LSFT_T(KC_CAPS)

