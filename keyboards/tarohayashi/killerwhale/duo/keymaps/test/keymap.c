// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "lib/add_keycodes.h"

// 1. レイヤー名の定義
enum layer_number {
    BASE = 0,
    ONOFF, OFFON, ONON,                       // トグルスイッチで変更するレイヤー
    LOWER, UPPER, UTIL,                       // 長押しで変更するレイヤー
    MOUSE, BALL_SETTINGS, MISC                // 自動マウスレイヤー切り替えや設定用のレイヤー
};

// 2. タップダンスの設定
enum {
    TD_ESC_GRAVE = 0,                        // ESCと半角／全角
    TD_1,                                    // 1
    TD_2,                                    // 2
    TD_3,                                    // 3
    TD_4,                                    // 4
    TD_5,                                    // 5
    TD_6,                                    // 6
    TD_7,                                    // 7
    TD_8,                                    // 8
    TD_9,                                    // 9
    TD_0,                                    // 0
    TD_COMM_S,                               // ,<
    TD_DOT_S                                 // />
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_GRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRAVE),
    [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, S(KC_1)),
    [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, S(KC_2)),
    [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, S(KC_3)),
    [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, S(KC_4)),
    [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, S(KC_5)),
    [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, S(KC_6)),
    [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, S(KC_7)),
    [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, S(KC_8)),
    [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, S(KC_9)),
    [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, S(KC_0)),
    [TD_COMM_S] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, S(KC_COMM)),
    [TD_DOT_S] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, S(KC_DOT))
};

// 3. コンボの設定 ※追加時は「config.h」で個数を増やして
enum combos {
    CMB_ENTER,
    CMB_SPACE,
};

const uint16_t PROGMEM enter_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM space_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
    [CMB_ENTER] = COMBO(enter_combo, KC_ENT),
    [CMB_SPACE] = COMBO(space_combo, KC_SPACE),
};

// 4. 独自のキーコードを定義
enum custom_keycodes {
    MC_CAD = SAFE_RANGE, // Ctrl + Alt + Del 用
    MC_TASK              // タスクマネージャーを直接起動
};

