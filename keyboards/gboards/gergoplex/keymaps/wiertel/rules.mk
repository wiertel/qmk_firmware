#----------------------------------------------------------------------------
# make gboards/gergoplex:wiertel:flash
# Make sure you have dfu-programmer installed!
#----------------------------------------------------------------------------

#Debug options
VERBOSE                = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX           = no
CONSOLE_ENABLE         = yes

COMBO_ENABLE           = yes
CAPS_WORD_ENABLE       = yes

VPATH                  +=  keyboards/gboards/

ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
