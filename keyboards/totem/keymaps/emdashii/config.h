#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_LEFT
// #define MASTER_RIGHT

//#define TAPPING_TERM 170
#define TAPPING_TERM 160
#define DEBOUNCE 10

// Keep normal quick-tap behavior for layer-taps (including Space); the
// per-key callback below disables tap auto-repeat only for home-row mods.
// This is the modern replacement for the removed TAPPING_FORCE_HOLD option.
#define QUICK_TAP_TERM TAPPING_TERM
#define QUICK_TAP_TERM_PER_KEY

// Let a home-row mod become a modifier when another key is tapped while it
// remains held, without making ordinary rolling keypresses into modifiers.
#define PERMISSIVE_HOLD_PER_KEY
