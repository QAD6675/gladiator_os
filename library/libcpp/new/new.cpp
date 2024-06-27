
#include <cstdlib>
#include <new>

namespace {
	std::new_handler new_handler_func = nullptr;
}

[[nodiscard]] void* operator new(std::size_t count) {
	void* ptr;
	while (!(ptr = std::malloc(count))) {
		if (new_handler_func) {
			new_handler_func();
		} else {
			// throw std::bad_alloc;
		}
	}
	return ptr;
}

[[nodiscard]] void* operator new[](std::size_t count) {
	return ::operator new(count);
}

std::new_handler std::get_new_handler() noexcept {
	return new_handler_func;
}

std::new_handler std::set_new_handler(std::new_handler new_p) noexcept {
	std::new_handler prev_handler = new_handler_func;
	new_handler_func = new_p;
	return prev_handler;
}
