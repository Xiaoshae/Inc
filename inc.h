//infoContainer
#ifndef __HEAD__INC__

#define __HEAD__INC__

#include <string>
#include <cstdlib>
#include <vector>

namespace incName {

	namespace multeName {

		typedef size_t th;
		typedef int8_t type;

		using std::string;
		typedef string u8;

		

		typedef const void* null;
		
		typedef size_t am; //amount

		using std::vector;

		struct multeSpec {

			u8 Name;
			null Fet;
			multeSpec* Her;		//fh Her;
			vector<multeSpec*>* Son;	//sn Son
			am amSon;

		};
		
		
		typedef multeSpec* sgsn;
		typedef vector<sgsn>* sn;
		typedef vector<sgsn> vesn;
		typedef multeSpec* fh; //father
		typedef multeSpec* multe;
		typedef multeSpec thmulte;

	}

	using std::string;
	typedef string pwd;
	
	using multeName::multe;
	using multeName::thmulte;
	using multeName::fh;

	using multeName::u8;
	using multeName::null;
	using multeName::sn;
	using multeName::vesn;
	using multeName::sgsn;
	using multeName::am;

	using multeName::th;
	using multeName::type;

	using multeName::thmulte;
	using multeName::multeSpec;



	typedef uint8_t ace;//abnormal code

	class inc {

	public:

		inc(u8 newName = "",null newFet = NULL,
			null (*newCreateFet)(null nowFet) = NULL,
			bool (*newEndingFet)(null nowFet) = NULL);
			
	private:
		
		multe base;

		//释放Fet
		null (*createFet)(null nowFet);
		//创建Fet副本
		bool (*endingFet)(null nowFet);


	public:

		bool setName(u8 newName);

		u8 getName(void);

		bool setFet(null newFet);

		null getFet(void);

		bool setAutoFet(null(*newCreateFet)(null nowFet),
			bool (*newEndingFet)(null nowFet));
		
		bool insertSon(u8 newName = "", null newFet = NULL,pwd path = "");

		friend void itf(void);
	};

}


#endif // !__INC__
