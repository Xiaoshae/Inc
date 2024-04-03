#include "inc.h"

namespace lib_inc {

	namespace n_sn {

		sn::sn(void) {

			sn& object = *this;

			try {
				object.son = new inc**;
			}
			catch (...) {
				cerr << "sn object new inc** memory error" << endl;
				throw;
			}

			try {
				object.amSon = new size_t;
				*(object.amSon) = 0;
			}
			catch (...) {
				cerr << "sn object new size_t memory error" << endl;
				throw;
			}

			return;
		}

		sn::sn(const sn& s) {

			sn& object = *this;

			//object.copy(s);

			return;

		}

		sn& sn::operator=(const sn& s) {

			sn& object = *this;

			//object.symbolic(s);

			return object;

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
