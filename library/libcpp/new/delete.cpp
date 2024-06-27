
#include <cstdlib>

void operator delete(void* ptr) noexcept {
	std::free(ptr);
}

void operator delete[](void* ptr) noexcept {
	std::free(ptr);
}
