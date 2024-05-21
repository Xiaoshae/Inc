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
				cout << "Error:out of index" << endl;
				throw;
			}

			return (*(o.son[n]));
		}

		const inc& sn::operator[](const size_t& n) const {

			const sn& o = *this;

			if (!(n >= 0 && n <= o.amSon)) {
				cout << "Error:out of index" << endl;
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
				cout << "Not found" << endl;
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
				cout << "Not found" << endl;
				throw;
			}

			return o[n];
		}

		bool sn::AdjustQuantity(const size_t& n) {

			sn& o = *this;

			bool judge = true;

			for (size_t i = n; i < o.amSon; i++) {
				delete o.son[i];
			}

			if (o.amSon - n > 0) {
				o.zoomOut(o.amSon - n);
			}
			else {
				judge = o.expand(n - o.amSon);

				// 增大失败
				// 需要处理
				if (judge == false) {
					cout << "错误AdjustQuantity" << endl;
					throw;
				}
			}

			if (judge == true) {

				for (size_t i = o.amSon; i < n; i++) {
					o.son[i] = new inc("");
				}
			}

			return judge;

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

			bool judge = false;

			judge = o.expand();

			if (judge == true) {

				for (size_t i = o.amSon - 1; i > n; i--) {

					o.son[i] = o.son[i - 1];

				}

				o.son[n] = new inc;

			}

			return judge;

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

			bool judge = true;

			if (t.amSon != s.amSon) {
				size_t n = t.amSon > s.amSon ? (t.amSon - s.amSon) : (s.amSon - t.amSon);
				judge = t.AdjustQuantity(t.amSon);
			}

			if (judge == true) {

				t.amSon = s.amSon;

				for (size_t i = 0; i < t.amSon; i++) {
					inc& ti = (*(t.son[i]));
					inc& si = (*(s.son[i]));

					ti.Copy(si);
				}

			}

			return judge;
		}

		bool sn::inCrease(const inc& i) {

			sn& o = *this;

			bool judge = false;

			size_t n = 0;
			size_t offset = o.computeOffset(i);

			if (i.CheckName() == true) {

				if (offset == o.amSon) {
					judge = true;
				}
				else {
					judge = (i != o[offset]);
				}

				if (judge == false) {
					cout << "Error:inCopy Name Error";
					throw;
				}

			}

			if (judge == true) {

				judge = o.AdjustBackward(offset);

			}

			if (judge == true) {

				o[offset].Copy(i);

			}
			else {

				cout << "Error:class sn inCopy to AdjustBackward" << endl;
				throw;

			}

			return judge;
		}



	}

}