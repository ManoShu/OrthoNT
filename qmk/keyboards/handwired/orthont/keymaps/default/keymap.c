/* Copyright 2021 ManoShu
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
#include QMK_KEYBOARD_H

#include "keymap_br_abnt2.h"

#define SND_E1M1_DOOM \
Q__NOTE(_E3), \
Q__NOTE(_E3), \
Q__NOTE(_E4), \
Q__NOTE(_E3), \
Q__NOTE(_E3), \
Q__NOTE(_D4), \
Q__NOTE(_E3), \
Q__NOTE(_E3), \
Q__NOTE(_C4), \
Q__NOTE(_E3), \
Q__NOTE(_E3), \
Q__NOTE(_BF3), \
Q__NOTE(_E3), \
Q__NOTE(_E3), \
Q__NOTE(_B3), \
Q__NOTE(_C4), \
Q__NOTE(_E3), \
Q__NOTE(_E3), \
Q__NOTE(_E4), \
Q__NOTE(_E3), \
Q__NOTE(_E3), \
Q__NOTE(_D4), \
Q__NOTE(_E3), \
Q__NOTE(_E3), \
Q__NOTE(_C4), \
Q__NOTE(_E3), \
Q__NOTE(_E3), \
H__NOTE(_BF3), 

float snd_e1m1[][2] = SONG(SND_E1M1_DOOM);

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _MOUSE
};

#define SEND_WINDOWS(x) SEND_STRING(SS_LGUI(x))

enum custom_keycodes {
    KC_SNIP = SAFE_RANGE,  // Screen Snip (Shift + S)
    KC_WRUN,               // Run (R)
    KC_WLCK,               // Lock (L)
    KC_WDSK,               // Desktop (D)
    KC_WEXP,               // Explorer (E)
    KC_WPSE,               // System Properties (Pause)
    KC_WMGP,               // Magnify (+)
    KC_WMGM,               // Magnify (-)
    KC_WPRN,               // Project (P)
    KC_WSPC,               // Input Select (Space)
    KC_PSBR,               // Ctrl-Pause/Break
    KC_DOOM,
};

layer_state_t layer_state_set_user(layer_state_t state) 
{
  if (get_highest_layer(state) == _BASE)
  {
    unregister_mods(MOD_MASK_GUI);
  }
  return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
  if(keycode == KC_WPRN || keycode == KC_WSPC)
  {
      if (record->event.pressed)
      {
        register_code(KC_LGUI);

        if(keycode == KC_WPRN)
        {
          tap_code(KC_P);
        }
        else if (keycode == KC_WSPC)
        {
          tap_code(KC_SPACE);
        }
      }
  }
  else if (keycode == KC_PSBR)
  {
    if (record->event.pressed)
    {
      register_code(KC_LCTL);
      tap_code(KC_PAUSE);
      unregister_code(KC_LCTL);
    }
  }
  else if (record->event.pressed) 
  {
    switch (keycode) 
    {
      case KC_SNIP:               // Screen Snip (Win + Shift + S)
        SEND_WINDOWS(SS_LSFT("s"));
        break;
      case KC_WRUN:               // Run
        SEND_WINDOWS("r");
        break;
      case KC_WLCK:               // Lock
        SEND_WINDOWS("l");
        break;
      case KC_WDSK:               // Desktop
        SEND_WINDOWS("d");
        break;
      case KC_WEXP:               // Explorer
        SEND_WINDOWS("e");
        break;
      case KC_WPSE:               // System Properties (Pause)
        SEND_WINDOWS(SS_TAP(X_PAUSE));
        break;
      case KC_WMGP:               // Magnify +
        SEND_WINDOWS("=");
        break;
      case KC_WMGM:               // Magnify -
        SEND_WINDOWS("-");
        break;
      case KC_DOOM:
        PLAY_SONG(snd_e1m1);
        break;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_ESC,     KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
		BR_QUOT, BR_1, BR_2, BR_3, BR_4, BR_5, BR_6, BR_7, BR_8, BR_9, BR_0, BR_MINS, BR_EQL, KC_BSPC, 
		KC_TAB, BR_Q, BR_W, BR_E, BR_R, BR_T, BR_Y, BR_U, BR_I, BR_O, BR_P, BR_ACUT, BR_LBRC, KC_ENT,
		KC_CAPS, BR_A, BR_S, BR_D, BR_F, BR_G, BR_H, BR_J, BR_K, BR_L, BR_CCED, BR_TILD, BR_RBRC, KC_MPLY, 
		KC_LSFT, BR_BSLS, BR_Z, BR_X, BR_C, BR_V, BR_B, BR_N, BR_M, BR_COMM, BR_DOT, BR_SCLN, BR_SLSH, KC_RSFT, 
		KC_LCTL, MO(_FN), KC_LGUI, KC_LALT, KC_SPC, MO(_MOUSE), KC_SPC, KC_DEL, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT),
    [_FN] = LAYOUT(
		RESET,            BL_TOGG, BL_INC, BL_DEC, BL_BRTG, _______, _______, _______, _______, _______, _______, KC_PSBR, KC_SNIP,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WMGM, KC_WMGP, _______, 
		_______, KC_MPLY, KC_MUTE, KC_WEXP, KC_WRUN, _______, _______, _______, _______, _______, KC_WPRN, _______, _______, _______,
		_______, KC_MPRV, KC_MNXT, KC_WDSK, _______, _______, _______, _______, _______, KC_WLCK, _______, _______, _______, _______, 
		_______, _______, KC_VOLU, KC_VOLD, KC_CALC, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, KC_WSPC,          _______, KC_WSPC,          KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END),
    [_MOUSE] = LAYOUT(
		KC_DOOM,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, KC_WH_U, _______, _______, _______, _______,
		_______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, KC_WH_D, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, KC_BTN1, _______, KC_BTN2, _______, _______, _______, _______, _______),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } 
    return false;
}

#ifdef AUDIO_ENABLE
	float caps_on[][2] = SONG(CAPS_LOCK_ON_SOUND);
  float caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);

#endif

bool led_update_user(led_t led_state) {
    #ifdef AUDIO_ENABLE
    static uint8_t caps_state = 0;
    if (caps_state != led_state.caps_lock) {
        led_state.caps_lock ? PLAY_SONG(caps_on) : PLAY_SONG(caps_off);
        caps_state = led_state.caps_lock;
    }
    #endif
    return true;
}

void keyboard_post_init_user(void) {
    
}