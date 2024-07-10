/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layer_number {
  _QWERTY = 0,
  _QWERTY_JA,
  _NUM_PAD,
  _SYMBOL,
  _BALL,
  _SCROLL,
};

enum my_keycodes {
  R_ARW = SAFE_RANGE,
  R_DARW,
  JA_SPC_SFT,
  PLS_EQL,
  MNS_EQL,
  PRD_EQL,
};

#define SFT_Z LSFT_T(KC_Z)
#define SFT_SLSH RSFT_T(KC_SLSH)
// #define NUM_G LT(_NUM_PAD, KC_G)
#define CTL_EN LCTL_T(KC_LNG2)
// #define BALL_JA LT(_BALL, KC_LNG1)
// #define SYM_TAB LT(_SYMBOL, KC_TAB)
// #define ALT_BS RALT_T(KC_BSPC)
#define ALT_ENT RALT_T(KC_ENT)
#define SCRL_COMM LT(_SCROLL, KC_COMM)
// #define ALT_ENT RALT_T(KC_ENT)
#define SFT_SPC RSFT_T(KC_SPC)
// #define NUM_ENT LT(_NUM_PAD, KC_ENT)
// #define NUM_ESC LT(_NUM_PAD, KC_ESC)
// #define CMD_ENT LGUI_T(KC_ENT)
#define SYM_JA LT(_SYMBOL, KC_LNG1)
// #define NUM_TAB LT(_NUM_PAD, KC_TAB)
// #define SYM_ENT LT(_SYMBOL, KC_ENT)
// #define SYM_BS LT(_SYMBOL, KC_BSPC)
#define CMD_JA LGUI_T(KC_LNG1)
// #define BALL_ESC LT(_BALL, KC_ESC)
#define SFT_PLS LSFT_T(KC_PLUS)
#define NUM_MINS LT(_NUM_PAD, KC_MINS)
#define SYM_TAB LT(_SYMBOL, KC_TAB)

#define MCTL LCTL(KC_UP)
#define LUNCPAD LGUI(KC_LBRC)  // This shortcut (cmd + [) should be on in OS setting.
#define EXPO LCTL(KC_DOWN)
#define CTL_LEFT LCTL(KC_LEFT)
#define CTL_RGT LCTL(KC_RIGHT)
#define CMD_SCRL LM(_SCROLL, MOD_LGUI) // cmd + scroll -> zoom is registered in SteerMouse.
#define ALT_SCRL LM(_SCROLL, MOD_LALT) // alt + left/right -> switch pages is registered in SteerMouse.
#define CMAL_SCRL LM(_SCROLL, MOD_LGUI | MOD_LALT) // cmd+alt + left/right -> mission control in SteerMouse.
#define CMCT_SCRL LM(_SCROLL, MOD_LGUI | MOD_LCTL) // cmd+alt + left/right -> app switch in SteerMouse.

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [_QWERTY] = LAYOUT_universal(
    KC_BSPC  , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_GRV   ,
    NUM_MINS , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    XXXXXXX  , SFT_Z    , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , SCRL_COMM, KC_DOT   , KC_SLSH  , KC_QUES  ,
                          KC_ESC   , MO(_BALL), CTL_EN   , SYM_TAB  , CMD_JA ,                   ALT_ENT  , SFT_SPC  , _______  , _______  , KC_CAPS
  ),

  // The difference from _QWERTY is that this layer disables shift-key layer taps.
  [_QWERTY_JA] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
                          _______  , _______  , _______  , _______  , _______ ,                   _______  , _______  , _______  , _______  , _______
  ),

  [_NUM_PAD] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        XXXXXXX  , KC_7     , KC_8     , KC_9     , KC_ASTR  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        KC_EQL   , KC_4     , KC_5     , KC_6     , KC_MINS  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        XXXXXXX  , KC_1     , KC_2     , KC_3     , KC_PLUS  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                  XXXXXXX   , KC_0     , _______  , _______  , _______
  ),

  [_SYMBOL] = LAYOUT_universal(
    PRD_EQL  , XXXXXXX  , XXXXXXX  , R_DARW   , R_ARW    , XXXXXXX  ,                                        XXXXXXX  , KC_LBRC  , KC_RBRC  , KC_CIRC  , KC_PERC  , KC_TILD   ,
    MNS_EQL  , KC_AT    , KC_HASH  , KC_DLR   , KC_PLUS  , KC_ASTR  ,                                        KC_EQL   , KC_LPRN  , KC_RPRN  , KC_AMPR  , KC_COLN  , KC_DQUO   ,
    PLS_EQL  , XXXXXXX  , XXXXXXX  , KC_LT    , KC_GT    , XXXXXXX  ,                                        XXXXXXX  , KC_LCBR  , KC_RCBR  , KC_PIPE  , KC_BSLS  , KC_EXLM   ,
                          _______  , _______  , _______  , _______  , _______  ,                  XXXXXXX  , KC_UNDS , _______  , _______  , _______
  ),

  [_BALL] = LAYOUT_universal(
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        XXXXXXX  , MCTL     , EXPO     , LUNCPAD  , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        XXXXXXX  , CMCT_SCRL, CMD_SCRL , ALT_SCRL , CMAL_SCRL, XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        XXXXXXX  , KC_BTN1 ,MO(_SCROLL),KC_BTN2   , XXXXXXX  , XXXXXXX  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , KC_SPC   , XXXXXXX  , XXXXXXX  , XXXXXXX
  ),

  [_SCROLL] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , _______  , _______  , _______  , QK_BOOT
  ),
};
// clang-format on

