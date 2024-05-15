#pragma once


#ifndef __LINK__

#define __LINK__

#include "space.h"

namespace lib_inc {

	class inc;

	namespace n_link {

		using sinc = n_space::space<inc**>;
		using gen = n_space::space<void*>;

		enum class method {
			hard = 0,
			symbolic = 1,
			mount = 3
		};


		using incptr = inc*;
		using linkGroup = inc**;

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

			bool requestNotice(void);

			bool responseNotice(void);

		public:

			link(gen& data, sinc& son);

			bool append(incptr i);

			bool reduce(incptr i);

		};
	}



}


#endif


