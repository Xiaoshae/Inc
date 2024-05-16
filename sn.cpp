#include "sn.h"

namespace lib_inc {

	namespace n_sn {


		sn::sn(void) :
			son(nullptr),
			amSon(0) {
			;
		}

		sn::~sn(void) {

		}

		void sn::s_free(void) {

			sn& object = *this;

			for (size_t i = 0; i < object.amSon; i++) {

				delete (object.son)[i];

			}

			delete (incGrouop)(object.son);

			return;
		}

		bool sn::expand(const size_t & n) {

			sn& object = *this;

			object.amSon = object.amSon + n;
			incGrouop newSon = reinterpret_cast<incGrouop>(realloc(object.son, (object.amSon + 1) * 8));

			// 内存扩大失败
			// 此处需要处理
			cout << "警告:代码编写未完成!/t[class sn;bool expand(void) function!" << endl;
			if (newSon == nullptr) {

				object.amSon = object.amSon - n;

			}

			object.amSon++;
			object.son = newSon;

			return true;	
		}

		void sn::zoomOut(const size_t & n) {

			sn& object = *this;

			if (object.amSon - n > 0) {
				object.amSon = object.amSon - n;
			}
			else {
				object.amSon = 0;
			}

			object.son = reinterpret_cast<incGrouop>(realloc(object.son, (object.amSon * 8)));

			return;
		}

		bool sn::Copy(const sn & s) {

			sn& t = *this;

			if (s.amSon > 0)



			if (s.amSon > 0 && s.amSon != t.amSon) {

			}

			return true;
		}


	}


}