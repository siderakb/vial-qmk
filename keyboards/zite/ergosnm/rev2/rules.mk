# MCU name
MCU = RP2040

BOOTLOADER = rp2040

# Build Options
BOOTMAGIC_ENABLE ?= yes	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE ?= yes	# Mouse keys(+4700)
EXTRAKEY_ENABLE ?= yes	# Audio control and System control(+450)
CONSOLE_ENABLE ?= no	# Console for debug(+400)
COMMAND_ENABLE ?= no    # Commands for debug and configuration
SLEEP_LED_ENABLE ?= no  # Breathing sleep LED during USB suspend
NKRO_ENABLE ?= yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE ?= no  # Enable keyboard backlight functionality
RGBLIGHT_ENABLE ?= no
AUDIO_ENABLE ?= no

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360

ENCODER_ENABLE = no 
# ENCODER_MAP_ENABLE = yes

# LTO_ENABLE = yes # Link time optimization, enable to reduce the compiled size of firmware.
