
#ifndef _LIBGUI_WMBASE_HPP
#define _LIBGUI_WMBASE_HPP

namespace GUI {

	class WmBase {
		static int wm_init_count;

	public:
		WmBase();
		WmBase(const WmBase&) = delete;
		WmBase(WmBase&&) = delete;
	};

} // namespace GUI

#endif