// 5. キーマップの設定
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        // 左手
        TD(TD_ESC_GRAVE), TD(TD_1), TD(TD_2), TD(TD_3),       TD(TD_4),       TD(TD_5),
                 KC_LSFT,     KC_Q,     KC_W,     KC_E,           KC_R,           KC_T,
                 CMD_CTL,     KC_A,     KC_S,     KC_D,           KC_F,           KC_G,
                              KC_Z,     KC_X,     KC_C, LT(OFFON,KC_V), LT(ONOFF,KC_B),
                                     KC_LWIN,
        // 側面スイッチ 上 下
        KC_SPACE, KC_ENT,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         L_CHMOD,
        // 追加スイッチ 左 右                       // トグルスイッチ
        KC_LALT, TG(BALL_SETTINGS),                     MO(ONOFF),

        // 右手
              TD(TD_6),       TD(TD_7),      TD(TD_8),     TD(TD_9), TD(TD_0), KC_BSPC,
                  KC_Y,           KC_U,          KC_I,         KC_O,     KC_P, KC_MINS,
                  KC_H,           KC_J,          KC_K,         KC_L,  KC_SCLN, KC_QUOT,
        LT(ONOFF,KC_N), LT(OFFON,KC_M), TD(TD_COMM_S), TD(TD_DOT_S),  KC_RBRC,
                                                            KC_LBRC,
        // 側面スイッチ 下 上
        KC_ENT, KC_SPACE,
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         R_CHMOD,
        // 追加スイッチ 左 右                        // トグルスイッチ
        TG(MOUSE), KC_TAB,                       MO(OFFON)
    ),
    [ONOFF] = LAYOUT(
        // 左手
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        _______, _______, _______, MC_TASK,  MC_CAD, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        // 側面スイッチ 上 下
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ 左 右                         // トグルスイッチ
        _______, _______,                            _______,

        // 右手
          KC_F6,   KC_F7,   KC_F8,    KC_F9,  KC_F10, KC_PSCR,
         KC_F11,  KC_F12,   KC_UP,  KC_QUOT,  KC_GRV, KC_NUHS,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSLS, KC_RSFT,
        _______, _______, _______,  _______, KC_SLSH,
                                     KC_EQL,
        // 側面スイッチ 下 上
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ 左 右                         // トグルスイッチ
        _______, _______,                           MO(ONON)
    ),
    [OFFON] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        // 側面スイッチ 上 下
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                      // トグルスイッチ
        _______, _______,                    MO(ONON),

        // 右手
        _______, _______, _______, KC_NUM_LOCK,    KC_KP_SLASH, _______,
        _______, KC_KP_7, KC_KP_8,     KC_KP_9, KC_KP_ASTERISK, _______,
        _______, KC_KP_4, KC_KP_5,     KC_KP_6,    KC_KP_MINUS, _______,
        KC_KP_0, KC_KP_1, KC_KP_2,     KC_KP_3,     KC_KP_PLUS,
                                   KC_KP_ENTER,
        // 側面スイッチ 下 上
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                      // トグルスイッチ
        _______, _______,                            _______
    ),
    [ONON] = LAYOUT(
        // 左手
        TD(TD_ESC_GRAVE),    KC_1, KC_2, KC_3, KC_4, KC_5,
                 _______,    KC_T, KC_Q, KC_W, KC_E, KC_R,
                 _______,    KC_G, KC_A, KC_S, KC_D, KC_F,
                             KC_B, KC_Z, KC_X, KC_C, KC_V,
                          _______,
        // 側面スイッチ 上 下
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                      // トグルスイッチ
        _______, _______,                            _______,

        // 右手
           KC_6,     KC_7,    KC_8,    KC_9,      KC_0, _______,
        _______,  C(KC_C), MS_WHLU, C(KC_V),   _______, _______,
        MOD_SCRL, MS_BTN1, MS_BTN3, MS_BTN2,   _______, _______,
        _______,  _______, MS_WHLD, _______, QK_USER_4,
                                   MOD_SCRL,
        // 側面スイッチ 下 上
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                      // トグルスイッチ
        _______, _______,                            _______
    ),
    [MOUSE] = LAYOUT(
        // 左手KC_COMM, KC_DOT
        _______,  _______, S(KC_COMM),  _______, S(KC_DOT), _______,
        _______,     KC_F,    S(KC_P),    KC_UP,   S(KC_N), KC_VOLU,
        _______,     KC_M,    KC_LEFT, KC_SPACE,  KC_RIGHT,    KC_F,
                     KC_C,       KC_J,  KC_DOWN,      KC_L, KC_VOLD,
                             MOD_SCRL,
        // 側面スイッチ 上 下
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                      // トグルスイッチ
        _______, _______,                            _______,

        // 右手
        _______,  _______, _______, _______,   _______, _______,
        _______,  C(KC_C), MS_WHLU, C(KC_V),   _______, _______,
        MOD_SCRL, MS_BTN1, MS_BTN3, MS_BTN2,   _______, _______,
        _______,  _______, MS_WHLD, _______, QK_USER_4,
                                   MOD_SCRL,
        // 側面スイッチ 下 上
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                      // トグルスイッチ
        TG(MOUSE), _______,                            _______
    ),
    [BALL_SETTINGS] = LAYOUT(
        // 左手
        QK_USER_15, XXXXXXX, XXXXXXX, QK_USER_14, _______, L_CHMOD,
           XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, L_SPD_I, XXXXXXX,
        AUTO_MOUSE, XXXXXXX, XXXXXXX,    L_ANG_D,   L_INV, L_ANG_I,
                    XXXXXXX, XXXXXXX,    XXXXXXX, L_SPD_D, XXXXXXX,
                            INV_SCRL,
        // 側面スイッチ 上 下
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                      // トグルスイッチ
        INV_SCRL, TG(BALL_SETTINGS),                           XXXXXXX,

        // 右手
        R_CHMOD, _______, QK_USER_14, XXXXXXX, XXXXXXX,    XXXXXXX,
        XXXXXXX, R_SPD_I,    XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
        R_ANG_D, R_INV,      R_ANG_I, XXXXXXX, XXXXXXX, AUTO_MOUSE,
        XXXXXXX, R_SPD_D,    XXXXXXX, XXXXXXX, XXXXXXX,
                                     INV_SCRL,
        // 側面スイッチ 下 上
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                      // トグルスイッチ
        XXXXXXX, XXXXXXX,                            XXXXXXX
    ),
    [MISC] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                                   _______,
        // 側面スイッチ 上 下
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                      // トグルスイッチ
        _______, _______,                            _______,

        // 右手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                           _______,
        // 側面スイッチ 下 上
        _______, _______,
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                      // トグルスイッチ
        _______, _______,                            _______
    )
};

// 6. エンコーダーの設定
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = {
        ENCODER_CCW_CW(KC_ESC, KC_TAB),
        ENCODER_CCW_CW(REDO, UNDO),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
        ENCODER_CCW_CW(KC_DEL, KC_BSPC),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD)
    },
    [ONOFF] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [OFFON] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [ONON] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [LOWER] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [UPPER] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [UTIL] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    
    [MOUSE] = {
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(S(KC_DOT), S(KC_COMM)),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______)
    },

    [BALL_SETTINGS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [MISC] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    
};

// 7. カスタムキーの設定
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MC_CAD:
            if (record->event.pressed) {
                // Ctrl + Alt + Del を同時に叩く
                tap_code16(LCTL(LALT(KC_DEL)));
            }
            break;
        case MC_TASK:
            if (record->event.pressed) {
                // Ctrl + Shift + Esc を同時に叩く
                tap_code16(LCTL(LSFT(KC_ESC)));
            }
            break;
    }
    return true;
}
