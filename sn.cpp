#include "sn.h"

namespace lib_inc {

	namespace n_sn {


		sn::sn(void) :son(nullptr), amSon(0) {
			;
		}

		sinc& sn::getSon(void) {
			sn& object = *this;
			return object.son;
		}



	}


}