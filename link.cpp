#include "link.h"
#include "inc.h"


namespace lib_inc {

	namespace n_link {

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
		bool link::requestNotice(void) {
			link& object = *this;

			object.responseNotice();

			return true;

		}

		// 接收当上级的变化通告，将通告继续传递到下级
		bool link::responseNotice(void) {

			link& object = *this;

			for (int i = 0; i < object.amNotice; i++) {
				(*(object.notice[i])).links.requestNotice();
			}

			return false;
		}


		link::link(gen&data,sinc& son):data(data),son(son) {
			link& object = *this;
			object.links = method::hard;
			object.notice = nullptr;
			object.amNotice = 0;
			return;
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
