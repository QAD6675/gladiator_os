
#ifndef _LIBGUI_BUTTON_HPP
#define _LIBGUI_BUTTON_HPP

#include <libgui/control.hpp>
#include <libgui/event.hpp>
#include <string>

namespace GUI {

	class Button : public GUI::ControlBase {
		std::string text;
		void on_mouse_down(int button, int x, int y) override;
		void draw(int handle) override;

	public:
		GUI::Event<> onclick;
		Button() = default;
		Button(const Button&) = delete;
		Button(Button&&) = delete;
		Button(const std::string& s);
		Button(const char* s);
		void set_test(const std::string& s);
		void set_text(const char* s);
	};

} // namespace GUI

#endif
