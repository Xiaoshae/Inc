//infoContainer
#ifndef __HEAD__INC__

#define __HEAD__INC__

#include <string>

namespace incName {

	namespace multeName {

		typedef size_t th;
		typedef int8_t type;

		using std::string;
		typedef string u8;
		typedef void* null;
		
		typedef size_t am; //amount

		

		struct multeSpec {

			u8 Name;
			null Fet;
			multeSpec** Son;
			am amSon;

		};

		typedef multeSpec** sn;
		typedef multeSpec* multe;

		const static th thmulte = sizeof(multeSpec);

	}
	


}


#endif // !__INC__
