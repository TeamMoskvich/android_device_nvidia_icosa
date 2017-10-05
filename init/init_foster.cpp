/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"
#include <stdio.h>
#include <string.h>

#define ANDROID_BUILD_VERSION "7.0"
#define ANDROID_BUILD_RELEASE "NRD90M"
#define NVIDIA_BUILD_VERSION "2427173_976.3748"
#define FINGERPRINT_VERSION ANDROID_BUILD_VERSION "/" ANDROID_BUILD_RELEASE "/" NVIDIA_BUILD_VERSION
#define DESCRIPTION_VERSION ANDROID_BUILD_VERSION " " ANDROID_BUILD_RELEASE " " NVIDIA_BUILD_VERSION

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    std::string platform = "";
    std::string model = "";
    std::string device = "foster";

    platform = property_get("ro.board.platform");
    if (strncmp(platform.c_str(), ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    model = property_get("ro.hardware");
    // Darcy just had to be different
    if (!model.compare("darcy")) {
        device = "darcy";
        property_override("ro.product.first_api_level", "23");
        property_override("ro.product.model", "SHIELD Android TV");
        property_override("ro.sf.lcd_density", "320");
    } else if (!model.compare("loki_e_wifi")) {
        property_override("ro.product.first_api_level", "21");
        property_override("ro.product.model", "SHIELD Portable");
        property_override("ro.sf.lcd_density", "240");
    } else {
        property_override("ro.product.first_api_level", "21");
        property_override("ro.product.model", "SHIELD Android TV");
        property_override("ro.sf.lcd_density", "320");
    }

    property_override("ro.build.fingerprint", ("NVIDIA/" + model + "/" + device + ":" + FINGERPRINT_VERSION + ":user/release-keys").c_str());
    property_override("ro.build.description", (model + "-user " + DESCRIPTION_VERSION + " release-keys").c_str());
    property_override("ro.product.name", model.c_str());
    property_override("ro.product.device", device.c_str());
    property_override("ro.build.product", "foster");
    ERROR("Setting build properties for %s model\n", model.c_str());
}
