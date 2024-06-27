
#include <ios>
#include <iostream>
#include <streambuf>

std::ios_base::ios_base() : format_flag(std::ios_base::dec) {}

std::ios_base::~ios_base() {
	if (callback_func) {
		callback_func(event::erase_event, *this, callback_index);
	}
}

void std::ios_base::register_callback(event_callback function, int index) {
	callback_func = function;
	callback_index = index;
}

bool std::ios_base::sync_with_stdio(bool sync) {
	return true;
}
