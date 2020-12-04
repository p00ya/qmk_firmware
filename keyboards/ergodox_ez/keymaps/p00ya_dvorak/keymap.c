#include QMK_KEYBOARD_H
#include "version.h"

// Layers.  The ordering seems weird but it aligns with nice bitwise LED states.
#define L_DVO 1
#define L_NUM 2
#define L_NAV 3
#define L_COD 4
#define L_DVC 5
#define L_STN 6
#define L_FN 7

// Dvorak-remapped keycodes for some punctuation.
#define KD_LBRC KC_MINS
#define KD_RBRC KC_EQL
#define KD_LCBR KC_UNDS
#define KD_RCBR KC_PLUS
#define KD_EQL KC_RBRC
#define KD_SLSH KC_LBRC
#define KD_UNDS KC_DQUO
#define KD_PLUS KC_RCBR
#define KD_MINS KC_QUOT
#define KD_DQUO LSFT(KC_Q)
#define KD_COLN LSFT(KC_Z)
#define KD_RABK LSFT(KC_E)

// defined in bootmagic.c.
extern keymap_config_t keymap_config;

// user-defined state; not preserved across reboots.
static struct { bool nkro : 1; } user_config;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base layer should mostly act like a 60% US (QWERTY) layout, with some of
  // the right pinky keys missing.
  [0] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_TRNS,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           MO(L_NUM),                                      TT(L_NUM),      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,
    KC_CAPS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,
    KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           OSM(MOD_LSFT),                                  TT(L_NAV),      KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_RSFT,
    MO(L_FN),       KC_ESC,         OSM(MOD_LCTL),  KC_LALT,        KC_LCMD,                                                                                                        KC_RCMD,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,
                                                                                                    TG(L_STN),      KC_PSCR,        KC_HOME,        KC_END,
                                                                                                                    KC_PGUP,        KC_INS,
                                                                                    LT(L_DVC,KC_SPC),KC_ENT,        KC_PGDN,        KC_DEL,         KC_ENT,         KC_SPC
  ),
  // Dvorak base layer (with caps-lock as control), for when OS remapping isn't
  // available.
  [L_DVO] = LAYOUT_ergodox_pretty(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                           KC_TRNS,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TRNS, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    MO(L_NUM),                      TT(L_NUM), KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    OSM(MOD_LSFT),                  TT(L_NAV), KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_TRNS,
    MO(L_FN),KC_ESC,OSM(MOD_LCTL),KC_LALT,KC_LCMD,                                                            KC_RCMD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
                                                         TG(L_STN), KC_PSCR,        KC_HOME, KC_END,
                                                                    KC_PGUP,        KC_INS,
                                         LT(L_COD,KC_SPC), KC_ENT,  KC_PGDN,        KC_DEL,  KC_ENT, KC_SPC
  ),
  // Simulates a numpad with the 5-key aligned with QWERTY's J-key.
  // Num-zero and enter keys are duplicated to the thumb clusters.
  [L_NUM] = LAYOUT_ergodox_pretty(
    KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, KC_NO,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                              KC_KP_0, KC_PDOT, KC_PENT, KC_NO,   KC_NO,
                                                           KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                                    KC_TRNS,        KC_TRNS,
                                                  KC_TRNS, KC_PENT, KC_TRNS,        KC_TRNS, KC_PENT, KC_KP_0
  ),
  // Dirpad / navigation pad on the right hand with a standard US layout.
  [L_NAV] = LAYOUT_ergodox_pretty(
    KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_INS,  KC_HOME, KC_PGUP, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_DEL,  KC_END,  KC_PGDN, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_TRNS,
    KC_TRNS, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS,                                                               KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT,
                                                          KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,         KC_TRNS,
                                                  KC_SPC, KC_TRNS, KC_TRNS,         KC_TRNS, KC_RCMD, KC_TRNS
  ),
  // Coding layer, for use when there is *no* OS remapping.
  // Moves various brackets and symbols to the right hand, particularly
  // optimizing for C-like programming languages.
  [L_COD] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                           KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_0,    KC_LCBR, KC_RCBR, KC_BSLS, KC_TRNS,
    KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LCMD, KC_TRNS,                                             KC_TRNS, KC_LPRN, KC_RPRN, KC_EQL,  KC_ENT,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_EXLM, KC_DQUO, KC_COLN, KC_RABK, KC_PLUS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                               KC_UNDS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                          KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,         KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
  ),
  // Additional overlay for use with L_COD when an OS (software) QWERTY to
  // Dvorak mapping is in use.
  [L_DVC] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KD_LBRC, KD_RBRC, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KD_LCBR, KD_RCBR, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KD_EQL,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KD_DQUO, KD_COLN, KD_RABK, KD_PLUS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                               KD_UNDS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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
    DF(0),   DF(1),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                               KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                                MAGIC_TOGGLE_NKRO, WEBUSB_PAIR,     KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,         KC_TRNS,
                                                 KC_TRNS, KC_PENT, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
  )
};
// clang-format on

