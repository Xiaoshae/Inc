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

			link& object = *this;

			linkGroup newNotice = reinterpret_cast<linkGroup>(realloc(notice, (amNotice + 1) * 8));

			if (newNotice == nullptr) {
				;
			}

			object.notice = newNotice;
			object.amNotice++;

			return true;

		}

		void link::zoomOut(void) {

			link& object = *this;

			object.amNotice--;
			object.notice = reinterpret_cast<linkGroup>(realloc(notice, object.amNotice * 8));

			return;
		}

		// 上级发生变化，上级调用下级该函数进行通告
		bool link::takeOver(void) {
			link& object = *this;

			object.transfer();

			return true;

		}

		// 接收当上级的变化通告，将通告继续传递到下级
		bool link::transfer(void) {

			link& object = *this;

			for (int i = 0; i < object.amNotice; i++) {
				(*(object.notice[i])).links.takeOver();
			}

			return false;
		}

		// 下游发生变化，需要反馈到上游去
		bool link::feedback(void) {

			return false;
		}

		bool link::append(incptr i) {

			link& object = *this;

			bool Judge = object.expand();

			if (Judge != true) {

			}

			object.notice[amNotice - 1] = i;

			return true;
		}

		bool link::reduce(incptr i) {

			link& object = *this;


			size_t n = 0;
			while (n < object.amNotice) {
				if (object.notice[n] == i) {
					break;
				}
				n++;
			}

			// linkGroupo中不存在这个incptr
			if (n == object.amNotice) {

			}

			while (n < object.amNotice - 1) {
				object.notice[n] = object.notice[n + 1];
				n++;
			}

			object.zoomOut();

			return true;
		}


		
	}

}
