
#ifndef _LIBCPP_IMPL_SWAP_HPP
#define _LIBCPP_IMPL_SWAP_HPP

#include <impl/move.hpp>

namespace std {

	template <class T>
	constexpr void swap(T& a, T& b) noexcept {
		T t(std::move(b));
		b = std::move(a);
		a = std::move(t);
	}

} // namespace std

#endif
