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
			multeSpec** Son;
			am amSon;

		};

		typedef multeSpec** sn;
		typedef multeSpec* multe;
		typedef multeSpec thmulte;

	}
	
	using multeName::multe;
	using multeName::thmulte;

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
		bool autoFet; //是否开启自动处理Fet
		null (*newFet)(null nowFet,ace* nowAce); //释放Fet
		ace(*endingFet)(null nowFet);  //新建Fet副本

		//异常代码，为0表示没有异常
		ace abnCode;

	public:

		bool setName(u8 newName);

		u8 getName(void);

		bool setFet(null newFet, ace(*Fetfree)(null Fet) = NULL);

		friend void itf(void);
	};

}


#endif // !__INC__
