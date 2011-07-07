#include <ffms.h>

#define BOOST_PYTHON_STATIC_LIB

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

void init() {
	FFMS_Init(0, 0);
}

BOOST_PYTHON_MODULE(ffms2) {
	using namespace boost::python;
	def("init", init);
}
