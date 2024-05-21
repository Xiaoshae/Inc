#include "link.h"
#include "inc.h"


namespace lib_inc {

	namespace n_link {

		link::link(inc& i) :
			ts(types::None),
			tg(nullptr),
			hn(1),
			data(i.data),
			son(i.son.son),
			amSon(i.son.amSon),
			sonback(nullptr),
			amSonback(0),
			notice(nullptr),
			amNotice(0)
		{
			;
		}

		link::~link(void) {

		}


		bool link::expand(void) {

			link& o = *this;

			linkGroup newNotice = reinterpret_cast<linkGroup>(realloc(notice, (amNotice + 1) * sizeof(void*)));

			if (newNotice == nullptr) {
				cout << "Error: class link | expand Memory Error!" << endl;
				throw;
			}

			o.notice = newNotice;
			o.amNotice++;

			return true;

		}

		void link::zoomOut(void) {

			link& o = *this;

			o.amNotice--;
			o.notice = reinterpret_cast<linkGroup>(realloc(notice, o.amNotice * sizeof(void*)));

			return;
		}

		// 上级发生变化，上级调用下级该函数进行通告
		bool link::takeOver(ctypes cs) {
			link& o = *this;

			switch (cs)
			{
			case ctypes::Delete: {
				break;
			}
			case ctypes::UpperLayer: {
				// o.son = o.Target->son.son;
				o.transfer(cs);
				break;
			}
			case ctypes::JoinLink: {
				break;
			}
			case ctypes::UnLink: {
				break;
			}
			}

			o.transfer(cs);

			return true;

		}

		// 接收当上级的变化通告，将通告继续传递到下级
		bool link::transfer(ctypes cs) {

			link& o = *this;

			for (int i = 0; i < o.amNotice; i++) {
				o[i].links.takeOver(cs);
				// (*(o.notice[i])).links.takeOver(cs);
			}

			return true;
		}

		

		// 取消链接
		bool link::joinLink(inc& i) {

			link& o = *this;

			return o.append(&i);

		}

		// 取消链接
		bool link::unLink(inc& i) {

			link& o = *this;

			return o.reduce(&i);

		}


		bool link::append(incptr i) {

			link& o = *this;

			bool judge = o.expand();

			if (judge != true) {
				cout << "Error: class link | append to expand Error!" << endl;
				throw;
			}

			o.notice[amNotice - 1] = i;

			return true;
		}

		bool link::reduce(incptr i) {

			link& o = *this;


			size_t n = 0;
			while (n < o.amNotice) {
				if (o.notice[n] == i) {
					break;
				}
				n++;
			}

			// linkGroupo中不存在这个incptr
			if (n == o.amNotice) {

			}

			while (n < o.amNotice - 1) {
				o.notice[n] = o.notice[n + 1];
				n++;
			}

			o.zoomOut();

			return true;
		}

		void link::Copy(const link& l) {

			link& o = *this;

			o.ts = l.ts;

			if (o.ts == types::Symbolic) {
				o.stg = l.stg;
			}
			else {
				o.tg = l.tg;
			}

			o.hn = 1;
			o.notice = nullptr;
			o.amNotice = 0;

			return;
		}


		inc& link::operator[](const size_t& n) {

			link& o = *this;

			if (!(n >= 0 && n <= o.amNotice)) {
				cout << "Error:out of index" << endl;
				throw;
			}

			return (*(o.notice[n]));
		}

		const inc& link::operator[](const size_t& n) const {

			const link& o = *this;

			if (!(n >= 0 && n <= o.amNotice)) {
				cout << "Error:out of index" << endl;
				throw;
			}

			return (*(o.notice[n]));
		}





	}

}
