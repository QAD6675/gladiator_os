
#include <cstdlib>
#include <iostream>
#include <libwm/wm.h>

#include "wmbase.hpp"

int GUI::WmBase::wm_init_count = 0;

GUI::WmBase::WmBase() {
	if (wm_init_count == 0) {
		if (!wm_init()) {
			std::cerr << "Cannot connect to Window Manager\n";
			std::exit(1);
		}
		wm_init_count = 1;
	}
}
