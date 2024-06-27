
#ifndef _LIBGUI_IMAGEBOX_HPP
#define _LIBGUI_IMAGEBOX_HPP

#include <libgui/control.hpp>

namespace GUI {

	class ImageBox : public GUI::ControlBase {
	private:
		int width, height;
		void* img = nullptr;

	public:
		ImageBox() = default;
		ImageBox(const char* filename);
		~ImageBox();
		void load_image(const char* filename);

		void on_mouse_down(int button, int x, int y) override;
		void draw(int handle) override;
	};

} // namespace GUI

#endif
