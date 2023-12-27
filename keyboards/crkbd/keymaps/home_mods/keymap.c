/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdint.h>
#include "oled.c"
#include "os_detection.h"
// #include "quantum.h"


// Layer Modifiers
#define LY_NAV LT(1, KC_T)
#define LY_SYMB LT(2, KC_ESC)
#define LY_NUMS LT(4, KC_SPC)
#define LY_FUN LT(5, KC_M)
// #define LY_MEDIA LT(5, KC_DEL)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_D LCTL_T(KC_D)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

// Left-hand layer 1 home row mods
#define MOD_F6 LGUI_T(KC_F6)
#define MOD_F7 LALT_T(KC_F7)
#define MOD_F8 LSFT_T(KC_F8)
#define MOD_F9 LCTL_T(KC_F9)

// Left-hand layer 2 home row mods
#define MOD_LT LGUI_T(S(KC_LT))
#define MOD_LSBR LALT_T(KC_LBRC)
#define MOD_LCBR LSFT_T(S(KC_LCBR))
#define MOD_LPRN LCTL_T(S(KC_LPRN))

// Right-hand layer 2 home row mods
// #define MOD_ LGUI_T(S(KC_LT))
#define MOD_6 LALT_T(KC_6)
#define MOD_5 LSFT_T(KC_5)
#define MOD_4 LCTL_T(KC_4)

// Mouse keys
#define MOUSE_U KC_MS_UP
#define MOUSE_D KC_MS_DOWN
#define MOUSE_L KC_MS_LEFT
#define MOUSE_R KC_MS_RIGHT
#define MS_L_CL KC_MS_BTN1
#define MS_R_CL KC_MS_BTN2

// Shortcuts
#define CR_AL_SUP C(A(KC_DEL))
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define MAC_CAPTURE LCMD(S(KC_5))

// Media
#define VOL_UP KC_KB_VOLUME_UP
#define VOL_DN KC_KB_VOLUME_DOWN
#define MUTE KC_KB_MUTE

#define _COLEMAK 0
#define _NAV 2
#define _SYMBOLS 4
#define _MOUSE 8
#define _NUMS 16
#define _FUN 32
// #define _MEDIA 32


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    QK_LEAD,  HOME_A,  HOME_R,  HOME_S,  LY_NAV,   HOME_D ,                     KC_H,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    CW_TOGG,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,   LY_FUN,   KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         TG(3),  KC_DEL,  LY_NUMS,  KC_ENT,  LY_SYMB, MAC_CAPTURE 
                                      //`--------------------------'  `--------------------------'

  ),

  // NAVIGATION
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                       _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______ ,  _______
                                      //`--------------------------'  `--------------------------'
  ),

  // SYMBOLS
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV, KC_EXLM, KC_AT,   KC_DLR,  KC_AMPR, KC_ASTR,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, MOD_LT, MOD_LSBR, MOD_LCBR, MOD_LPRN, KC_MINS,                     XXXXXXX, _______, _______, _______, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_GT,   KC_RBRC, KC_RCBR, KC_RPRN, KC_EQL,                      XXXXXXX, KC_HASH, KC_PERC, KC_CIRC,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // MOUSE
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______,  _______, _______, _______, _______,                    CR_AL_SUP, MS_L_CL, MOUSE_U, MS_R_CL, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, MOUSE_L, MOUSE_D, MOUSE_R, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_WH_D, KC_WH_U, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, TG(3),  _______,     _______, TG(3), _______
                                      //`--------------------------'  `--------------------------'
  ),

  // NUMS
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                     KC_PLUS,  KC_7,    KC_8,    KC_9,  _______,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                     KC_UNDS,  MOD_4,   MOD_5,   MOD_6,  KC_RGUI,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_0,    KC_1,    KC_2,    KC_3,   _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______,  _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    // FUNCS
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,  MOD_F6,  MOD_F7,  MOD_F8,  MOD_F9,  KC_F10,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,  KC_F11,  KC_F12,  CUT,     COPY,    PASTE,                      _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )

  // // MEDIA
  // [5] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //    _______, BL_BRTG,  _______, VOL_DN,  VOL_UP,   MUTE,                       _______, _______, _______, _______, _______, _______,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                      _______, _______, _______, _______, _______, _______,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,                      _______, _______, _______, _______, _______, _______,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         _______, _______, _______,    _______, _______, _______
  //                                     //`--------------------------'  `--------------------------'
  // )
};

// Per-key tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return TAPPING_TERM + 350;
        
        case HOME_O:
            return TAPPING_TERM + 350;

        case HOME_R:
            return TAPPING_TERM + 250;

        case HOME_I:
            return TAPPING_TERM + 250;

        default:
            return TAPPING_TERM;
    }
}

// Intercept layer 2 home modifiers
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(S(KC_LT)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_LT)); 
                return false;        
            }
            break;

        case LSFT_T(S(KC_LCBR)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_LCBR)); 
                return false;        
            }
            break;

        case LCTL_T(S(KC_LPRN)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_LPRN)); 
                return false;        
            }
            break;
    }
    return true;
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A)  || LALT_T(KC_R) :
            return true;
        default:
            return false;
    }
}


const uint16_t PROGMEM esc_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_A, KC_R, COMBO_END};

combo_t key_combos[] = {  
    COMBO(esc_combo, KC_ESC),
    // TODO: Change for regurlar key code, not working
    COMBO(caps_combo, CW_TOGG),
};

void leader_end_user(void){
  uint8_t host_os = detected_host_os();

  switch (host_os){
    case OS_LINUX:
      if(leader_sequence_one_key(KC_N)){
        SEND_STRING(SS_LALT("1"));
  
      }else if (leader_sequence_one_key(KC_E)){
        SEND_STRING(SS_LALT("2"));
  
      }else if (leader_sequence_one_key(KC_I)){
        SEND_STRING(SS_LALT("3"));
  
      }
      break;

    default:
      if(leader_sequence_one_key(KC_N)){
        SEND_STRING(SS_LCTL("1"));
  
      }else if (leader_sequence_one_key(KC_E)){
        SEND_STRING(SS_LCTL("2"));
  
      }else if (leader_sequence_one_key(KC_I)){
        SEND_STRING(SS_LCTL("3"));
  
      }
      break;
  }

  
}
