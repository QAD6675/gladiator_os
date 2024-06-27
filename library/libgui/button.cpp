
#include "button.hpp"
#include <libwm/wm.h>

void GUI::Button::on_mouse_down(int button, int x, int y) {
	onclick();
}

void GUI::Button::draw(int handle) {
	wm_fill_rect(handle, x, y, width, height, {159, 150, 150});
	wm_print_text(handle, x + width / 2 - text.length() * 4, y + height / 2 - 8,
				  {0, 0, 0}, text.c_str());
}

GUI::Button::Button(const std::string& s) : text(s) {}
GUI::Button::Button(const char* s) : text(s) {}

void GUI::Button::set_text(const char* s) {
	text = s;
}

void GUI::Button::set_test(const std::string& s) {
	text = s;
}
