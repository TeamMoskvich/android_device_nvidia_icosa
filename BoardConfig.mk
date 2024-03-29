#
# Copyright (C) 2014 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# This variable is set first, so it can be overridden
# by BoardConfigVendor.mk

include device/nvidia/shield-common/BoardConfigCommon.mk

TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_SMP := true
TARGET_CPU_VARIANT := cortex-a53
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a

TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv7-a-neon
TARGET_2ND_CPU_VARIANT := cortex-a53.a57
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi

# Assert
TARGET_OTA_ASSERT_DEVICE := darcy,foster,loki,icosa

# Board
TARGET_BOARD_PLATFORM := tegra
TARGET_NO_BOOTLOADER := true
TARGET_NO_RADIOIMAGE := true
TARGET_BOARD_INFO_FILE := device/nvidia/foster/board-info.txt

# Kernel
KERNEL_TOOLCHAIN_PREFIX := aarch64-linux-android-
TARGET_KERNEL_SOURCE := kernel/nvidia/shield
TARGET_KERNEL_CONFIG := lineageos_t210_defconfig
BOARD_KERNEL_IMAGE_NAME := zImage

BOARD_FLASH_BLOCK_SIZE := 4096
BOARD_BOOTIMAGE_PARTITION_SIZE      := 26738688
BOARD_RECOVERYIMAGE_PARTITION_SIZE  := 26767360
BOARD_USERDATAIMAGE_PARTITION_SIZE  := 10099646976
BOARD_SYSTEMIMAGE_PARTITION_SIZE    := 2147483648
BOARD_VENDORIMAGE_PARTITION_SIZE    := 805306368
TARGET_USERIMAGES_USE_EXT4 := true
BOARD_VENDORIMAGE_FILE_SYSTEM_TYPE := ext4
TARGET_COPY_OUT_VENDOR := vendor

# Bluetooth
BOARD_HAVE_BLUETOOTH := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR ?= device/nvidia/foster/comms

# Graphics
USE_OPENGL_RENDERER := true

#Audio
BOARD_USES_GENERIC_AUDIO := false
BOARD_USES_ALSA_AUDIO := true

# Include an expanded selection of fonts
EXTENDED_FONT_FOOTPRINT := true

# Per-application sizes for shader cache
MAX_EGL_CACHE_SIZE := 4194304
MAX_EGL_CACHE_ENTRY_SIZE := 262144

# Recovery
TARGET_RECOVERY_FSTAB := device/nvidia/foster/initfiles/fstab.icosa

# RenderScript
OVERRIDE_RS_DRIVER := libnvRSDriver.so

# Wifi related defines
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
WPA_SUPPLICANT_VERSION      := VER_0_8_X
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_bcmdhd
BOARD_WLAN_DEVICE           := bcmdhd
BOARD_HOSTAPD_DRIVER        := NL80211
BOARD_HOSTAPD_PRIVATE_LIB   := lib_driver_cmd_bcmdhd
WIFI_DRIVER_FW_PATH_STA     := "/system/vendor/firmware/fw_bcmdhd.bin"
WIFI_DRIVER_FW_PATH_AP      := "/system/vendor/firmware/fw_bcmdhd.bin"
WIFI_DRIVER_FW_PATH_P2P     := "/system/vendor/firmware/fw_bcmdhd.bin"
WIFI_DRIVER_FW_PATH_PARAM   := "/sys/module/bcmdhd/parameters/firmware_path"
WIFI_DRIVER_MODULE_ARG      := "iface_name=wlan0"
WIFI_DRIVER_MODULE_NAME     := "bcmdhd"

BOARD_HARDWARE_CLASS := device/nvidia/foster/lineagehw/

# SELinux
BOARD_SEPOLICY_DIRS += device/nvidia/foster/sepolicy/

# Pro model doesn't support trim commands
BOARD_SUPPRESS_EMMC_WIPE := true

# Forced shims
TARGET_LD_SHIM_LIBS := /vendor/bin/glgps_nvidiaTegra2android|/system/lib/libsensor.so

## Vendor Init
TARGET_INIT_VENDOR_LIB := libinit_shield libinit_foster
TARGET_LIBINIT_DEFINES_FILE := device/nvidia/foster/init/init_foster.cpp

# Override common releasetools
TARGET_RELEASETOOLS_EXTENSIONS := device/nvidia/foster/releasetools

# TWRP Support
ifeq ($(WITH_TWRP),true)
-include device/nvidia/foster/twrp/twrp.mk
endif
