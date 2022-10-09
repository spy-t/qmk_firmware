#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY     0
#define _COLEMAK_DH 1
#define _SYMB       2
#define _NAV        3
#define _MOUSE      4
#define _MEDIA      5
#define _ADJUST     6
#define _FN         7

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK_DH,
    SYMB,
    NAV,
    MOUSE,
    MEDIA,
    ADJUST,
    FN,
};

// Shortcut to make keymap more readable
#define SYM_L LT(_SYMB, KC_LPRN)
#define SYM_R LT(_SYMB, KC_RPRN)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_ALMINS RALT_T(KC_MINS)

// Home row mods
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LSFT_T(KC_D)
#define HM_F LCTL_T(KC_F)

#define HM_SCLN RGUI_T(KC_SCLN)
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
#define LTHUMB_1 LT(_MEDIA, KC_BSLS)
#define LTHUMB_2 LT(_NAV, KC_BSPC)
#define LTHUMB_3 LT(_MOUSE, KC_DEL)
// #define SHIFT_DEL LSFT_T(KC_DEL)

#define RTHUMB_1 KC_ENT
#define RTHUMB_2 KC_SPC
#define RTHUMB_3 LT(_FN, KC_ALMINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_NAGR, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NAMI,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, SYM_L, SYM_R, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LGUI,    HM_A    , HM_S   , HM_D   , HM_F   , KC_G   , KC_LBRC, KC_RBRC                 , KC_H   ,  HM_J  , HM_K   , HM_L   , HM_SCLN, KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ADPU, KC_PGDN, KC_HOME, KC_ADEN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
        //├────────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼──────────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
           KC_ESC      , KC_PPLS, KC_PMNS, KC_ALAS,     LTHUMB_1,    LTHUMB_2 , LTHUMB_3    ,        RTHUMB_1,RTHUMB_2,    RTHUMB_3     , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
        //└────────────┴────────┴────────┴────────┘    └────────┘   └────────┴──────────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_COLEMAK_DH] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_NAGR, KC_1   , KC_2   , KC_3   ,KC_4    , KC_5   ,                                              KC_6  , KC_7   , KC_8   , KC_9   , KC_0   , KC_NAMI,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , SYM_L  ,                            SYM_R , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_EQL,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LGUI, HM_CM_A, HM_CM_R, HM_CM_S, HM_CM_T, KC_G   , KC_LBRC,                           KC_RBRC, KC_M   ,HM_CM_N , HM_CM_E, HM_CM_I, HM_CM_O , KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LSPO, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V    ,KC_ADPU, KC_PGDN,         KC_HOME, KC_ADEN, KC_K   ,  KC_H   , KC_COMM , KC_DOT, KC_SLSH, KC_RSPC,
        //├────────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼──────────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
           KC_ESC      , KC_PPLS, KC_PMNS, KC_ALAS,     LTHUMB_1,    LTHUMB_2 , LTHUMB_3    ,        RTHUMB_1,RTHUMB_2,    RTHUMB_3     , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
        //└────────────┴────────┴────────┴────────┘    └────────┘   └────────┴──────────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_SYMB] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NLCK,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PSLS, KC_PSCR,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_HASH, KC_DLR, KC_LBRC, KC_RBRC, KC_GRV, _______, _______, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST, KC_VOLU,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_TILD, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PENT, KC_PENT, KC_VOLD,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_PDOT, KC_PENT, KC_PENT, KC_MUTE
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_NAV] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______ , _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           XXXXXXX , XXXXXXX, KC_MS_U, XXXXXXX, KC_WH_U, XXXXXXX, _______,                           _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           XXXXXXX, KC_MS_L,  KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX, _______,                           _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______ ,        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, _______, _______ ,        _______ , XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_MOUSE] = LAYOUT(
           _______ , _______, _______, _______, _______, _______,                                             _______          , _______   , _______, _______, _______, _______,

           XXXXXXX , XXXXXXX, KC_MS_U, XXXXXXX, KC_WH_U, XXXXXXX, _______,                             _______, XXXXXXX        , XXXXXXX   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

           XXXXXXX, KC_LGUI,  KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, _______,                             _______, KC_MS_LEFT     , KC_MS_DOWN     , KC_MS_UP, KC_MS_RIGHT, XXXXXXX, XXXXXXX,

           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______ ,        _______   , XXXXXXX , KC_MS_WH_LEFT , KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, XXXXXXX, XXXXXXX,

           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,     XXXXXXX, _______,        KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        ),

    [_MEDIA] = LAYOUT(
           _______ , _______, _______, _______, _______, _______,                                             _______          , _______   , _______, _______, _______, _______,

           XXXXXXX , XXXXXXX, KC_MS_U, XXXXXXX, KC_WH_U, XXXXXXX, _______,                             _______, XXXXXXX        , XXXXXXX   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

           XXXXXXX, KC_LGUI,  KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, _______,                             _______, KC_MPRV        , KC_VOLD     , KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,

           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______ ,        _______   , XXXXXXX , KC_MS_WH_LEFT , KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, XXXXXXX, XXXXXXX,

           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,     XXXXXXX, _______,        KC_MSTP, KC_MPLY, KC_MUTE  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        ),

    [_ADJUST] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, XXXXXXX,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX, RESET, RGB_M_P, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_FN] = LAYOUT(
           DF(_QWERTY) , _______, _______, _______, _______, _______,                                             _______          , _______   , _______, _______, _______, _______,

           DF(_COLEMAK_DH) , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                             _______, XXXXXXX        , XXXXXXX   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

           XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                             _______, XXXXXXX        , XXXXXXX     , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______ ,        _______   , XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,     XXXXXXX, _______,        XXXXXXX, XXXXXXX, XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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
        case HM_SCLN:
            return true;
        default:
            return false;
    }
}
