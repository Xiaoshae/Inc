#pragma once

#ifndef __SN__

#define __SN__

#include "space.h"

#include <string>
#include <cstdlib>

using std::string;


namespace lib_inc {


	class inc;

	namespace n_link {
		class link;
	}

	namespace n_sn {


		using sinc = n_space::space<inc**>;
		using am = n_space::space<size_t>;

		using n_link::link;

		class sn {

			friend class link;

		private:

			sinc son;
			am amSon;

		public:

			sn(void);
			~sn(void);

		public:

			sinc& getSon(void);

		};



	}

}

#endif // !__SN__
