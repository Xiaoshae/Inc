#include "inc.h"

namespace lib_inc {


	inc::inc(void):data(nullptr),links(data,son.getSon()){

	}

	link& inc::getLinks(void) {
		inc& object = *this;
		return object.links;
	}



}
