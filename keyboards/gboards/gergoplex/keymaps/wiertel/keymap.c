/* Copyright 2021 Jane Bernhardt
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum {
    _ALPHA,   // default
    _SPECIAL, // special characters
    _NUMBERS  // numbers/function/motion
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#define KC_SPE_ESC LT(_SPECIAL, KC_ESC)   // Tap for Esc, hold for Special layer
#define KC_NUM_BKSP LT(_NUMBERS, KC_BACKSPACE)  // Tap for Backspace, hold for Numbers layer

    /* Combomap
     *
     * ,-------------------------------.      ,-------------------------------.
     * |       |    ESC    |     |     |      |     |     |    TAB    |       |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |     |     |     |     |      |     |     |     |     |       |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |     |     |     |     |      |     |     |     |     "       |
     * `-------------------------------'      `-------------------------------'
     *            .-----------------.            .-----------------.
     *            |     |     |     |            |     |     |     |
     *            '-----------------'            '-----------------'
     */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Alpha layer
     *
     * ,-------------------------------------.      ,-----------------------------------.
     * |   Q   |   W   |   E   |   R   |  T  |      |   Y   |   U   |   I   |   O   | P |
     * |-------+-------+-------+-------+-----|      |-------+-------+-------+-------+---|
     * | WIN  A| ALT S | SHI D | CTR F |  G  |      | CTR H | SHI J | ALT K | WIN L | ; |
     * |-------+-------+-------+-------+-----|      |-------+-------+-------+-------+---|
     * |   Z   |   X   |   C   |   V   |  B  |      |   N   |   M   |   ,   |   .   | / |
     * `-------------------------------------'      `-----------------------------------'
     *           .-------+----------+---------.    .-------+-------+-----.
     *           | SHIFT | BKSP NUM | ESC SPE |    | ENT   | SPC   | ALT |
     *           '-------+----------+---------'    '-------+-------+-----'
     */
    [_ALPHA] = LAYOUT_split_3x5_3(
         KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,          KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,
         HOME_A,   HOME_S, HOME_D, HOME_F, KC_G,          KC_H,   HOME_J, HOME_K,   HOME_L, HOME_SCLN,
         KC_Z,     KC_X,   KC_C,   KC_V,   KC_B,          KC_N,   KC_M,   KC_COMMA, KC_DOT, KC_SLASH,
            KC_LSFT, KC_NUM_BKSP, KC_SPE_ESC,             KC_ENTER, KC_SPACE, KC_RALT),

    /* Keymap 1: Special characters layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |    !  |  @  |  {  |  }  |  |  |      |  `  |  ~  |  ?  |     |   \   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |    #  |  $  |  (  |  )  | RMB |      |  +  |  -  |  /  |  *  |   '   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |    %  |  ^  |  [  |  ]  | LMB |      |  &  |  =  |  ,  |  .  |   -   |
     * `-------------------------------'      `-------------------------------'
     *     .-------------------------.          .-----------------.
     *     | ComboToggle |  ;  |     |          |     |     | DEL |
     *     '-------------------------'          '-----------------'
     */
    [_SPECIAL] = LAYOUT_split_3x5_3(
         KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,          KC_GRV,  KC_TILD, KC_QUES, KC_TRNS, KC_BSLS,
         KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2,          KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT,
         KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1,          KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_MINS,
                           CM_TOGG, KC_SCLN, KC_TRNS,          KC_TRNS, KC_TRNS, KC_DEL),

    /* Keymap 2: Numbers/Function/Motion layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |   1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |  F1   | F2  | F3  | F4  | F5  |      | LFT | DWN | UP  | RGT | VOLUP |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |  F6   | F7  | F8  | F9  | F10 |      | MLFT| MDWN| MUP | MRGT| VOLDN |
     * `-------------------------------'      `-------------------------------'
     *             .-----------------.          .-----------------.
     *             | F11 |     | F12 |          |     | PLY | CTR |
     *             '-----------------'          '-----------------'
     */
    [_NUMBERS] = LAYOUT_split_3x5_3(
         KC_1,  KC_2,  KC_3,  KC_4,  KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
         KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
                    KC_F11, KC_TRNS, KC_F12,         KC_TRNS, KC_MPLY,  KC_RCTL)
};