void keyboard_post_init_user() {
    // The LEDs are painfully bright.
    ergodox_led_all_set(LED_BRIGHTNESS_LO);
}

// Returns the desired LED state encoded as a 3-bit integer, from the given
// layer state.
// The layers are ordered so that L_NUM sets LED 1, L_NAV sets LED 2, and
// L_FN sets all 3 LEDs.
static inline uint8_t encode_layer_to_leds(uint8_t layer) {
    switch (layer) {
        case L_FN:
            return 7;
        case 0:
            // Don't underflow.
            return 0;
    }
    return layer - 1;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t top_layer = get_highest_layer(state);

    // Make overlays mutually exclusive.
    state = state & 0x03;  // drop overlays, keep base layers
    state |= 1 << top_layer;  // add just the top overlay

    // When using OS Dvorak remapping, set/unset L_COD when L_DVC is set.
    //
    // Note that when the keyboard initializes, default_layer_state is 0.
    // However, after processing a DF(0) action, default_layer_state will be 1!
    // Test with an inequality to cover both these cases.
    if (default_layer_state < (1 << L_DVO)) {
        const layer_state_t code_mask = 1 << L_COD;
        if (state & (1 << L_DVC)) {
            state |= code_mask;  // activate L_COD
        } else {
            state &= ~code_mask;  // deactivate L_COD
            top_layer = get_highest_layer(state);
        }
    }

    // Encode overlay as binary then display that on the LEDs.
    const uint8_t leds = encode_layer_to_leds(top_layer) << 1;
    for (uint8_t i = 1; i <= 3; ++i) {
        if (leds & (1 << i)) {
            ergodox_right_led_on(i);
        } else {
            ergodox_right_led_off(i);
        }
    }

    // Force NKRO on when switching to the stenography layer.
    if (top_layer == L_STN) {
        clear_keyboard();  // prevent stuck keys
        user_config.nkro   = keymap_config.nkro;
        keymap_config.nkro = true;
    } else if (!user_config.nkro) {
        keymap_config.nkro = user_config.nkro;
    }

    return state;
};

// Returns the brightness of LED 3, a conflation of scroll lock and NKRO status.
static uint8_t user_led_3_brightness(void) {
    led_t leds = host_keyboard_led_state();

    uint8_t brightness = LED_BRIGHTNESS_LO;
    brightness += leds.scroll_lock ? 64 : 0;
    brightness += user_config.nkro ? 176 : 0;
    return brightness;
}

bool led_update_user(led_t led_state) {
    // Indicate the host LED status via the brightness of the 3 LEDs.  This will
    // only be visible if the LEDs are actually turned on by a relevant layer.
    ergodox_right_led_1_set(led_state.num_lock ? LED_BRIGHTNESS_HI : LED_BRIGHTNESS_LO);
    ergodox_right_led_2_set(led_state.caps_lock ? LED_BRIGHTNESS_HI : LED_BRIGHTNESS_LO);
    ergodox_right_led_3_set(user_led_3_brightness());

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAGIC_TOGGLE_NKRO: {
            if (record->event.pressed) {
                user_config.nkro   = !user_config.nkro;
                keymap_config.nkro = user_config.nkro;
                ergodox_right_led_3_set(user_led_3_brightness());
            }
            return false;
        }
        default:
            break;
    }
    return true;
}
