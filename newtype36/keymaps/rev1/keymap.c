/*
Copyright 2024 ProtieusKeebs

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

enum combo_events {
    COMBO_ENT,
    COMBO_ESC,
    COMBO_TAB,
    COMBO_CAPS,
    COMBO_SPECIAL,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_ent[] = {RALT_T(KC_K),   RCTL_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {LCTL_T(KC_S),   LALT_T(KC_D), COMBO_END};
const uint16_t PROGMEM combo_caps[] = {LSFT_T(KC_A), RSFT_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM combo_special[] = {LT(1,KC_BSPC), LT(3,KC_SPC), COMBO_END};

combo_t key_combos[] = {
    [COMBO_ENT] = COMBO(combo_ent, KC_ENT),
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
    [COMBO_CAPS] = COMBO(combo_caps, KC_CAPS),
    [COMBO_SPECIAL] = COMBO(combo_special, MO(4))
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, 1, 2, 3);
// } 

enum layer_names {
  _BASE,
  _FN1,
  _FN2,
  _FN3,
  _FN4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_BASE] = LAYOUT(
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
        LSFT_T(KC_A),   LCTL_T(KC_S),   LALT_T(KC_D),   LGUI_T(KC_F),   HYPR_T(KC_G),   HYPR_T(KC_H),   RGUI_T(KC_J),   RALT_T(KC_K),   RCTL_T(KC_L),   RSFT_T(KC_SCLN),
        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                        _______,        LT(2,KC_DEL),   LT(1,KC_BSPC),  LT(3,KC_SPC),   _______,        _______
    ),
    [_FN1] = LAYOUT(
        _______,        _______,        KC_UP,          _______,        _______,        KC_NUM,         KC_7,           KC_8,           KC_9,           KC_PMNS,
        _______,        KC_LEFT,        KC_DOWN,        KC_RGHT,        _______,        KC_PSLS,        KC_4,           KC_5,           KC_6,           KC_PPLS,
        _______,        _______,        _______,        _______,        _______,        KC_PAST,        KC_1,           KC_2,           KC_3,           KC_PEQL,
                                        _______,        _______,        _______,        KC_NO,          KC_0,           KC_PDOT
    ),
    [_FN2] = LAYOUT(
        _______,        _______,        KC_END,         KC_HOME,        _______,        KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END,         _______,
        _______,        _______,        KC_MS_BTN2,     KC_MS_BTN1,     _______,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        _______,
        _______,        _______,        KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, _______,        _______,        _______,        _______,        _______,        _______,
                                        _______,        _______,        _______,        _______,        _______,        _______
    ),
    [_FN3] = LAYOUT(
        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        _______,        _______,
        KC_LPRN,        KC_LBRC,        KC_LCBR,        LSFT(KC_COMM),  KC_GRV,         KC_TILD,        LSFT(KC_DOT),   KC_RCBR,        KC_RBRC,        KC_RPRN,
        KC_SCLN,        KC_COLN,        KC_QUOT,        KC_DQUO,        _______,        KC_MINS,        KC_UNDS,        KC_BSLS,        KC_PIPE,        KC_SLSH,
                                        _______,        _______,        _______,        _______,        _______,        _______
    ),
    [_FN4] = LAYOUT(
        RGB_TOG,        _______,        _______,        _______,        _______,        _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,
        RGB_VAI,        RGB_SAI,        RGB_HUI,        RGB_SPI,        RGB_MOD,        _______,        KC_F5,          KC_F6,          KC_F7,          KC_F8,
        RGB_VAD,        RGB_SAD,        RGB_HUD,        RGB_SPD,        RGB_RMOD,       _______,        KC_F9,          KC_F10,         KC_F11,         KC_F12,
                                        _______,        _______,        _______,        _______,        _______,        _______
    )
};

#if defined(POINTING_DEVICE_ENABLE)
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}
#endif

//bool encoder_update_user(uint8_t index, bool clockwise) {
    //if (index == 0) {
        //if (clockwise) {
            //tap_code(KC_VOLD);
            //tap_code(KC_KC_MS_WH_UP);
        //} else {
            //tap_code(KC_VOLU);
            //tap_code(KC_KC_MS_WH_DOWN);
        //}
    //}
    //return true;
//}

//#if defined(ENCODER_MAP_ENABLE)
//const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    //[0] =  { ENCODER_CCW_CW(KC_KC_MS_WH_UP, KC_KC_MS_WH_DOWN)  },
    //[1] =  { ENCODER_CCW_CW(KC_KC_MS_WH_LEFT, KC_KC_MS_WH_RIGHT)  },
    //[2] =  { ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    //[3] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  } 
    //[4] =  { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) }
//};
//#endif

//keyevent_t encoder1_ccw = {
    //.key = (keypos_t){.row = 3, .col = 0},
    //.pressed = false
//};

//keyevent_t encoder1_cw = {
    //.key = (keypos_t){.row = 3, .col = 9},
    //.pressed = false
//};

//bool encoder_update_user(uint8_t index, bool clockwise) {
    //if (index == 0) { /* First encoder */
        //if (clockwise) {
            //encoder1_cw.pressed = true;
            //encoder1_cw.time = (timer_read() | 1);
            //action_exec(encoder1_cw);
        //} else {
            //encoder1_ccw.pressed = true;
            //encoder1_ccw.time = (timer_read() | 1);
            //action_exec(encoder1_ccw);
        //}
    //}

    //return true;
//}

//void matrix_scan_user(void) {

    //if (IS_PRESSED(encoder1_ccw)) {
        //encoder1_ccw.pressed = false;
        //encoder1_ccw.time = (timer_read() | 1);
        //action_exec(encoder1_ccw);
    //}

    //if (IS_PRESSED(encoder1_cw)) {
        //encoder1_cw.pressed = false;
        //encoder1_cw.time = (timer_read() | 1);
        //action_exec(encoder1_cw);
    //}

//}
