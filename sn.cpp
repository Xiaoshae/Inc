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

		bool sn::expand(void) {

			sn& object = *this;

			incGrouop newSon = reinterpret_cast<incGrouop>(realloc(object.son, (object.amSon + 1) * 8));

			// 内存扩大失败
			// 此处需要处理
			cout << "警告:代码编写未完成!/t[class sn;bool expand(void) function!" << endl;
			if (newSon == nullptr) {

			}

			object.amSon = object.amSon + 1;
			object.son = newSon;

			return true;	
		}

		void sn::zoomOut(void) {

			sn& object = *this;

			object.amSon = object.amSon - 1;
			object.son = reinterpret_cast<incGrouop>(realloc(object.son, (object.amSon * 8)));

			return;
		}


	}


}