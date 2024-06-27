
#include "label.hpp"
#include <libwm/wm.h>

void GUI::Label::draw(int handle) {
	COLOUR c{0, 0, 0};
	wm_print_text(handle, x, y, c, label_str.c_str());
}

void GUI::Label::on_mouse_down(int button, int x, int y) {}

void GUI::Label::set_text(const char* text) {
	label_str = text;
}

void GUI::Label::set_text(const std::string& text) {
	label_str = text;
}
