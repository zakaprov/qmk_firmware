#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define ALT_2 LALT_T(KC_2)
#define ALT_3 LALT_T(KC_3)
#define ALT_8 LALT_T(KC_8)
#define ALT_D LALT_T(KC_D)
#define ALT_E LALT_T(KC_E)
#define ALT_K LALT_T(KC_K)
#define ALT_LB LALT_T(KC_LBRC)
#define ALT_S LALT_T(KC_S)
#define CTRL_2 LCTL_T(KC_2)
#define CTRL_4 LCTL_T(KC_4)
#define CTRL_5 LCTL_T(KC_5)
#define CTRL_9 LCTL_T(KC_9)
#define CTRL_EQ LCTL_T(KC_EQL)
#define CTRL_I LCTL_T(KC_I)
#define CTRL_L LCTL_T(KC_L)
#define CTRL_R LCTL_T(KC_R)
#define CTRL_S LCTL_T(KC_S)
#define GUI_0 LGUI_T(KC_0)
#define GUI_1 LGUI_T(KC_1)
#define GUI_4 LGUI_T(KC_4)
#define GUI_7 LGUI_T(KC_7)
#define GUI_RB LGUI_T(KC_RBRC)
#define GUI_F LGUI_T(KC_F)
#define GUI_J LGUI_T(KC_J)
#define GUI_N LGUI_T(KC_N)
#define GUI_TEA LGUI_T(KC_T)
#define MAC_EM S(LALT(KC_MINS))
#define MAC_EN LALT(KC_MINS)
#define NAV_BK LT(_NAV, KC_BSPC)
#define NAV_LK TG(_NAV)
#define NUME_SPC LT(_NUM_E, KC_SPC)
#define NUMLK_E TG(_NUM_E)
#define NUMLK_N TG(_NUM_N)
#define NUMN_SPC LT(_NUM_N, KC_SPC)
#define SFT_0 LSFT_T(KC_0)
#define SFT_1 LSFT_T(KC_1)
#define SFT_6 LSFT_T(KC_6)
#define SFT_7 LSFT_T(KC_7)
#define SFT_A LSFT_T(KC_A)
#define SFT_O LSFT_T(KC_O)
#define SFT_OS OSM(MOD_LSFT)
#define SFT_QOT LSFT_T(KC_QUOT)
#define SYM_OS OSL(_SYM)
#define SYS_Z LT(_SYS, KC_Z)
#define VOL_DN S(LALT(KC__VOLDOWN))
#define VOL_UP S(LALT(KC__VOLUP))

#define ALT_F LALT_T(KC_F)
#define ALT_6 LALT_T(KC_6)
#define CTRL_A LCTL_T(KC_A)
#define CTRL_0 LCTL_T(KC_0)
#define GUI_G LGUI_T(KC_G)
#define RALT_D RALT_T(KC_D)
#define RALT_5 RALT_T(KC_5)
#define SFT_S LSFT_T(KC_S)
#define SFT_4 LSFT_T(KC_4)

#define ALT_J LALT_T(KC_J)
#define ALT_MIN LALT_T(KC_MINS)
#define CTRL_SCLN LCTRL_T(KC_SCLN)
#define CTRL_RBRC LCTRL_T(KC_RBRC)
#define GUI_H LGUI_T(KC_H)
#define RALT_K RALT_T(KC_K)
#define RALT_EQL RALT_T(KC_EQL)
#define SFT_L LSFT_T(KC_L)
#define SFT_LBRC LSFT_T(KC_LBRC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_TAB,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,    CTRL_A,    SFT_S,    RALT_D,    ALT_F,    GUI_G,                  GUI_H,    ALT_J,    RALT_K,    SFT_L, CTRL_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   KC_LALT,  LT(_LOWER, KC_SPC),     LT(_RAISE, KC_ENT),  KC_RALT, KC_LCTL \
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, ALT_MIN, RALT_EQL, SFT_LBRC, CTRL_RBRC, KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   KC_LALT,  LT(_LOWER, KC_SPC),     LT(_RAISE, KC_ENT),  KC_RALT, KC_LCTL \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, XXXXXXX, KC_7,   KC_8,   KC_9,   XXXXXXX,                         KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, KC_GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC, CTRL_0,    SFT_4,   RALT_5,   ALT_6,   GUI_G,                         GUI_H, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, KC_1,   KC_2,   KC_3,   XXXXXXX,                         XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   KC_LALT,  LT(_LOWER, KC_SPC),     LT(_RAISE, KC_ENT),  KC_RALT, KC_LCTL \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1,  KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                 KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   KC_LALT,  LT(_LOWER, KC_SPC),     LT(_RAISE, KC_ENT),  KC_RALT, KC_LCTL \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
