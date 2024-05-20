#include "link.h"
#include "inc.h"


namespace lib_inc {

	namespace n_link {

		link::link(inc & i):
			linktype(types::Hard),
			Target(nullptr),
			hn_link(1),
			data(i.data),
			son(i.son.son),
			amSon(i.son.amSon),
			notice(nullptr),
			amNotice(0){

			return;

		}

		link::~link(void) {

		}


		bool link::expand(void) {

			link& o = *this;

			linkGroup newNotice = reinterpret_cast<linkGroup>(realloc(notice, (amNotice + 1) * 8));

			if (newNotice == nullptr) {
				;
			}

			o.notice = newNotice;
			o.amNotice++;

			return true;

		}

		void link::zoomOut(void) {

			link& o = *this;

			o.amNotice--;
			o.notice = reinterpret_cast<linkGroup>(realloc(notice, o.amNotice * 8));

			return;
		}

		// 上级发生变化，上级调用下级该函数进行通告
		bool link::takeOver(void) {
			link& o = *this;

			o.transfer();

			return true;

		}

		// 接收当上级的变化通告，将通告继续传递到下级
		bool link::transfer(void) {

			link& o = *this;

			for (int i = 0; i < o.amNotice; i++) {
				(*(o.notice[i])).links.takeOver();
			}

			return false;
		}

		// 下游发生变化，需要反馈到上游去
		bool link::feedback(void) {

			return false;
		}

		bool link::append(incptr i) {

			link& o = *this;

			bool Judge = o.expand();

			if (Judge != true) {

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

			o.linktype = l.linktype;

			if (o.linktype == types::Symbolic) {
				o.SymbolicTarget = l.SymbolicTarget;
			}
			else {
				o.Target = l.Target;
			}

			o.hn_link = 1;
			o.notice = nullptr;
			o.amNotice = 0;

			return;
		}


		
	}

}
