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

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum {
    _ALPHA,   // default
    _NUMBERS, // numbers and symbols
    _SPECIAL, // special characters - media, fun
    _MOTION,  // mouse, cursor, page motions
};

// Left-hand home row mods
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)

#define KC_SPE_ESC LT(_SPECIAL, KC_ESC)   // Tap for Esc, hold for Special layer
#define KC_NUM_BKSP LT(_NUMBERS, KC_BACKSPACE)  // Tap for Backspace, hold for Numbers layer

    /* Combomap
     *
     * ┌───────┬─────┬─────┬─────┬─────┐      ┌───────────────────────────────┐
     * │       │    ESC    │     │     │      │     │     │    TAB    │       │
     * ├───────┼─────┼─────┼─────┼─────│      ├─────┼─────┼─────┼─────┼───────│
     * │       │     │     │     │     │      │     │     │     │     │       │
     * ├───────┼─────┼─────┼─────┼─────│      ├─────┼─────┼─────┼─────┼───────│
     * │       │     │     │     │     │      │     │     │     │     "       │
     * └───────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴───────┘
     */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Alpha layer
     *
     * ┌───────┬───────┬───────┬───────┬─────┐      ┌───────┬───────┬───────┬───────┬────┐
     * │   Q   │   W   │   E   │   R   │  T  │      │   Y   │   U   │   I   │   O   │ P  │
     * ├───────┼───────┼───────┼───────┼─────┤      ├───────┼───────┼───────┼───────┼────┤
     * │   A   │ ALT S │ SHI D │ CTR F │  G  │      │   H   │ CTR J │ SHI K │ ALT L │ ;: │
     * ├───────┼───────┼───────┼───────┼─────┤      ├───────┼───────┼───────┼───────┼────┤
     * │   Z   │   X   │   C   │   V   │  B  │      │   N   │   M   │   ,<  │   .>  │ /? │
     * └───────┴───────┴───────┴───────┴─────┘      └───────┴───────┴───────┴───────┴────┘
     *           ┌───────┼──────────┼─────────┐    ┌───────┼───────┼─────┐
     *           │ SHIFT │ BKSP NUM │ ESC SPE │    │ ENT   │ SPC   │ ALT │
     *           └───────┼──────────┼─────────┘    └───────┼───────┼─────┘
     */
    [_ALPHA] = LAYOUT_split_3x5_3(
         KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,     KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,
         KC_A,     HOME_S, HOME_D, HOME_F, KC_G,     KC_H,   HOME_J, HOME_K,   HOME_L, KC_SCLN,
         KC_Z,     KC_X,   KC_C,   KC_V,   KC_B,     KC_N,   KC_M,   KC_COMMA, KC_DOT, KC_SLASH,
            KC_LSFT, KC_NUM_BKSP, KC_SPE_ESC,        KC_ENTER, KC_SPACE, KC_RALT),

    /* Keymap 1: Numbers/Symbols
     *
     * ┌───────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬───────┐
     * │   !   │  @  │  #  │  $  │  %  │      │  ^  │  &  │  *  │  (  │   )   │
     * ├───────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼───────┤
     * │   1   │  2  │  3  │  4  │  5  │      │  6  │  7  │  8  │  9  │   0   │
     * ├───────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼───────┤
     * │   `~  │  '" │  |  │  [{ │  ]} │      │  \| │  +  │  -_ │  {  │   }   │
     * └───────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴───────┘
     *                ┌─────┼─────┼─────┐    ┌─────┼─────┼─────┐
     *                │     │     │     │    │  =  │  _  │ GUI │
     *                └─────┼─────┼─────┘    └─────┼─────┼─────┘
     */
    [_NUMBERS] = LAYOUT_split_3x5_3(
         KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
         KC_GRV,  KC_QUOT, KC_PIPE, KC_LBRC, KC_RBRC,    KC_BSLS, KC_PLUS, KC_MINS, KC_LCBR, KC_RCBR,
                           XXXXXXX, XXXXXXX, XXXXXXX,    KC_EQL,  KC_UNDS, KC_RGUI),

    /* Keymap 2: Funtion keys, media, special (qmk)
     *
     *    ┌─────┬─────┬────┬────┬────┐      ┌─────┬─────┬─────┬─────┬─────┐
     *    │ F1  │ F2  │ F3 │ F4 │ F5 │      │  F6 │  F7 │ F8  │ F9  │ F10 │
     *    ├─────┼─────┼────┼────┼────┤      ├─────┼─────┼─────┼─────┼─────┤
     *    │ ⏹   │  ⏮  │    │ ⏯  │ ⏭  │      │     │     │     │     │  "  │
     *    ├─────┼─────┼────┼────┼────┤      ├─────┼─────┼─────┼─────┼─────┤
     *    │ F11 │ F12 │ V- │ V+ │ V0 │      │     │     │     │Combo│Debug│
     *    └─────┴─────┴────┴────┴────┘      └─────┴─────┴─────┴─────┴─────┘
     *         ┌───────┼───────┼──────┐    ┌─────────┼─────┼───────┐
     *         │       │       │      │    │  Motion │ DEL │ CTRL  │
     *         └───────┼───────┼──────┘    └─────────┼─────┼───────┘
     */
    [_SPECIAL] = LAYOUT_split_3x5_3(
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
         KC_MSTP, KC_MPRV, XXXXXXX, KC_MPLY, KC_MNXT,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DQUO,
         KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, KC_MUTE,    XXXXXXX, XXXXXXX, XXXXXXX, CM_TOGG, DB_TOGG,
                           _______, _______, _______,    TO(_MOTION), KC_DEL, KC_RCTL),


    /* Keymap 3: Motion layer
     *
     * ┌───────┬───────┬───────┬───────┬─────┐      ┌───────┬───────┬───────┬───────┬─────┐
     * │       │  M⇈   │  M↑   │  M⇊   │     │      │ Home  │ PgDn  │ PgUp  │  End  │     │
     * ├───────┼───────┼───────┼───────┼─────┤      ├───────┼───────┼───────┼───────┼─────┤
     * │  Tab  │  M←   │  M↓   │  M→   │     │      │   ←   │   ↓   │   ↑   │   →   │     │
     * ├───────┼───────┼───────┼───────┼─────┤      ├───────┼───────┼───────┼───────┼─────┤
     * │       │       │       │       │     │      │       │ Macc1 │ Macc2 │ Macc3 │     │
     * └───────┴───────┴───────┴───────┴─────┘      └───────┴───────┴───────┴───────┴─────┘
     *           ┌───────┼──────────┼─────────┐    ┌───────┼───────┼─────┐
     *           │ CTRL  │          │  Alpha  │    │  M1   │  M2   │  M3 │
     *           └───────┼──────────┼─────────┘    └───────┼───────┼─────┘
     */
    [_MOTION] = LAYOUT_split_3x5_3(
         XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D, XXXXXXX,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,   XXXXXXX,
         KC_TAB,  KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2,  XXXXXXX,
                           KC_LCTL, XXXXXXX, TO(_ALPHA),   KC_BTN1, KC_BTN2, KC_BTN3),
};
