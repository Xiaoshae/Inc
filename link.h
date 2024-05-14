#pragma once


#ifndef __LINK__

#define __LINK__


#include "space.h"
#include "sn.h"
#include "inc.h"

namespace lib_inc {

	namespace n_link {

		class inc;

		enum class method {
			hard = 0,
			symbolic = 1,
			mount = 3
		};

		typedef inc* incptr;
		typedef inc** linkGroup;

		using sinc = n_space::space<inc**>;
		using gen = n_space::space<void*>;

		class link {

		private:

			method links;

			gen& data;
			sinc& son;

			linkGroup notice;
			size_t amNotice;



		private:

			bool expand(void);

			void zoomOut(void);

			bool requestNotice(gen& data, sinc& son);

			bool responseNotice(void);

		public:

			link(gen& data, sinc& son);

			bool append(incptr i);

			bool reduce(incptr i);

		};
	}



}


#endif


