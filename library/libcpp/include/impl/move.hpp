
#ifndef _LIBCPP_IMPL_MOVE_HPP
#define _LIBCPP_IMPL_MOVE_HPP

#include <type_traits>

namespace std {

	template <class T>
	constexpr typename std::remove_reference<T>::type&& move(T&& t) noexcept {
		return static_cast<typename std::remove_reference<T>::type&&>(t);
	}

} // namespace std

#endif
