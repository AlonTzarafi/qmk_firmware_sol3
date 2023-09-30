/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ GESC │   1  │   2  │   3  │   4  │   5  │   -  │  │   =  │   6  │   7  │   8  │   9  │   0  │ BkSp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │   [  │  │   ]  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │FNCAPS│   A  │   S  │   D  │   F  │   G  │   (  │  │   )  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   B  │   {  │  │   }  │   N  │   M  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │  Win │  Alt │  RGB │ ADJ  │      │ DEL  │  │ Enter│      │  FN  │ Left │ Down │ Up   │Right │
 * └──────┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Space├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ DEL  │  │ Enter│      │
 *                                    └──────┴──────┘  └──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│ Prev │ Play │ Next │                              │Vol Dn│Vol Up│ Prev │ Play │ Next │
 * └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
 */

enum sol_layers {
    _QWERTY,
    _MIRROR,
    _FN,
    _RGB,
    /* _COLEMAK, */
    /* _GAME, */
    /* _ADJUST */
};

enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

#define QWERTY   MO(_QWERTY)
#define MIRROR   MO(_MIRROR)
#define FN       MO(_FN)
#define RGB      MO(_RGB)

#define CTL_DEL  LCTL_T(KC_DEL)

/* #define FN_CAPS  LT(_FN, KC_CAPS) */
//#define RGB_ADJ  LT(_ADJUST, RGB_TOG)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                  KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        FN,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LPRN,                  KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR,                  KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,  KC_LGUI, KC_LALT, MIRROR,  FN,      KC_SPC,  KC_PGDN, CTL_DEL, KC_ENT, KC_PGUP, KC_ENT,  FN,      KC_MINS, KC_EQL,  KC_RGUI, KC_RCTL,

        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),

    [_MIRROR] = LAYOUT(
        KC_BSPC,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    KC_MINS,                  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_BSLS,  KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_LBRC,                  KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_QUOT,  KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,    KC_LPRN,                  KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_RSFT,  KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_LCBR,                  KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_RCTL,  KC_EQL,  KC_MINS, _______, RGB,     KC_SPC,  KC_PGDN, CTL_DEL, KC_ENT, KC_PGUP, KC_SPC,  FN,      KC_MINS, KC_EQL,  KC_RGUI, KC_RCTL,

        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),

    [_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, KC_HOME, KC_UP,   KC_END,  KC_F11,  KC_F12,  _______,                   _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PSCR, _______,
        KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, _______,                   _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
        _______, AU_TOGG, MU_TOGG, MU_NEXT, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, RGB,     _______, KC_ENT,  _______, KC_INS,  _______, QK_BOOT, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_RGB] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, QK_BOOT, _______, _______,                   _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, RGB_RST, _______, DM_REC1,                   _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, DM_RSTP,                   _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
        RGB_TOG, RGB_RMOD,RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_NUM,  _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case MENU_BTN:
            if (record->event.pressed) {
                rgb_menu_selection();
            }
            return false;
        case MENU_UP:
            if (record->event.pressed) {
                rgb_menu_action(true);
            }
            return false;
        case MENU_DN:
            if (record->event.pressed) {
                rgb_menu_action(false);
            }
            return false;
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;
    }
}

void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWRTY"), false);
            break;
        /* case _COLEMAK: */
        /*     oled_write_ln_P(PSTR("Colemk"), false); */
        /*     break; */
        /* case _GAME: */
        /*     oled_write_ln_P(PSTR("Game  "), false); */
        /*     break; */
        case _FN:
            oled_write_ln_P(PSTR("FN   "), false);
            break;
        /* case _ADJUST: */
        /*     oled_write_ln_P(PSTR("Adjst"), false); */
        /*     break; */
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0]       = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
                  ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1 ... 3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______),
                  ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif
