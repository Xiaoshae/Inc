

#ifndef __INC__

#define __INC__

#include <iostream>

#include "space.h"
#include "sn.h"


using std::string;
using std::cout;
using std::cerr;
using std::endl;



namespace lib_inc {


	class inc;

	typedef inc* incptr;

	using n_sn::sn;
	using n_link::link;

	using gen = n_space::space<void*>;
	using am = n_space::space<size_t>;


	class link;

	class inc {

	private:

		friend class link;

		string name;
		gen data;
		incptr father;
		sn son;
		link links;

	private:


	public:


		inc(void):data(nullptr),links(data,son.getSon()) {

		}

	};

}

#endif // !__INC__
