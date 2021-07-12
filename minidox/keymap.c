#include QMK_KEYBOARD_H

#define _DVORAK 0
#define _MOUSE 1
#define _SYMBOL 2
#define _NUMBER 3
#define _FUNCTION 4

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  MOUSE,
  SYMBOL,
  NUMBER,
  FUNCTION
};

#define ENTR_OR_MOUSE LT(_MOUSE,KC_ENT)
#define SPC_OR_SYMBOL LT(_SYMBOL,KC_SPC)

#define TMUX RCTL(KC_B)

#define MAC_COPY LGUI(KC_C)
#define MAC_PASTE LGUI(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   ;  |   <  |   >  |   P  |   Y  |           |   F  |   G  |   C  |   R  |   L  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   O  |   E  |   U  |   I  |           |   D  |   H  |   T  |   N  |   S  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   '  |   Q  |   J  |   K  |   X  |           |   B  |   M  |   W  |   V  |   Z  |
 * `----------------------------------'           `----------------------------------'
 *                ,-----------------------.    ,------,---------------.
 *                | Esc  | Space   |      |    |      | Enter  | Up   |
 *                |      |->SYMBOL |      |    |      |->MOUSE |      |
 *                `----------------| Tab  |    |  Del |--------+------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */

[_DVORAK] = LAYOUT_split_3x5_3( \
    KC_SCLN,      KC_COMM,      KC_DOT,       KC_P,         KC_Y,                   KC_F,        KC_G,         KC_C,         KC_R,         KC_L, \
    LSFT_T(KC_A), LCTL_T(KC_O), LALT_T(KC_E), LGUI_T(KC_U), ALL_T(KC_I),            MEH_T(KC_D), RGUI_T(KC_H), RALT_T(KC_T), RCTL_T(KC_N), RSFT_T(KC_S), \
    KC_QUOT,      KC_Q,         KC_J,         KC_K,         KC_X,                   KC_B,        KC_M,         KC_W,         KC_V,         KC_Z, \
                                KC_ESC,       SPC_OR_SYMBOL,KC_TAB,                 KC_BSPC,     ENTR_OR_MOUSE,KC_UP   \
),


/* Mouse
 *
 * ,----------------------------------.           ,----------------------------------.
 * |WhlClk|L Clk | M /\ |R Clk |      |           |      |      |WhlClk|      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |Whl /\| M <  | M \/ | M >  |      |           |      |L Clk |Acc 1 |Acc 0 |R Clk |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |Whl \/|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | PLAY |      |    |      | ENTRY|      |
 *                  `-------------| NEXT |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */

[_MOUSE] = LAYOUT_split_3x5_3(
    KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, _______,              _______, _______, KC_BTN3, _______, _______,
    KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, _______,              _______, KC_BTN1, KC_ACL1, KC_ACL0, KC_BTN2,
    KC_WH_D, _______, _______, _______, _______,              _______, _______, _______, _______, _______,
                      _______, KC_MPLY, KC_MNXT,              _______, _______, _______
),


/* Symbol
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   `  |   &  |   +  |   =  |   @  |           |   !  |   *  |   #  |   /  |   |  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   ^  |   [  |   {  |   (  |   $  |           |   _  |   )  |   }  |   ]  |   -  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   ~  |   \  |   %  |   @  |PASTE |           | Tmux |   !  |L ARW |R ARW |   ?  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |->FUNC|      |      |    |      | ->NUM| Down |
 *                  `-------------|ENTRY |    | Del  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYMBOL] = LAYOUT_split_3x5_3( \
  KC_GRAVE, KC_AMPR,     KC_PLUS, KC_EQUAL,  KC_AT,            KC_EXLM, KC_ASTR, KC_HASH, KC_SLASH, KC_PIPE, \
  KC_CIRC,  KC_LBRACKET, KC_LCBR, KC_LPRN,   KC_DLR,           KC_UNDS, KC_RPRN, KC_RCBR, KC_RBRACKET, KC_MINUS, \
  KC_TILD,  KC_BSLASH,   KC_PERC, KC_AT,     MAC_PASTE,        TMUX,    KC_EXLM, KC_LEFT, KC_RIGHT,  KC_QUES, \
                         MO(_FUNCTION), _______, _______,      KC_DEL,  MO(_NUMBER), KC_DOWN                    \
),

/* Number 
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |   7  |   8  |   9  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |   4  |   5  |   6  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |   1  |   2  |   3  |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      | ENTRY|   0  |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */

[_NUMBER] = LAYOUT_split_3x5_3(
    _______, _______, _______, _______, _______,              _______, KC_7   , KC_8   , KC_9   , _______,
    _______, _______, _______, _______, _______,              _______, KC_4   , KC_5   , KC_6   , _______,
    _______, _______, _______, _______, _______,              _______, KC_1   , KC_2   , KC_3   , _______,
                      _______, _______, _______,              _______, _______, KC_KP_0
),

/* Function 
 *
 * ,----------------------------------.           ,----------------------------------.
 * |RESET |      |      |      |      |           |      | F7   | F8   | F9   | F10  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      | F4   | F5   | F6   | F11  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |COPY  |PASTE |           |      | F1   | F2   | F3   | F12  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |ENTRY |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */

[_FUNCTION] = LAYOUT_split_3x5_3(
    RESET,   _______, _______, _______, _______,              _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 ,
    _______, _______, _______, _______, _______,              _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 ,
    _______, _______, _______,MAC_COPY,MAC_PASTE,             _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 ,
                      _______, _______, _______,              _______, _______, _______
)

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case MOUSE:
        persistant_default_layer_set(1UL<<_MOUSE);
      return false;
      break;
    case SYMBOL:
        persistant_default_layer_set(1UL<<_SYMBOL);
      return false;
      break;
    case NUMBER:
        persistant_default_layer_set(1UL<<_NUMBER);
      return false;
      break;
    case FUNCTION:
        persistant_default_layer_set(1UL<<_FUNCTION);
      return false;
      break;
  }
  return true;
}
