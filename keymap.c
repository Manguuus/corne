#include QMK_KEYBOARD_H
#include "features/achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!process_achordion(keycode, record))
    {
        return false;
    }
    // Your macros ...

    return true;
}
void housekeeping_task_user(void)
{
    achordion_task();
}
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t *tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t *other_record)
{
    switch (tap_hold_keycode)
    {
    case LSFT_T(KC_H): // A + U.
        if (other_keycode == MO(4))
        {
            return true;
        }
        break;

    case LGUI_T(KC_T): // S + H and S + G.
        if (other_keycode == MO(4))
        {
            return true;
        }
        break;

    case LCTL_T(KC_I): 
        if (other_keycode == KC_C || other_keycode == KC_V)
        {
            return true;
        }
        break;
    }
    return achordion_opposite_hands(tap_hold_record, other_record);
}
/*uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_I):
            return 300;
        case RCTL_T(KC_N):
            return 300;
       case RCTL_T(KC_S):
            return 300;
        case RCTL_T(KC_L):
            return 300;
        default:
            return TAPPING_TERM;
    }

}*/
#ifdef LAYOUT_split_3x6_3_ex2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [0] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
            KC_TAB, KC_Y,    KC_Z,      KC_U,   KC_A,    KC_Q,    DF(0),     KC_TRNS, KC_P,     KC_B,    KC_M,     KC_L,    KC_F,   KC_J,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_ESC, LSFT_T(KC_C), LT(3, KC_S), LCTL_T(KC_I), LT(11, KC_E), KC_O, DF(7), KC_TRNS, KC_D, LGUI_T(KC_T), RCTL_T(KC_N), LT(3, KC_R), LSFT_T(KC_H), MO(3),
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
            KC_CAPS, KC_V,    KC_X,    KC_LBRC, KC_QUOTE, KC_COLON,                     KC_W,    KC_G,  KC_COMMA, KC_DOT, KC_K,    KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        MO(8), MO(4), KC_SPC, MO(4), TD(1), MO(9)
        //`--------------------------'  `--------------------------'
        ),
        
    [1] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
            KC_TAB, KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,   DF(0),      KC_VOLU, KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,    KC_LBRC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_CAPS, LSFT_T(KC_A), RCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G, DF(7), KC_VOLD, KC_H, LGUI_T(KC_J), LALT_T(KC_K), RCTL_T(KC_L), LSFT_T(KC_COLON), KC_QUOT,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           KC_ESC,  KC_Z,      KC_X,   KC_C,    KC_V,     KC_B,                         KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        MO(8), MO(6), KC_SPC, MO(6), MO(2), MO(9)
        //`--------------------------'  `--------------------------'

        ),

    [2] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, DF(0), KC_VOLU, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, DF(7), KC_VOLD, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(6), KC_SPC, MO(6), MO(2), MO(9)
        //`--------------------------'  ------------------------'

        ),

    [3] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        KC_NONUS_BACKSLASH, KC_NONUS_BACKSLASH, LSFT(KC_SLASH), RALT(KC_8), RALT(KC_9), LSFT(KC_LBRC), DF(0), XXXXXXX, LSFT(KC_1), KC_NONUS_BACKSLASH, LSFT(KC_NONUS_BACKSLASH), KC_KP_EQUAL, LSFT(KC_6), RALT(KC_Q),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, RALT(KC_MINUS), KC_KP_SLASH, RALT(KC_7), RALT(KC_0), KC_KP_ASTERISK, XXXXXXX, XXXXXXX, LSFT(KC_MINUS), LSFT(KC_8), LSFT(KC_9), KC_KP_MINUS, LSFT(KC_DOT), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_NONUS_HASH, LSFT(KC_4), RALT(KC_NONUS_BACKSLASH), RALT(KC_RBRC), LSFT(KC_EQUAL), KC_KP_PLUS, LSFT(KC_5), LSFT(KC_2), LSFT(KC_NONUS_HASH), LSFT(KC_COMMA), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_SPC, MO(4), _______, KC_RGUI
        //`--------------------------'  `--------------------------'

        ),

    [4] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        XXXXXXX, KC_PGDN, TD(0), KC_UP, KC_DELETE, KC_PGUP, DF(0), XXXXXXX, KC_KP_ASTERISK, KC_7, KC_8, KC_9, KC_KP_SLASH, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, XXXXXXX, XXXXXXX, KC_KP_MINUS, KC_4, KC_5, KC_6, KC_KP_DOT, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_ESCAPE, KC_TAB, KC_TAB, KC_ENTER, KC_MINUS, KC_KP_PLUS, KC_1, KC_2, KC_3, KC_KP_COMMA, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, KC_LALT, KC_LCTL, KC_0, KC_NO, KC_TRNS
        //`--------------------------'  `--------------------------'
        ),

    [5] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        KC_ESCAPE, KC_TAB, KC_Q, KC_W, KC_E, KC_R, DF(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, DF(7), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_Z, KC_X, KC_C, KC_V, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RGUI
        //`--------------------------'  `--------------------------'
        ),

    [6] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        XXXXXXX, KC_PGDN, TD(0), KC_UP, KC_DELETE, KC_PGUP, DF(0), XXXXXXX, KC_KP_ASTERISK, KC_7, KC_8, KC_9, KC_KP_SLASH, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+-------- |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, XXXXXXX, XXXXXXX, KC_KP_MINUS, KC_4, KC_5, KC_6, KC_KP_DOT, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_ESCAPE, KC_TAB, KC_TAB, KC_ENTER, KC_RBRC, KC_KP_PLUS, KC_1, KC_2, KC_3, KC_KP_COMMA, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, KC_LALT, KC_LCTL, KC_0, KC_NO, KC_TRNS
        //`--------------------------'  `--------------------------'
        ),

    [7] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(7), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(5), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, DF(5), DF(6), DF(1), DF(10)
        //`--------------------------'  `--------------------------'
        ),

    [8] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        LGUI(LCTL(KC_SLASH)), XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, DF(0), KC_VOLU, XXXXXXX, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), XXXXXXX, LGUI(LCTL(KC_SLASH)),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_LSFT, KC_F5, KC_F6, KC_F7, KC_F8, DF(7), KC_VOLD, XXXXXXX, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), RGB_VAI, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), RGB_VAD, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_SPC, LGUI(KC_0), KC_BRID, KC_BRIU
        //`--------------------------'  `--------------------------'
        ),

    [9] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        XXXXXXX, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, DF(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, DF(7), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RGUI
        //`--------------------------'  `--------------------------'
        ),

    [10] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        XXXXXXX, XXXXXXX, LALT(KC_Q), LALT(KC_UP), LALT(KC_H), DF(0), DF(0), XXXXXXX, XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_RIGHT), XXXXXXX, DF(7), XXXXXXX, XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RCTL(KC_1), XXXXXXX, XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        RCTL(KC_2), RCTL(KC_3), KC_ENTER, KC_0, _______, KC_RGUI
        //`--------------------------'  `--------------------------'
        ),

    [11] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(0), XXXXXXX, XXXXXXX, RGUI(KC_U), RGUI(KC_I), RGUI(KC_O), RGUI(KC_P), RGUI(KC_LBRC),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(7), XXXXXXX, XXXXXXX, RGUI(KC_J), RGUI(KC_K), RGUI(KC_L), RGUI(LSFT(KC_COLON)), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGUI(KC_N), XXXXXXX, XXXXXXX, XXXXXXX, RGUI(KC_SLASH), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RGUI
        //`--------------------------'  `--------------------------'
        ),

    [12] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RCTL(KC_L), XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(7), XXXXXXX, XXXXXXX, RCTL(KC_T), XXXXXXX, RCTL(KC_H), XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RCTL(KC_W), XXXXXXX, XXXXXXX, RCTL(KC_K), XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RGUI
        //`--------------------------'  `--------------------------'
        ),

    [13] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RGUI
        //`--------------------------'  `--------------------------'
        ),

    [14] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RGUI
        //`--------------------------'  `--------------------------'
        ),

    [15] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RGUI
        //`--------------------------'  `--------------------------'
        )};
#endif
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [1] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [2] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [3] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [4] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [5] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [6] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [7] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [8] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [9] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [10] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [11] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [12] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [13] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [14] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [15] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
};
#endif
