PRODUCT_COPY_FILES += \
                      device/nvidia/foster/twrp/twrp.fstab.emmc:recovery/root/etc/twrp.fstab.emmc \
                      device/nvidia/foster/twrp/twrp.fstab.sdcard:recovery/root/etc/twrp.fstab.sdcard \
                      device/nvidia/foster/twrp/twrp.fstab.sata:recovery/root/etc/twrp.fstab.sata

TW_THEME := landscape_hdpi
TW_HWROTATION := 270
TW_NO_SCREEN_TIMEOUT := true
TW_NO_SCREEN_BLANK := false
TW_BRIGHTNESS_PATH := /sys/class/backlight/pwm-backlight/brightness
TW_MAX_BRIGHTNESS := 255
