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
  _SYMBOL1,
  _SYMBOL2,
  _SYMBOL3,
  _NUM_PAD,
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
  CMD_SPC,
};

#define SFT_Z LSFT_T(KC_Z)
#define SFT_SLSH RSFT_T(KC_SLSH)
#define CTL_LANG LCTL_T(CMD_SPC)
#define ALT_ENT RALT_T(KC_ENT)
#define SCRL_COMM LT(_SCROLL, KC_COMM)
#define SFT_SPC RSFT_T(KC_SPC)
#define NUM_MINS LT(_NUM_PAD, KC_MINS)
#define SYM_TAB LT(_SYMBOL1, KC_TAB)
#define LGUI_BSPC LGUI_T(KC_BSPC)  // currently unused because this key combination can be a shortcut.
#define L_NUM MO(_NUM_PAD)
#define L_SYM2 MO(_SYMBOL2)
#define L_SYM3 MO(_SYMBOL3)
#define SYM2_UND LT(_SYMBOL2, KC_UNDS)

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
    XXXXXXX  , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_GRV   ,
    XXXXXXX  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , XXXXXXX  ,
    KC_BSPC  , SFT_Z    , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , SCRL_COMM, KC_DOT   , KC_SLSH  , XXXXXXX  ,
                          KC_ESC   , MO(_BALL), CTL_LANG , SYM_TAB  , KC_LGUI  ,                  ALT_ENT  , SFT_SPC  , _______  , _______  , KC_CAPS
  ),

  [_SYMBOL1] = LAYOUT_universal(
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_TILD  , KC_CIRC  , KC_QUOT  , KC_DQUO  , KC_GRV   , XXXXXXX  ,
    XXXXXXX  , L_NUM    , KC_HASH  , KC_DLR   , KC_AT    , L_SYM3   ,                                        KC_ASTR  , KC_LPRN  , KC_RPRN  , KC_MINS  , KC_COLN  , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_UNDS  , KC_LCBR  , KC_RCBR  , KC_QUES  , KC_BSLS  , XXXXXXX  ,
                          _______  , _______  , _______  , _______  , _______  ,                  KC_EQL   , SYM2_UND , _______  , _______  , _______
  ),

  [_SYMBOL2] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , XXXXXXX  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        KC_PERC  , KC_LBRC  , KC_RBRC  , KC_PLUS  , KC_AMPR  , XXXXXXX  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , KC_LT    , KC_GT    , KC_EXLM  , KC_PIPE  , XXXXXXX  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , _______  , _______  , _______  , _______
  ),

  [_SYMBOL3] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , PRD_EQL  , _______  , XXXXXXX  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , R_ARW    , R_DARW   , MNS_EQL  , _______  , XXXXXXX  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , PLS_EQL  , _______  , XXXXXXX  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , _______  , _______  , _______  , _______
  ),

  [_NUM_PAD] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        XXXXXXX  , KC_7     , KC_8     , KC_9     , KC_ASTR  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        XXXXXXX  , KC_4     , KC_5     , KC_6     , KC_MINS  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        XXXXXXX  , KC_1     , KC_2     , KC_3     , KC_PLUS  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                  KC_EQL   , KC_0     , _______  , _______  , _______
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
    case SYM2_UND:
    case SYM_TAB:
      return 170;
    default:
      return TAPPING_TERM;
   }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_SPC:
        case SYM2_UND:
            return 100;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CTL_LANG:
    case LGUI_BSPC:
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
    case CTL_LANG:
      // https://getreuer.info/posts/keyboards/triggers/index.html
      if (record->tap.count) {
        if (record->event.pressed) {
          // https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md#changing-hold-function
          // Mod tap for LGUI(KC_SPC).
          tap_code16(LGUI(KC_SPC));
          return false;
        }
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
      break;
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
    case SYM2_UND:
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_UNDS);
        return false;
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
