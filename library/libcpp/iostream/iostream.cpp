
#include <cstdio>
#include <ostream>
#include <streambuf>

namespace {
	std::streambuf cout_buf(stdout);
	std::streambuf cerr_buf(stderr);
	std::streambuf clog_buf(stderr);
} // namespace

namespace std {
	ostream cout(&cout_buf);
	ostream cerr(&cerr_buf);
	ostream clog(&clog_buf);
} // namespace std
