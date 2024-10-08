#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY     0
#define _COLEMAK_DH 1
#define _SYM        2
#define _NUM        3
#define _NAV        4
#define _MOUSE      5
#define _MEDIA      6
#define _ADJUST     7
#define _FN         8

enum custom_keycodes {
    // Layers
    QWERTY = SAFE_RANGE,
    COLEMAK_DH,
    SYM,
    NUM,
    NAV,
    MOUSE,
    MEDIA,
    ADJUST,
    FN,

    // Macros
    GONIL,
    ARROW,
    NEQ
};

// Shortcut to make keymap more readable
#define SYM_L LT(_SYM, KC_LPRN)
#define SYM_R LT(_SYM, KC_RPRN)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_ALMINS RALT_T(KC_MINS)

// Home row mods
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LSFT_T(KC_D)
#define HM_F LCTL_T(KC_F)

#define HM_QUOT RGUI_T(KC_QUOT)
#define HM_L    RALT_T(KC_L)
#define HM_K    RSFT_T(KC_K)
#define HM_J    RCTL_T(KC_J)


#define HM_CM_A LGUI_T(KC_A)
#define HM_CM_R LALT_T(KC_R)
#define HM_CM_S LSFT_T(KC_S)
#define HM_CM_T LCTL_T(KC_T)

#define HM_CM_O    RGUI_T(KC_O)
#define HM_CM_I    RALT_T(KC_I)
#define HM_CM_E    RSFT_T(KC_E)
#define HM_CM_N    RCTL_T(KC_N)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

// I hate ascii keyboard diagrams
#define LTHUMB_1 LT(_MEDIA, KC_ESC)
#define LTHUMB_2 LT(_NAV, KC_SPC)
#define LTHUMB_3 LT(_MOUSE, KC_TAB)
// #define SHIFT_DEL LSFT_T(KC_DEL)

#define RTHUMB_1 LT(_SYM, KC_ENT)
#define RTHUMB_2 LT(_NUM, KC_BSPC)
#define RTHUMB_3 LT(_FN, KC_DEL)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GONIL:
            if (record->event.pressed) {
                SEND_STRING("if err != nil {}");
                tap_code(KC_LEFT);
            }
            break;
        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case NEQ:
            if (record->event.pressed) {
                SEND_STRING("!=");
            }
            break;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        ├ 0,0    ├  0,1   ├ 0,2    ├ 0,3    ├ 0,4    ├ 0,5    ├                                           ├ 0,6    ├ 0,7    ├ 0,8    ├ 0,9    ├ 0,10   ├ 0,11   ├
        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        ├ 1,0    ├  1,1   ├ 1,2    ├ 1,3    ├ 1,4    ├ 1,5    ├ 1,6    ├                         ├ 1,7    ├ 1,8    ├ 1,9    ├ 1,10   ├ 1,11   ├ 1,12   ├ 1,13   ├
        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        ├ 2,0    ├  2,1   ├ 2,2    ├ 2,3    ├ 2,4    ├ 2,5    ├ 2,6    ├                         ├ 2,7    ├ 2,8    ├ 2,9    ├ 2,10   ├ 2,11   ├ 2,12   ├ 2,13   ├
        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        ├ 3,0    ├  3,1   ├ 3,2    ├ 3,3    ├ 3,4    ├ 3,5    ├ 3,6    ├ 3,7    ├       ├ 3,8      3,9    ├ 3,10   ├ 3,11   ├ 3,12   ├ 3,13   ├ 3,14   ├ 3,15   ├
        ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        ├ 4,0    ├  4,1   ├ 4,2    ├ 4,3    ├    ├ 4,4    ├     4,5    ├ 4,6    ├       ├ 4,7    ├ 4,8    ├   ├ 4,9    ├    ├ 4,10   ├ 4,11   ├ 4,12   ├ 4,13   ├
        └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    */

    [_QWERTY] = LAYOUT(
        GONIL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, XXXXXXX,

        ARROW, KC_Q, KC_W, KC_E, KC_R, KC_T, SYM_L, SYM_R, KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,

        NEQ, HM_A, HM_S, HM_D, HM_F, KC_G, KC_LBRC, KC_RBRC, KC_H, HM_J, HM_K, HM_L, HM_QUOT, XXXXXXX,

        XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ADPU, KC_PGDN, KC_HOME, KC_ADEN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LTHUMB_1, LTHUMB_2, LTHUMB_3, RTHUMB_1, RTHUMB_2, RTHUMB_3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_COLEMAK_DH] = LAYOUT(
        _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, XXXXXXX,

        _______, KC_Q, KC_W, KC_F, KC_P, KC_B, SYM_L, SYM_R, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, XXXXXXX,

        _______, HM_CM_A, HM_CM_R, HM_CM_S, HM_CM_T, KC_G, KC_LBRC, KC_RBRC, KC_M, HM_CM_N, HM_CM_E, HM_CM_I, HM_CM_O, XXXXXXX,

        _______, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_ADPU, KC_PGDN, KC_HOME, KC_ADEN, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LTHUMB_1, LTHUMB_2, LTHUMB_3, RTHUMB_1, RTHUMB_2, RTHUMB_3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,

        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT, KC_BSPC, KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_MOUSE] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, XXXXXXX, KC_MS_U, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, XXXXXXX, XXXXXXX,

        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_MEDIA] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,

        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, XXXXXXX,

        _______, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT, KC_0, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_SYM] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, XXXXXXX,

        _______, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_FN] = LAYOUT(
        DF(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        DF(_COLEMAK_DH), KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, XXXXXXX,

        XXXXXXX, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_APP, KC_SPC, KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_ADJUST] = LAYOUT(
        XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, XXXXXXX,

        XXXXXXX, RESET, RGB_M_P, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )

};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case HM_A:
        case HM_S:
        case HM_D:
        case HM_F:
        case HM_J:
        case HM_K:
        case HM_L:
        case HM_QUOT:
            return true;
        default:
            return false;
    }
}
