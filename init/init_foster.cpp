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

#include "init_shield.h"
#include "service_shield.h"


#include <map>

void set_usb_props(shield_init *si)
{
	std::map<std::string, std::string> mcommon       = { { "ro.nv.usb.vid",                  "0955" },
	                                                     { "ro.nv.usb.pid.rndis.acm.adb",    "AF00" },
	                                                     { "ro.nv.usb.pid.adb",              "7104" },
	                                                     { "ro.nv.usb.pid.accessory.adb",    "7105" },
	                                                     { "ro.nv.usb.pid.audio_source.adb", "7106" },
	                                                     { "ro.nv.usb.pid.ncm",              "7107" },
	                                                     { "ro.nv.usb.pid.ncm.adb",          "7108" },
	                                                     { "ro.nv.usb.pid.ecm",              "710B" },
	                                                     { "ro.nv.usb.pid.ecm.adb",          "710C" },
	                                                     { "ro.nv.usb.pid.midi",             "7109" },
	                                                     { "ro.nv.usb.pid.midi.adb",         "710A" } };

	std::map<std::string, std::string> mt210ref      = { { "ro.nv.usb.pid.mtp",              "EE02" },
	                                                     { "ro.nv.usb.pid.mtp.adb",          "EE03" },
	                                                     { "ro.nv.usb.pid.rndis",            "EE08" },
	                                                     { "ro.nv.usb.pid.rndis.adb",        "EE09" },
	                                                     { "ro.nv.usb.pid.ptp",              "EE04" },
	                                                     { "ro.nv.usb.pid.ptp.adb",          "EE05" } };

	for (auto const& nvusb : mcommon)
		si->property_set(nvusb.first, nvusb.second);

	for (auto const& nvusb : mt210ref)
		si->property_set(nvusb.first, nvusb.second);
}

void vendor_load_properties()
{
	//                                              device    name            model                manufacturer id  gsm support                               boot device type                 api  dpi
	std::vector<shield_init::devices> devices = { { "foster", "foster_e",     "SHIELD Android TV", "NVIDIA",    "",  shield_init::gsm_support_type::NONE,      shield_init::boot_dev_type::EMMC,   21, 320 },
	                                              { "foster", "foster_e_hdd", "SHIELD Android TV", "NVIDIA",    "",  shield_init::gsm_support_type::NONE,      shield_init::boot_dev_type::SATA,   21, 320 },
	                                              { "darcy",  "darcy",        "SHIELD Android TV", "NVIDIA",    "",  shield_init::gsm_support_type::NONE,      shield_init::boot_dev_type::EMMC,   23, 320 },
	                                              { "foster", "jetson_cv",    "Jetson TX1",        "NVIDIA",    "",  shield_init::gsm_support_type::NONE,      shield_init::boot_dev_type::EMMC,   21, 320 },
	                                              { "foster", "loki_e_lte",   "SHIELD Portable",   "NVIDIA",    "",  shield_init::gsm_support_type::DATA_ONLY, shield_init::boot_dev_type::EMMC,   21, 240 },
	                                              { "foster", "loki_e_wifi",  "SHIELD Portable",   "NVIDIA",    "",  shield_init::gsm_support_type::NONE,      shield_init::boot_dev_type::EMMC,   21, 240 },
	                                              { "icosa",  "icosa",        "Switch",            "Nintendo",  "",  shield_init::gsm_support_type::NONE,      shield_init::boot_dev_type::SDCARD, 21, 240 } };
	shield_init::build_version sav = { "8.0.0", "OPR6.170623.010", "2604118_1256.7693" };
	std::vector<std::string> parts = { "userdata", "system", "vendor" };

	shield_init si(devices, true, sav, parts);
	si.set_properties();
}

int vendor_handle_control_message(const std::string &msg, const std::string &arg)
{
    return shield_handle_control_message(msg, arg);
}
