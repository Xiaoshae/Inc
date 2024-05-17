#include "sn.h"
#include "inc.h"

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

		bool sn::AdjustQuantity(const size_t& n) {

			sn& object = *this;

			bool Judge = true;

			for (size_t i = n; i < object.amSon; i++) {
				delete object.son[i];
			}

			if (object.amSon - n > 0) {
				object.zoomOut(object.amSon - n);
			}
			else {
				Judge = object.expand(n - object.amSon);

				// 增大失败
				// 需要处理
				if (Judge == false) {
					cout << "错误AdjustQuantity" << endl;
				}
			}

			if (Judge == true) {

				for (size_t i = object.amSon; i < n; i++) {
					object.son[i] = new inc("");
				}
			}

			return Judge;

		}

		bool sn::expand(const size_t& n) {

			sn& object = *this;

			object.amSon = object.amSon + n;
			incGrouop newSon = reinterpret_cast<incGrouop>(realloc(object.son, (object.amSon) * 8));

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

		void sn::zoomOut(const size_t& n) {

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

		bool sn::Copy(const sn& s) {

			sn& t = *this;

			bool Judge = true;

			if (t.amSon != s.amSon) {
				size_t n = t.amSon > s.amSon ? (t.amSon - s.amSon) : (s.amSon - t.amSon);
				Judge = t.AdjustQuantity(t.amSon);
			}

			if (Judge == true) {

				t.amSon = s.amSon;

				for (size_t i = 0; i < t.amSon; i++) {
					inc& ti = (*(t.son[i]));
					inc& si = (*(s.son[i]));

					ti.Copy(si);
				}

			}

			return Judge;
		}

		bool sn::inCopy(const inc& i) {

			sn& o = *this;


			return true;
		}

		bool sn::inHard(const inc& i) {

			return true;
		}

		bool sn::inSymbolic(const inc& i) {

			return true;
		}

		bool sn::inMount(const inc& i) {

			return true;
		}


	}

}