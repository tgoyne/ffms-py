#include <ffms.h>

#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

#include "enum_mappings.h"

static void init_ffms() {
	static bool initialized = false;
	if (!initialized) {
		FFMS_Init(0, 1);
		initialized = true;
	}
}

static int version() {
	init_ffms();
	return FFMS_GetVersion();
}

static int get_log_level() {
	init_ffms();
	return FFMS_GetLogLevel();
}

static void set_log_level(int level) {
	init_ffms();
	FFMS_SetLogLevel(level);
}

#define EXPORT(a) def(#a, a)

BOOST_PYTHON_MODULE(ffms2) {
	using namespace boost::python;
	EXPORT(version);
	EXPORT(get_log_level);
	EXPORT(set_log_level);
}
