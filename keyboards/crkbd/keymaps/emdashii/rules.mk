MOUSEKEY_ENABLE = yes    			# Mouse keys
RGBLIGHT_ENABLE = no    			# Enable WS2812 RGB underlight. Might need to be no?
RGB_MATRIX_ENABLE = yes
OLED_ENABLE     = yes
OLED_DRIVER     = ssd1306
WPM_ENABLE 			= yes			# Enable word per minute counter
COMBO_ENABLE 		= yes			# Enable base-layer combos
CAPS_WORD_ENABLE 	= yes			# Caps Word on the Caps Lock spot
LAYER_LOCK_ENABLE 	= yes			# Layer Lock on the right-inner thumb
LTO_ENABLE 			= yes			# Makes hex file smaller
#OLED_DRIVER_ENABLE = yes			# Enable OLEDs

SRC += ./oled.c ./rgb.c
