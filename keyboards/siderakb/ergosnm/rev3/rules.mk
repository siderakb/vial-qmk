# MCU name
MCU = atmega32u4
F_CPU = 8000000
F_USB = $(F_CPU)
ARCH = AVR8
BOOTLOADER = caterina

OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
OPT_DEFS += -DBOOTLOADER_SIZE=4096

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

CUSTOM_MATRIX = yes

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom

ENCODER_ENABLE = no 
# ENCODER_MAP_ENABLE = yes

SRC += matrix.c uart.c
UART_DRIVER_REQUIRED = yes
