﻿#pragma once

#ifndef __SN__

#define __SN__

#include "space.h"
#include "link.h"

#include <string>
#include <cstdlib>

using std::string;


namespace lib_inc {


	class inc;

	namespace n_sn {

		using sinc = n_space::space<inc**>;
		using am = n_space::space<size_t>;

		class sn {

		private:

			

			sinc son;
			am amSon;

		public:

			sn(void);

			sinc& getSon(void);

		};



	}

}

#endif // !__SN__
