
#include <libgui/control.hpp>
#include <libgui/wmbase.hpp>
#include <vector>

namespace GUI {

	class Window : private WmBase {
		int handle;
		std::vector<ControlBase*> control_cont;

	public:
		Window() = delete;
		Window(int width, int height);
		Window(const Window&) = delete;
		Window(Window&&) = delete;
		virtual ~Window();

		void render();
		void set_title(const char* title);
		void add_control(ControlBase& control);

		constexpr int get_handle() {
			return handle;
		}

		// events
		virtual void on_key_down(int key);
		virtual void on_key_up(int key);
		virtual void on_mouse_down(int button, int x, int y);
		virtual void on_mouse_up(int button, int x, int y);
	};

	void start_application(Window& win);

} // namespace GUI
