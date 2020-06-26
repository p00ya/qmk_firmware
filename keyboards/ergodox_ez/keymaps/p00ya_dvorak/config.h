/* See: https://docs.qmk.fm/#/config_options?id=the-configh-file */
#define ORYX_CONFIGURATOR

// Ergodox EZ uses eager_pr debounce by default, so this only delays key down
// events on physical *columns* (matrix rows).  Kailh and Cherry switches
// specify a 5ms debounce but there is some question of noise in the Ergodox
// itself.
#undef DEBOUNCE
#define DEBOUNCE 20

#undef TAPPING_TERM
#define TAPPING_TERM 180

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// https://configure.ergodox-ez.com/ergodox-ez/layouts/vAdRO/J4yp0/0
#define FIRMWARE_VERSION u8"vAdRO/J4yp0"
