/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes {
	FLOAT = SAFE_RANGE,
	ADDX,
	SUBX,
	PROMOTE,
	ROTM,
	ROTS,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case FLOAT:
		if (record->event.pressed) {
			// when keycode FLOAT is pressed
			register_code(KC_LWIN);
			register_code(KC_LSFT);
			register_code(KC_F);
			register_code(KC_D);
		} else {
			// when keycode FLOAT is released
			unregister_code(KC_LWIN);
			unregister_code(KC_LSFT);
			unregister_code(KC_F);
			unregister_code(KC_D);
		}
		break;

	case ADDX:
		if (record->event.pressed) {
			// when keycode ADDX is pressed
			register_code(KC_LWIN);
			register_code(KC_LCTL);
			register_code(KC_RGHT);
		} else {
			// when keycode ADDX is released
			unregister_code(KC_LWIN);
			unregister_code(KC_LCTL);
			unregister_code(KC_RGHT);
		}
		break;

	case SUBX:
		if (record->event.pressed) {
			// when keycode SUBX is pressed
			register_code(KC_LWIN);
			register_code(KC_LCTL);
			register_code(KC_LEFT);
		} else {
			// when keycode SUBX is released
			unregister_code(KC_LWIN);
			unregister_code(KC_LCTL);
			unregister_code(KC_LEFT);
		}
		break;

	case PROMOTE:
		if (record->event.pressed) {
			// when keycode PROMOTE is pressed
			register_code(KC_LWIN);
			register_code(KC_LSFT);
			register_code(KC_ENT);
		} else {
			// when keycode PROMOTE is released
			unregister_code(KC_LWIN);
			unregister_code(KC_LSFT);
			unregister_code(KC_ENT);
		}
		break;

	case ROTM:
		if (record->event.pressed) {
			//when keycode ROTM is pressed
			register_code(KC_LWIN);
			register_code(KC_LCTL);
			register_code(KC_TAB);
		} else {
			// when keycode ROTM is released
			unregister_code(KC_LWIN);
			unregister_code(KC_LCTL);
			unregister_code(KC_TAB);
		}
		break;

	case ROTS:
		if (record->event.pressed) {
			//when keycode ROTS is pressed
			register_code(KC_LWIN);
			register_code(KC_LCTL);
			register_code(KC_LSFT);
			register_code(KC_TAB);
		} else {
			// when keycode ROTS is pressed
			unregister_code(KC_LWIN);
			unregister_code(KC_LCTL);
			unregister_code(KC_LSFT);
			unregister_code(KC_TAB);
		}
		break;
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      			 | Knob 2: Vol Dn/Up 	 |
        | Rotate master     | Rotate stack		 | Press: Mute  	 |
        | Promote window    | Master subtract horizontal | Master add horizontal |
        | float window 	    | Media play/pause  	 | Media Next            |
     */
    [0] = LAYOUT(
        ROTM     , ROTS    , KC_MUTE ,
        PROMOTE  , SUBX    , ADDX    ,
        FLOAT    , KC_MPLY , KC_MNXT 
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 2) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