// Key overrides
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_key_overrides.md
// Ctrl+h -> Bspc
const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_CTRL, KC_H, KC_BSPC);
const key_override_t enter_key_override = ko_make_basic(MOD_MASK_CTRL, KC_M, KC_ENT);
const key_override_t cmd_enter_key_override = ko_make_basic(MOD_MASK_GUI, KC_M, LGUI(KC_ENT));
const key_override_t app_next_key_override = ko_make_basic(MOD_MASK_GUI, KC_K, LGUI(KC_TAB));
const key_override_t app_prev_key_override = ko_make_basic(MOD_MASK_GUI, KC_J, LGUI(KC_TILD));

const key_override_t **key_overrides = (const key_override_t *[]){
  &backspace_key_override,
  &enter_key_override,
  &cmd_enter_key_override,
  &app_next_key_override,
  &app_prev_key_override,
  NULL
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SFT_SPC:
    case NUM_MINS:
    case SYM_TAB:
      return 170;
    default:
      return TAPPING_TERM;
   }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_SPC:
            return 100;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMD_JA:
    case CTL_EN:
      // case SFT_SPC:
      // Immediately select the hold action when another key is pressed.
      return true;
    default:
      // Do not select the hold action when another key is pressed.
      return false;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // Auto enable scroll mode.
  int current_layer = get_highest_layer(state);
  keyball_set_scroll_mode(current_layer == _SCROLL);
  return state;
}

void keyboard_post_init_user(void) {
  set_auto_mouse_layer(_BALL);
  set_auto_mouse_enable(true);         // always required before the auto mouse feature will work

  keyball_set_cpi(4);
  keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_FREE);
  keyball_set_scroll_div(5);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CTL_EN:
      // https://getreuer.info/posts/keyboards/triggers/index.html
      if (record->tap.count > 0) {
        if (!record->event.pressed) {  // tapped -> released.
          layer_off(_QWERTY_JA);
          return true;
        }
        return true;
      } else {
        if (record->event.pressed) {  // tapped -> hold.
          // We want to exit _BALL layer immediately when we push CTRL.
          layer_off(_BALL);
          // We also disable auto mouse layer because CTRL+CLICK causes an accidental right click.
          set_auto_mouse_enable(false);
          return true;
        } else {
          set_auto_mouse_enable(true);
          return true;
        }
      }
    case CMD_JA:
      if (record->tap.count > 0) {
        if (!record->event.pressed) {
          layer_on(_QWERTY_JA);
          return true;
        }
      }
      return true;
    case R_DARW:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      break;
    case R_ARW:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      break;
    case PRD_EQL:
      if (record->event.pressed) {
        SEND_STRING("*=");
      }
      break;
    case MNS_EQL:
      if (record->event.pressed) {
        SEND_STRING("-=");
      }
      break;
    case PLS_EQL:
      if (record->event.pressed) {
        SEND_STRING("+=");
      }
      break;
    case SFT_PLS:
      if (record->tap.count && record->event.pressed) {
        // We need to manually define the tap behavior of SFT_PLS, because KC_PLUS requires 16 bits.
        tap_code16(KC_PLUS);  // Send KC_PLUS on tap
        return false;         // Return false to ignore further processing of key
      }
      break;
  }
  return true;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
  keyball_oled_render_layerinfo();
}
#endif
