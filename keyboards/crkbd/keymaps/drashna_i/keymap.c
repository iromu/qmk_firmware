#include QMK_KEYBOARD_H
#include "drashna.h"

extern keymap_config_t keymap_config;
extern uint8_t is_master;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum crkbd_keycodes {
    RGBRST = NEW_SAFE_RANGE
};

    #define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RT   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLTB,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLTB,    F1,    F2,    F3,    F4,    F5,                     F6,    F7,    F8,    F9,   F10, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,   F11,   F12,   F13,   F14,   F15,                    F16,   F17,   F18,   F19,   F20, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLTB, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   MINS,   EQL,  LCBR,  RCBR,  PIPE,   GRV,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   UNDS,  PLUS,  LBRC,  RBRC,  BSLS,  TILD,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        RT,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                  LEFT,  UP,   DOWN, RIGHT, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,                  XXXXX, DOWN, LEFT, RIGHT, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  GUIEI, LOWER,   SPC,      ENT, RAISE, ALTKN \
                              //`--------------------'  `--------------------'
  )
};

void matrix_init_keymap(void) {
#ifndef CONVERT_TO_PROTON_C
    setPinOutput(D5);
    writePinHigh(D5);

    setPinOutput(B0);
    writePinHigh(B0);
#endif
}


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_master) {
        return OLED_ROTATION_270;
    } else {
        return rotation;
    }
}

void render_crkbd_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

#define KEYLOG_LEN (int)(32 / OLED_FONT_WIDTH)
char keylog_str[KEYLOG_LEN] = {};
uint8_t keylogs_str_idx = 0;
uint16_t log_timer = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {  add_keylog(keycode); }
    return true;
}

void render_status(void) {

    oled_write_P(PSTR("Layer"), false);
    switch (biton32(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_P(PSTR("Unkn "), false);
            break;
    }
    oled_write_P(PSTR("Lyout"), false);
    switch (biton32(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWRTY"), false);
            break;
    }

    uint8_t modifiers = get_mods();
    uint8_t one_shot = get_oneshot_mods();

    oled_write_P(PSTR("Mods:"), false);
    oled_write_P( (modifiers & MOD_MASK_SHIFT || one_shot & MOD_MASK_SHIFT) ? PSTR(" SFT ") : PSTR("     "), false);
    oled_write_P( (modifiers & MOD_MASK_CTRL  || one_shot & MOD_MASK_CTRL ) ? PSTR(" CTL ") : PSTR("     "), false);
    oled_write_P( (modifiers & MOD_MASK_ALT   || one_shot & MOD_MASK_ALT  ) ? PSTR(" ALT ") : PSTR("     "), false);
    oled_write_P( (modifiers & MOD_MASK_GUI   || one_shot & MOD_MASK_GUI  ) ? PSTR(" GUI ") : PSTR("     "), false);


    oled_write_P(PSTR("BTMGK"), false);

    if (keymap_config.swap_lalt_lgui) {
        oled_write_P(PSTR(" Win "), false);
    } else {
        oled_write_P(PSTR(" Mac "), false);
    }

    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(PSTR("Lock:"), false);
    oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK)    ? PSTR(" NUM ") : PSTR("     "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK)   ? PSTR(" CAPS") : PSTR("     "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR(" SCRL") : PSTR("     "), false);

    oled_write(keylog_str, false);
}


void oled_task_user(void) {
    if (is_master) {
        render_status();     // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_crkbd_logo();
        oled_scroll_left();  // Turns on scrolling
    }
}

void matrix_scan_keymap(void) { update_log(); }
#endif

uint16_t get_tapping_term(uint16_t keycode) {
    switch (keycode) {
        case ALT_T(KC_A):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}

void rgb_matrix_indicators_user(void) {
    if ( userspace_config.rgb_layer_change &&
#ifdef RGB_DISABLE_WHEN_USB_SUSPENDED
        !g_suspend_state &&
#endif
#if defined(RGBLIGHT_ENABLE)
        (!rgblight_config.enable && rgb_matrix_config.enable)
#else
        rgb_matrix_config.enable
#endif
    ) {
        switch (biton32(layer_state)) {
            case _RAISE:
                rgb_matrix_layer_helper(0xFF, 0xFF, 0x00, LED_FLAG_UNDERGLOW); break;
            case _LOWER:
                rgb_matrix_layer_helper(0x00, 0xFF, 0x00, LED_FLAG_UNDERGLOW); break;
            case _ADJUST:
                rgb_matrix_layer_helper(0xFF, 0x00, 0x00, LED_FLAG_UNDERGLOW); break;
            default:
                switch (biton32(default_layer_state)) {
                    case _QWERTY:
                        rgb_matrix_layer_helper(0x00, 0xFF, 0xFF, LED_FLAG_UNDERGLOW); break;
                }
        }
    }
}
#endif
