
#ifndef _LIBGUI_LABEL_HPP
#define _LIBGUI_LABEL_HPP

#include <libgui/control.hpp>
#include <string>

namespace GUI {

	class Label : public GUI::ControlBase {
		std::string label_str;

		void draw(int handle) override;
		void on_mouse_down(int button, int x, int y) override;

	public:
		constexpr Label() = default;
		constexpr Label(const char* text) : label_str(text) {}
		constexpr Label(std::string text) : label_str(text) {}
		void set_text(const char* text);
		void set_text(const std::string& text);
	};

} // namespace GUI

#endif
