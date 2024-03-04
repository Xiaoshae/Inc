//infoContainer
#ifndef __HEAD__INC__

#define __HEAD__INC__

#include <string>
#include <cstdlib>

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
			multeSpec* Her;		//fh Her;
			multeSpec** Son;	//sn Son
			am amSon;

		};

		typedef multeSpec** sn;
		typedef multeSpec* fh; //father
		typedef multeSpec* multe;
		typedef multeSpec thmulte;

	}
	
	using multeName::multe;
	using multeName::thmulte;
	using multeName::fh;

	using multeName::u8;
	using multeName::null;
	using multeName::sn;
	using multeName::am;

	using multeName::th;
	using multeName::type;

	using multeName::thmulte;
	using multeName::multeSpec;

	typedef uint8_t ace;//abnormal code

	class inc {

		inc(u8 newName = "",null newFet = (null)(NULL));

	private:
		
		multe base;
		bool autoFet;
		null (*newFet)(null nowFet,ace* nowAce);
		ace(*endingFet)(null nowFet);

		//异常代码，为0表示没有异常
		ace abnCode;

	public:

		bool setName(u8 newName);

		bool setFet(null newFet, ace(*Fetfree)(null Fet) = NULL);

		friend void itf(void);
	};

}


#endif // !__INC__
