/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

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
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│                │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│
 * └──────┴──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│ Prev │ Play │ Next │                              │Vol Dn│Vol Up│ Prev │ Play │ Next │
 * └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
 */

enum sol_layers {
    _QWERTY = 0,
    _FN = 1,
    _MIRROR = 2,
    _KP_RGB = 3,
};

enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST,
    PLY_SNG,
};

#define FN       MO(_FN)
#define MIRROR   MO(_MIRROR)
#define KP_RGB   MO(_KP_RGB)
#define SPC_CTL  MT(MOD_LCTL, KC_SPC)
#define DEL_CTL  MT(MOD_LCTL, KC_DEL)
/* #define QWERTY   DF(_QWERTY) */
/* #define FN_CAPS  LT(_FN, KC_CAPS) */
//#define RGB_ADJ  LT(_KP_RGB, RGB_TOG)

/* #define E1M1_DOOM  \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E4 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_D4 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_C4 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_BF3), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_B3 ), \ */
/*     Q__NOTE(_C4 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E4 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_D4 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_C4 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     Q__NOTE(_E3 ), \ */
/*     H__NOTE(_BF3), */

#ifdef AUDIO_ENABLE
float my_button_song[][2] = SONG(CAMPANELLA);
/* float my_button_song[][2] = SONG(E1M1_DOOM); */
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                  KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        FN,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_CALC,                  KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    PLY_SNG,                  KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,  KC_LGUI, KC_LALT, MIRROR,  FN,      KC_SPC,  KC_PGDN, DEL_CTL, KC_ENT, KC_PGUP, SPC_CTL, FN,      KC_MINS, KC_EQL,  KC_RGUI, KC_RCTL,

        KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                     KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),
    
    /* [_QWERTY] = LAYOUT( */
    /*     KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, */
    /*     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                  KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, */
    /*     FN_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LPRN,                  KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
    /*     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR,                  KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, */
    /*     KC_LCTL,  KC_LGUI, KC_LALT, RGB_TOG, KP_RGB,  KC_SPC,  KC_PGDN, KC_DEL, KC_ENT,  KC_PGUP, KC_SPC,  KP_RGB,  KC_DOWN, KC_UP,   KC_RGHT, KC_RCTL, */

    /*     KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                     KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, */
    /*     KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV */
    /* ), */


    [_FN] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, KC_PGUP, KC_UP,   KC_PGDN, KC_F11,  KC_F12,  _______,                   _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_LBRC, KC_RBRC,
        KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, _______,                   _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_END,
        _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KP_RGB,  _______,  KC_ENT,  _______, _______, _______, RESET,   _______, _______, KC_VOLD, KC_VOLU, _______, _______,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_MIRROR] = LAYOUT(
        KC_BSPC, KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_BSLS, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    _______,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, KC_PSCR, XXXXXXX,
        KC_QUOT, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,    _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, KC_SCLN, XXXXXXX,
        KC_RSFT, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_RCTL, KC_EQL,  KC_MINS, _______, KP_RGB, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_KP_RGB] = LAYOUT(
        _______, KC_F10,  KC_F9,   KC_F8,   KC_F7,   KC_F6,   KC_F11,                    XXXXXXX, XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, 
        _______, RGB_SAD, RGB_VAI, RGB_SAI, RESET,   _______, _______,                   XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, RGB_RST, _______, _______,                   XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, TCH_TOG,                   XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX,
        _______, RGB_RMOD,RGB_TOG, RGB_MOD, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   KC_PDOT, KC_NLCK, KC_PENT, XXXXXXX,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
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
        case PLY_SNG:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                PLAY_SONG(my_button_song);
                #endif
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
        case _MIRROR:
            oled_write_ln_P(PSTR("Miror"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("FN   "), false);
            break;
        case _KP_RGB:
            oled_write_ln_P(PSTR("kpRGB"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}
