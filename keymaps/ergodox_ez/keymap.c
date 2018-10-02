#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE   0 // Base layer
#define SYMB   1 // Symbols
#define UNIC1  2 // Unicode
#define UNIC2  3 // Unicode

#define __    KC_TRNS // To make the keymaps more readable
#define _x_   KC_NO   // Ditto

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // Can always be here
  TROLL,
  TADA,
  DANCER,
  TABLEFLIP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 1: Colemak
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  `~    |   1  |   2  |   3  |   4  |   5  | ScrS |           |  L0  |   6  |   7  |   8  |   9  |   0  |   =+   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   G  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |   \|   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BS/L2  |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  | '"/L3  |
 * |--------+------+------+------+------+------| Ctrl |           |      |------+------+------+------+------+--------|
 * | LShift(|   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  |RShift) |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Esc  |      |      | Left | Right|                                       |  Up  | Down |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space|  Cmd |------|       |------|  L2  |Enter |
 *                                 |      |      | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
       KC_GRAVE,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   LCMD(LSFT(KC_4)),
       KC_TAB,           KC_Q,         KC_W,   KC_F,   KC_P,   KC_G,   _x_,
       LT(SYMB, KC_BSPC),KC_A,         KC_R,   KC_S,   KC_T,   KC_D,
       KC_LSPO,          KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LCTRL,
       KC_ESC,           _x_,          _x_,    KC_LEFT,KC_RIGHT,

                                                       _x_,  _x_,
                                                             KC_HOME,
                                              KC_SPC,KC_LGUI,KC_END,


            TABLEFLIP,   KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_EQUAL,
            _x_,         KC_J,   KC_L,  KC_U,   KC_Y,   KC_SCOLON,        KC_BSLS,
                         KC_H,   KC_N,  KC_E,   KC_I,   KC_O,             LT(UNIC1, KC_QUOT),
            _x_,         KC_K,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          KC_RSPC,
                                 KC_UP, KC_DOWN,_x_,    _x_,              _x_,
            _x_,    _x_,
            KC_PGUP,
            KC_PGDN,LT(SYMB, KC_A), KC_ENT
   ),

 /* Keymap 2: Symbol Layer
  *
  * ,---------------------------------------------------.           ,--------------------------------------------------.
  * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
  * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
  * |         |      |      |  Up  |      |      |      |           |      |      |      |      |   [  |   ]  |    -   |
  * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |   Del   |      | Left | Down | Right|      |------|           |------|      |      |      |   {  |   }  |    _   |
  * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |       |      |      |      |      |                                       |      |      |      |      |      |
  *   `-----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
[SYMB] = LAYOUT_ergodox(
       __,     KC_F1,  KC_F2,   KC_F3,   KC_F4,    KC_F5,  __,
       __,     __,     __,      KC_UP,   __,       __,     __,
       KC_DEL, __,     KC_LEFT, KC_DOWN, KC_RIGHT, __,
       __,     __,     __,      __,      __,       __,     __,
       __,     __,     __,      __,      __,
                                                 __, __,
                                                     __,
                                             __, __, __,


       __, KC_F6,   KC_F7,  KC_F8,   KC_F9,      KC_F10,      __,
       __, __,      __,     __,      KC_LBRC,    KC_RBRC,     KC_MINUS,
           __,      __,     __,      S(KC_LBRC), S(KC_RBRC),  S(KC_MINUS),
       __, __,      __,     __,      __,      __,             __,
                    __,     __,      __,      __,             __,

       __, __,
       __,
       __, __, __
),

/* Keymap 3: Unicode
 * https://en.wikipedia.org/wiki/Esperanto_orthography#Unicode
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |   ĝ  |      |           |      |   ĵ  |      |   ŭ  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   ŝ  |   🎉  |  💃 |------|           |------|   ĥ  | troll|      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  L4    |      |      |   ĉ  |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[UNIC1] = LAYOUT_ergodox(
       __,        __, __, __, __, __, __,
       __,        __, __, __, __, UC(0x011D), __,
       __,        __, __, UC(0x015D), TADA, DANCER,
       MO(UNIC2), __, __, UC(0x0109), __, __, __,
       __,        __, __, __, __,
                                           __, __,
                                               __,
                                       __, __, __,

       __,  __,         __,    __,         __, __, __,
       __,  UC(0x0135), __,    UC(0x016D), __, __, __,
            UC(0x0125), TROLL, __,         __, __, __,
       __,  __,         __,    __,         __, __, __,
                        __,    __,         __, __, __,
       __, __,
       __,
       __, __, __
),

/* Keymap 4: Unicode (shift)
 * https://en.wikipedia.org/wiki/Esperanto_orthography#Unicode
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |   Ĝ  |      |           |      |   Ĵ  |      |   Ŭ  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   Ŝ  |      |      |------|           |------|   Ĥ  |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   Ĉ  |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[UNIC2] = LAYOUT_ergodox(
       __, __, __, __, __, __, __,
       __, __, __, __, __, UC(0x011C), __,
       __, __, __, UC(0x015C), __, __,
       __, __, __, UC(0x0108), __, __, __,
       __, __, __, __, __,
                                           __, __,
                                               __,
                                       __, __, __,

       __,  __,         __,    __,         __, __, __,
       __,  UC(0x0134), __,    UC(0x016C), __, __, __,
            UC(0x0124), __,    __,         __, __, __,
       __,  __,         __,    __,         __, __, __,
                        __,    __,         __, __, __,
       __, __,
       __,
       __, __, __
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
      switch(keycode) {
          case TROLL:
              SEND_STRING(":trollface:");
              return false;
          case TADA:
              SEND_STRING(SS_LALT("D83C+DF89"));
              return false;
          case DANCER:
              SEND_STRING(SS_LALT("D83D+DC83"));
              return false;
          case TABLEFLIP:
              SEND_STRING("(");
              process_unicode((0x256F | QK_UNICODE), record); // Arm
              process_unicode((0x00B0 | QK_UNICODE), record); // Eye
              process_unicode((0x25A1 | QK_UNICODE), record); // Mouth
              process_unicode((0x00B0 | QK_UNICODE), record); // Eye
              SEND_STRING(")");
              process_unicode((0x256F | QK_UNICODE), record); // Arm
              SEND_STRING(" ");
              process_unicode((0x0361 | QK_UNICODE), record); // Flippy
              SEND_STRING(" ");
              process_unicode((0x253B | QK_UNICODE), record); // Table
              process_unicode((0x2501 | QK_UNICODE), record); // Table
              process_unicode((0x253B | QK_UNICODE), record); // Table
              return false;
      }
  }

  return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UC_OSX);
    ergodox_right_led_3_on();

    rgblight_mode(0);
    rgblight_init();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case SYMB: // Purple
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        rgblight_setrgb(255, 0, 255);
        break;
      case BASE: // Cyan
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        rgblight_setrgb(0, 255, 255);
        break;
      case UNIC1: // Red
        ergodox_right_led_1_on();
        rgblight_setrgb(255, 0, 0);
        break;
      case UNIC2: // Red
        ergodox_right_led_1_on();
        rgblight_setrgb(255, 0, 0);
        break;
      default:
        break;
    }

  return state;
};
