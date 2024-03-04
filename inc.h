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
		typedef const void* null;
		
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

		inc(u8 newName = "",null newFet = NULL,
			bool (*newCreateFet)(null nowFet) = NULL,
			null(*newEndingFet)(null nowFet) = NULL);

	private:
		
		multe base;

		//释放Fet
		bool (*createFet)(null nowFet);
		//创建Fet副本
		null (*endingFet)(null nowFet);


	public:

		bool setName(u8 newName);

		u8 getName(void);

		bool setFet(null newFet, ace(*Fetfree)(null Fet) = NULL);

		null getFet(void);


		friend void itf(void);
	};

}


#endif // !__INC__
