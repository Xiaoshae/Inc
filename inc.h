//infoContainer
#ifndef __HEAD__INC__

#define __HEAD__INC__

#include <string>

namespace __NSPE__INC__ {

	namespace __NSPE__MULTE__ {

		typedef size_t th;
		typedef int8_t type;

		using std::string;
		typedef string u8;
		typedef void* null;
		typedef multeSpec** sn;
		typedef size_t am; //amount

		typedef multeSpec* multe;

		struct multeSpec {

			u8 Name;
			null Fet;
			sn Son;
			am amSon;

		};

		const static th thmulte = sizeof(multeSpec);

	}

	namespace multe = __NSPE__MULTE__;

}

namespace inc = __NSPE__INC__;

#endif // !__INC__
