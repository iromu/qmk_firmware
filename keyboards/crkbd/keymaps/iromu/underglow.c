#include "crkbd.h"
#include "quantum.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _RAISE:
      rgblight_sethsv_noeeprom_yellow();
      rgblight_mode_noeeprom(5);
      break;
    case _LOWER:
      rgblight_sethsv_noeeprom_magenta();
      rgblight_mode_noeeprom(5);
      break;
    case _ADJUST:
      rgblight_sethsv_noeeprom_red();
      rgblight_mode_noeeprom(5); // sets mode to Fast breathing without saving
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_noeeprom_cyan();
      rgblight_mode_noeeprom(1); // if _MODS layer is on, then breath to denote it
      break;
    }
  return state;
}

//void suspend_power_down_user(void) {
//    rgb_matrix_set_suspend_state(true);
//    rgblight_disable_noeeprom();
//}
//
//void suspend_wakeup_init_user(void) {
//    rgb_matrix_set_suspend_state(false);
//    rgblight_enable_noeeprom();
//}
