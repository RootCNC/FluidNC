// Copyright (c) 2020 -	Bart Dring
// Use of this source code is governed by a GPLv3 license that can be found in the LICENSE file.

#pragma once

/*
	
*/

#include "Display.h"

namespace Displays {
    class Oled_Ss1306 : public Display {
    protected:
        Pin      _sda_pin;
        Pin      _scl_pin;
        uint32_t _addr     = 0x3c;
        String   _geometry = "128x64";

    public:
        void init() override;

        void config_message() override;

        void group(Configuration::HandlerBase& handler) override {
            handler.item("sda_pin", _sda_pin);
            handler.item("scl_pin", _scl_pin);
            handler.item("address", _addr);
            handler.item("geometry", _geometry);
        }

        virtual ~Oled_Ss1306() {}

        // Name of the configurable. Must match the name registered in the cpp file.
        const char* name() const override { return "oled_ss1306"; }

    protected:
    };
}
