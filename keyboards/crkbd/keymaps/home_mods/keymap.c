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
// #include <stdio.h>

// Layer Modifiers
#define LY_NAV LT(1, KC_BSPC)
#define LY_SYMB LT(2, KC_ESC)
#define LY_NUMS LT(4, KC_SPC)
#define LY_MEDIA LT(5, KC_DEL)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

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
#define _MEDIA 32


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    CAPS_WORD,  HOME_A,  HOME_R,  HOME_S,  HOME_T,   KC_D,                       KC_H,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TG(3),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, S(KC_BSLS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         LY_MEDIA,  LY_NAV,  LY_NUMS,  KC_ENT,  LY_SYMB, MAC_CAPTURE 
                                      //`--------------------------'  `--------------------------'

  ),

  // NAVIGATION
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,  MOD_F6,  MOD_F7,  MOD_F8,  MOD_F9,  KC_F10,                      KC_UNDS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,  KC_F11,  KC_F12,  CUT,     COPY,    PASTE,                       KC_PLUS, KC_BSLS, KC_HASH, KC_PERC, KC_CIRC, S(KC_GRV),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______ ,  _______
                                      //`--------------------------'  `--------------------------'
  ),

  // SYMBOLS
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GESC, KC_EXLM, KC_AT,   KC_DLR,  KC_AMPR, KC_ASTR,                     _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, MOD_LT, MOD_LSBR, MOD_LCBR, MOD_LPRN, KC_MINS,                    _______, _______, _______, _______, _______,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_GT,   KC_RBRC, KC_RCBR, KC_RPRN, KC_EQL,                      _______, _______, _______, _______, _______,  _______,
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

  // MEDIA
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, BL_BRTG,  _______, VOL_DN,  VOL_UP,   MUTE,                       _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  } 
  return OLED_ROTATION_270;
}

// void oled_render_layer_state(void) {
//     oled_write_P(PSTR("\n\n"), false);
//     switch (layer_state) {
//         case _COLEMAK:
//             oled_write_ln_P(PSTR("BASE"), false);
//             break;
//         case _NAV:
//             oled_write_ln_P(PSTR("NAV"), false);
//             break;
//         case _SYMBOLS:
//             oled_write_ln_P(PSTR("SYMBL"), false);
//             break;
//         case _NUMS:
//             oled_write_ln_P(PSTR("NUMS"), false);
//             break;
//         case _MEDIA:
//             oled_write_ln_P(PSTR("MEDIA"), false);
//             break;
//         case _MOUSE:
//         case _MOUSE|_NAV:
//         case _MOUSE|_SYMBOLS:
//         case _MOUSE|_NUMS:
//         case _MOUSE|_MEDIA:
//         case _MOUSE|_NAV|_SYMBOLS|_NUMS|_MEDIA:
//             oled_write_ln_P(PSTR("MOUSE"), false);
//             break;
//     }
// }

void render_layer_state(void) {
    oled_write_ln_P(PSTR("LAYER"), false);
    oled_write_ln_P(PSTR("--*--"), false);
    oled_write_ln_P(PSTR("COLEM"), layer_state_is(0));
    oled_write_ln_P(PSTR("SYMBL"), layer_state_is(2));
    oled_write_ln_P(PSTR("NAVIG"), layer_state_is(1));
    oled_write_ln_P(PSTR("MOUSE"), layer_state_is(3));
    oled_write_ln_P(PSTR("MEDIA"), layer_state_is(5));
    oled_write_ln_P(PSTR("NUMS "), layer_state_is(4));
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // oled_render_layer_state();
        render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}


#endif // OLED_ENABLE

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