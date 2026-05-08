// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "lib/add_keycodes.h"

// 1. レイヤー名の定義
enum layer_number {
    BASE = 0,
    ONOFF, OFFON, ONON,                       // トグルスイッチで変更するレイヤー
    LOWER, UPPER, UTIL,                       // 長押しで変更するレイヤー
    MOUSE, BALL_SETTINGS, MISC // 自動マウスレイヤー切り替えや設定用のレイヤー
};

// 2. タップダンスの設定
// 型名を qk_tap_dance_action_t から tap_dance_action_t に修正しました
enum {
    TD_ESC_GRAVE = 0
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_GRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRAVE)
};

// 3. コンボの設定
enum combos {
    CMB_ENTER,
    CMB_ESC,
};

const uint16_t PROGMEM enter_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM esc_combo[]   = {KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
    [CMB_ENTER] = COMBO(enter_combo, KC_ENT),
    [CMB_ESC]   = COMBO(esc_combo, KC_ESC),
};

// 4. キーマップの設定
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        // 左手
        TD(TD_ESC_GRAVE), KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_TAB,  KC_Q,         KC_W, KC_E, KC_R, KC_T,
        CMD_CTL, KC_A,         KC_S, KC_D, KC_F, KC_G,
                 LSFT_T(KC_Z), KC_X,       KC_C, KC_V, KC_B,
                                      MOD_SCRL,
        // 側面スイッチ
        KC_LNG2, KC_SPC,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         L_CHMOD,
        // 追加スイッチ                       // トグルスイッチ
        MS_BTN2, MS_BTN1,                    MO(ONOFF),

        // 右手
        KC_6, LT(BALL_SETTINGS, KC_7), KC_8, KC_9, KC_0, KC_BSPC,
        KC_Y, KC_U, KC_I,    KC_O,             KC_P,    KC_ENT,
        KC_H, KC_J, KC_K,    LT(MOUSE, KC_L),  KC_SCLN, KC_RSFT,
        KC_N, KC_M, KC_COMM, KC_DOT,           KC_SLSH,
                                     MOD_SCRL,
        // 側面スイッチ
        KC_SPACE, KC_LNG1,
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         R_CHMOD,
        // 追加スイッチ                       // トグルスイッチ
        MS_BTN1, MS_BTN2,                    MO(OFFON)
    ),
    [ONOFF] = LAYOUT(
        // 左手
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                                   _______,
        // 側面スイッチ
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                       // トグルスイッチ
        _______, _______,                            _______,

        // 右手
          KC_F6,   KC_F7,   KC_F8,    KC_F9,  KC_F10, _______,
        _______, _______,   KC_UP,   KC_F11,  KC_F12, _______,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
        _______, _______, _______,  _______, _______,
                                           _______,
        // 側面スイッチ
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                       // トグルスイッチ
        _______, _______,                    MO(ONON)
    ),
    [OFFON] = LAYOUT(
        // 左手
        _______, _______,    KC_P,    KC_UP,     KC_P, _______,
        _______, _______, KC_LEFT, KC_SPACE, KC_RIGHT,    KC_F,
        _______, _______, _______,  KC_DOWN,  _______, _______,
                 _______, _______,  _______,  _______, _______,
                                    _______,
        // 側面スイッチ
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                       // トグルスイッチ
        _______, _______,                    MO(ONON),

        // 右手
        _______, _______, _______, KC_NUM_LOCK,    KC_KP_SLASH, _______,
        _______, KC_KP_7, KC_KP_8,     KC_KP_9, KC_KP_ASTERISK, _______,
        _______, KC_KP_4, KC_KP_5,     KC_KP_6,    KC_KP_MINUS, _______,
        KC_KP_0, KC_KP_1, KC_KP_2,     KC_KP_3,     KC_KP_PLUS,
                                           KC_KP_ENTER,
        // 側面スイッチ
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                       // トグルスイッチ
        _______, _______,                            _______
    ),
    [ONON] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                                   _______,
        // 側面スイッチ
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                       // トグルスイッチ
        _______, _______,                            _______,

        // 右手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                           _______,
        // 側面スイッチ
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                       // トグルスイッチ
        _______, _______,                            _______
    ),
    [MOUSE] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______,    _______,
        _______, _______, _______, _______, _______,    _______,
        _______, _______, _______, MS_BTN2, MS_BTN1, MOD_SCRL,
                 QK_USER_4, _______, _______, _______, _______,
                                   MOD_SCRL,
        // 側面スイッチ
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                       // トグルスイッチ
        _______, _______,                            _______,

        // 右手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        MOD_SCRL, MS_BTN1, MS_BTN2, _______, _______, _______,
        _______, _______, _______, _______, QK_USER_4,
                                           MOD_SCRL,
        // 側面スイッチ
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                       // トグルスイッチ
        _______, _______,                            _______
    ),
    [BALL_SETTINGS] = LAYOUT(
        // 左手
        QK_USER_15,    XXXXXXX, XXXXXXX, QK_USER_14, _______, L_CHMOD,
           XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, L_SPD_I, XXXXXXX,
        AUTO_MOUSE, XXXXXXX, XXXXXXX, L_ANG_D, L_INV,   L_ANG_I,
                    XXXXXXX, XXXXXXX,XXXXXXX, L_SPD_D, XXXXXXX,
                                     INV_SCRL,
        // 側面スイッチ
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                       // トグルスイッチ
        XXXXXXX, INV_SCRL,                           XXXXXXX,

        // 右手
        R_CHMOD, _______, QK_USER_14, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, R_SPD_I,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        R_ANG_D, R_INV,   R_ANG_I, XXXXXXX, XXXXXXX, AUTO_MOUSE,
        XXXXXXX, R_SPD_D,   XXXXXXX, XXXXXXX, XXXXXXX,
                                             INV_SCRL,
        // 側面スイッチ
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                       // トグルスイッチ
        XXXXXXX, XXXXXXX,                            XXXXXXX
    ),
    [MISC] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                                   _______,
        // 側面スイッチ
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                       // トグルスイッチ
        _______, _______,                            _______,

        // 右手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                           _______,
        // 側面スイッチ
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                       // トグルスイッチ
        _______, _______,                            _______
    )
};

// 5. エンコーダーの設定
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =   {
        ENCODER_CCW_CW(KC_ESC, KC_TAB),
        ENCODER_CCW_CW(REDO, UNDO),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
        ENCODER_CCW_CW(KC_DEL, KC_BSPC),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD)
    },
    [MISC] =   {
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______)
    }
};
