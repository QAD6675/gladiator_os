/*
 * Widget Toolkit Button
 *
 * This file is part of GLADIATOROS.
 *
 * GLADIATOROS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GLADIATOROS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GLADIATOROS.  If not, see <https://www.gnu.org/licenses/>.
 */

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
