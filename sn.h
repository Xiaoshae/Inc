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

		using incptr = inc*;
		using incGrouop = inc**;

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

		private:

			void s_free(void);

			bool expand(const size_t & n = 1);

			void zoomOut(const size_t & n = 1);

		public:

			bool Increase(void);

			bool Copy(const sn & s);

		};



	}

}

#endif // !__SN__
