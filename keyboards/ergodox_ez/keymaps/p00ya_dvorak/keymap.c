#include QMK_KEYBOARD_H
#include "version.h"


// Layers.
#define L_NUM 1
#define L_NAV 2
#define L_COD 3
#define L_STN 4
#define L_FN 5

// Dvorak-remapped keycodes for some punctuation.
#define KD_LBRC KC_MINS
#define KD_RBRC KC_EQL
#define KD_LCBR KC_UNDS
#define KD_RCBR KC_PLUS
#define KD_EQL  KC_RBRC
#define KD_SLSH KC_LBRC
#define KD_UNDS KC_DQUO

// defined in bootmagic.c.
extern keymap_config_t keymap_config;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base layer should mostly act like a 60% US (QWERTY) layout, with some of
  // the right pinky keys missing.
  [0] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_TRNS,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TT(L_NUM),                                      TT(L_NUM),      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,
    LCTL_T(KC_ESC), KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,
    KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           OSM(MOD_LSFT),                                  TT(L_NAV),      KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_RSFT,
    MO(L_FN),       KC_LCTRL,       C(KC_LALT),     KC_LALT,        KC_LCMD,                                                                                                        KC_RCMD,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,
                                                                                                    TG(L_STN),      KC_PSCR,        KC_HOME,        KC_END,
                                                                                                                    KC_PGUP,        KC_INS,
                                                                                    LT(L_COD,KC_SPC),KC_ENT,        KC_PGDN,        KC_DEL,         KD_UNDS,        KC_SPC
  ),
  // Simulates a numpad with the 5-key aligned with QWERTY's J-key.
  // Num-zero and enter keys are duplicated to the thumb clusters.
  [L_NUM] = LAYOUT_ergodox_pretty(
    KC_ESC,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO,   KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, KC_NO,   KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_NO,   KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, KC_NO,   KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                              KC_KP_0, KC_PDOT, KC_PENT, KC_NO,   KC_NO,
                                                           KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                                    KC_TRNS,        KC_TRNS,
                                                  KC_TRNS, KC_PENT, KC_TRNS,        KC_TRNS, KC_PENT, KC_KP_0
  ),
  // Mouse-keys on the left hand and the dirpad / navigation pad on the right
  // with a standard US layout.
  [L_NAV] = LAYOUT_ergodox_pretty(
    KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_BTN2, KC_MS_U, KC_BTN1, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_INS,  KC_HOME, KC_PGUP, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                                             KC_TRNS, KC_DEL,  KC_END,  KC_PGDN, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_BTN1, KC_UP,   KC_BTN2, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                               KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,
                                                           KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                                    KC_NO,          KC_TRNS,
                                                  KC_ACL0, KC_ACL1, KC_ACL2,        KC_TRNS, KC_TRNS, KC_TRNS
  ),
  // Dvorak coding layer.  Moves various brackets and symbols to the right hand,
  // particularly optimizing for C-like programming languages, *assuming*
  // an additonal QWERTY -> Dvorak remapping in (OS) software.
  [L_COD] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                           KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KD_LCBR, KD_RCBR, KC_PIPE, KC_BSLS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_LPRN, KC_RPRN, KD_EQL,  KC_ENT,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_0,    KD_LBRC, KD_RBRC, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                          KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,         KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
  ),
  // Stenography layer.  Designed for Plover and similar software that maps
  // QWERTY to a Steno layout, but with the vowels on the actual thumb clusters
  // (instead of using the QWERTY "CV"/"NM" placements).  I've also moved the
  // pinky keys down one row.
  [L_STN] = LAYOUT_ergodox_pretty(
    KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
    KC_NO,   KC_NO,   KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,                             KC_NO,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_NO,   KC_NO,
    KC_NO,   KC_Q,    KC_S,    KC_D,    KC_F,    KC_G,                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    KC_LBRC,
    KC_NO,   KC_A,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SCLN, KC_QUOT,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                          KC_TRNS, KC_NO,           KC_NO,   KC_NO,
                                                                   KC_NO,           KC_NO,
                                                 KC_C,    KC_V,    KC_NO,           KC_NO,   KC_N,    KC_M
  ),
  // Function layer.  This makes MO(L_FN) feel like the "fn" modifier key on a
  // Mac, enabling a function key row, some media keys, and some Apple-like
  // behaviours for "return" and arrow keys.  It also makes caps-lock available
  // in the traditional position.
  [L_FN] = LAYOUT_ergodox_pretty(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_TRNS, KC_BRMD, KC_BRMU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,
    KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                               KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                                          KC_TRNS, WEBUSB_PAIR,     KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,         KC_TRNS,
                                                 KC_TRNS, KC_PENT, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
  )
};
// clang-format on

void keyboard_post_init_user() {
    // The LEDs are painfully bright.
    ergodox_led_all_set(LED_BRIGHTNESS_LO);
}


uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    if (layer == L_FN) {
        // Turn on all right LEDs as if L_FN was actually layer 7, which will
        // also show the host LED status via the brightness.
        layer = 7;
    }

    // Encode layers as binary.
    for (int i = 0; i < 3; ++i) {
        if (layer & (1 << i)) {
            ergodox_right_led_on(i + 1);
        } else {
            ergodox_right_led_off(i + 1);
        }
    }

    // Enable NKRO iff the stenography layer is active.
    if (keymap_config.nkro != (layer == L_STN)) {
        clear_keyboard();  // prevent stuck keys
        keymap_config.nkro = (layer == L_STN);
    }

    return state;
};

bool led_update_user(led_t led_state) {
    // Indicate the host LED status via the brightness of the 3 LEDs.  This will
    // only be visible if the LEDs are actually turned on by a relevant layer.
    ergodox_right_led_1_set(led_state.num_lock ? LED_BRIGHTNESS_HI : LED_BRIGHTNESS_LO);
    ergodox_right_led_2_set(led_state.caps_lock ? LED_BRIGHTNESS_HI : LED_BRIGHTNESS_LO);
    ergodox_right_led_3_set(led_state.scroll_lock ? LED_BRIGHTNESS_HI : LED_BRIGHTNESS_LO);

    return true;
}
