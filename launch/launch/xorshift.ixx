module;
#include <cstdint>
#include <tl/generator.hpp>
export module xorshift;

export namespace launch {
	tl::generator<std::uint64_t> xorshift(std::uint64_t seed) {
		while (true) {
			seed ^= seed >> 13;
			seed ^= seed << 17;
			seed ^= seed >> 7;
			co_yield seed;
		}
	}
}