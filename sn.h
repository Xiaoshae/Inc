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

			bool AdjustQuantity(const size_t& n);

			size_t computeOffset(const inc& i) const;

			bool AdjustBackward(const size_t& n);

			bool expand(const size_t& n = 1);

			void zoomOut(const size_t& n = 1);


		public:



			bool inCrease(const inc& i);


			bool Copy(const sn& s);

			size_t Getquantity(void) const;

			inc& operator[](const size_t& n);
			const inc& operator[](const size_t& n) const;

			inc& operator[](const string& name);
			const inc& operator[](const string& name)const;


		};



	}

}

#endif // !__SN__
