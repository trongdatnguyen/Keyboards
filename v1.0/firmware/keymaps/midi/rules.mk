# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
HD44780_ENABLE = no         # Enable support for HD44780 based LCDs
SPLIT_KEYBOARD = no
AUTO_SHIFT_ENABLE = no
AUTO_SHIFT_MODIFIERS = no
COMBO_ENABLE = no
KEY_LOCK_ENABLE =no

TAP_DANCE_ENABLE = yes

OLED_DRIVER_ENABLE = no

ENCODER_ENABLE = yes         # Rotary Encode
EXTRAKEY_ENABLE = no         # Audio control and System control
MOUSEKEY_ENABLE = no         # Mouse keys
RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
MIDI_ENABLE = yes            # MIDI support
NKRO_ENABLE = yes            # USB Nkey Rollover
SLEEP_LED_ENABLE = yes       # Breathing sleep LED during USB suspend

# DEFAULT_FOLDER = microdrumpad

RGB_MATRIX_ENABLE = WS2812
EXTRAFLAGS += -flto
RGB_MATRIX_CUSTOM_USER = yes
