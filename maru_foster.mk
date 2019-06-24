# Inherit device configuration for foster.
$(call inherit-product, device/nvidia/foster/full_foster.mk)

# Inherit some common lineage stuff.
ifeq ($(ALTERNATE_BUILD),true)
$(call inherit-product, vendor/lineage/config/common_full_tablet_wifionly.mk)
else
$(call inherit-product, vendor/lineage/config/common_full_tv.mk)
endif


# Bring in Maru OS stuff
$(call inherit-product, vendor/maruos/device-maru.mk)
$(call inherit-product, vendor/maruos/BoardConfigVendor.mk)

PRODUCT_NAME := maru_foster
PRODUCT_MODEL := Maru OS for the Nintendo Switch
