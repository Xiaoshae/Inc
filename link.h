#pragma once


#ifndef __LINK__

#define __LINK__

#include "space.h"
#include <string>

using std::string;

namespace lib_inc {

	class inc;

	namespace n_link {


		enum class linkMethod {
			hard = 0,
			symbolic = 1,
			mount = 3
		};

		using sinc = n_space::space<inc**>;
		using gen = n_space::space<void*>;
		using am = n_space::space<size_t>;

		using incptr = inc*;
		using linkGroup = inc**;

		class link {

		private:

			linkMethod linktype;

			union {
				string SymbolicTarget;
				incptr Target;	
			};

			am hn_link;

			gen& data;
			sinc& son;
			am& amSon;

			linkGroup notice;
			size_t amNotice;

		public:

			link(inc & i);
			~link(void);

		private:

			bool expand(void);

			void zoomOut(void);

			bool requestNotice(void);

			bool responseNotice(void);

		public:


			bool append(incptr i);

			bool reduce(incptr i);

		};
	}



}


#endif


