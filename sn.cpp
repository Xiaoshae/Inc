#include "sn.h"
#include "inc.h"

namespace lib_inc {

	namespace n_sn {

		sn::sn(void) :
			son(nullptr),
			amSon(0)
		{
			;
		}

		sn::~sn(void) {

		}

		void sn::s_free(void) {

			sn& o = *this;

			for (size_t i = 0; i < o.amSon; i++) {

				delete (o.son)[i];

			}

			delete (incGrouop)(o.son);

			return;
		}

		size_t sn::Getquantity(void) const {

			const sn& o = *this;

			return o.amSon;
		}

		inc& sn::operator[](const size_t& n) {

			sn& o = *this;

			if (!(n >= 0 && n <= o.amSon)) {
				throw;
			}

			return (*(o.son[n]));
		}

		const inc& sn::operator[](const size_t& n) const {

			const sn& o = *this;

			if (!(n >= 0 && n <= o.amSon)) {
				throw;
			}

			return (*(o.son[n]));
		}

		inc& sn::operator[](const string& name) {

			sn& o = *this;
			inc i(name);
			size_t n = 0;

			while (n < o.amSon) {
				if (i == o[n]) {
					break;
				}
				n++;
			}

			if (n == o.amSon) {
				throw;
			}

			return o[n];
		}

		const inc& sn::operator[](const string& name) const {

			const sn& o = *this;
			inc i(name);
			size_t n = 0;

			while (n < o.amSon) {
				if (i == o[n]) {
					break;
				}
			}

			if (n == o.amSon) {
				throw;
			}

			return o[n];
		}

		bool sn::AdjustQuantity(const size_t& n) {

			sn& o = *this;

			bool Judge = true;

			for (size_t i = n; i < o.amSon; i++) {
				delete o.son[i];
			}

			if (o.amSon - n > 0) {
				o.zoomOut(o.amSon - n);
			}
			else {
				Judge = o.expand(n - o.amSon);

				// 增大失败
				// 需要处理
				if (Judge == false) {
					cout << "错误AdjustQuantity" << endl;
					throw;
				}
			}

			if (Judge == true) {

				for (size_t i = o.amSon; i < n; i++) {
					o.son[i] = new inc("");
				}
			}

			return Judge;

		}

		size_t sn::computeOffset(const inc& i) const {

			const sn& o = *this;

			size_t offset = 0;

			while (offset < o.amSon) {

				if (i <= o[offset]) {
					break;
				}

				offset++;

			}

			return offset;
		}

		bool sn::AdjustBackward(const size_t& n) {

			sn& o = *this;

			bool Judge = false;

			Judge = o.expand();

			if (Judge == true) {

				for (size_t i = o.amSon - 1; i > n; i--) {

					o.son[i] = o.son[i - 1];

				}

				o.son[n] = new inc;

			}

			return Judge;

		}

		bool sn::expand(const size_t& n) {

			sn& o = *this;

			o.amSon = o.amSon + n;
			incGrouop newSon = reinterpret_cast<incGrouop>(realloc(o.son, (o.amSon) * sizeof(void*)));

			if (newSon == nullptr) {

				// 内存扩大失败
				// 此处需要处理
				cout << "警告:代码编写未完成!/t[class sn;bool expand(void) function!" << endl;
				o.amSon = o.amSon - n;
				throw;

			}

			o.son = newSon;

			return true;
		}

		void sn::zoomOut(const size_t& n) {

			sn& o = *this;

			if (o.amSon - n > 0) {
				o.amSon = o.amSon - n;
			}
			else {
				o.amSon = 0;
			}

			o.son = reinterpret_cast<incGrouop>(realloc(o.son, (o.amSon * 8)));

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

			bool Judge = false;

			size_t n = 0;
			size_t offset = o.computeOffset(i);

			if (i.CheckName() == true) {

				if (offset == o.amSon) {
					Judge = true;
				}
				else {
					Judge = (i != o[offset]);
				}

				if (Judge == false) {
					cout << "Error:inCopy Name Error";
					throw;
				}

			}

			if (Judge == true) {

				Judge = o.AdjustBackward(offset);

			}

			if (Judge == true) {

				o[offset].Copy(i);

			}

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