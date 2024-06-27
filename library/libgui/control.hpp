
#ifndef _LIBGUI_CONTROL_HPP
#define _LIBGUI_CONTROL_HPP

namespace GUI {

	class ControlBase {
	public:
		int x, y;
		int width, height;

		virtual void on_mouse_down(int button, int x, int y) = 0;
		virtual void draw(int handle) = 0;
	};

} // namespace GUI

#endif
