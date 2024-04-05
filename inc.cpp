#include "inc.h"

namespace lib_inc {

	namespace n_sn {

		//新建
		sn::sn(void):son(nullptr),amSon(0) { }

		//共享
		sn::sn(const sn& s) : son(s.son),amSon(s.amSon) { }

		//共享
		sn& sn::operator=(const sn& s) {

			sn& object = *this;

			object.son.share(s.son);
			object.amSon.share(s.amSon);

			return object;

		}

		void sn::hard(const sn& s) {


		}

		void sn::symbolic(const sn& s) {


		}

		void sn::copy(const sn& s) {



		}
	}



	void inc::setFather(inc* father) {
		inc& object = *this;

		object.father = father;

		return;
	}

	inc::inc(const string& name, void* data, inc* father) :
		inc(name, data) {

		inc& object = *this;

		object.setFather(father);

		return;

	}


	inc::inc(const char* C_name, void* data) :
		inc((string)(C_name), data) {
		;
	}


	inc::inc(const string& name, void* data) :
		name(name), father(nullptr), type(link::hard) {

		inc& object = *this;

		// object.name = name;

		try {
			object.data = new void*;
			*(object.data) = data;
		}
		catch (...) {
			cerr << "inc object new void * memory error" << endl;
			throw;
		}

		try {
			object.n_link = new size_t;
			*(object.n_link) = 1;
		}
		catch (...) {
			cerr << "inc object new size_t memory error" << endl;
			throw;
		}

		return;
	}

	void inc::symbolic(const inc& i) {

		inc& object = *this;

		object.name = i.name;
		object.data = i.data;
		object.son = i.son;
		object.type = link::symbolic;
		object.n_link = i.n_link;

		return;
	}

	void inc::copy(const inc& i) {

		inc& object = *this;

		object.name = i.name;
		try {
			object.data = new void*;
			//*(object.data) = d_copy(*(object.data), *(i.data));
		}
		catch (...) {
			cerr << "inc copy fun new void * memory error" << endl;
			throw;
		}

		//object.son.copy(i.son);

		object.type = link::hard;

		try {
			object.n_link = new size_t;
			*(object.n_link) = 1;
		}
		catch (...) {
			cerr << "inc copy fun new size_t memory error" << endl;
			throw;
		}


		return;

	}

	inc::inc(const inc& i) {

		inc& object = *this;

		object.copy(i);

		return;

	}

	inc& inc::operator=(const inc& i) {

		inc& object = *this;

		//object.symbolic(i);

		return object;
	}


}
