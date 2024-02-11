#include QMK_KEYBOARD_H

enum layers {
  _MAIN,
  _QWERTY,
  _SYMBOL,
  _NUMBER,
  _FUNCTION,
  _SHORTCUT,
  _DANGEROUS,
};

#define KEY_1_1 LCTL_T(KC_R)
#define KEY_1_2 LSFT_T(KC_S)
#define KEY_1_3 LALT_T(KC_N)
#define KEY_1_8 RALT_T(KC_E)
#define KEY_1_9 RSFT_T(KC_I)
#define KEY_1_10 RCTL_T(KC_H)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_MAIN] = LAYOUT_split_3x6_3(
    KC_TAB,     KC_J,       KC_G,       KC_M,       KC_P,       KC_V,                  KC_COMMA,        KC_DOT,     KC_SLASH,   KC_QUOTE,   KC_EQUAL,   KC_PGUP,
    KC_ESCAPE,  KEY_1_1,    KEY_1_2,    KEY_1_3,    KC_D,       KC_B,                  KC_SEMICOLON,    KC_A,       KEY_1_8,    KEY_1_9,    KEY_1_10,   KC_BACKSLASH,
    KC_GRAVE,   KC_X,       KC_F,       KC_L,       KC_C,       KC_W,                  KC_MINUS,        KC_U,       KC_O,       KC_Y,       KC_K,       KC_PGDN,
                KC_LGUI, LT(_SHORTCUT, KC_BSPC), LT(_NUMBER, KC_T),                 LT(_SYMBOL, KC_SPC), LT(_FUNCTION, KC_ENT), KC_DELETE
),

[_QWERTY] = LAYOUT_split_3x6_3(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U,  KC_I,  KC_O, KC_P, _______,
    KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,  KC_K,  KC_L, KC_SEMICOLON, KC_QUOTE,
    KC_GRAVE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M,  KC_COMMA,  KC_DOT, KC_SLASH, _______,
    KC_LGUI, LT(_SHORTCUT, KC_BSPC), LT(_NUMBER, KC_T),                 LT(_SYMBOL, KC_SPC), LT(_FUNCTION, KC_ENT), KC_DELETE
),

[_SYMBOL] = LAYOUT_split_3x6_3(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, _______,
    _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,    KC_LEFT_BRACKET, KC_RIGHT_BRACKET, _______,
    _______, _______,   _______,   _______,   _______,  _______,  _______,  _______, _______, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE,  _______,
    _______, _______, _______, _______, _______, _______
),

[_NUMBER] = LAYOUT_split_3x6_3(
    _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______,  _______,   _______,   _______,   _______,   _______,   _______,   KC_KP_4, KC_KP_5,  KC_KP_6, _______, _______,
    _______, _______,   _______,   _______,   _______,  _______,  _______,  KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
    _______, _______, _______, _______, KC_KP_0, _______
),

[_FUNCTION] = LAYOUT_split_3x6_3(
    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                  _______,    KC_HOME,    KC_UP,      _______,    _______,    _______,
    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,                 _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,
    _______,    KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_LEFT_ALT, _______, _______,             _______,    KC_END,     _______,    _______,    _______,    _______,
                    _______, KC_MNXT, KC_MPLY,                                                 KC_VOLD, _______, KC_VOLU
),

[_SHORTCUT] = LAYOUT_split_3x6_3(
    LGUI(KC_LEFT_BRACKET), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), RCS(KC_V), KC_PSCR,      _______, LCTL(KC_PAGE_UP), LCTL(KC_PAGE_DOWN), LCTL(KC_Z), LCTL(KC_A), LGUI(KC_RIGHT_BRACKET),
    KC_F13,     KC_F14,     KC_F15,     KC_F16,    KC_F17,      KC_F18,                 KC_F19, KC_F20,  KC_F21,  KC_F22, KC_F23, KC_F24,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______,  _______, _______, _______
),

[_DANGEROUS] = LAYOUT_split_3x6_3(
    QK_BOOTLOADER, _______, _______, _______, _______, _______,                         _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                               _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                               _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______,  _______, _______, _______
),

};

const uint16_t PROGMEM bootloader[] = {KC_F20, KC_F21, KC_F22, COMBO_END};

const uint16_t PROGMEM layer_to_main[] = {KC_F17, KC_F20, COMBO_END};
const uint16_t PROGMEM layer_to_qwerty[] = {KC_F13, KC_F14, KC_F23, KC_F24, COMBO_END};

const uint16_t PROGMEM oneshot_dangerous[] = {KC_F13, KC_F14, KC_F15};
const uint16_t PROGMEM combo_keypress_q[] = {KC_O, KC_K, COMBO_END};
const uint16_t PROGMEM combo_keypress_z[] = {KC_J, KC_G, COMBO_END};

combo_t key_combos[] = {
    COMBO(bootloader, QK_BOOTLOADER),
    COMBO(layer_to_main, DF(_MAIN)),
    COMBO(layer_to_qwerty, DF(_QWERTY)),
    COMBO(oneshot_dangerous, OSL(_DANGEROUS)),
    COMBO(combo_keypress_q, KC_Q),
    COMBO(combo_keypress_z, KC_Z),
};
