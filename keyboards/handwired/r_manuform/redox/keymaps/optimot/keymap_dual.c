#include QMK_KEYBOARD_H
#include "keymap_french.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _OPTIMOT_W 1
#define _SHORTCUT_W 2
#define _OPTIMOT_M 3
#define _SHORTCUT_M 4
#define _NUM 5
#define _NAV 6


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUM,
  NAV,
  SHORTCUT_W,
  SHORTCUT_M,
}
;
// Shortcut to make keymap more readable
#define NUM_L   MO(_NUM)
#define NAV_L   MO(_NAV)

#define KC_NAVDN   LT(_NAV, KC_PGDN)
#define KC_NAVHOME   LT(_NAV, KC_HOME)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_LTNUM LT(_NUM, FR_SCLN)
#define KC_RTNUM LT(_NUM, KC_LEFT)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_PUSFT LSFT_T(KC_PGUP)

#define KC_ENSFT RSFT_T(KC_END)

#define KC_CTRLL LM(_SHORTCUT_W, MOD_LCTL)
#define KC_POML LM(_SHORTCUT_M, MOD_LGUI)

#define KC_DWIN DF(0)
#define KC_DMAC DF(3)


//override shift 

const key_override_t quote_shift_override = ko_make_basic(MOD_MASK_SHIFT, FR_QUOT, FR_QUES);
const key_override_t excl_shift_override = ko_make_basic(MOD_MASK_SHIFT, FR_EXLM, FR_CIRC);
const key_override_t dot_shift_override = ko_make_basic(MOD_MASK_SHIFT, FR_DOT, FR_COLN );
const key_override_t dollar_shift_override = ko_make_basic(MOD_MASK_SHIFT, FR_DLR, FR_EURO);
const key_override_t dash_shift_override = ko_make_basic(MOD_MASK_SHIFT, FR_MINS, FR_UNDS);
const key_override_t slash_shift_override = ko_make_basic(MOD_MASK_SHIFT, FR_SLSH, FR_BSLS);

const key_override_t **key_overrides = (const key_override_t *[]){
    &quote_shift_override,
    &excl_shift_override,
    &dot_shift_override,
    &dollar_shift_override,
    &dash_shift_override,
    &slash_shift_override,
    NULL // Null terminate the array of overrides!
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_OPTIMOT_W] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     FR_DLR  ,FR_LABK ,FR_RABK ,FR_DQUO ,FR_MINS ,FR_PLUS ,                                            FR_ASTR ,FR_SLSH ,FR_EQL  ,FR_AT   ,FR_HASH ,FR_PIPE ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,FR_AGRV ,FR_J    ,FR_O    ,FR_EACU ,FR_B    ,XXXXXXX ,                          XXXXXXX ,FR_F    ,FR_D    ,FR_L    ,FR_QUOT ,FR_Q    ,FR_X    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,FR_A    ,FR_I    ,FR_E    ,FR_U    ,FR_COMM ,FR_LPRN ,                          FR_RPRN ,FR_P    ,FR_T    ,FR_S    ,FR_R    ,FR_N    ,FR_EXLM ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CTRLL,FR_K    ,FR_Y    ,FR_EGRV ,FR_DOT  ,XXXXXXX ,KC_PUSFT,KC_NAVDN,      KC_NAVHOME,KC_ENSFT,FR_G    ,FR_C   ,FR_M    ,FR_H   ,FR_V     , FR_Z ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,XXXXXXX ,KC_LALT ,XXXXXXX ,     KC_LTNUM,    KC_SPC  ,KC_DEL  ,       KC_BSPC  ,KC_ENT  ,    KC_RTNUM,     FR_W   , FR_CCED ,KC_RALT ,KC_UP 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_SHORTCUT_W] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ , FR_DOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ , _______,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_X    ,KC_C    ,KC_V    ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,FR_EGRV ,_______ ,_______ ,FR_Y    ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_OPTIMOT_M] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     FR_DLR  ,FR_LABK ,FR_RABK ,FR_DQUO ,FR_MINS ,FR_PLUS ,                                            FR_ASTR ,FR_SLSH ,FR_EQL  ,FR_AT   ,FR_HASH ,FR_PIPE ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,FR_AGRV ,FR_J    ,FR_O    ,FR_EACU ,FR_B    ,XXXXXXX ,                          XXXXXXX ,FR_F    ,FR_D    ,FR_L    ,FR_QUOT ,FR_Q    ,FR_X    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,FR_A    ,FR_I    ,FR_E    ,FR_U    ,FR_COMM ,FR_LPRN ,                          FR_RPRN ,FR_P    ,FR_T    ,FR_S    ,FR_R    ,FR_N    ,FR_EXLM ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_POML,FR_K    ,FR_Y    ,FR_EGRV ,FR_DOT  ,XXXXXXX ,KC_PUSFT,KC_NAVDN,      KC_NAVHOME,KC_ENSFT,FR_G    ,FR_C   ,FR_M    ,FR_H   ,FR_V     , FR_Z ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,XXXXXXX ,KC_LALT ,XXXXXXX ,     KC_LTNUM,    KC_SPC  ,KC_DEL  ,       KC_BSPC  ,KC_ENT  ,    KC_RTNUM,     FR_W   , FR_CCED ,KC_RALT ,KC_UP 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_SHORTCUT_M] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ , FR_DOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ , _______,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_X    ,KC_C    ,KC_V    ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,FR_EGRV ,_______ ,_______ ,FR_Y    ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,FR_EXLM ,FR_AT   ,FR_LCBR ,FR_RCBR ,FR_PIPE ,_______ ,                          _______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,FR_HASH ,FR_DLR  ,FR_LBRC ,FR_RBRC ,FR_GRV  ,FR_LCBR ,                          FR_RCBR ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,FR_PERC ,FR_CIRC ,FR_LPRN ,FR_RPRN ,FR_TILD ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,FR_AMPR ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_P0   ,     KC_P0   ,KC_PDOT ,KC_LEFT ,KC_RIGHT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_DWIN ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,KC_DMAC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_WH_U ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_L ,KC_MS_U ,KC_MS_R ,KC_WH_D ,_______ ,                          _______ ,XXXXXXX ,KC_LEFT ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_MS_D ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_DOWN ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,_______ ,        _______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};
