
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <libwm/wm.h>

#include "imagebox.hpp"
#include "imageloader/bmp.hpp"

GUI::ImageBox::ImageBox(const char* filename) {
	load_image(filename);
}

GUI::ImageBox::~ImageBox() {
	::operator delete(img);
}

void GUI::ImageBox::load_image(const char* filename) {
	if (img) {
		::operator delete(img);
	}

	BMPLoader bmp(filename);
	width = bmp.get_width();
	height = bmp.get_height();
	img = ::operator new(width* height * sizeof(COLOUR));
	bmp.load(img);
}

void GUI::ImageBox::on_mouse_down(int button, int x, int y) {}

void GUI::ImageBox::draw(int handle) {
	if (img) {
		wm_draw_buffer(handle, x, y, width, height, reinterpret_cast<COLOUR*>(img));
	}
}
