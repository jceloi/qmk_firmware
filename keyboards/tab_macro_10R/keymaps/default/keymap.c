#include "keymap_french.h"
#include "tab_macro_10R.h"


#define _BASE 0
#define _REBELLE 1
#define _CLIPSTUDIO 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = KEYMAP(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,  TO(_REBELLE), KC_R),
	[_REBELLE] = KEYMAP(
		KC_LEFT_CTRL, KC_E, KC_I, KC_LEFT_SHIFT, KC_B, LSFT(KC_D), KC_SPACE, FR_Z, LCTL(FR_Z), TO(_CLIPSTUDIO), LSFT(KC_L)),
	[_CLIPSTUDIO] = KEYMAP(
		KC_Z, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, TO(_BASE), KC_K),

};
