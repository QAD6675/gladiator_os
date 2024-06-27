
#include <ios>

namespace std {
	ios_base::fmtflags ios_base::flags() const {
		return format_flag;
	}

	ios_base::fmtflags ios_base::flags(ios_base::fmtflags flags) {
		fmtflags oldflg = format_flag;
		format_flag = flags;
		return oldflg;
	}

	ios_base::fmtflags ios_base::setf(ios_base::fmtflags flags) {
		fmtflags oldflg = format_flag;
		format_flag |= flags;
		return oldflg;
	}

	ios_base::fmtflags ios_base::setf(ios_base::fmtflags flags, ios_base::fmtflags mask) {
		fmtflags oldflg = format_flag;
		format_flag = (format_flag & ~mask) | (flags & mask);
		return oldflg;
	}

	void ios_base::unsetf(ios_base::fmtflags flags) {
		format_flag &= ~flags;
	}

	ios_base& dec(std::ios_base& str) {
		str.unsetf(std::ios_base::basefield);
		str.setf(std::ios_base::dec);
		return str;
	}

	ios_base& hex(std::ios_base& str) {
		str.unsetf(std::ios_base::basefield);
		str.setf(std::ios_base::hex);
		return str;
	}

	ios_base& oct(std::ios_base& str) {
		str.unsetf(std::ios_base::basefield);
		str.setf(std::ios_base::oct);
		return str;
	}
} // namespace std
